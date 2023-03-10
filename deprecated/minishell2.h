/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrement <mbrement@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:36:01 by mbrement          #+#    #+#             */
/*   Updated: 2023/03/07 21:09:52 by mbrement         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "Tools/Libft/libft.h"

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env
{
	char			*name;
	char			*content;
	int				is_env;
	int				is_export;
	struct s_env	*next;
}					t_env;

typedef struct s_param
{
	char			*content;
	int				type;
	struct s_param	*next;
}					t_param;

int	g_ g_return_value;

void	end_of_prog(t_env *env, int i);

///ENV
void	env_lstadd_back(t_env **lst, t_env *next);
void	env_lstadd_front(t_env **lst, t_env *next);
void	env_lstclear(t_env **lst);
void	env_lstdelone(t_env *lst);
t_env	*env_lstlast(t_env *lst);
t_env	*env_lstnew(char **content);
int		env_lstsize(t_env *lst);
t_env	*env_search(t_env *list, char *str);
t_env	*get_env(char **env);
void	env_change(char *name, char *content, t_env *env);
char	**env_split(char **env, int nb);
void	env_add(t_env *env, char *str);
void	env_clear(t_env *env);
t_env	*env_search_before(t_env *list, char *str);
t_env	*env_unset(t_env *env, char *str);

void	param_lstadd_back(t_param **lst, t_param *next);
t_param	*param_lstnew(char *content);
void	param_lstclear(t_param **lst);

///BUILT_IN
void	pwd(t_list *env);
void	print_env(t_env *list);
char	*get_pwd(void);

///ERROR
void	error_handler(int name);

#endif