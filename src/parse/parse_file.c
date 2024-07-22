/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:24 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:25 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	parse_file(char *filename)
{
	t_config	*cfg;
	int			fd;

	cfg = get_config();
	fd = open(filename, O_RDONLY);
	while (1)
	{
		cfg->p_line = get_next_line(fd);
		if (cfg->p_line == NULL)
			break ;
		parse_line(cfg->p_line);
		free(cfg->p_line);
		cfg->p_line = NULL;
	}
	close(fd);
}
