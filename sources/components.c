/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 23:42:11 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 19:43:31 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    libui_component_init(t_libui_component *component)
{
    ft_bzero(component, sizeof(t_libui_component));
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