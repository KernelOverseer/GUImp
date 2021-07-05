/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:55:48 by abiri             #+#    #+#             */
/*   Updated: 2021/07/05 17:30:48 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_mouse_is_in_rect(int x, int y, t_rect rect)
{
    if (x < rect.x || x > rect.x + rect.w ||
        y < rect.y || y > rect.y + rect.h)
        return (FALSE);
    return (TRUE);
}