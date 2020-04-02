/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factorization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee <chlee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 17:34:07 by chlee             #+#    #+#             */
/*   Updated: 2020/04/02 22:35:08 by chlee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERROR_NUM_RANGE 1
#define ERROR_ARGC_MORE_TWO 1 << 1
#define ERROR_ARGC_LESS_TWO 1 << 2
#define ERROR_WRONG_INPUT 1 << 3
#define TRUE 1
#define FALSE 0
#include <unistd.h>
#include <stdio.h>

static int		ft_print_error(const int error, char info)
{
	if (error == ERROR_ARGC_LESS_TWO)
	{
		write(2, "[ERROR] The argc is \'", 22);
		write(2, &info, 1);
		write(2, "\'. and it under 2. Please check the input and try again.\n", 58);
	}
	if (error == ERROR_ARGC_MORE_TWO)
	{
		write(2, "[ERROR] The argc is \'", 22);
		write(2, &info, 1);
		write(2, "\'. and it more 2. Please check the input and try again.\n", 57);
	}
	if (error == ERROR_WRONG_INPUT)
	{
		write(2, "[ERROR] \'", 10);
		write(2, &info, 1);
		write(2, "\' is not a number or more length of UINT_MAX. Check input and try again.\n", 74);
	}
	if (error == ERROR_NUM_RANGE)
	{
		write(2, "[ERROR] a number is under 2 or more UINT_MAX. Please edit the input is between 2 and UINT_MAX.\n", 96);
	}
	return (FALSE);
}

static void		ft_putnbr(unsigned int number)
{
	char	singleDigit;

	if (number >= 10)
	{
		ft_putnbr(number / 10);
	}
	singleDigit = (number % 10) + '0';
	write(1, &singleDigit, 1);
}

static int		ft_atoi(const char *inputStr)
{
	size_t			idx = 0;
	size_t			cnt = 0;
	unsigned int	number = 0;
	const char		UINT_MAX[] = "4294967295";

	while (inputStr[idx] != '\0')
	{
		if (inputStr[idx] < '0' || inputStr[idx] > '9')
			return (ft_print_error(ERROR_WRONG_INPUT, inputStr[idx]));
		number = number * 10 + (inputStr[idx] - '0');
		idx++;
	}
	if (idx == 10)
	{
		while (cnt < 10)
		{
			if (inputStr[cnt] > UINT_MAX[cnt])
				break;
			cnt++;
		}
	}
	if (idx > 10 || number <= 1 || (idx == 10 && cnt != 10))
		return (ft_print_error(ERROR_NUM_RANGE, '\0'));
	return (number);
}

static void		ft_factorization(unsigned int number)
{
	size_t	divisor;
	size_t	blankCheck;

	divisor = 2;
	blankCheck = FALSE;
	while (divisor <= 65535 && number > 1)
	{
		if (number % divisor == 0)
		{
			while (number % divisor == 0)
				number /= divisor;
			if (blankCheck)
				write(1, " ", 1);
			ft_putnbr(divisor);
			blankCheck = TRUE;
		}
		divisor++;
	}
	if (number > 1)
		ft_putnbr(number);
	write(1, "\n", 1);
}

int				main(int argc, char *argv[])
{
	unsigned int	input_num;
	size_t			remove_zero;

	if (argc > 2)
	{
		return (ft_print_error(ERROR_ARGC_MORE_TWO, argc + '0'));
	}
	else if (argc < 2)
	{
		return (ft_print_error(ERROR_ARGC_LESS_TWO, argc + '0'));
	}
	else
	{
		remove_zero = 0;
		while (argv[1][remove_zero] == '0')
			remove_zero++;
		input_num = ft_atoi(argv[1] + remove_zero);
		if (input_num >= 2)
			ft_factorization(input_num);
	}
	return (0);
}
