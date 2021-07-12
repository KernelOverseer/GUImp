/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   css_to_raw_style.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 02:50:29 by abiri             #+#    #+#             */
/*   Updated: 2021/07/12 21:19:41 by abiri            ###   ########.fr       */
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

int                 css_apply_to_query(t_libui_window *widnow, t_css_element *element)
{
    
}

int                 css_apply_to_element(t_libui_component *component, t_css_element)
{
    
}

int                 css_apply_to_window(t_libui_window *window, t_css_context *css)
{
    t_list_head     elements;
    t_css_element   *element;

    elements = css->elements;
    elements.iterator = elements.first;
    while ((element = ttslist_iter_content(&elements)))
    {

    }
}