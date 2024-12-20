/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:38:24 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/19 19:45:09 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This one works for sure
static void ft_rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while (*b != cheapest->target_node && *a != cheapest)
        ft_rrr(a, b, false);
    ft_index(*a);
    ft_index(*b);
}

// This one works for sure
static void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		ft_rr(a, b, false);
	ft_index(*a);
	ft_index(*b);
}

// Fixed a tiny thing, now it works for sure
static void	ft_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = ft_find_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		ft_rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		ft_rev_rotate_both(a, b, cheapest);
	ft_prep_for_push(a, cheapest, 'a');
	ft_prep_for_push(b, cheapest->target_node, 'b');
	ft_pb(b, a, false);
}

// Can't believe I forgot this one??
// But now there are 6 functions in this file
static void	ft_push_to_a(t_stack **a, t_stack **b)
{
	ft_prep_for_push(a, (*b)->target_node, 'a');
	ft_pa(a, b, false); 
}

// This one works for sure
static void	ft_min_on_top(t_stack **a)
{
	while ((*a)->nb != ft_find_min(*a)->nb)
	{
		if (ft_find_min(*a)->above_median)
			ft_ra(a, false);
		else
			ft_rra(a, false);
	}
}

// This one works for sure
void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a-- > 3 && !ft_is_sorted(*a))
		ft_pb(b, a, false);
	if (len_a-- > 3 && !ft_is_sorted(*a))
		ft_pb(b, a, false);
	while (len_a-- > 3 && !ft_is_sorted(*a))
	{
		ft_init_nodes_a(*a, *b);
		ft_push_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_nodes_b(*a, *b);
		ft_push_to_a(a, b);
	}
	ft_index(*a);
	ft_min_on_top(a);
}

