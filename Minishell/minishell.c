#include "minishell.h"

void ft_omylist()
{
    t_env *tmp;

    tmp = g_env;
    while (tmp)
    {
        ft_putendl_fd(ft_strjoin_elements(tmp->key, '=', tmp->value), 1);
        tmp = tmp->next;
    }
}
void ft_set_environement(char **env)
{
	ft_tab_to_glist(env);
	ft_set_env("yassir", "taousi");
	ft_omylist();

}

void ft_init_shell(char **env)
{
	ft_set_environement(env);
	//ft_set_builtins();
}

//start shell
void ft_gogoshell(char **env)
{
	//initialize shell componants
	ft_init_shell(env);
	//start Main loop
	   //check line
	   //parse data

}

int main(int argc, char **argv, char **env)
{
	if (argv)
		;
    if (argc == 1)
		ft_gogoshell(env);
	else
		ft_putstr_fd(" Error Usage : ./minishell\n", 2);
	ft_free_env();
    return(0);
}