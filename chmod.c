/*=============================================================================
#     FileName: chmod.c
#         Desc: 
#       Author: quake0day
#        Email: quake0day@gmail.com
#     HomePage: http://www.darlingtree.com
#      Version: 0.0.1
#   LastChange: 2011-08-26 00:33:40
#      History:
=============================================================================*/
#include "apue.h"

int main(void)
{
    struct stat statbuf;

    /* turn on set-group-ID and turn off group-execute */
    if(stat("foo",&statbuf) <0)
        err_sys("stat error for foo");
    if(chmod("foo",(statbuf.st_mode & ~S_IXGRP) | S_ISGID ) < 0 )
        err_sys("chmod error for foo");
    /* set absolute mode to "rw-r--r--" */
    if(chmod("bar",S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
        err_sys("chmod error for bar");
    exit(0);
}
