/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:05:20 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/05 01:37:27 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_stack(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

void ft_append_node(t_stack **stack, long int nb)
{
    t_stack *new;
    t_stack *tmp;

    new = malloc(sizeof(t_stack));
    if (!new)
        exit(EXIT_FAILURE);
    new->nb = nb;
    new->index = 0;
    new->push_cost = 0;
    new->above_median = false;
    new->cheapest = false;
    new->target_node = NULL;
    new->next = NULL;
    new->prev = NULL;
    if (!*stack)
        *stack = new;
    else
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
        new->prev = tmp;
    }
}

void ft_init_a(t_stack **a, char **argv)
{
    int i;
    long nb;

    i = 0;
    while (argv[i])
    {
        if (!ft_is_number(argv[i]))
            ft_error(a, NULL, NULL);
        nb = ft_atol(argv[i]);
        if (nb > INT_MAX || nb < INT_MIN || ft_is_duplicate(*a, nb))
            ft_error(a, NULL, NULL);
        ft_append_node(a, nb);
        i++;
    }
}

int ft_stack_len(t_stack *stack)
{
    int len;
    t_stack *tmp;

    len = 0;
    tmp = stack;
    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }
    return (len);
}