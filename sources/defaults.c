/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 23:38:29 by abiri             #+#    #+#             */
/*   Updated: 2021/07/05 19:41:34 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int             libui_defaults_component_mouse_enter(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("ENTER\n");
    return (0); 
}

static int             libui_defaults_component_mouse_leave(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("LEAVE\n");
    return (0);
}

static int             libui_defaults_component_active(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("ACTIVE\n");
    return (0);
}

static int             libui_defaults_component_release(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("RELEASED\n");
    return (0);
}

static int             libui_defaults_component_focus(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("GAINED FOCUS\n");
    return (0);
}

static int             libui_defaults_component_loose_focus(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("LOST FOCUS\n");
    return (0);
}

static int             libui_defaults_component_scroll(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("SCROLLED\n");
    return (1);
}

static int              libui_defaults_component_key_down(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("KEY DOWN\n");
    return (1);
}

static int              libui_defaults_component_key_up(t_libui_component *component,
    SDL_Event *e)
{
    (void)component;
    (void)e;
    printf("KEY UP\n");
    return (1);
}

t_libui_window  *libui_defaults_create_window(t_libui_env *env)
{
    t_libui_window  *window;

    window = ft_memalloc(sizeof(t_libui_window));
    if (!window)
        return (NULL);
    libui_window_init(window);
    window->props.title = ft_strdup("libui");
    libui_window_create(env, window);
    return (window);
}

t_libui_component   *libui_defaults_create_component(void)
{
    t_libui_component   *component;

    component = ft_memalloc(sizeof(t_libui_component));
    if (!component)
        return (NULL);
    libui_component_init(component);
    component->draw = libui_component_draw_default;
    component->style.width = 100;
    component->style.height = 50;
    component->events.mouse_enter = libui_defaults_component_mouse_enter;
    component->events.mouse_leave = libui_defaults_component_mouse_leave;
    component->events.active = libui_defaults_component_active;
    component->events.release = libui_defaults_component_release;
    component->events.focus = libui_defaults_component_focus;
    component->events.lose_focus = libui_defaults_component_loose_focus;
    component->events.scroll = libui_defaults_component_scroll;
    component->events.key_down = libui_defaults_component_key_down;
    component->events.key_up = libui_defaults_component_key_up;
    return (component);
}