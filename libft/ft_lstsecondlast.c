/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsecondlast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverger <mverger@42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:05:27 by mverger           #+#    #+#             */
/*   Updated: 2022/01/18 20:07:04 by mverger          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsecondlast(t_list *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (lst);
	while (lst->next != NULL)
	{
		if (lst->next->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}