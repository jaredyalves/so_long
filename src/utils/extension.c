/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:41:24 by jcapistr          #+#    #+#             */
/*   Updated: 2023/05/30 17:41:25 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	has_extension(char *filename, char *extension)
{
	char	*dot;

	dot = ft_strrchr(filename, '.');
	return (dot && !ft_strncmp(dot + 1, extension, ft_strlen(extension) + 1));
}
