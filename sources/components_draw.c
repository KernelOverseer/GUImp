/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:36:12 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 14:28:52 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_component_draw_default(t_libui_component *component)
{
    t_libui_window  *window;
    Uint32          color;

    color = 0xFF00FF;
    window = component->window;
    if (window->env->hovered_component == component)
        color = 0x00FF00;
    if (window->env->active_component == component)
        color = 0x0000FF;
    if (window->env->focused_component == component)
    {
        ft_sdl_image_rect(window->main_image, (t_rect){component->style.pos_x-1,
        component->style.pos_y-1, component->style.width+2, component->style.height+2},
        0xFFFFFF);
    }
    else if (window->focused_component == component)
    {
        ft_sdl_image_rect(window->main_image, (t_rect){component->style.pos_x-1,
        component->style.pos_y-1, component->style.width+2, component->style.height+2},
        0x0000FF);
    }
    ft_sdl_image_rect(window->main_image, (t_rect){component->style.pos_x,
        component->style.pos_y, component->style.width, component->style.height},
        color);
    static TTF_Font *my_font = NULL;
    if (!my_font)
    {
        my_font = TTF_OpenFont("./fonts/roboto/Roboto-Regular.ttf", 32);
    }
    ft_sdl_put_text("hello", (t_text){.align=ALIGN_CENTER_CENTER, .color=0x000000, .x=200, .y=200},
        my_font, window->main_image);
    return (0);
}

int libui_component_recalculate_image(t_libui_component *component)
{
    if (!component->image ||
        component->image->height != component->style.height ||
        component->image->width != component->style.width)
    {
        if (component->image)
            free(component->image->pixels);
        free(component->image);
        component->image = newimage(component->style.width, component->style.height);
        return (1);
    }
    return (0);
}

int libui_component_blit_image(t_libui_component *component)
{
    libui_draw_blit_image((t_rect){.x=component->style.pos_x,
        .y=component->style.pos_y, .w=component->style.width,
        .h=component->style.height},
        component->window->main_image,
        component->image);
    return (1);
}

int libui_components_draw(t_libui_component *component)
{
    t_list_head         children_list;
    t_libui_component   *child;

    libui_component_style_compute(component);
    if (component->draw)
    {
        if (component->status.re_render)
            component->draw(component);
        component->status.re_render = FALSE;
        libui_component_blit_image(component);
    }
    children_list = component->children;
    children_list.iterator = children_list.first;
    while ((child = (ttslist_iter_content(&children_list))))
        libui_components_draw(child);
    return (0);
}