#include "libasm.h"
#include "ft_test.h"
#include <stdlib.h>
#include <string.h>

T_Case  test_ft_strcpy_with_non_blank_strings(void)
{
    T_Case tc = {
        .name = "test_ft_strcpy_with_non_blank_strings",
        .failure_message = NULL
    };

    const char  *src = "Hello, World!";
    char        *custom_dest = malloc(strlen(src) + 1);
    char        *std_dest = malloc(strlen(src) + 1);

    const char  *ret_dest = ft_strcpy(custom_dest, src);
    strcpy(std_dest, src);

    if (!ft_assert_str_eq(&tc, custom_dest, std_dest))
        return tc;
    if (!ft_assert_ptr_eq(&tc, custom_dest, ret_dest))
        return tc;

    free(custom_dest);
    free(std_dest);

    return tc;
}

T_Case  test_ft_strcpy_with_blank_strings(void)
{
    T_Case tc = {
        .name = "test_ft_strcpy_with_blank_strings",
        .failure_message = NULL
    };

    const char  *src = "";
    char        *custom_dest = malloc(strlen(src) + 1);
    char        *std_dest = malloc(strlen(src) + 1);

    const char  *ret_dest = ft_strcpy(custom_dest, src);
    strcpy(std_dest, src);

    if (!ft_assert_str_eq(&tc, custom_dest, std_dest))
        return tc;
    if (!ft_assert_ptr_eq(&tc, custom_dest, ret_dest))
        return tc;

    free(custom_dest);
    free(std_dest);

    return tc;
}

bool    ft_strcpy_suite(void)
{
    t_test_func test_funcs[] = {
        test_ft_strcpy_with_blank_strings,
        test_ft_strcpy_with_non_blank_strings
    };

    return ft_test_suite("ft_strcpy", test_funcs, sizeof(test_funcs) / sizeof(t_test_func));
}
