/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:50:25 by mjarry            #+#    #+#             */
/*   Updated: 2022/11/22 14:59:31 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../miniRT.h"

char	**error_message(char *str, char *strfree)
{
	printf("Error: ");
	printf("%s\n", str);
	if (strfree)
		free(strfree);
	return (NULL);
}

int	check_file_size(int fd, char *file)
{
	int		bytes;

	bytes = read(fd, file, 100001);
	file[100000] = 0;
	close(fd);
	return (bytes);
}

void	free2d(char **split)
{
	int	i;
	
	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}