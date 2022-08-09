/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:45:44 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:45:44 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	solver(t_frame *frame)
{
	if (find_stack_len(frame, 'a') <= 5)
		solve_5_or_less(frame);
	else if (find_stack_len(frame, 'a') <= 100)
		insertion_solve_half(frame);
	else
		insertion_solve_quarters(frame);
}
