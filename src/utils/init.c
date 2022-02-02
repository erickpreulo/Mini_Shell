
#include "mini_shell.h"

void	start_struct(char **env)
{
	t_mini_shell *ms;

	ms = get_ms();
	get_env_list(env);

}

void	reset_struct()
{
	t_mini_shell *ms;

	ms = get_ms();
	ms->size = 0;
	ms->group_size = 0;
	ms->current_pipe = 0;
}
