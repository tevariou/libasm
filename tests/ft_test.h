#ifndef FT_TEST_H
#define FT_TEST_H

#include <stdbool.h>
#include <sys/types.h>

typedef struct {
    char    *name;
    char    *failure_message;
}       T_Case;

typedef T_Case(* t_test_func)(void);
typedef bool(* t_suite_func)(void);

bool    ft_assert_ssize_eq(T_Case *tc, ssize_t a, ssize_t b);
bool    ft_assert_size_eq(T_Case *tc, size_t a, size_t b);
bool    ft_assert_str_eq(T_Case *tc, const char *a, const char *b);
bool    ft_assert_ptr_eq(T_Case *tc, const void *a, const void *b);
bool    ft_assert_ptr_ne(T_Case *tc, const void *a, const void *b);
bool    ft_test_suite(const char *name, T_Case (*test_funcs[])(void), u_int size);

bool    ft_read_suite(void);
bool    ft_strcmp_suite(void);
bool    ft_strcpy_suite(void);
bool    ft_strdup_suite(void);
bool    ft_strlen_suite(void);
bool    ft_write_suite(void);

#endif
