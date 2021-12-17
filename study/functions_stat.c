/* vou colocar aqui as explicaçoes das funçoes.

stat:

A funçao serve para examinar os arquivos e suas autorizaçoes.

struct stat {
	dev_t st_dev:           ID of device containing file 
   ino_t st_ino;           inode number
   mode_t st_mode;         protection 
   nlink_t st_nlink:       number of hard links 
   uild_t st_uid;          user ID of owner 
   gid_t st_gid;           group ID of owner 
   dev_t st_rdev;          device ID (if special file) 
   off_t st_size;          total size, in bytes 
   blksize_t st_blksize;   blocksize for filesystem I/0 
   blkcnt_t st_blocks;     number of 512B blocks allocated 
   time_t st_atime;        time of last access 
   time_t st_mtime;        time of last modification 
   time_t st_ctime;        time of last status change 
};


stat(nome, buf);
   nome = nome do arquivo que sera aberto.
   buf = pontero da estrutura.

fstat(fd, buf);
   retorna 0 se for sucesso ou -1 se falhar.

lstat(name, buff);
   e´ um link file.*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int   main(int ac, char **av)
{
   struct stat buf;

   stat("mini_shell.c", &buf);

   printf("st_mtime = %lo\n", buf.st_mtime);

   return (0);
}
