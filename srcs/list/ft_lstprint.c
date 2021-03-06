/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:22:03 by efischer          #+#    #+#             */
/*   Updated: 2019/10/10 16:34:36 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*get_str_to_print(ssize_t *len, t_list *lst,
			void (*f)(t_list*, t_list**))
{
	t_list	*elem;
	void	*str;
	void	*tmp;

	str = NULL;
	while (lst != NULL)
	{
		tmp = str;
		f(lst, &elem);
		if (elem == NULL)
			break ;
		str = ft_memjoin(tmp, elem->content, *len, elem->content_size);
		*len += elem->content_size;
		free(tmp);
		ft_strdel((char**)&elem->content);
		free(elem);
		lst = lst->next;
	}
	return (str);
}

int			ft_lstprint(t_list *lst, void (*f)(t_list*, t_list**))
{
	void	*str;
	ssize_t	len;

	len = 0;
	if (lst == NULL)
		return (SUCCESS);
	if (f == NULL)
		return (FAILURE);
	str = get_str_to_print(&len, lst, f);
	if (write(1, str, len) == FAILURE)
		len = FAILURE;
	free(str);
	return (len);
}
