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


### RPM/DEB�t�@�C���̗��p

#### �C���X�g�[��

[CentOS, Ubuntu]

�ȉ���URL���Q�Ƃ��Ă��������B  
https://software.opensuse.org/download/package?project=home:knonomura&package=griddb-c-client

[openSUSE]

�ȉ���URL���Q�Ƃ��Ă��������B  
https://software.opensuse.org//download.html?project=home%3Aknonomura&package=griddb-c-client-devel

#### �T���v���v���O�����̎��s
���O��GridDB�T�[�o���N�����Ă����K�v������܂��B

    $ cp /usr/griddb_c_client-X.X.X/sample/sample1.c .
    $ gcc sample1.c -lgridstore
    $ ./a.out <GridDB notification address(default is 239.0.0.1)> <GridDB notification port(default is 31999)>
      <GridDB cluster name> <GridDB user> <GridDB password>
      -->Person: name=name02 status=false count=2 lob=[65, 66, 67, 68, 69, 70, 71, 72, 73, 74]

(�ǉ����)
- /usr/include�t�H���_�̉��ɁA�r���h�Ɏg����gridstore.h�t�@�C��������܂��B  
- /usr/lib64(CentOS, openSUSE)�A/usr/lib/x86_64-linux-gnu(Ubuntu)�t�H���_�̉��ɁA�r���h����ю��s�Ɏg����libgridstore.so�t�@�C��������܂��B  

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

### MSI�t�@�C���̗��p

#### �C���X�g�[��

MSI�p�b�P�[�W(https://github.com/griddb/c_client/releases) ���_�E�����[�h���Ď��s���Ă��������BC:/Program Files/GridDB/C Client/X.X.X�t�H���_�̉��ɃC���X�g�[������܂��B

#### �T���v���v���O�����̍쐬�A�r���h

�ȉ��́AVS2017�̏ꍇ�̎菇�ł��B
* x64�̃v���W�F�N�g���쐬�B[�\���}�l�[�W��] - [�A�N�e�B�u�\�����[�V�����v���b�g�t�H�[��] - [�V�K�쐬]�� "x64"��I�����܂��B
* �v���W�F�N�g�̃\�[�X �t�@�C����sample1.c�t�@�C����ǉ����܂��B
* Include�f�B���N�g���̐ݒ�B[�\���v���p�e�B] - [C/C++] - [�S��] - [�ǉ��̃C���N���[�h�f�B���N�g��]�� gridstore.h �����݂���f�B���N�g�����w�肵�܂��B
* �C���|�[�g���C�u����(gridstore_c.lib)�̐ݒ�B[�����J�[] - [����] - [�ǉ��̈ˑ��t�@�C��] �ɒǉ����܂��B
* �v���W�F�N�g���r���h���܂��B

#### �T���v���v���O�����̎��s
���O��GridDB�T�[�o���N�����Ă����K�v������܂��B

    > sample.exe <GridDB notification address(default is 239.0.0.1)> <GridDB notification port(default is 31999)>
      <GridDB cluster name> <GridDB user> <GridDB password>
      -->Person: name=name02 status=false count=2 lob=[65, 66, 67, 68, 69, 70, 71, 72, 73, 74]

## �h�L�������g
  �ڍׂ͈ȉ��̃h�L�������g���Q�Ƃ��Ă��������B
  - [C API���t�@�����X](http://griddb.github.io/docs-ja/manuals/GridDB_C_API_Reference.html)

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
