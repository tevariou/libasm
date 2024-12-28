#include "libasm.h"
#include "ft_test.h"
#include <string.h>

T_Case  test_ft_strlen_with_non_blank_string(void)
{
    T_Case tc = {
        .name = "test_ft_strlen_with_non_blank_string",
        .passed = true
    };

    const char      *str = "Hello, World!";
    const size_t    custom_len = ft_strlen(str);
    const size_t    std_len = strlen(str);

    if (!ft_assert_size_eq(&tc, custom_len, std_len))
        return tc;

    return tc;
}

T_Case  test_ft_strlen_with_blank_string(void)
{
    T_Case tc = {
        .name = "test_ft_strlen_with_blank_string",
        .passed = true
    };

    const char      *str = "";
    const size_t    custom_len = ft_strlen(str);
    const size_t    std_len = strlen(str);

    if (!ft_assert_size_eq(&tc, custom_len, std_len))
        return tc;
    if (!ft_assert_size_eq(&tc, custom_len, 0))
        return tc;

    return tc;
}

bool    ft_strlen_suite(void)
{
    t_test_func test_funcs[] = {
        test_ft_strlen_with_blank_string,
        test_ft_strlen_with_non_blank_string
    };

    return ft_test_suite("ft_strlen", test_funcs, sizeof(test_funcs) / sizeof(t_test_func));
}
