/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 23:42:11 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 15:03:58 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    libui_component_init(t_libui_component *component)
{
    ft_bzero(component, sizeof(t_libui_component));
    component->status.re_render = TRUE;
    ttslist_init(&(component->children));
}

int     libui_component_insert_component(t_libui_component *parent, t_libui_component *child)
{
    if (!parent || !child)
        return (0);
    child->window = parent->window;
    child->parent = parent;
    parent->children.push(&(parent->children), child);
    return (1);
}