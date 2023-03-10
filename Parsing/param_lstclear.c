/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_lstclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:36:25 by mbrement          #+#    #+#             */
/*   Updated: 2023/03/07 19:09:40 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	param_lstclear(t_param **lst)
{
	t_param	*next;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		free((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}
