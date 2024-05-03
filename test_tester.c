#include "ft_printf.h"

int main()
{
    char *str = NULL;

    printf("size: %i\n", ft_printf("This is a string: %s\n", str));
    printf("size: %i\n", printf("This is a string: %s\n", str));

    // Test with an integer
    int num = 42;
    printf("size: %i\n", ft_printf("This is an integer: %d\n", num));
    printf("size: %i\n", printf("This is an integer: %d\n", num));

    // Test with a floating-point number
    double pi = 3.14159;
    printf("size: %i\n", ft_printf("This is a float: %f\n", pi));
    printf("size: %i\n", printf("This is a float: %f\n", pi));

    // Test with a character
    char ch = 'A';
    printf("size: %i\n", ft_printf("This is a character: %c\n", ch));
    printf("size: %i\n", printf("This is a character: %c\n", ch));

    return 0;
}