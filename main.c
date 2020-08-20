#include "libasm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		main()
{
	char *s;

	s = strdup("42");
	printf("%s\n", s);
	free(s);
	return (EXIT_SUCCESS);
}