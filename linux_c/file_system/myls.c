#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <sys/sysmacros.h>

int aflag = 0, lflag = 0;

void display_file(char *fname, char *nname)
{
    struct stat buf;
    struct tm *t;
    int i;

    if (stat(fname, &buf) < 0)
    {
        perror("stat error\n");
        return;
    }

    switch (buf.st_mode & S_IFMT)
    {
    case S_IFSOCK:
        printf("s");
        break;
    case S_IFLNK:
        printf("l");
        break;
    case S_IFREG:
        printf("-");
        break;
    case S_IFBLK:
        printf("b");
        break;
    case S_IFDIR:
        printf("d");
        break;
    case S_IFCHR:
        printf("c");
        break;
    case S_IFIFO:
        printf("p");
        break;
    }

    for (i = 8; i >= 0; i--)
    {
        if (buf.st_mode & (1 << i))
        {
            if (i % 3 == 2)
                printf("r");
            if (i % 3 == 1)
                printf("w");
            if (i % 3 == 0)
                printf("x");
        }
        else
            printf("-");
    }

    printf(" %d ", buf.st_nlink);

    printf("%s ", getpwuid(buf.st_uid)->pw_name);
    printf("%s ", getgrgid(buf.st_gid)->gr_name);

    printf("%ld ", buf.st_size);

    t = localtime(&buf.st_mtime);
    printf("%d-%02d-%02d  %02d:%02d ", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
           t->tm_hour, t->tm_min);
    printf("%s\n", nname);

    return;
}

void display_dir(char *dir)
{
    DIR *mydir;
    struct dirent *myitem;
    char fname[256];

    if ((mydir = opendir(dir)) == NULL)
    {
        perror("fail to opendir!\n");
        return;
    }
    while ((myitem = readdir(mydir)) != NULL)
    {
        if (myitem->d_name[0] == '.' &&
            !aflag) //如果if条件成立的就继续下一次循环，否则往下执行
            continue;

        if (lflag) // ls -l -a dir
        {

            sprintf(fname, "%s/%s", dir, myitem->d_name);
            display_file(fname, myitem->d_name);
        }
        else // ls dir
            printf("%s  ", myitem->d_name);
    }
    printf("\n");
    closedir(mydir);
    return;
}

int main(int argc, char *argv[])
{
    int ch, i;
    struct stat buf;

    opterr = 0;
    //解析命令
    while ((ch = getopt(argc, argv, "la")) != -1)
    {
        switch (ch)
        {
        case 'a':
            aflag = 1;
            break;
        case 'l':
            lflag = 1;
            break;
        default:
            printf("wrong option:%c\n", optopt);
            return -1;
        }
    }

    if (optind == argc) // no argument //ls .没有带参直接ls当前目录
        display_dir(".");

    for (i = optind; i < argc; ++i) // ls name1 name2....
    {
        if (stat(argv[i], &buf) < 0)
        {
            perror("fail to stat!\n");
            return -1;
        }
        if (S_ISDIR(buf.st_mode)) // dir
        {
            printf("%s:\n", argv[i]);
            display_dir(argv[i]);
        }
        else           // file
            if (lflag) // ls -l file
                display_file(argv[i], argv[i]);
            else // ls file
                printf("%s", argv[i]);
        printf("\n");
    }

    return 0;
}