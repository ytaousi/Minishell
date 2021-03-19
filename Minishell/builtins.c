#include "minishell.h"

void	ft_set_builtins(void)
{	
	g_builtins_str[0] = ft_strdup("echo");
	g_builtins_str[1] = ft_strdup("cd");
	g_builtins_str[2] = ft_strdup("pwd");
	g_builtins_str[3] = ft_strdup("export");
	g_builtins_str[4] = ft_strdup("unset");
	g_builtins_str[5] = ft_strdup("env");
	g_builtins_str[6] = ft_strdup("exit");
	g_builtins_str[7] = NULL;
	//g_builtins_funcs[0] = &ft_builtin_echo;
	//g_builtins_funcs[1] = &ft_builtin_cd;
	//g_builtins_funcs[2] = &ft_builtin_pwd;
	//g_builtins_funcs[3] = &ft_builtin_export;
	//g_builtins_funcs[4] = &ft_builtin_unset;
	//g_builtins_funcs[5] = &ft_builtin_env;
	//g_builtins_funcs[6] = &ft_builtin_exit;
}

// int ft_builtin_pwd(char **arg)
// {
//     char tab[1024];

//     getcwd(tab, 1024);
//     ft_putstr_fd(tab, 1);
//     ft_putchar_fd('\n', 1);
//     return (0);
// }

int ft_builtin_env(char **arg)
{
	if (arg)
		;
    t_env *tmp;

	tmp = g_env;
	while (tmp)
	{
		ft_putendl_fd(ft_strjoin_elements(tmp->key, '=', tmp->value), 1);
		tmp = tmp->next;
	}
    return (0);
}