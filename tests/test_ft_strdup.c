#include "libasm.h"
#include "ft_test.h"
#include <string.h>

T_Case   test_ft_strdup_with_non_blank_strings(void)
{
    T_Case tc = {
        .name = "test_ft_strdup_with_non_blank_strings",
        .failure_message = NULL
    };

    const char *src = "Hello, World!";
    char *ft_d = ft_strdup(src);
    char *std_d = strdup(src);

    if (!ft_assert_str_eq(&tc, ft_d, src))
        return tc;
    if (!ft_assert_str_eq(&tc, ft_d, std_d))
        return tc;
    if (!ft_assert_ptr_ne(&tc, ft_d, src))
        return tc;
    if (!ft_assert_ptr_ne(&tc, std_d, src))
        return tc;

    free(ft_d);
    free(std_d);

    return tc;
}

T_Case  test_ft_strdup_with_blank_strings(void)
{
    T_Case tc = {
        .name = "test_ft_strdup_with_blank_strings",
        .failure_message = NULL
    };

    const char *src = "";
    char *ft_d = ft_strdup(src);
    char *std_d = strdup(src);

    if (!ft_assert_str_eq(&tc, ft_d, src))
        return tc;
    if (!ft_assert_str_eq(&tc, ft_d, std_d))
        return tc;
    if (!ft_assert_str_eq(&tc, std_d, src))
        return tc;
    if (!ft_assert_ptr_ne(&tc, ft_d, src))
        return tc;
    if (!ft_assert_ptr_ne(&tc, std_d, src))
        return tc;

    free(ft_d);
    free(std_d);

    return tc;
}

bool    ft_strdup_suite(void)
{
    t_test_func test_funcs[] = {
        test_ft_strdup_with_blank_strings,
        test_ft_strdup_with_non_blank_strings
    };

    return ft_test_suite("ft_strdup", test_funcs, sizeof(test_funcs) / sizeof(t_test_func));
}
