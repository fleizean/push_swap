/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:47:34 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/08 13:47:34 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_frame	*create_frame(t_frame *frame, char **av)
{
	frame = (t_frame *)malloc(sizeof(t_frame));
	if (!frame)
		exit(1);
	frame->a = NULL;
	frame->b = NULL;
	frame->av = av;
	frame->stack_len = 0;
	frame->quar = 0;
	frame->median = 0;
	frame->t_quar = 0;
	frame->biggest = 0;
	frame->b_rotate = 0;
	frame->b_rrotate = 0;
	frame->b_flag = 0;
	frame->smallest = 0;
	frame->s_rotate = 0;
	frame->s_rrotate = 0;
	frame->s_flag = 0;
	frame->after_rotate = 0;
	return (frame);
}
