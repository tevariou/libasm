#include "libasm.h"
#include <stdlib.h>

int		main(int ac, char **av)
{
	(void)av;
	(void)ac;
	ft_write(1, "42\n", 3);
	return (EXIT_SUCCESS);
}