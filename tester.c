/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:34:27 by phartman          #+#    #+#             */
/*   Updated: 2024/05/03 15:39:41 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	//write me a char * variable with null assigned as its value


	// char *str = NULL;

	// printf("size: %i\n", ft_printf("This is a string: %s\n", str));
	// printf("size: %i\n", printf("This is a string: %s\n", str));
	// // Test with an integer

	// //int num = 42;
	// printf("size: %i\n", ft_printf("This is an integer: %d\n", _SC_ULONG_MAX));
	// printf("size: %i\n", printf("This is an integer: %d\n", _SC_ULONG_MAX));

	//write a test passing two with two pointer arguments and with 0s passed in as the values	
	//write me pointer long pointer variables to store the long mins in
	long *ptr1 = LONG_MIN;
	long *ptr2 = LONG_MAX;
	printf("size: %i\n", ft_printf("This is an pointer: %p\n", ptr1));
	printf("size: %i\n", printf("This is an pointer: %p\n", ptr1));
	printf("size: %i\n", ft_printf("This is an pointer: %p\n", ptr2));
	printf("size: %i\n", printf("This is an pointer: %p\n", ptr2));
	printf("size: %i\n", ft_printf("This is an pointer: %p\n", ULONG_MAX));
	printf("size: %i\n", printf("This is an pointer: %p\n", ULONG_MAX));
	printf("size: %i\n", ft_printf("This is an pointer: %p\n", -ULONG_MAX));
	printf("size: %i\n", printf("This is an pointer: %p\n", -ULONG_MAX));
	printf("size: %i\n", ft_printf("This is an pointer: %p\n", 0));
	printf("size: %i\n", printf("This is an pointer: %p\n", 0));

	// int i = 0;
	// while(i > -1000)
	// {
	// 		printf("size: %i\n", ft_printf("This is an hex: %x\n", i));
	// 		printf("size: %i\n", printf("This is an hex: %x\n", i));
	// 	i -=100;

	// }

	// Test with a floating-point number
	//int n = -1;
	// printf("size: %i\n", ft_printf("This is a int: %d\n", 9223372036854775807LL));
	// printf("size: %i\n", printf("This is a int: %d\n", 9223372036854775807LL));

	//write me a test for hex numbers
	printf("size: %i\n", ft_printf("This is a hex: %x\n", ULONG_MAX));
	printf("size: %i\n", printf("This is a hex: %x\n", ULONG_MAX));


}
