#include "libasm.h"
#include <check.h>


START_TEST(test_ft_strcpy_with_non_blank_strings)
{
    const char  *src = "Hello, World!";
    char        *custom_dest = malloc(strlen(src) + 1);
    char        *std_dest = malloc(strlen(src) + 1);

    const char  *ret_dest = ft_strcpy(custom_dest, src);
    strcpy(std_dest, src);

    ck_assert_str_eq(custom_dest, std_dest);
    ck_assert_ptr_eq(custom_dest, ret_dest);

    free(custom_dest);
    free(std_dest);
}
END_TEST

START_TEST(test_ft_strcpy_with_blank_strings)
{
    const char  *src = "";
    char        *custom_dest = malloc(strlen(src) + 1);
    char        *std_dest = malloc(strlen(src) + 1);

    const char  *ret_dest = ft_strcpy(custom_dest, src);
    strcpy(std_dest, src);

    ck_assert_str_eq(custom_dest, std_dest);
    ck_assert_ptr_eq(custom_dest, ret_dest);

    free(custom_dest);
    free(std_dest);
}
END_TEST

Suite *ft_strcpy_suite(void)
{
    Suite   *s = suite_create("ft_strcpy");
    TCase   *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_ft_strcpy_with_blank_strings);
    tcase_add_test(tc_core, test_ft_strcpy_with_non_blank_strings);

    suite_add_tcase(s, tc_core);

    return s;
}
