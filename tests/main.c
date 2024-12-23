#include "ft_test.h"
#include <check.h>
#include <stdlib.h>

int		main()
{
    const t_test_func test_funcs[] = {
        ft_read_suite,
        ft_strcmp_suite,
        ft_strcpy_suite,
        ft_strdup_suite,
        ft_strlen_suite,
        ft_write_suite
    };

    for (u_int i=0; i < sizeof(test_funcs) / sizeof(t_test_func); i++)
    {
        Suite *s = test_funcs[i]();
        SRunner *sr = srunner_create(s);
        srunner_run_all(sr, CK_NORMAL);
        const int number_failed = srunner_ntests_failed(sr);
        srunner_free(sr);

        if (number_failed != 0)
            return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
