#include "gridstore.h"
#include <stdlib.h>
#include <stdio.h>

void main(int argc, char *argv[]){

	GSGridStore *store;
	GSCollection *collection;
	GSQuery *query;
	GSRowSet *rs;
	GSRow *row;
	GSContainerInfo info = GS_CONTAINER_INFO_INITIALIZER;
	GSColumnInfo columnInfo = GS_COLUMN_INFO_INITIALIZER;
	GSColumnInfo columnInfoList[3];
	GSResult ret;
	size_t stackSize;
	GSResult errorCode;
	GSChar errMsgBuf1[1024], errMsgBuf2[1024];	// �G���[���b�Z�[�W���i�[����o�b�t�@
	int i;

	//===============================================
	// �N���X�^�ɐڑ�����
	//===============================================
	// �ڑ������w�肷�� (�}���`�L���X�g����)
	const GSPropertyEntry props[] = {
		{ "notificationAddress", "239.0.0.1" },
		{ "notificationPort", "31999" },
		{ "clusterName", "myCluster" },
		{ "database", "public" },
		{ "user", "admin" },
		{ "password", "admin" },
		{ "applicationName", "SampleC" }
	};

	
	// �ڑ������w�肷�� (�Œ胊�X�g����)
	/*
	const GSPropertyEntry props[] = {
		{ "notificationMember", "192.168.10.110:10001" },
		{ "clusterName", "myCluster" },
		{ "database", "public" },
		{ "user", "admin" },
		{ "password", "admin" },
		{ "applicationName", "SampleC" }
	};
	*/
	
	const size_t propCount = sizeof(props) / sizeof(*props);
	const int32_t rowKeyColumnList[] = { 0, 1 };
	const size_t rowKeyColumnCount = sizeof(rowKeyColumnList) / sizeof(*rowKeyColumnList);
	const GSChar *productType;
	int32_t productId;
	const GSChar *productName;

	// GridStore�C���X�^���X���擾����
	ret = gsGetGridStore(gsGetDefaultFactory(), props, propCount, &store);
	if ( !GS_SUCCEEDED(ret) ){
		fprintf(stderr, "ERROR gsGetGridStore\n");
		goto LABEL_ERROR;
	}
	// �R���e�i�쐬��擾�Ȃǂ̑�����s���ƁA�N���X�^�ɐڑ������
	ret = gsGetContainerGeneral(store, "SampleC_CompositKey", &collection);
	if ( !GS_SUCCEEDED(ret) ){
		fprintf(stderr, "ERROR gsGetContainerGeneral\n");
		goto LABEL_ERROR;
	}

	//===============================================
	// �R���N�V�������쐬����
	//===============================================
	// �R���e�i��ʂ�ݒ肷��
	info.type = GS_CONTAINER_COLLECTION;

	// ���E�L�[����̏ꍇ�͐ݒ肷��
	info.rowKeyColumnList = rowKeyColumnList;
	info.rowKeyColumnCount = rowKeyColumnCount;

	// �J���������`����
	columnInfo.name = "productType";
	columnInfo.type = GS_TYPE_STRING;
	columnInfoList[0] = columnInfo;

	columnInfo.name = "productId";
	columnInfo.type = GS_TYPE_INTEGER;
	columnInfoList[1] = columnInfo;

	columnInfo.name = "productaName";
	columnInfo.type = GS_TYPE_STRING;
	columnInfoList[2] = columnInfo;

	// �J���������R���e�i���I�u�W�F�N�g�ɐݒ肷��
	info.columnCount = sizeof(columnInfoList) / sizeof(*columnInfoList);
	info.columnInfoList = columnInfoList;

	// �R���N�V�������쐬����
	fprintf(stdout, "Create Collection CompositKey\n");
	ret = gsPutContainerGeneral(store, "CompositKey", &info, GS_FALSE, &collection);
	if ( !GS_SUCCEEDED(ret) ){
		fprintf(stderr, "ERROR gsPutContainerGeneral\n");
		goto LABEL_ERROR;
	}
	
	// ��̃��E�I�u�W�F�N�g�̍쐬
	ret = gsCreateRowByContainer(collection, &row);
	if (!GS_SUCCEEDED(ret)) {
		fprintf(stderr, "ERROR gsCreateRowByContainer\n");
		goto LABEL_ERROR;
	}

	// �J�����l���Z�b�g
	gsSetRowFieldByString(row, 0, "Food");
	gsSetRowFieldByInteger(row, 1, 1);
	gsSetRowFieldByString(row, 2, "apple");

	// ���E��o�^����
	ret = gsPutRow(collection, NULL, row, NULL);
	if (!GS_SUCCEEDED(ret)) {
		fprintf(stderr, "ERROR gsPutRow\n");
		goto LABEL_ERROR;
	}

	printf("Put Row\n");

	ret = gsQuery(collection, "SELECT *", &query);
	if (!GS_SUCCEEDED(ret)) {
		fprintf(stderr, "ERROR gsQuery\n");
		goto LABEL_ERROR;
	}
	ret = gsFetch(query, GS_FALSE, &rs);
	if (!GS_SUCCEEDED(ret)) {
		fprintf(stderr, "ERROR gsFetch\n");
		goto LABEL_ERROR;
	}

	// ��̃��E���쐬
	gsCreateRowByContainer(collection, &row);

	// ���ʂ��擾����
	while (gsHasNextRow(rs)) {
		// ���E���擾����
		ret = gsGetNextRow(rs, row);
		if (!GS_SUCCEEDED(ret)) {
			fprintf(stderr, "ERROR gsGetNextRow\n");
			goto LABEL_ERROR;
		}

		gsGetRowFieldAsString(row, 0, &productType);
		gsGetRowFieldAsInteger(row, 1, &productId);
		gsGetRowFieldAsString(row, 2, &productName);

		printf("id=%s, productName=%d, count=%s\n", productType, productId, productName);
	}
	
	//===============================================
	// �I������
	//===============================================
	// ���\�[�X���������
	gsCloseGridStore(&store, GS_TRUE);
	
	printf("success!\n");

	return;


LABEL_ERROR:
	//===============================================
	// �G���[����
	//===============================================
	// �G���[�R�[�h�ƃG���[���b�Z�[�W���o�͂���
	stackSize = gsGetErrorStackSize(store);
	for ( i = 0; i < stackSize; i++ ){
		errorCode = gsGetErrorCode(store, i);
		gsFormatErrorMessage(store, i, errMsgBuf1, sizeof(errMsgBuf1));
		gsFormatErrorLocation(store, i, errMsgBuf2, sizeof(errMsgBuf2));
		printf("[%d] %s (%s)\n", errorCode, errMsgBuf1, errMsgBuf2);
	}

	// ���\�[�X���������
	gsCloseGridStore(&store, GS_TRUE);
	return;

}
