/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:46:01 by gvial             #+#    #+#             */
/*   Updated: 2022/11/22 13:42:39 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char *argv[])
{
	(void) argv;
	t_miniRT	miniRT;
	// char **elements;
	
	if (argc == 2)
	{
		// if (!valid_name(argv[1]))
		// 	return (0);
		// elements = parse_mapfile(argv[1]);
		// if (!elements)
		// 	return (0);
		init(&miniRT);
		create_window(&miniRT);
		hook(&miniRT);
		return (0);
	}
	printf("Error: invalid number of arguments\n");
}
