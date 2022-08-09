/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:46:00 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:46:00 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_swap(t_frame *frame)
{
	fill_stack_a(frame);
	if (!sorted(frame))
	{
		solver(frame);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_frame		*frame;

	frame = NULL;
	if (argc < 2)
		return (1);
	frame = create_frame(frame, argv);
	push_swap(frame);
	push_swap_free(frame);
	return (0);
}
