/*=============================================================================
#     FileName: umask.c
#         Desc: 
#       Author: quake0day
#        Email: quake0day@gmail.com
#     HomePage: http://www.darlingtree.com
#      Version: 0.0.1
#   LastChange: 2011-08-26 00:19:38
#      History:
=============================================================================*/
#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
    umask(0);
    if (creat("foo",RWRWRW) < 0)
        err_sys(" creat error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
    if(creat("bar",RWRWRW) < 0)
        err_sys("create error for bar");
    exit(0);
}
