#ifndef FS_INCLUDED
#define FS_INCLUDED

#define FS_SIZE 2048
#define MAX_FILE_NAME 32
#define MAX_PATH_NAME 256 // This is the maximum supported "full" path len, eg: /foo/bar/test.txt, rather than the maximum individual filename len.

struct SuperBlock // 24 byte
{
    int blockSize;  // +
    int iNodeCount; // +
    int blockCount;
    // int iNodeSize;  //+
    int iNodePositions; // +
    int blockPositions; // +
};

struct iNode // 104 byte
{
    int fileType; // 0 = root 1 = file, 2 = folder,3 = softlink, 4 = hardlink
    int fileSize;
    char fileName[MAX_FILE_NAME];
    int parentInode;
    int inodeNumber;         // 0-> root
    time_t lastModification; // 8 byte
    int blocksNum[12];       // assigned to 65535 as unused
};

typedef iNode iNode;
typedef SuperBlock SuperBlock;

void fs_init(void);
int fs_mkfs(void);
int fs_open(char *fileName, int flags);
int fs_close(int fd);
int fs_read(int fd, char *buf, int count);
int fs_write(int fd, char *buf, int count);
int fs_lseek(int fd, int offset);
int fs_mkdir(char *fileName);
int fs_rmdir(char *fileName);
int fs_cd(char *dirName);
int fs_link(char *old_fileName, char *new_fileName);
int fs_unlink(char *fileName);
int fs_stat(char *fileName, fileStat *buf);

#endif
