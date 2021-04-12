/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:44:54 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 15:56:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

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