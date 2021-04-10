/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:09:22 by abiri             #+#    #+#             */
/*   Updated: 2021/04/10 17:11:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

char	*libui_set_error(char *error)
{
	static char	*last_error = NULL;

	if (error)
	{	
		free(last_error);
		last_error = ft_strdup(error);
	}
	return (last_error);
}

char	*libui_get_error(void)
{
	return (libui_set_error(NULL));
}
