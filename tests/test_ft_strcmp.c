#include "libasm.h"
#include "ft_test.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

T_Case  test_ft_strcmp_with_blank_strings(void)
{
    T_Case tc = {
        .name = "test_ft_strcmp_with_blank_strings",
        .failure_message = NULL
    };

    const char *str1 = "";
    const char *str2 = "";

    const int custom_result = ft_strcmp(str1, str2);
    const int std_result = strcmp(str1, str2);

    if (!ft_assert_ssize_eq(&tc, custom_result, std_result))
        return tc;

    return tc;
}

T_Case  test_ft_strcmp_with_str1_less_than_str2(void)
{
    T_Case tc = {
        .name = "test_ft_strcmp_with_str1_less_than_str2",
        .failure_message = NULL
    };

    const char *str1 = "Hello, World";
    const char *str2 = "Hello, World!!";

    const int custom_result = ft_strcmp(str1, str2);
    const int std_result = strcmp(str1, str2);

    if (!ft_assert_ssize_eq(&tc, custom_result, std_result))
        return tc;

    return tc;
}


T_Case  test_ft_strcmp_with_str1_greater_than_str2(void)
{
    T_Case tc = {
        .name = "test_ft_strcmp_with_str1_greater_than_str2",
        .failure_message = NULL
    };

    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World";

    const int custom_result = ft_strcmp(str1, str2);
    const int std_result = strcmp(str1, str2);

    if (!ft_assert_ssize_eq(&tc, custom_result, std_result))
        return tc;

    return tc;
}

T_Case  test_ft_strcmp_with_same_string(void)
{
    T_Case tc = {
        .name = "test_ft_strcmp_with_same_string",
        .failure_message = NULL
    };

    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";

    const int custom_result = ft_strcmp(str1, str2);
    const int std_result = strcmp(str1, str2);

    if (!ft_assert_ssize_eq(&tc, custom_result, std_result))
        return tc;

    return tc;
}

bool    ft_strcmp_suite(void)
{
    t_test_func   test_funcs[] = {
        test_ft_strcmp_with_same_string,
        test_ft_strcmp_with_str1_greater_than_str2,
        test_ft_strcmp_with_str1_less_than_str2,
        test_ft_strcmp_with_blank_strings
    };

    return ft_test_suite("ft_strcmp", test_funcs, sizeof(test_funcs) / sizeof(t_test_func));
}
