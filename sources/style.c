/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:45:49 by abiri             #+#    #+#             */
/*   Updated: 2021/07/07 22:36:52 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    libui_component_style_compute(t_libui_component *component)
{
    if (component->status.active)
        component->style = *((t_libui_style*)&component->raw_styles.active);
    else if (component->status.hovered)
        component->style = *((t_libui_style*)&component->raw_styles.hovered);
    else if (component->status.focused)
        component->style = *((t_libui_style*)&component->raw_styles.focused);
    else
        component->style = *((t_libui_style*)&component->raw_styles.regular);
}