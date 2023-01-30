# include <stdarg.h> 
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    while (*s != 0)
    {
        ft_putchar_fd(*s, fd);
        s++;
    }
}

void    ft_putnbr_fd(int n, int fd)
{
    char    single_digit;
    int        first_digit;

    if (n == -2147483648)
    {
        ft_putchar_fd('-', fd);
        ft_putstr_fd("2147483648", fd);
        return ;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
    }
    if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        first_digit = n % 10;
        ft_putchar_fd(first_digit + 48, fd);
    }    
    else
    {
        single_digit = n + 48;
        ft_putchar_fd(single_digit, fd);
    }
}

int    ft_nbrlen(int n)
{
    int    counter_nbr;

    counter_nbr = 0;
    while (n != 0)
    {
        n = n / 10;
        counter_nbr++;
    }
    return (counter_nbr);
}

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0' && (unsigned char)c != *s)
        s++;
    if ((unsigned char)c == *s)
        return ((char *)s);
    return (0);
}

static int    print_int(va_list ap)
{
    int    arg;
    int    len;
    int    default_fd;

    arg = va_arg(ap, int);
    len = ft_nbrlen(arg);
    default_fd = 1;
    ft_putnbr_fd(arg, default_fd);
    return (len);
}

int    flag_check(const char *format, int current_index, va_list arg)
{
    if (format[current_index] == '%' && format[current_index + 1] == 'd')
    {
        return (print_int(arg));
    }
    return (0);
}

int    ft_printf(const char *format, ...)
{
    va_list    arg_ptr;
    int        current_index;
    int        c_printed;

    current_index = 0;
    c_printed = 0;
    va_start(arg_ptr, format);

    while (format[current_index])
    {
        if (format[current_index] == '%'
            && ft_strchr("cspdiuxX%", format[current_index + 1]))
        {
        c_printed += flag_check(format, current_index, arg_ptr);
        current_index++;
            return (0);
        }
        else
        c_printed += ft_putchar(format[current_index]);
        current_index++;
    }
    va_end(arg_ptr);
    return (c_printed);
}
int    main(void)
{
    int        age = 30;
    char    name[] = "John Smith";

    ft_printf("Hello there! I like the numbers %d, %d and %d\n\n\n", 1, 3, 7);
    return (0);
}