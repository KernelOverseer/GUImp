/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 23:59:58 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 16:50:25 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void         constructor_init(t_libui_component *text)
{
    text->status.name = ft_strdup("text");
    text->draw = libui_text_draw;
    libui_text_load_style(text);
}

t_libui_component   *libui_new_text(t_libui_style props)
{
    t_libui_component    *result;

    if (!(result = malloc(sizeof(t_libui_component))))
        return (NULL);
    libui_component_init(result);
    result->style = props;
    constructor_init(result);
    return (result);
}