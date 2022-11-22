/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:50:50 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/21 11:16:20 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	error_message(char *str)
{
	printf("Error: ");
	printf("%s\n", str);
	return (0);
}

int	check_file_size(int fd)
{
	char	*file;
	int		bytes;

	file = malloc(sizeof(char) * 100001);
	bytes = read(fd, file, 100001);
	free(file);
	return (bytes);
}

//utils ^

int	valid_name(char *str)
{
	int	i;

	i = 1;
	while (str[0] && str[0]!= '.' && str[i] && str[i] != '.')
		i++;
	if (str[i] && str[++i] == 'r' && str[++i] == 't' && str[i + 1] == '\0')
		return (1);
	return (error_message("invalid file name, format should be \"*.rt\""));
}

int	parse_mapfile(char *str)
{
	int	fd;
	int	size;
	// char **map;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (error_message("cannot open mapfile."));
	size = check_file_size(fd);
	if (size == -1)
		return (error_message("read returned an error."));
	if (size == 0)
		return (error_message("map file is empty."));
	if (size > 100000)
		return (error_message("map file contains too many characters."));
	return (1);
	// return (parse_contents(fd, size, &map));
}
