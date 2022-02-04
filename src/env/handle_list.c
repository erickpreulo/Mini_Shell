#include "mini_shell.h"

t_env	*create_t_env(char *line)
{
	t_env *env = malloc(sizeof(t_env));
	char *find;

	env->str = ft_strdup(line);
	env->key = ft_strdup(line);
	find = ft_strchr(env->key, '=');
	find[0] = '\0';

	return (env);
}

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
		ft_lstadd_back(lst, ft_lstnew(create_t_env(env[i])));
		i++;
	}
	ms->lst_env = lst;
}