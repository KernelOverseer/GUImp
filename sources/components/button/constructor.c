/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:36:55 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 18:40:26 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int          libui_component_button_draw(t_libui_component *button,
                    void * args)
{
    (void)args;

    if (!button->window)
        return (0);
    ft_sdl_image_rect(button->window->main_image, (t_rect){
        .x=button->props.posX,
        .y=button->props.posY,
        .h=button->props.height,
        .w=button->props.width
    }, 0xFF00FF);
    printf("drew button\n");
    return (1);
}

t_libui_component   *libui_component_button_new(t_libui_component_props props)
{
    t_libui_component   *new_component;

    if (!(new_component = ft_memalloc(sizeof(t_libui_component))))
        return (NULL);
    ttslist_init(&new_component->children);
    new_component->props = props;
    new_component->draw = &libui_component_button_draw;
    return (new_component);
}

t_libui_component   *libui_create_button_default(void)
{
    t_libui_component_props props;

    ft_bzero(&props, sizeof(t_libui_component_props));
    props.height = 50;
    props.width = 100;
    props.posX = 0;
    props.posY = 0;
    return (libui_component_button_new(props));
}