/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymatch.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:31:15 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/01 21:31:17 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMATCH_H
# define MYMATCH_H

typedef char const	*t_mtc_pattern;

typedef void	*t_mtc_store;

typedef int	(*t_mtc_pattern_adder)(
	t_mtc_node		*addee,
	t_mtc_pattern	pattern_store);

typedef int	(*t_mtc_pattern_remover)(
	t_mtc_pattern	removee,
	t_mtc_store		pattern_store)

typedef int	(*t_mtc_pattern_matcher)(
	char const		**matchee,
	t_mtc_store		pattern_store,
	t_memp			**state)

typedef struct s_mtc_unit	t_s_mtc_node;
struct						s_mtc_pattern_node
{
	char const		*node_pattern;
	t_s_mtc_node	*previous;
	t_mtc_store		continue;
	t_mtc_matcher	continue_mtc;
	t_mtc_adder		continue_add;
	t_mtc_remover	continue_rem;
}

/*
**FUNCTIONS:
*/
int							mtc_match(
	char const		*txt,
	t_mtc_store		patterns,
	void			**p_ret);

# define MTC_SYS_ERR -1
# define MTC_SUCCESS 0
# define MTC_NO_PATTERN 1

#endif
