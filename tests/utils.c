#include "ft_test.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool    ft_assert_ssize_eq(T_Case *tc, const ssize_t a, const ssize_t b)
{
    char *msg = NULL;
    if (a != b)
        asprintf(&msg, "Expected: %ld, got: %ld", a, b);
    tc->failure_message = msg;
    if (msg)
        return false;
    return true;
}

bool    ft_assert_size_eq(T_Case *tc, const size_t a, const size_t b)
{
    char *msg = NULL;
    if (a != b)
        asprintf(&msg, "Expected: %ld, got: %ld", a, b);
    tc->failure_message = msg;
    if (msg)
        return false;
    return true;
}

bool    ft_assert_str_eq(T_Case *tc, const char *a, const char *b)
{
    char *msg = NULL;
    if (strcmp(a, b) != 0)
        asprintf(&msg, "Expected: %s, got: %s", a, b);
    tc->failure_message = msg;
    if (msg)
        return false;
    return true;
}

bool    ft_assert_ptr_eq(T_Case *tc, const void *a, const void *b)
{
    char *msg = NULL;
    if (a != b)
        asprintf(&msg, "Expected: %p, got: %p", a, b);
    tc->failure_message = msg;
    if (msg)
        return false;
    return true;
}

bool ft_assert_ptr_ne(T_Case *tc, const void *a, const void *b)
{
    char *msg = NULL;
    if (a == b)
        asprintf(&msg, "Expected: %p, got: %p", a, b);
    tc->failure_message = msg;
    if (msg)
        return false;
    return true;
}

bool    ft_test_suite(const char *name, T_Case (*test_funcs[])(void), const u_int size)
{
    printf("Test: %s ", name);

    for (u_int i=0; i < size; i++)
    {
        const T_Case tc = test_funcs[i]();
        if (tc.failure_message)
        {
            printf("F [FAILURE] %s failed. %s.\n", tc.name, tc.failure_message);
            free(tc.failure_message);
            return false;
        }
        printf(".");
    }
    printf(" [OK]\n");

    return true;
}
