#include "libasm.h"
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		main()
{
	char *s;
	char buf[42];
	int file;

    if ((file = open("./Makefile", O_RDONLY)) < 0)
        return (EXIT_FAILURE);
    memset(buf, 0, 42);
    while (ft_read(file, buf, 41) > 0)
    {
        s = ft_strdup(buf);
        ft_write(1, s, ft_strlen(s));
        free(s);
        memset(buf, 0, 42);
    }
    if (errno)
        perror(NULL);
    close(file);
	return (EXIT_SUCCESS);
}
