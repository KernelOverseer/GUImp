/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 22:57:57 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 14:57:57 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

char    *libui_set_error(char *error)
{
    static char *last_error = NULL;

    if (error)
    {
        free(last_error);
        last_error = ft_strdup(error);
    }
    return (last_error);
}

char    *libui_get_error(void)
{
    return (libui_set_error(NULL));
}