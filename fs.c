#include "util.h"
#include "common.h"
#include "block.h"
#include "fs.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#ifdef FAKE
#define ERROR_MSG(m) printf m;
#else
#define ERROR_MSG(m)
#endif

char *MAGIC_NUMBER = 0x0140c52a;

void *my_malloc(int size)
{
  void *tmp = malloc(size);
  if (tmp == NULL)
  {
    fprintf(stderr, "Could not alloc memory\n");
    exit(1);
  }
  memset(tmp, 0, size);
  return tmp;
}

void my_fseek(void *file, int seek)
{
  int ret;
  ret = fseek(file, 0, SEEK_SET);
  assert(ret == 0);
  ret = fseek(file, seek, SEEK_SET);
  assert(ret == seek);
  return;
}

void fs_init(void)
{
  block_init();
  FILE *file = fopen("./disk", "r+b");
  my_fseek(file, SECTOR_SIZE - 4);
  char *magic_number;
  int ret = fread(magic_number, 1, 4, file);
  if (magic_number == MAGIC_NUMBER)
  {
    // mounted
    return;
  }

  my_fseek(file, SECTOR_SIZE - 4);
  ret = fwrite(MAGIC_NUMBER, 1, 4, file);
  assert(ret == 4);
  return;
}

int fs_mkfs(void)
{
  FILE *fp;
  char zero = '0';
  int i, k, j;
  char dataFileName[MAX_FILE_NAME];
  SuperBlock spBlock;

  spBlock.blockSize = 512;
  spBlock.iNodeCount = 64;
  // strcpy(dataFileName, argv[3]);
  spBlock.iNodePositions = spBlock.blockSize + sizeof(SuperBlock); // starting address of iNode
  spBlock.iNodeSize = sizeof(iNode);

  return -1;
}

int fs_open(char *fileName, int flags)
{
  return -1;
}

int fs_close(int fd)
{
  return -1;
}

int fs_read(int fd, char *buf, int count)
{
  return -1;
}

int fs_write(int fd, char *buf, int count)
{
  return -1;
}

int fs_lseek(int fd, int offset)
{
  return -1;
}

int fs_mkdir(char *fileName)
{
  return -1;
}

int fs_rmdir(char *fileName)
{
  return -1;
}

int fs_cd(char *dirName)
{
  return -1;
}

int fs_link(char *old_fileName, char *new_fileName)
{
  return -1;
}

int fs_unlink(char *fileName)
{
  return -1;
}

int fs_stat(char *fileName, fileStat *buf)
{
  return -1;
}

int main()
{
  fs_init();
  return 0;
}
