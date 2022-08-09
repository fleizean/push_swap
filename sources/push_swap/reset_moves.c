/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:42:37 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/05 19:42:37 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reset_moves(t_frame *frame)
{
	frame->biggest = 0;
	frame->b_rotate = 0;
	frame->b_rrotate = 0;
	frame->b_flag = 0;
	frame->smallest = 0;
	frame->s_rotate = 0;
	frame->s_rrotate = 0;
	frame->s_flag = 0;
}
