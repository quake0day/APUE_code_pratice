/*=============================================================================
#     FileName: fcntl.c
#         Desc: 
#       Author: quake0day
#        Email: quake0day@gmail.com
#     HomePage: http://www.darlingtree.com
#      Version: 0.0.1
#   LastChange: 2011-08-20 15:20:55
#      History:
=============================================================================*/
#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int val;
    if(argc!=2)
        err_quit("usage: a.out <descriptor#>");

    if((val=fcntl(atoi(argv[1]),F_GETFL,0)) <  0)
        err_sys("fcntl error for fd %d", atoi(argv[1]));

    switch(val & O_ACCMODE) {
        case O_RDONLY:
            printf("read only");
            break;

        case O_WRONLY:
            printf("write only");
            break;

        case O_RDWR:
            printf("read & write");
            break;

        default:
            err_dump("unknown access mode");


    }

    if (val & O_APPEND)
        printf(",append");
    if( val & O_NONBLOCK)
        printf(",nonblocking");
    putchar('\n');
    exit(0);
}
