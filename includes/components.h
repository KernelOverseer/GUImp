/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:25:05 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 16:45:02 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include "ttslist.h"
# include "style.h"
# include "events.h"

/*
**  Each component has events, which are
**  on_focus: The element just became focused on
**  on_click: When the user clicks on the component
**  on_release: When the user releases the mouse button on the component
**  on_mouse_enter: When the mouse cursor just got on the component
**  on_mouse_out: When the mouse cursor just got off the component
**  on_key_down: When a keyboard key is pressed down
**  on_key_up: When a leyboard key is released
*/

typedef struct  s_libui_component_events
{
    t_libui_event_handler   on_focus;
    t_libui_event_handler   on_click;
    t_libui_event_handler   on_release;
    t_libui_event_handler   on_mouse_enter;
    t_libui_event_handler   on_mouse_out;
    t_libui_event_handler   on_key_down;
    t_libui_event_handler   on_key_up;
}               t_libui_component_events;

typedef struct  s_libui_component_props
{
    t_libui_component_style     style;
    int                         posX;
    int                         posY;
    int                         width;
    int                         height;
}               t_libui_component_props;

typedef struct s_libui_component t_libui_component;


typedef int (*t_libui_component_draw)(t_libui_component *component, void *args);

typedef struct s_libui_component
{
    t_libui_component_props     props;
    t_libui_component_draw      draw;
    t_libui_component_events    events;
    t_libui_component           *parent;
    t_list_head                 children;
    struct s_libui_window       *window;
}               t_libui_component;


#endif