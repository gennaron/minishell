/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:14:01 by mbrement          #+#    #+#             */
/*   Updated: 2023/03/05 16:52:42 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	export_handler(t_param *param, t_env *env)
{
	char	**str;
	int		i;

	str = param_to_array(param);
	(void) env;
	if (!str)
		error_handler(130);
	if (!str[1] || str[1][0] == '\0')
	{
		print_export(env);
	}
	else
	{
		i = 0;
		while (str[++i] && str[i][0] != '\0')
			env_add(env, str[i]);
	}
	free_tab(str);
	g_global.return_value = 0;
}
