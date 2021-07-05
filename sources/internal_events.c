/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:09:23 by abiri             #+#    #+#             */
/*   Updated: 2021/07/05 19:57:33 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_event_dispatch(t_libui_env *env, SDL_Event *e)
{
    if (e->type == SDL_WINDOWEVENT)
        return (libui_windows_event_dispatcher(env, e));
    else
        return (libui_components_event_dispatcher(env, e));
    return (0);
}

t_libui_window_event_handler  libui_event_get_handler(
    const t_libui_event_handler_map *map, Uint32 type)
{
    int i;

    i = 0;
    while (map[i].handler != NULL)
    {
        if (map[i].type == type)
            return (map[i].handler);
        i++;
    }
    return (NULL);
}

t_libui_event_handler    libui_component_event_get_handler(
    const t_libui_component_event_handler_map *map, Uint32 type)
{
    int i;

    i = 0;
    while (map[i].handler != NULL)
    {
        if (map[i].type == type)
            return (map[i].handler);
        i++;
    }
    return (NULL);
}

int libui_event_poll(t_libui_env *env)
{
    SDL_Event e;

    if (!SDL_PollEvent(&e))
        return (0);
    if (libui_event_dispatch(env, &e))
        return (1);
    // For now exiting is done this way
    if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        env->quit = 1;
    // Here dispatch events
    return (0);
}