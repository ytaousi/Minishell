#ifndef _MINISHELL_H
# define _MINISHELL_H
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct			s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct			s_cmds
{
	char				**cmds;
	struct s_cmds		*next;

}						t_cmds;

typedef struct			s_multipls
{
	t_cmds				cmds;
	struct s_multipls	*next;		

}						t_multipls;

t_env               *g_env;
char				*g_builtins_str[8];
char				(*g_builtins_funcs[7])();



void                ft_gogoshell(char **env);
void				ft_init_shell(char **env);
void				ft_set_builtins(void);
//void				ft_set_environement(char **env);



int					ft_get_maximum_value(int a, int b);
int					ft_get_minimum_value(int a, int b);
int					ft_is_equal_str(char *s1, char *s2);
char				*ft_strjoin_elements(char *s1, char c, char *s2);




char				*ft_get_key(char *env);
char				*ft_get_value(char *env);
int					ft_get_len_env(void);

void				ft_free_env(void);
int					ft_free_node(t_env *e);
t_env				*ft_new_env(char *key, char *value);

t_env				*ft_get_node_key(char *key);
char				**ft_list_to_tab(void);
void				ft_tab_to_glist(char **envp);
int					ft_set_env(char *key, char *value);
int					ft_unset_env(char *key);

void				ft_omylist(void);

int					ft_builtin_pwd(char **arg);
int					ft_builtin_env(char **arg);

//int					ft_builtin_echo(char **arg);
//int					ft_builtin_cd(char **arg);
//int					ft_builtin_export(char **arg);
//int					ft_builtin_unset(char **arg);
//int					ft_builtin_exit(char **arg);
#endif
