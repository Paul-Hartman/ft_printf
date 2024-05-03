/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phartman <phartman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:55:51 by phartman          #+#    #+#             */
/*   Updated: 2024/05/03 14:56:46 by phartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_print_hex(unsigned long n, char *base)
{
	unsigned long power;
	int count;
	int digit;

	count = 0;
	power = 1;
	while (power <= n / 16) 
		power *= 16;
	while (power > 0)
	{
		digit = n / power;
		if (digit < 16)
		{
			ft_putchar_fd(base[digit], 1);
			count++;
		}
		n %= power;
		power /= 16;
	}
	return (count);
}


int ft_print_pointer(void *n)
{
	unsigned long address;
	int size;
	int count;

	count = 2;
	size = sizeof(address) * 2;
	address = (unsigned long)n;
	ft_putstr_fd("0x", 1);
	count += ft_print_hex(address, "0123456789abcdef");
	return (count); 
}

int ft_countnbr(int n)
{
	int count;
	count = 1;
	ft_putnbr_fd(n, 1);

	while(n >= 10)
	{
		 n /= 10;
		count++;
	}
	return(count);
}

int ft_countnbruns(unsigned int n)
{
	int count;
	count = 1;
	ft_putnbruns_fd(n, 1);

	while(n >= 10)
	{
		 n /= 10;
		count++;
	}
	return(count);
}

int ft_countstr(char *str)
{
	int count;
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);	
	return (count);
}