/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:36:12 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 19:48:10 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_component_draw_default(t_libui_component *component)
{
    t_libui_window  *window;

    printf("IN COMPONENT DRAW\n");
    window = component->window;
    ft_sdl_image_rect(window->main_image, (t_rect){component->style.pos_x,
        component->style.pos_y, component->style.width, component->style.height},
        0xFF00FF);
    return (0);
}

int libui_components_draw(t_libui_component *component)
{
    t_list_head         children_list;
    t_libui_component   *child;

    if (component->draw)
        component->draw(component);
    children_list = component->children;
    children_list.iterator = children_list.first;
    while ((child = (ttslist_iter_content(&children_list))))
    {
        libui_components_draw(child);
    }
    return (0);
}