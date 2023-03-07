/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:20:20 by ngennaro          #+#    #+#             */
/*   Updated: 2023/03/07 19:54:37 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_params(t_param *list)
{
	while (list)
	{
		ft_putstr_fd(list->content, 1);
		ft_putchar_fd('\n', 1);
		list = list->next;
	}
}

void	header(void)
{
	ft_putstr_fd (" ____    ____   _             _  ", 1);
	ft_putstr_fd ("        __             _   __   \n", 1);
	ft_putstr_fd ("|_   \\  /   _| (_)           (_)", 1);
	ft_putstr_fd ("        [  |           [  | [  |  \n", 1);
	ft_putstr_fd ("  |   \\/   |   __   _ .--.   __ ", 1);
	ft_putstr_fd ("  .--.   | |--.  .---.  | |  | |  \n", 1);
	ft_putstr_fd ("  | |\\  /| |  [  | [ `.-. | [  |", 1);
	ft_putstr_fd (" ( (`\\]  | .-. |/ /__\\  | |  | |  \n", 1);
	ft_putstr_fd (" _| |_\\/_| |_  | |  | | | |  | |", 1);
	ft_putstr_fd ("  `'.'.  | | | || \\__., | |  | |  \n", 1);
	ft_putstr_fd ("|_____||_____|[___][___||__][___]", 1);
	ft_putstr_fd ("[\\__) )[___]|__]'.__.'[___][___] \n", 1);
}

int	main(int argc, char **argv, char **envp)
{
	size_t	i;
	size_t	start;
	int		close;
	char	*line;
	char	*new_str;
	t_param	*param;
	t_param	*new_lst;
	t_env	*env;

	(void)argc;
	(void)argv;
	env = get_env(envp);
	header();
	while (1)
	{
		line = readline("Enter a line: ");
		i = 0;
		param = NULL;
		while (line[i])
		{
			close = 0;
			while (line[i] == ' ')
				i++;
			start = i;
			if (line[i] == '\'')
			{
				i++;
				while (line[i] && line[i] != '\'')
					i++;
				if (!line[i] && line[i] != '\'')
				{
					close = 1;
					break;
				}
				new_str = ft_substr(line, start + 1, i - start - 1);
			}
			else if (line[i] == '"')
			{
				i++;
				while (line[i] && line[i] != '"')
					i++;
				if (!line[i] && line[i] != '"')
				{
					close = 2;
					break;
				}
				new_str = ft_substr(line, start + 1, i - start - 1);
			}
			else
			{
				while (line[i + 1] && line[i + 1] != ' ')
					i++;
				new_str = ft_substr(line, start, i - start + 1);
			}
			i++;
			new_lst = param_lstnew(new_str);
			param_lstadd_back(&param, new_lst);
		}
		if (close == 0)
			exec_core(param, env);
		if (close == 1)
			ft_putstr_fd ("Abort, quotes not close\n", 1);
		if (close == 2)
			ft_putstr_fd ("Abort, dobble quotes not close\n", 1);
		param_lstclear(&param);
	}
}