/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:39:06 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:39:07 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

#include <stdlib.h>

int	ft_exit(char *error)
{
	free_config();
	if (error)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(error, 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
