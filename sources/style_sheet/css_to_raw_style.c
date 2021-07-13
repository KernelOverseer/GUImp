/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   css_to_raw_style.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 02:50:29 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 18:00:59 by abiri            ###   ########.fr       */
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

t_libui_raw_style   css_to_raw_style(t_libui_raw_style *source, t_list_head props)
{
    t_libui_css_prop_handler    handler;
    t_libui_raw_style           style;
    t_css_prop                  *prop;

    ft_bzero(&style, sizeof(style));
    if (source)
        style = *source;
    props.iterator = props.first;
    while ((prop = ttslist_iter_content(&props)))
    {
        handler = get_handler(prop->key);
        if (handler)
            handler(prop, &style);
    }
    return (style);
}

static int          get_query_type(char **name)
{
    char    *raw_name;
    char    prefix;

    prefix = (*name)[0];
    if (prefix == '.' || prefix == '#')
    {
        raw_name = ft_strdup(*name + 1);
        free(*name);
        *name = raw_name;
        return (STYLE_QUERY_CLASS + (prefix == '#'));
    }
    return (STYLE_QUERY_TAG);
}

int                 css_apply_to_element(t_libui_component *component, t_css_element *element)
{
    t_libui_raw_style   regular;
    // for now we are only reading the regular style and applying it on the rest
    // we need to add oarsing the different states like hover active etc... in css

    regular = css_to_raw_style(&component->raw_styles.regular, element->props);
    component->raw_styles.regular = regular;
    component->raw_styles.active = regular;
    component->raw_styles.focused = regular;
    component->raw_styles.hovered = regular;
    return (1);
}

static int          search_for_component_with_class(t_libui_component *component, void *arg)
{
    t_css_element   *element;
    char            **classes;

    element = arg;
    classes = ft_strsplitcharset(component->status.class, WHITESPACES);
    if (!classes)
        return (0);
    while (*classes)
    {
        if (ft_strequ(*classes, element->name))
            return (1);
        classes++;
    }
    return (0);
}

static int          search_for_component_with_tag(t_libui_component *component, void *arg)
{
    t_css_element   *element;
    
    element = arg;
    if (ft_strequ(component->status.name, "*") || ft_strequ(element->name, component->status.name))
        return (1);
    return (0);
}

static int         effect_apply_style(t_libui_component *component, void *arg)
{
    t_css_element   *element;

    element = arg;
    return (css_apply_to_element(component, element));
}

int                 css_apply_to_class(t_libui_window *window, t_css_element *element)
{
    libui_component_map_function(window->components, &search_for_component_with_class,
        &effect_apply_style, element);
    return (1);
}

int                 css_apply_to_tag(t_libui_window *window, t_css_element *element)
{
    libui_component_map_function(window->components, &search_for_component_with_tag,
        &effect_apply_style, element);
    return (1);
}

int                 css_apply_to_query(t_libui_window *window, t_css_element *element)
{
    int                 query_type;
    t_libui_component   *component;

    query_type = get_query_type(&(element->name));
    if (query_type == STYLE_QUERY_ID)
    {
        if ((component = libui_component_get_by_id(window, element->name)))
            return (css_apply_to_element(component, element));
    }
    else if (query_type == STYLE_QUERY_CLASS)
        return (css_apply_to_class(window, element));
    else if (query_type == STYLE_QUERY_TAG)
        return (css_apply_to_tag(window, element));
    return (0);
}

int                 css_apply_to_window(t_libui_window *window, t_css_context *css)
{
    int             status;
    t_list_head     elements;
    t_css_element   *element;

    if (!css)
        return (0);
    status = 1;
    elements = css->elements;
    elements.iterator = elements.first;
    while ((element = ttslist_iter_content(&elements)))
        status &= css_apply_to_query(window, element);
    return (status);
}
