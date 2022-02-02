#include "mini_shell.h"

// typedef struct s_lisenv
// {
// 	char *line;
// } t_lisenv;

// t_lstenv	*create_env(char *line)
// {
// 	t_lisenv *env = malloc(sizeof(t_lisenv));
// 	env->line = line;
// 	return(env);
// }

void get_env_list(char **env)
{
	t_mini_shell *ms;
	t_list **lst;
	int i;

	ms = get_ms();
	ms->env = env;

	lst = malloc(sizeof(t_list *));

	i = 0;
	while (env[i])
	{
		ft_lstadd_back(lst, ft_lstnew(env[i]));
		i++;
	}

	ms->lst_env = lst;
}