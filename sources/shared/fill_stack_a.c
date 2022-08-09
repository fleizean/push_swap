/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:48:47 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:48:47 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

static long	atoi_push_swap(t_frame *frame, char *str)
{
	long	num;
	int		i;
	int		len;
	int		sign;

	num = 0;
	i = 0;
	len = 0;
	sign = 1;
	while (str[i] >= 1 && str[i] <= 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		len++;
	}
	my_returner_swap_error(len, frame);
	return (num * sign);
}

static void	check_equal(t_frame *frame)
{
	t_stack		*slow;
	t_stack		*fast;

	slow = frame->a;
	while (slow != frame->a->prev)
	{
		fast = slow->next;
		while (fast != frame->a)
		{
			if (slow->num == fast->num)
				push_swap_error(frame);
			fast = fast->next;
		}
		slow = slow->next;
	}
}

static void	complete_filling(t_frame *frame, char *str, int i)
{
	long int	test_int_size;

	while (str)
	{
		test_int_size = atoi_push_swap(frame, str);
		if (test_int_size > 2147483647 || test_int_size < -2147483648)
			push_swap_error(frame);
		stack_add_end(frame, 'a', test_int_size);
		str = frame->av[++i];
	}
	throwswaperror(frame);
}

static void	error_parser(t_frame *frame)
{
	char	*str;
	int		i;

	i = 1;
	str = frame->av[i];
	while (str)
	{
		while (*str)
		{
			if (*str == ' ' || ft_isdigit(*str))
				str++;
			else if (*str == '-' && ft_isdigit(*(str + 1))
				&& (str == frame->av[i] || *(str - 1) == ' '))
				str++;
			else if (*str == '+' && ft_isdigit(*(str + 1))
				&& (str == frame->av[i] || *(str - 1) == ' '))
				str++;
			else
				push_swap_error(frame);
		}
		str = frame->av[++i];
	}
}

void	fill_stack_a(t_frame *frame)
{
	char	*str;
	int		i;

	i = 1;
	str = frame->av[i];
	error_parser(frame);
	complete_filling(frame, str, i);
	check_equal(frame);
}
