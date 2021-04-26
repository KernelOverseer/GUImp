/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:34:16 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 11:39:37 by abiri            ###   ########.fr       */
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