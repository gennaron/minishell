/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:32:30 by mbrement          #+#    #+#             */
/*   Updated: 2023/03/05 14:52:42 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd()
{
	char	*str;

	str = get_pwd();
	ft_putstr_fd(str, 1);
	write (1, "\n", 1);
	free(str);
	g_global.return_value = 0;
}
