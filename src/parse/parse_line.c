/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:24 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:25 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

#include <stdlib.h>

static void	parse_map_line(char *line)
{
	int			i;
	t_config	*cfg;
	char		**map;

	i = -1;
	cfg = get_config();
	cfg->height += 1;
	map = (char **)ft_calloc(sizeof(char *), cfg->height);
	if (map == NULL)
		ft_exit("Memory allocation failed");
	while (++i < cfg->height - 1)
		map[i] = cfg->map[i];
	map[cfg->height - 1] = ft_strtrim(line, "\n");
	free(cfg->map);
	cfg->map = map;
}

void	parse_line(char *line)
{
	t_config	*cfg;
	char		*trm;
	int			len;

	cfg = get_config();
	trm = ft_strtrim(line, "\n");
	len = ft_strlen(trm);
	if (cfg->width == -1)
		cfg->width = len;
	else if (cfg->width != len)
		ft_exit("Map is invalid");
	free(trm);
	parse_map_line(line);
}
