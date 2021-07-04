/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 23:38:29 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 19:48:39 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

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
    return (component);
}