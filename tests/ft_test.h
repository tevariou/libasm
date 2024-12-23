#ifndef FT_TEST_H
#define FT_TEST_H

#include <check.h>

Suite   *ft_read_suite(void);
Suite   *ft_strcmp_suite(void);
Suite   *ft_strcpy_suite(void);
Suite   *ft_strdup_suite(void);
Suite   *ft_strlen_suite(void);
Suite   *ft_write_suite(void);

typedef Suite*(* t_test_func)(void);

#endif
