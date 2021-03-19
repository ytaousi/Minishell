#include "minishell.h"

int			ft_get_maximum_value(int a, int b)
{
	if (a > b)
		return (a);
	else
		return(b);
}

int			ft_get_minimum_value(int a, int b)
{
	if (a > b)
		return (b);
	else
		return(a);
}

int		ft_is_equal_str(char *s1, char *s2)
{
	if (ft_strncmp(s1, s2, ft_get_maximum_value(ft_strlen(s1), ft_strlen(s2))) == 0)
		return (1);
	else
		return (0);
}


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
		return (EXIT_SUCCESS);
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



char *ft_strjoin_elements(char *s1, char c, char *s2)
{
	char *joined;
	int len1;
	int len2;
	int i;
	int j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1 + 1))))
		return (NULL);
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i] = c;
	i++;
	while (j < len2)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}



//extract key fro char
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

int main(int ac, char **av, char **env)
{
	if (ac || av)
		;
    ft_tab_to_glist(env);
    ft_set_env("yassir", "taousi");
	//ft_unset_env("yassir");
	ft_omylist();
    return (0);
}