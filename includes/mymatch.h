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

typedef void	*t_mtc_pattern;

typedef int	(*t_mtc_adder)(
	t_mtc_node		*addee,
	t_mtc_pattern	pattern_store);

typedef int	(*t_mtc_remover)(
	t_mtc_pattern	*removee,
	t_mtc_pattern	pattern_store);

typedef int	(*t_mtc_matcher)(
	char const		**matchee,
	t_mtc_pattern	pattern_store,
	void			**p_ret);

typedef struct s_mtc_unit	t_s_mtc_unit;
struct s_mtc_unit
{
	t_mtc_matcher	mtc;
	t_mtc_adder		add;
	t_mtc_remover	rem;
	t_mtc_pattern	continue_pattern;
}

# define MTC_SYS_ERR -1
# define MTC_SUCCESS 0
# define MTC_NO_PATTERN 1

#endif
