/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:11:38 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 19:57:13 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "libui.h"

int libui_event_poll(t_libui_env *env);

struct          s_libui_component_events
{
    t_libui_component_event_handler mouse_enter;
    t_libui_component_event_handler mouse_leave;
    t_libui_component_event_handler active;
    t_libui_component_event_handler release;
    t_libui_component_event_handler scroll;
    t_libui_component_event_handler focus;
    t_libui_component_event_handler lose_focus;
    t_libui_component_event_handler key_down;
    t_libui_component_event_handler key_up;
};

struct          s_libui_event_handler_map
{
    Uint32                              type;
    t_libui_internal_event_handler      handler;
};

extern const t_libui_event_handler_map  g_windows_internal_events[];

/*
**  Internal Window Events
*/

int libui_components_event_dispatcher(t_libui_env *env, SDL_Event *e);
int libui_windows_event_dispatcher(t_libui_env *env, SDL_Event *e);
int libui_windows_event_handler_size_changed(t_libui_env *env,
    t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_focus_gained(t_libui_env *env,
    t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_focus_lost(t_libui_env *env,
    t_libui_window *window, SDL_Event *e);
t_libui_internal_event_handler  libui_event_get_handler(
    const t_libui_event_handler_map *map, Uint32 type);

#endif