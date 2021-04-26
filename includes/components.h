/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:25:05 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 14:06:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENTS_H
# define COMPONENTS_H
# include "ttslist.h"
# include "style.h"
# include "events.h"

enum    e_libui_component_states
{
    LIBUI_COMPONENT_STATE_IDLE, LIBUI_COMPONENT_STATE_HOVERED,
    LIBUI_COMPONENT_STATE_ACTIVE
};

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
    t_libui_event_handler   on_mouse_move;
    t_libui_event_handler   on_key_down;
    t_libui_event_handler   on_key_up;
}               t_libui_component_events;

typedef struct  s_libui_component_props
{
    t_libui_component_style             style;
    t_libui_component_style             computed_style;
    int                                 posX;
    int                                 posY;
    int                                 width;
    int                                 height;
    int                                 state;
    t_sdl_image                         render_image;
    int                                 render_refresh;
}               t_libui_component_props;

typedef struct s_libui_component t_libui_component;


typedef int (*t_libui_component_draw)(t_libui_component *component, void *args);

typedef struct s_libui_component
{
    t_libui_component_props     props;
    t_libui_component_draw      draw;
    t_libui_component_events    events;
    t_libui_component_events    user_events;
    t_libui_component           *parent;
    t_list_head                 children;
    struct s_libui_window       *window;
    void                        *data;
}               t_libui_component;


#endif