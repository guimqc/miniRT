/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:50:50 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/17 16:53:01 by mjarry           ###   ########.fr       */
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
	printf("Error : invalid file name, format should be \"*.rt\"\n");
	return (0);
}

int	parse_mapfile(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error : cannot open mapfile");
		return (0);
	}
	return (1);
}