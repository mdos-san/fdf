/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:43:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/12/18 17:55:39 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_chain	*chain_new(void)
{
	t_chain	*new;

	new = (t_chain*)malloc(sizeof(t_chain));
	new->pnt = (t_pnt*)malloc(sizeof(t_pnt));
	new->next = 0;
	return  (new);
}
