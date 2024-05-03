
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);

#endif