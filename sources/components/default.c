/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:34:16 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 18:35:45 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int     libui_component_insert_component(t_libui_component *parent,
    t_libui_component *child)
{
    if (!parent || !child)
        return (0);
    child->window = parent->window;
    child->parent = parent;
    parent->children.push(&(parent->children), child);
    return (1);
}