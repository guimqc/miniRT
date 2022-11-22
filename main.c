/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarry <mjarry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:46:01 by gvial             #+#    #+#             */
/*   Updated: 2022/11/17 16:52:45 by mjarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char *argv[])
{
	t_miniRT	miniRT;
	
	if (argc == 2)
	{
		if (!valid_name(argv[1]))
			return (0);
		if (!parse_mapfile(argv[1]))
			return (0);
		// init(&miniRT);
		create_window(&miniRT);
		hook(&miniRT);
		return (0);
	}
	printf("Error: invalid number of arguments\n");
}
