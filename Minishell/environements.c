#include "minishell.h"

//Free a node
int         ft_free_node(t_env *e)
{
	if (e)
	{
		free(e->key);
		free(e->value);
		free(e);
        return (1);
	}
    return (0);
}

//Free  Global Environement linked list
void		ft_free_env(void)
{
	t_env	*tmp;

	while (g_env != NULL)
	{
		if (g_env->key)
			free(g_env->key);
		if (g_env->value)	
			free(g_env->value);
		tmp = g_env->next;
		free(g_env);
		g_env = tmp;
	}
	g_env = NULL;
}

//extract key form char*
char	*ft_get_key(char *env)
{
	char	*key;
    int     i;
	int		j;

	i = 0;
	j = 0;
	key = NULL;
	if (env)
	{
		while (env[i] != '\0' && env[i] != '=')
			i++;
		if (!(key = (char *)malloc(sizeof(char ) * (i + 1))))
			return (NULL);
		while (j < i)
        {
			key[j] = env[j];
            j++;
        }
		key[j] = '\0';
	}
	return (key);
}

//extract value form char*
char	*ft_get_value(char *env)
{
	char	*value;
    char    *tmp;

    value = NULL;
    tmp = NULL;
	if (env)
	{
        if ((tmp = ft_strchr(env, '=')))
            if (!(value = ft_strdup(tmp + 1)))
			    return (NULL);
	}
	return (value);
}

// create node with key/value
t_env	*ft_new_env(char *key, char *value)
{
	t_env *new;

	if (!(new = (t_env *)malloc(sizeof(t_env))))
		return (0);
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

// environements list len
int			ft_get_len_env(void)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = g_env;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

// from linked list to char**
char		**ft_list_to_tab(void)
{
	char	**tab;
	t_env	*tmp;
	int		i;

	if (!g_env)
		return (0);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_get_len_env() + 1))))
		return (0);
	i = 0;
	tmp = g_env;
	while (tmp)
	{
                //don't forget to create/test/add sourceCode to libft
		tab[i] = ft_strjoin_elements(tmp->key, '=', tmp->value);
		i++;
		tmp = tmp->next;
	}
	tab[i] = 0;
	return (tab);
}

//from char** to global linked list
//u can set a return to normal pointer to a linked list
void	ft_tab_to_glist(char **envp)
{
	int		i;
	t_env	*new;
	char	*n;

	i = 0;
	n = NULL;
	while (envp[i] != NULL)
	{
		new = ft_new_env(ft_get_key(envp[i]), ft_get_value(envp[i]));
		new->next = g_env;
		g_env = new;
		i++;
	}
}

// find a node and set a pointer to it
t_env		*ft_get_node_key(char *key)
{
	t_env *tmp;

	if (!g_env)
		return (0);
	tmp = g_env;
	while (tmp)
	{
		if (ft_is_equal_str(tmp->key, key))
			return (tmp);
		tmp = tmp->next;
	}
	return (0);
}

// set Environement with value if !key create new node
int		ft_set_env(char *key, char *value)
{
	t_env *tmp;

	if (!g_env)
		return (0);
	if (!key || !value)
		return (0);
	tmp = g_env;
	while (tmp)
	{
		if (ft_is_equal_str(tmp->key, key))
		{
			free(tmp->value);
			tmp->value = ft_strdup(value);
			return (EXIT_SUCCESS);
		}
		else if (!tmp->next && !ft_is_equal_str(tmp->key, key))
		{
			tmp->next = ft_new_env(key, value);
			return (EXIT_SUCCESS);
		}
		tmp = tmp->next;
	}
	return (EXIT_FAILURE);
}

// unset/delete the Environement vaariable 

int		ft_unset_env(char *key)
{
	t_env *tmp;
	t_env *to_free;

	tmp = NULL;
	if (ft_is_equal_str(g_env->key, key))
	{
		to_free = g_env;
		g_env = to_free->next;
		free(to_free);
		return (1);
	}
	else
	{
		tmp = g_env;
		while (tmp->next)
		{
			if (ft_is_equal_str(tmp->next->key, key))
			{
				to_free = tmp->next;
				tmp->next = to_free->next;
				free(to_free);
				return (EXIT_SUCCESS);
			}
			tmp = tmp->next;
		}
	}
	return(EXIT_FAILURE);
}