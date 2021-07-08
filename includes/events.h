/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:11:38 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 15:00:28 by abiri            ###   ########.fr       */
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

struct          s_libui_window_events
{
    t_libui_window_event_handler    close;
    t_libui_window_event_handler    resize;
    t_libui_window_event_handler    moved;
    t_libui_window_event_handler    exposed;
    t_libui_window_event_handler    minimized;
    t_libui_window_event_handler    restored;
    t_libui_window_event_handler    focus;
    t_libui_window_event_handler    lose_focus;
};


struct          s_libui_event_handler_map
{
    Uint32                              type;
    t_libui_window_event_handler        handler;
};

struct          s_libui_component_event_handler_map
{
    Uint32                              type;
    t_libui_event_handler               handler;
};


extern const t_libui_component_event_handler_map g_component_internal_events[];
extern const t_libui_event_handler_map  g_windows_internal_events[];

/*
**  Internal Window Events
*/

int libui_components_event_dispatcher(t_libui_env *env, SDL_Event *e);
int libui_windows_event_dispatcher(t_libui_env *env, SDL_Event *e);
int libui_windows_event_handler_size_changed(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_focus_gained(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_focus_lost(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_mouse_leave(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_mouse_enter(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_close(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_moved(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_exposed(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_minimized(t_libui_window *window, SDL_Event *e);
int libui_windows_event_handler_restored(t_libui_window *window, SDL_Event *e);

t_libui_window_event_handler  libui_event_get_handler(
    const t_libui_event_handler_map *map, Uint32 type);
t_libui_event_handler    libui_component_event_get_handler(
    const t_libui_component_event_handler_map *map, Uint32 type);

/*
**  Internal component interaction Events
*/

int libui_component_call_event(t_libui_component_event_handler handler,
    t_libui_component *component, SDL_Event *e);
int libui_components_event_handler_mouse_down(t_libui_env *env, SDL_Event *e);
int libui_components_event_handler_mouse_up(t_libui_env *env, SDL_Event *e);
int libui_components_event_handler_mouse_motion(t_libui_env *env, SDL_Event *e);
int libui_components_event_handler_scroll(t_libui_env *env, SDL_Event *e);
int libui_components_event_handler_key_up(t_libui_env *env, SDL_Event *e);
int libui_components_event_handler_key_down(t_libui_env *env, SDL_Event *e);
t_libui_component   *libui_components_get_from_mouse(t_libui_window *window,
    int x, int y);

/*
**  Component User Events
*/

void libui_component_user_event_call(t_libui_component_user_event event,
    void *internal_arg);

#endif