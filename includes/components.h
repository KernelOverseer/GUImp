/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:49:30 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 17:33:04 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include "ttslist.h"
# include "style.h"
# include "libui.h"

typedef struct  s_libui_component_status
{
    char            *name;
    char            *class;
    char            *id;
    unsigned int    hovered:1;
    unsigned int    active:1;
    unsigned int    focused:1;
    unsigned int    re_render:1; // For now the component is automatically re_rendered when there is a style change
}               t_libui_component_status;


struct  s_libui_component
{
    t_libui_component_draw_handler  draw;
    t_libui_component_events        events;
    t_libui_component_user_events   user_events;
    t_libui_style                   style;
    t_libui_component_status        status;
    struct s_libui_component        *parent;
    t_libui_window                  *window;
    void                            *data;
    t_sdl_image                     *image;
    t_list_head                     children;
    t_libui_raw_styles              raw_styles;
};

/*
** Component API
*/

void    libui_component_init(t_libui_component *component);
int     libui_component_insert_component(t_libui_component *parent, t_libui_component *child);

/*
** Internal Component API
*/

int     libui_components_draw(t_libui_component *component);
int     libui_component_draw_default(t_libui_component *component);
int     libui_component_recalculate_image(t_libui_component *component);
void    libui_component_style_compute(t_libui_component *component);
#endif