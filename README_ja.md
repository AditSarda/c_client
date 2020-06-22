GridDB C�N���C�A���g

## �T�v

GridDB C�N���C�A���g��C����p�̃C���^�t�F�[�X��񋟂��܂��B  
�܂��A���̃��|�W�g���ɂ͊ȒP�ȃT���v���v���O����������܂��B  
�ڍׂ�API���t�@�����X��API(C����)�̏͂��Q�Ƃ��Ă��������B

## �����

�ȉ��̊���C�N���C�A���g�̃r���h�ƃT���v���v���O�����̎��s���m�F���Ă��܂��B

    OS: CentOS 7.6(x64) (gcc 4.8.5), Windows 10(x64) (VS2017, CMake 3.15.2)
    GridDB server: V4.5 CE(Community Edition), CentOS 7.6(x64) (gcc 4.8.5)

    OS: Ubuntu 18.04(x64) (gcc 7.5)
    GridDB server: V4.5 CE(Community Edition), Ubuntu 18.04(x64) (gcc 4.8.5)

    OS: openSUSE 15.1(x64) (gcc 7.5)
    GridDB server: V4.5 CE(Community Edition), openSUSE 15.1(x64) (gcc 4.8.5)

## �N�C�b�N�X�^�[�g(CentOS, Ubuntu, openSUSE)

### �\�[�X�R�[�h�̗��p

#### C�N���C�A���g�̃r���h

    $ cd client/c
    $ ./bootstrap.sh
    $ ./configure
    $ make 
    
�����s����ƁAbin�t�H���_�̉��Ɉȉ��̃t�@�C���⃊���N���쐬����܂��B

    libgridstore.so
	libgridstore.so.0
	libgridstore.so.0.0.0

#### �T���v���v���O�����̎��s
���O��GridDB�T�[�o���N�����Ă����K�v������܂��B

    $ cp client/c/sample/sample1.c .
    $ gcc -I./client/c/include -L./bin sample1.c -lgridstore
    $ export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:./bin
    $ ./a.out <GridDB notification address(default is 239.0.0.1)> <GridDB notification port(default is 31999)>
      <GridDB cluster name> <GridDB user> <GridDB password>
      -->Person: name=name02 status=false count=2 lob=[65, 66, 67, 68, 69, 70, 71, 72, 73, 74]

(�ǉ����)
- client/c/include�t�H���_�̉��ɁA�r���h�Ɏg����gridstore.h�t�@�C��������܂��B  
- client/c/sample�t�H���_�̉��ɁA�T���v���v���O����������܂��B

## �N�C�b�N�X�^�[�g(Windows)

### �\�[�X�R�[�h�̗��p

#### CMake�ɂ��VS�\�����[�V�����t�@�C���̐���

* <CMAKE_PATH>\bin\cmake-gui.exe���I�[�v�����܂��B
* "Where is the source code"�� <C_CLIENT_SRC_PATH>\client\c\sample �t�H���_���w�肵�܂��B
* "Where to build the binaries"�Ƀ\�����[�V�����t�@�C��(*.sln , *.vcxproj)�̐�����t�H���_���w�肵�܂��B
* Configure�{�^�����N���b�N��A "Specify the generator for this project"��"Visual Studio 15 2017 Win64"���w�肵�܂��B
* Generate�{�^�����N���b�N����ƃt�@�C������������܂��B

#### VS2017�ɂ��r���h

�\�����[�V�����t�@�C���̐�����t�H���_��client.sln�t�@�C�����N���b�N����VS���N����Aclient�\�����[�V�������r���h���Ă��������B

<C_CLIENT_SRC_PATH>\bin\x64\Release�t�H���_(�����[�X���[�h��)�A<C_CLIENT_SRC_PATH>\bin\x64\Debug�t�H���_(�f�o�b�O���[�h��)�̉��Ɉȉ��̃t�@�C�����쐬����܂��B

    gridstore_c.dll
    gridstore_c.lib

### �T���v���v���O�����̎��s
���O��GridDB�T�[�o���N�����Ă����K�v������܂��B

�\�����[�V�����t�@�C���̐�����t�H���_��sample.sln�t�@�C�����N���b�N����VS���N����Asample�v���W�F�N�g���r���h����ƁA<C_CLIENT_SRC_PATH>\bin\x64\Release�t�H���_(�����[�X���[�h��)�A<C_CLIENT_SRC_PATH>\bin\x64\Debug�t�H���_(�f�o�b�O���[�h��)�̉���sample.exe�t�@�C������������܂��B

    > sample.exe sample1 en <GridDB notification address(default is 239.0.0.1)> <GridDB notification port(default is 31999)>
      <GridDB cluster name> <GridDB user> <GridDB password>
      -->Person: name=name02 status=false count=2 lob=[65, 66, 67, 68, 69, 70, 71, 72, 73, 74]

(�ǉ����)
- client/c/include�t�H���_�̉��ɁA�r���h�Ɏg����gridstore.h�t�@�C��������܂��B  
- client/c/sample�t�H���_�̉��ɁA�T���v���v���O����������܂��B

## �h�L�������g
  �ڍׂ͈ȉ��̃h�L�������g���Q�Ƃ��Ă��������B
  - [API���t�@�����X](https://griddb.github.io/griddb_nosql/manual/GridDB_API_Reference_ja.html)

��C�N���C�A���g(Community Edition)�ł͋�Ԍ^�͗��p�ł��܂���B  

## �R�~���j�e�B
  * Issues  
    ����A�s��񍐂�issue�@�\�������p���������B
  * PullRequest  
    GridDB Contributor License Agreement(CLA_rev1.1.pdf)�ɓ��ӂ��Ē����K�v������܂��B
    PullRequest�@�\�������p�̏ꍇ��GridDB Contributor License Agreement�ɓ��ӂ������̂Ƃ݂Ȃ��܂��B

## ���C�Z���X
  C�N���C�A���g�̃��C�Z���X��Apache License, version 2.0�ł��B  
  �T�[�h�p�[�e�B�̃\�[�X�ƃ��C�Z���X�ɂ��Ă�3rd_party/3rd_party.md���Q�Ƃ��������B
