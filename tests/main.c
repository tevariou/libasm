#include "ft_test.h"
#include <stdlib.h>
#include <stdio.h>

int		main()
{
    printf("[LIBASM]\nRunning tests...\n");
    const t_suite_func t_suite_funcs[] = {
        ft_read_suite,
        ft_strcmp_suite,
        ft_strcpy_suite,
        ft_strdup_suite,
        ft_strlen_suite,
        ft_write_suite
    };

    for (u_int i=0; i < sizeof(t_suite_funcs) / sizeof(t_suite_func); i++)
    {
        if (!t_suite_funcs[i]())
            return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
