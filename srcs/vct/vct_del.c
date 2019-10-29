/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:27:15 by efischer          #+#    #+#             */
/*   Updated: 2019/10/29 15:28:32 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vctlib.h"

void	vct_del(t_vector *vct)
{
	if (vct != NULL)
	{
		ft_strdel(&vct->str);
		free(vct);
	}
}
