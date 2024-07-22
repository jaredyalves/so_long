/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:24 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:25 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <fcntl.h>
#include <unistd.h>

void	check_args(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		ft_exit("Missing .ber file");
	if (argc != 2)
		ft_exit("Too many arguments");
	if (!has_extension(argv[1], "ber"))
		ft_exit("File missing .ber extension");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit("File does not exist or cannot be opened");
	close(fd);
}
