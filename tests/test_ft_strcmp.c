#include "libasm.h"
#include <check.h>


START_TEST(test_ft_strcmp_with_blank_strings)
{
    const char *str1 = "";
    const char *str2 = "";

    const int custom_result = ft_strcmp(str1, str2);
    const int std_result = strcmp(str1, str2);

    ck_assert_int_eq(custom_result, std_result);
}

START_TEST(test_ft_strcmp_with_str1_less_than_str2)
{
    const char *str1 = "Hello, World";
    const char *str2 = "Hello, World!!";

    const int custom_result = ft_strcmp(str1, str2);
    const int std_result = strcmp(str1, str2);

    ck_assert_int_eq(custom_result, std_result);
}

START_TEST(test_ft_strcmp_with_str1_greater_than_str2)
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello,";

    const int custom_result = ft_strcmp(str1, str2);
    const int std_result = strcmp(str1, str2);

    ck_assert_int_eq(custom_result, std_result);
}

START_TEST(test_ft_strcmp_with_same_string)
{
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, World!";

    const int custom_result = ft_strcmp(str1, str2);
    const int std_result = strcmp(str1, str2);

    ck_assert_int_eq(custom_result, std_result);
}
END_TEST

Suite *ft_strcmp_suite(void)
{
    Suite   *s = suite_create("ft_strcmp");
    TCase   *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_ft_strcmp_with_same_string);
    tcase_add_test(tc_core, test_ft_strcmp_with_str1_greater_than_str2);
    tcase_add_test(tc_core, test_ft_strcmp_with_str1_less_than_str2);
    tcase_add_test(tc_core, test_ft_strcmp_with_blank_strings);

    suite_add_tcase(s, tc_core);

    return s;
}
