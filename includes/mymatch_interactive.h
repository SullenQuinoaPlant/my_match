/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymatch_interactive.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 19:05:36 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/11 19:56:12 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMATCH_INTERACTIVE_H
# define MYMATCH_INTERACTIVE_H

/*
**(t_mtc_pattern)s are strings (null terminated).
*/
typedef char const	*t_mtc_pattern;

/*
**Nodes can be held in various data structures.
*/
typedef void		*t_mtc_nodes;

typedef int	(*t_mtc_test)(
	t_mtc_pattern	node_pattern,
	char const		**matchee,
	void			*match_state);

typedef int	(*t_mtc_action)(
	char const		**matchee,
	void			*match_state
	t_memp			*ret);

typedef int	(*t_mtc_node_matcher)(
	char const		**matchee,
	t_mtc_nodes		nodes,
	void			*match_state,
	t_memp			*ret);

typedef struct s_mtc_node	t_s_mtc_n;
struct						s_mtc_node
{
	t_mtc_pattern			node_pattern;
	t_mtc_test				is_match;
	t_mtc_action			on_match;
	t_mtc_nodes				continue;
	t_mtc_node_matcher		continue_mtc;
	t_mtc_action			on_return;
};
typedef int	(*t_mtc_node_adder)(
	t_s_mtc_n		*add,
	t_mtc_nodes		to);

typedef int	(*t_mtc_node_remover)(
	t_mtc_pattern	remove,
	t_mtc_nodes		from);

typedef struct s_mtc_modifiable_node	t_s_mtc_mn;
struct s_mtc_modifiable_node
{
	union
	{
		t_s_mtc_n	n;
		struct
		{
			t_mtc_pattern			node_pattern;
			t_mtc_test				is_match;
			t_mtc_action			on_match;
			t_mtc_nodes				continue;
			t_mtc_node_matcher		continue_mtc;
			t_mtc_action			on_return;
		};
	};
	t_s_mtc_n				*previous;
	t_mtc_node_adder		continue_add;
	t_mtc_node_remover		continue_rem;
}

typedef int		(*t_mtc_init)(void *arg, t_memp *ret_state);
typedef void	(*t_mtc_teardown)(t_memp state);

typedef struct s_mtc_store	t_s_mtc_s;
struct s_mtc_store
{
	t_mtc_init		init_match;
	t_s_mtc_n		*head;
	t_mtc_teardown	end_match;
}

#endif
