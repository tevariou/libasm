#include "libasm.h"
#include <check.h>


START_TEST(test_ft_strdup_with_non_blank_strings)
{
    const char *src = "Hello, World!";
    char *ft_d = ft_strdup(src);
    char *std_d = strdup(src);

    ck_assert_str_eq(ft_d, src);
    ck_assert_str_eq(ft_d, std_d);
    ck_assert_ptr_ne(ft_d, src);
    ck_assert_ptr_ne(std_d, src);

    free(ft_d);
    free(std_d);
}
END_TEST

START_TEST(test_ft_strdup_with_blank_strings)
{
    const char *src = "";
    char *ft_d = ft_strdup(src);
    char *std_d = strdup(src);

    ck_assert_str_eq(ft_d, src);
    ck_assert_str_eq(ft_d, std_d);
    ck_assert_str_eq(std_d, src);
    ck_assert_ptr_ne(ft_d, src);
    ck_assert_ptr_ne(std_d, src);

    free(ft_d);
    free(std_d);
}
END_TEST

Suite *ft_strdup_suite(void)
{
    Suite   *s = suite_create("ft_strdup");
    TCase   *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_ft_strdup_with_blank_strings);
    tcase_add_test(tc_core, test_ft_strdup_with_non_blank_strings);

    suite_add_tcase(s, tc_core);

    return s;
}
