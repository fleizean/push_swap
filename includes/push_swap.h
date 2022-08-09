/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyagiz <eyagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:12:18 by eyagiz            #+#    #+#             */
/*   Updated: 2022/08/05 17:12:18 by eyagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_stack
{
	long int		num;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_frame
{
	struct s_stack	*a;
	struct s_stack	*b;
	char			**av;
	int				stack_len;
	long			quar;
	long			median;
	long			t_quar;
	long			biggest;
	int				b_rotate;
	int				b_rrotate;
	int				b_flag;
	long			smallest;
	int				s_rotate;
	int				s_rrotate;
	int				s_flag;
	int				after_rotate;
}					t_frame;

typedef void		(*t_table)(t_frame *frame);
void				find_moves(t_frame *frame, char stack_name);
void				find_biggest_smallest(t_frame *frame, char stack_name);
void				find_biggest(t_frame *frame, char stack_name);
void				find_smallest(t_frame *frame, char stack_name);
int					find_stack_len(t_frame *frame, char stack_name);
void				insertion_solve_half(t_frame *frame);
void				insertion_solve_quarters(t_frame *frame);
void				ifpusher_quarter(t_stack *s_a_end, t_frame *frame,
						t_stack *stack_a, int split);
void				median(t_frame *frame, char stack_name);
int					my_returner_bigorsmall(t_frame *frame, int flag);
void				my_returner_swap_error(int len, t_frame *frame);
void				throwswaperror(t_frame *frame);
t_stack				*my_returner_aorb(t_frame *frame, char stack_name);
t_stack				*my_returner_prevaorb(t_frame *frame, char stack_name);
int					my_returner_frameflag(t_frame *frame, t_stack *stack_a_end);
int					my_returner_flag(t_stack *stack_a_end, t_stack *stack_a);
void				moves_to_end(t_frame *frame, char stack_name, int flag);
void				moves_to_start(t_frame *frame, char stack_name, int flag);
void				push_median(t_frame *frame, int split);
void				push_quarters(t_frame *frame, t_stack *stack_a, int split);
void				reset_moves(t_frame *frame);
void				solve_5_or_less(t_frame *frame);
void				solver(t_frame *frame);
int					sorted(t_frame *frame);
t_frame				*create_frame(t_frame *frame, char **argv);
void				do_pa(t_frame *frame);
void				do_pb(t_frame *frame);
void				do_ra(t_frame *frame);
void				do_rb(t_frame *frame);
void				do_rr(t_frame *frame);
void				do_rra(t_frame *frame);
void				do_rrb(t_frame *frame);
void				do_rrr(t_frame *frame);
void				do_sa(t_frame *frame);
void				do_sb(t_frame *frame);
void				do_ss(t_frame *frame);
void				fill_stack_a(t_frame *frame);
void				push_swap_error(t_frame *frame);
void				push_swap_free(t_frame *frame);
void				stack_add_end(t_frame *frame, char stack_name, int num);
void				stack_del_top(t_frame *frame, char stack_name);
void				stack_add_top(t_frame *frame, char stack_name, int num);
#endif