/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:44:54 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 18:19:54 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int         libui_component_apply_event(t_libui_component *component,
    t_libui_event_handler handler, t_libui_event event)
{
    if (component && handler)
        return (handler(component, event, NULL));
    return (0);
}

t_libui_event libui_event_create_from_sdl(SDL_Event *e)
{
    t_libui_event result;

    result.type = e->type;
    SDL_GetMouseState(&result.mouse_x, &result.mouse_y);
    result.scancode = e->key.keysym.scancode;
    return (result);
}

int libui_event_dispatch_for_window(t_libui_env *env, SDL_Event *e,
    t_libui_window *window)
{
    t_libui_event_dispatcher    process_event;

    process_event = libui_event_get_dispatcher_from_type(e->type);
    if (!process_event)
        return (0);
    return (process_event(env, window, e));
}

int libui_event_dispatch(t_libui_env *env, SDL_Event *e)
{
    t_libui_window  *window;

    window = libui_window_get_by_index(env, e->window.windowID);
    if (!window)
        return (1);
    libui_event_dispatch_for_window(env, e, window);
    return (1);
}

int libui_event_poll(t_libui_env *env)
{
    SDL_Event   e;

    if (!SDL_PollEvent(&e))
        return (0);
    // TEMP FOR EXITING
    if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		env->quit = 1;
    return (libui_event_dispatch(env, &e));
}