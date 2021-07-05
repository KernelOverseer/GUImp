/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:49:30 by abiri             #+#    #+#             */
/*   Updated: 2021/07/06 00:19:20 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include "ttslist.h"
# include "style.h"
# include "libui.h"

struct  s_libui_component
{
    t_libui_style                   style;
    t_libui_window                  *window;
    struct s_libui_component        *parent;
    t_libui_component_draw_handler  draw;
    t_libui_component_events        events;
    void                            *data;
    t_list_head                     children;
};

/*
** Component API
*/

void    libui_component_init(t_libui_component *component);
int     libui_component_insert_component(t_libui_component *parent, t_libui_component *child);

/*
** Internal Component API
*/

int libui_components_draw(t_libui_component *component);
int libui_component_draw_default(t_libui_component *component);
#endif