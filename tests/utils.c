#include "ft_test.h"
#include <stdio.h>
#include <string.h>

bool    ft_assert_ssize_eq(T_Case *tc, const ssize_t a, const ssize_t b)
{
    tc->passed = (a == b);
    return (tc->passed);
}

bool    ft_assert_size_eq(T_Case *tc, const size_t a, const size_t b)
{
    tc->passed = (a == b);
    return (tc->passed);
}

bool    ft_assert_str_eq(T_Case *tc, const char *a, const char *b)
{
    tc->passed = (!strcmp(a, b));
    return (tc->passed);
}

bool    ft_assert_ptr_eq(T_Case *tc, const void *a, const void *b)
{
    tc->passed = (a == b);
    return (tc->passed);
}

bool    ft_assert_ptr_ne(T_Case *tc, const void *a, const void *b)
{
    tc->passed = (a != b);
    return (tc->passed);
}

bool    ft_test_suite(const char *name, T_Case (*test_funcs[])(void), const u_int size)
{
    printf("Test: %s ", name);

    for (u_int i=0; i < size; i++)
    {
        const T_Case tc = test_funcs[i]();
        if (!tc.passed)
        {
            printf("F [FAILURE] %s failed.\n", tc.name);
            return false;
        }
        printf(".");
    }
    printf(" [OK]\n");

    return true;
}
