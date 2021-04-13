/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:43:34 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 18:24:02 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int          libui_component_div_draw(t_libui_component *div,
                    void * args)
{
    (void)args;

    if (!div->window)
        return (0);
    ft_sdl_image_rect(div->window->main_image, (t_rect){
        .x=div->props.posX,
        .y=div->props.posY,
        .h=div->props.height,
        .w=div->props.width
    }, 0x212121);
    return (1);
}

t_libui_component   *libui_component_div_new(t_libui_component_props props)
{
    t_libui_component   *new_component;

    if (!(new_component = ft_memalloc(sizeof(t_libui_component))))
        return (NULL);
    ttslist_init(&new_component->children);
    new_component->props = props;
    new_component->draw = &libui_component_div_draw;
    return (new_component);
}

t_libui_component   *libui_create_div_default(void)
{
    t_libui_component_props props;

    ft_bzero(&props, sizeof(t_libui_component_props));
    props.height = 200;
    props.width = 200;
    props.posX = 0;
    props.posY = 0;
    return (libui_component_div_new(props));
}