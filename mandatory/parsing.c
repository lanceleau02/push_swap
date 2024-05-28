/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laprieur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:15:17 by laprieur          #+#    #+#             */
/*   Updated: 2023/01/26 17:47:30 by laprieur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_findlen(int argc, char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < argc)
	{
		len += ft_strlen(argv[i]);
		i++;
	}
	len += (argc - 1);
	return (len);
}

static char	*ft_catargv(int argc, char **argv, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			str[k] = argv[i][j];
			j++;
			k++;
		}
		if (i != argc - 1)
		{
			str[k] = ' ';
			k++;
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	**ft_parsing(int argc, char **argv)
{
	char	*str;
	char	**tab;

	str = malloc(sizeof(char) * (ft_findlen(argc, argv) + 1));
	if (str == NULL)
		return (NULL);
	str = ft_catargv(argc, argv, str);
	tab = ft_split(str, ' ');
	if (ft_check_full_space(str) == 1 || ft_check_type(str) == 1
		|| ft_check_int_size(tab) == 1 || ft_check_duplicates(tab) == 1)
	{
		free(str);
		str = NULL;
		ft_free_tab_of_tab(tab);
		tab = NULL;
		write(2, "Error\n", 6);
		return (NULL);
	}
	free(str);
	str = NULL;
	return (tab);
}
