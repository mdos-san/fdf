/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:43:25 by mdos-san          #+#    #+#             */
/*   Updated: 2016/01/23 14:14:47 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_chain	*chain_new(void)
{
	t_chain	*new;

	if (!(new = (t_chain*)malloc(sizeof(t_chain))))
		return (NULL);
	if (!(new->pnt = (t_pnt*)malloc(sizeof(t_pnt))))
	{
		chain_del(&new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}
