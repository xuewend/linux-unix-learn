

/* display_env.c
 * 显示当前的环境变量

   Display the process environment list.
*/
#include "../lib/tlpi_hdr.h"

extern char **environ;
                /* Or define _GNU_SOURCE to get it from <unistd.h> */

int
main(int argc, char *argv[])
{
    char **ep;

    for (ep = environ; *ep != NULL; ep++)
        puts(*ep);

    exit(EXIT_SUCCESS);
}

