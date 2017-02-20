#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, const char **argv) {
	DIR *dptr;
	struct dirent *ds;
	struct stat filestat;
	char fileinfo[255];
	dptr = opendir(argv[1]);
	if (!dptr)
		perror("Error: ");
	if (dptr)
		while ((ds = readdir(dptr)) != 0) {
			sprintf(fileinfo, "%s/%s", argv[1], ds->d_name);
			stat(fileinfo, &filestat);
			printf("%d %d %d %d %d %d ", filestat.st_mode, filestat.st_nlink, filestat.st_uid, filestat.st_gid, filestat.st_blksize, filestat.st_mtim);
			printf("%s\n", fileinfo);
		}
	closedir(dptr);
	return 0;
}
