/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:50:50 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/22 15:00:43 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	valid_name(char *str)
{
	int	i;

	i = 1;
	while (str[0] && str[0]!= '.' && str[i] && str[i] != '.')
		i++;
	if (str[i] && str[++i] == 'r' && str[++i] == 't' && str[i + 1] == '\0')
		return (1);
	error_message("invalid file name, format should be \"*.rt\"", NULL);
	return (0);
}

int	elem_names(char **elems)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (elems[i])
	{
		while (elems[i][j] == ' ')
			j++;
		if ((elems[i][j] == 'A' || elems[i][j] == 'L' || elems[i][j] == 'C')
				&& elems[i][j + 1] == ' ')
			i++;
		else if (((elems[i][j] == 's' && elems[i][j + 1] == 'p')
				|| (elems[i][j] == 'p' && elems[i][j + 1] == 'l')
				|| (elems[i][j] == 'c' && elems[i][j + 1] == 'y')) && elems[i][j + 2] == ' ')
			i++;
		else
		{
			printf("Error3: invalid object name at line %d\n", i + 1);
			return (0);
		}
	}
	return (1);
}

char	**parse_contents(char *file)
{
	char **elems;
	
	elems = ft_split(file, '\n');
	free(file);
	if (!elem_names(elems))
	{
		free2d(elems);
		return (NULL);
	}
	return (elems);
}

char	**parse_mapfile(char *str)
{
	int		fd;
	int		size;
	char	*file;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (error_message("cannot open mapfile.", NULL));
	file = malloc(sizeof(char) * 100001);
	size = check_file_size(fd, file);
	if (size == -1)
		return (error_message("read returned an error.", file));
	if (size == 0)
		return (error_message("map file is empty.", file));
	if (size > 100000)
		return (error_message("map file contains too many characters.", file));
	return (parse_contents(file));
}
