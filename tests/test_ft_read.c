#include "libasm.h"
#include <check.h>
#include <errno.h>
#include <fcntl.h>


START_TEST(test_ft_read_with_closed_fd)
{
    const int   fd1 = open("/dev/random", O_RDONLY);
    char        buf1[100];
    memset(buf1, 0, 100);

    close(fd1);

    const ssize_t ret1 = ft_read(fd1, buf1, 100);

    const int errno1 = errno;

    const ssize_t ret2 = read(fd1, buf1, 100);

    const int errno2 = errno;

    ck_assert_int_eq(ret1, ret2);
    ck_assert_int_eq(errno1, errno2);
}
END_TEST

START_TEST(test_ft_read_with_null_buf)
{
    const int   fd1 = open("/dev/random", O_RDONLY);
    const ssize_t ret1 = ft_read(fd1, NULL, 0);
    const int erron1 = errno;
    close(fd1);

    const int   fd2 = open("/dev/random", O_RDONLY);
    const ssize_t ret2 = read(fd2, NULL, 0);
    const int errno2 = errno;
    close(fd2);

    ck_assert_int_eq(ret1, ret2);
    ck_assert_int_eq(erron1, errno2);
}
END_TEST

START_TEST(test_ft_read_with_invalid_fd)
{
    char        buf1[100];
    memset(buf1, 0, 100);

    const ssize_t ret1 = ft_read(-1, buf1, 100);

    const int errno1 = errno;

    char        buf2[100];
    memset(buf2, 0, 100);

    const ssize_t ret2 = read(-1, buf2, 100);

    const int errno2 = errno;

    ck_assert_int_eq(errno1, errno2);
    ck_assert_int_eq(ret1, ret2);
    ck_assert_str_eq(buf1, buf2);
}
END_TEST

START_TEST(test_ft_read_with_valid_fd)
{
    const char  *SOURCE_FILE_PATH = "../author";
    const int   fd1 = open(SOURCE_FILE_PATH, O_RDONLY);
    char        buf1[100];

    memset(buf1, 0, 100);

    const ssize_t ret1 = ft_read(fd1, buf1, 100);

    const int errno1 = errno;

    close(fd1);

    const int   fd2 = open(SOURCE_FILE_PATH, O_RDONLY);
    char        buf2[100];

    memset(buf2, 0, 100);

    const ssize_t ret2 = read(fd2, buf2, 100);

    const int errno2 = errno;

    close(fd2);

    ck_assert_int_eq(ret1, ret2);
    ck_assert_str_eq(buf1, buf2);
    ck_assert_int_eq(errno1, errno2);
}
END_TEST

Suite *ft_read_suite(void)
{
    Suite   *s = suite_create("ft_read");
    TCase   *tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_ft_read_with_invalid_fd);
    tcase_add_test(tc_core, test_ft_read_with_valid_fd);
    tcase_add_test(tc_core, test_ft_read_with_null_buf);
    tcase_add_test(tc_core, test_ft_read_with_closed_fd);

    suite_add_tcase(s, tc_core);

    return s;
}
