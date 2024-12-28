#include "libasm.h"
#include "ft_test.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


T_Case  test_ft_read_with_closed_fd(void)
{
    T_Case tc = {
        .name = "test_ft_read_with_closed_fd",
        .failure_message = NULL
    };

    const int   fd1 = open("/dev/random", O_RDONLY);
    char        buf1[100];
    memset(buf1, 0, 100);

    close(fd1);

    const ssize_t ret1 = ft_read(fd1, buf1, 100);

    const int errno1 = errno;

    const ssize_t ret2 = read(fd1, buf1, 100);

    const int errno2 = errno;

    if (!ft_assert_ssize_eq(&tc, ret1, ret2))
        return tc;
    if (!ft_assert_ssize_eq(&tc, errno1, errno2))
        return tc;

    return tc;
}

T_Case  test_ft_read_with_null_buf(void)
{
    T_Case tc = {
        .name = "test_ft_read_with_null_buf",
        .failure_message = NULL
    };

    const int   fd1 = open("/dev/random", O_RDONLY);
    const ssize_t ret1 = ft_read(fd1, NULL, 0);
    const int erron1 = errno;
    close(fd1);

    const int   fd2 = open("/dev/random", O_RDONLY);
    const ssize_t ret2 = read(fd2, NULL, 0);
    const int errno2 = errno;
    close(fd2);

    if (!ft_assert_ssize_eq(&tc, ret1, ret2))
        return tc;
    if (!ft_assert_ssize_eq(&tc, erron1, errno2))
        return tc;

    return tc;
}

T_Case  test_ft_read_with_invalid_fd(void)
{
    T_Case tc = {
        .name = "test_ft_read_with_invalid_fd",
        .failure_message = NULL
    };

    char        buf1[100];
    memset(buf1, 0, 100);

    const ssize_t ret1 = ft_read(-1, buf1, 100);

    const int errno1 = errno;

    char        buf2[100];
    memset(buf2, 0, 100);

    const ssize_t ret2 = read(-1, buf2, 100);

    const int errno2 = errno;

    if (!ft_assert_ssize_eq(&tc, errno1, errno2))
        return tc;
    if (!ft_assert_ssize_eq(&tc, ret1, ret2))
        return tc;
    if (!ft_assert_str_eq(&tc, buf1, buf2))
        return tc;

    return tc;
}

T_Case  test_ft_read_with_valid_fd(void)
{
    T_Case tc = {
        .name = "test_ft_read_with_valid_fd",
        .failure_message = NULL
    };

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

    if (!ft_assert_ssize_eq(&tc, ret1, ret2))
        return tc;
    if (!ft_assert_ssize_eq(&tc, errno1, errno2))
        return tc;
    if (!ft_assert_str_eq(&tc, buf1, buf2))
        return tc;

    return tc;
}

bool    ft_read_suite(void)
{
    t_test_func   test_funcs[] = {
        test_ft_read_with_invalid_fd,
        test_ft_read_with_valid_fd,
        test_ft_read_with_null_buf,
        test_ft_read_with_closed_fd
    };

    return ft_test_suite("ft_read", test_funcs, sizeof(test_funcs) / sizeof(t_test_func));
}
