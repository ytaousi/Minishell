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

