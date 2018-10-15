/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymatch.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 21:31:15 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/11 19:49:10 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMATCH_H
# define MYMATCH_H

typedef void	*t_mtc_store;

int							mtc_match(
	char const			*matchee,
	t_mtc_store			*against,
	void				*state_init,
	t_memp				**p_ret);

# define MTC_SYS_ERR -1
# define MTC_SUCCESS 0
# define MTC_NO_PATTERN 1

#endif
