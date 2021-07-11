/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   css_to_raw_style.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 02:50:29 by abiri             #+#    #+#             */
/*   Updated: 2021/07/11 03:19:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static t_libui_css_prop_handler    get_handler(char *name)
{
    int i;

    i = 0;
    while (g_libui_css_prop_handlers[i].name)
    {
        if (ft_strequ(g_libui_css_prop_handlers[i].name, name))
            return (g_libui_css_prop_handlers[i].handler);
        i++;
    }
    return (NULL);
}

t_libui_raw_style   css_to_raw_style(t_list_head props)
{
    t_libui_css_prop_handler    handler;
    t_libui_raw_style           style;
    t_css_prop                  *prop;

    ft_bzero(&style, sizeof(style));
    props.iterator = props.first;
    while ((prop = ttslist_iter_content(&props)))
    {
        handler = get_handler(prop->key);
        if (handler)
            handler(prop, &style);
    }
}