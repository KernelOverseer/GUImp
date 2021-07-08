/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:49:30 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 11:34:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include "ttslist.h"
# include "style.h"
# include "libui.h"

typedef struct  s_libui_component_status
{
    unsigned int    hovered:1;
    unsigned int    active:1;
    unsigned int    focused:1;
}               t_libui_component_status;


struct  s_libui_component
{
    t_libui_component_draw_handler  draw;
    t_libui_component_events        events;
    t_libui_style                   style;
    t_libui_component_status        status;
    struct s_libui_component        *parent;
    t_libui_window                  *window;
    void                            *data;
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
void    libui_component_style_compute(t_libui_component *component);
#endif