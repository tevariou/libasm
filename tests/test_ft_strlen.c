#include "libasm.h"
#include <check.h>


START_TEST(test_ft_strlen_with_non_blank_string)
{
    const char *str = "Hello, World!";
    const size_t custom_len = ft_strlen(str);
    const size_t std_len = strlen(str);

    ck_assert_int_eq(custom_len, std_len);
    ck_assert_int_eq(custom_len, 13);
}
END_TEST

START_TEST(test_ft_strlen_with_blank_string)
{
    const char *str = "";
    const size_t custom_len = ft_strlen(str);
    const size_t std_len = strlen(str);

    ck_assert_int_eq(custom_len, std_len);
    ck_assert_int_eq(custom_len, 0);
}
END_TEST

Suite *ft_strlen_suite(void)
{
    Suite   *s = suite_create("ft_strlen");
    TCase   *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_ft_strlen_with_blank_string);
    tcase_add_test(tc_core, test_ft_strlen_with_non_blank_string);

    suite_add_tcase(s, tc_core);

    return s;
}
