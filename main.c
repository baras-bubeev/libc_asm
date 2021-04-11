#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);
ssize_t ft_write(int fd, const void *buf, size_t count);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strdup(const char *s);
ssize_t ft_read(int fd, void *buf, size_t count);

int     main(void)
{
    printf("*** ft_strlen ***\n");
    printf("my: %zu\n", ft_strlen("hello world!"));
    printf("or: %zu\n", strlen("hello world!"));
    printf("my: %zu\n", ft_strlen(""));
    printf("or: %zu\n", strlen(""));
    printf("my: %zu\n", ft_strlen("Hello \0world"));
    printf("or: %zu\n", strlen("Hello \0world"));
    // printf("my: %zu\n", ft_strlen(0));
    // printf("or: %zu\n", strlen(0));

     printf("\n*** ft_strcpy ***\n");
    char    b1[20];
    char    b2[20];
    printf("my: |%s|\n", ft_strcpy(b1, "Hello world!"));
    printf("or: |%s|\n", strcpy(b2, "Hello world!"));
    printf("my: |%s|\n", ft_strcpy(b1, ""));
    printf("or: |%s|\n", strcpy(b2, ""));
    printf("my: |%s|\n", ft_strcpy(b1, "Hello \0world!"));
    printf("or: |%s|\n", strcpy(b2, "Hello \0world!"));
    printf("my: |%s|\n", ft_strcpy(b1, "\x01"));
    printf("or: |%s|\n", strcpy(b2, "\x01"));
    printf("my: |%s|\n", ft_strcpy(b1, "\x01\x01"));
    printf("or: |%s|\n", strcpy(b2, "\x01\x01"));
    // printf("my: |%s|\n", ft_strcpy(b1, 0));
    // printf("or: |%s|\n", strcpy(b2, 0));

    printf("\n*** ft_strcmp ***\n");
    printf("my: |%d|\n", ft_strcmp("Hello world", "Hello world"));
    printf("or: |%d|\n", strcmp("Hello world", "Hello world"));
    printf("my: |%d|\n", ft_strcmp("Hello world", "Hello "));
    printf("or: |%d|\n", strcmp("Hello world", "Hello "));
    printf("my: |%d|\n", ft_strcmp("Hello ", "Hello world"));
    printf("or: |%d|\n", strcmp("Hello ", "Hello world"));
    printf("my: |%d|\n", ft_strcmp("Hello world", "Hello World"));
    printf("or: |%d|\n", strcmp("Hello world", "Hello World"));
    printf("my: |%d|\n", ft_strcmp("world", "Hello world"));
    printf("or: |%d|\n", strcmp("world", "Hello world"));
    printf("my: |%d|\n", ft_strcmp("Hello \0world", "Hello "));
    printf("or: |%d|\n", strcmp("Hello \0world", "Hello "));
    printf("my: |%d|\n", ft_strcmp("\x01", "\x01\x01"));
    printf("or: |%d|\n", strcmp("\x01", "\x01\x01"));
    printf("my: |%d|\n", ft_strcmp("\x01\x01", "\x01"));
    printf("or: |%d|\n", strcmp("\x01\x01", "\x01"));


    printf("\n*** ft_write ***\n");
    printf("    my: |%ld| errno: |%d|\n", ft_write(1, "Hello world!", 12), errno);
    printf("    or: |%ld| errno: |%d|\n", write(1, "Hello world!", 12), errno);
    printf("    my: |%ld| errno: |%d|\n", ft_write(1, "Hello world!", 11), errno);
    printf("    or: |%ld| errno: |%d|\n", write(1, "Hello world!", 11), errno);
    // printf("    my: |%ld| errno: |%d|\n", ft_write(1, "Hello world!", 15), errno);
    // printf("    or: |%ld| errno: |%d|\n", write(1, "Hello world!", 15), errno);
    printf("my: |%ld| errno: |%d|\n", ft_write(1, "", 1), errno);
    printf("or: |%ld| errno: |%d|\n", write(1, "", 1), errno);
    printf("my: |%ld| errno: |%d|\n", ft_write(1, "Hello world!", 0), errno);
    printf("or: |%ld| errno: |%d|\n", write(1, "Hello world!", 0), errno);
    errno = 0;
    ft_write(-1, "Hello world!", 13);
    printf("my errno: |%d|\n", errno);
    write(-1, "Hello world!", 13);
    printf("or errno: |%d|\n", errno);
    // errno = 0;
    // ft_write(1, 0, 13);
    // printf("my errno: |%d|\n", errno);
    // write(1, 0, 13);
    // printf("or errno: |%d|\n", errno);
    printf("    my: |%ld| errno: |%d|\n", ft_write(1, "Hello world!", 11), errno);
    printf("    or: |%ld| errno: |%d|\n", write(1, "Hello world!", 11), errno);

    printf("\n*** ft_read ***\n");
    char a1[5] = "";
    char a2[5] = "";
    errno = 0;
    printf("my: |%ld|", ft_read(0, a1, 5));
    printf(" errno: %d|", errno);
    printf(" str: %s", a1);
    printf("or: |%ld|", read(0, a2, 5));
    printf(" errno: %d|", errno);
    printf(" str: %s", a2);

    printf("my: |%ld|", ft_read(0, a1, 0));
    printf(" errno: %d|", errno);
    printf(" str: %s", a1);
    printf("or: |%ld|", read(0, a2, 0));
    printf(" errno: %d|", errno);
    printf(" str: %s", a2);

    printf("my: |%ld|", ft_read(-1, a1, 5));
    printf(" errno: %d|", errno);
    printf(" str: %s", a1);
    printf("or: |%ld|", read(-1, a2, 5));
    printf(" errno: %d|", errno);
    printf(" str: %s", a2);

    // printf("my: |%ld|", ft_read(0, 0, 5));
    // printf(" errno: %d|", errno);
    // printf(" str: %s", a1);
    // printf("or: |%ld|", read(0, 0, 5));
    // printf(" errno: %d|", errno);
    // printf(" str: %s", a2);

    printf("\n*** ft_strdup ***\n");
    char *d1;
    char *d2;
    printf("my: |%s|\n", (d1 = ft_strdup("Hello world")));
    printf("or: |%s|\n", (d2 = strdup("Hello world")));
    free(d1);
    free(d2);
    printf("my: |%s|\n", (d1 = ft_strdup("")));
    printf("or: |%s|\n", (d2 = strdup("")));
    free(d1);
    free(d2);
    printf("my: |%s|\n", (d1 = ft_strdup("Hello \0world")));
    printf("or: |%s|\n", (d2 = strdup("Hello \0world")));
    free(d1);
    free(d2);
    // printf("my: |%s|\n", (d1 = ft_strdup(0)));
    // printf("or: |%s|\n", (d2 = strdup(0)));
    // free(d1);
    // free(d2);

    return (0);
}