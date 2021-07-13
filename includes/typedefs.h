/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 14:48:22 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 16:33:54 by azouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct  s_libui_env t_libui_env;
typedef struct  s_libui_window_props t_libui_window_props;
typedef struct  s_libui_window t_libui_window;
typedef struct  s_libui_component t_libui_component;
typedef int     (*t_libui_event_handler)(t_libui_env *env, SDL_Event *e);
typedef int     (*t_libui_component_draw_handler)(t_libui_component *component);
typedef int     (*t_libui_component_event_handler)(t_libui_component *component,
    SDL_Event *e);
typedef int     (*t_libui_window_event_handler)(t_libui_window *window,
    SDL_Event *e); // hmmm
typedef struct  s_libui_event_handler_map t_libui_event_handler_map;
typedef struct  s_libui_component_event_handler_map
    t_libui_component_event_handler_map;
typedef struct  s_libui_component_events t_libui_component_events;
typedef struct  s_libui_window_events   t_libui_window_events;
#endif