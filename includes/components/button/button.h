/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:00:14 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 19:07:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H
# include "libui.h"

typedef struct  s_libui_component_button_data
{
    char        *name;
}               t_libui_component_button_data;

int     libui_component_button_event_on_mouse_in(void *component,
    t_libui_event event_data, void *args);
int     libui_component_button_event_on_mouse_out(void *component,
    t_libui_event event_data, void *args);
int     libui_component_button_event_on_mouse_move(void *component,
    t_libui_event event_data, void *args);
int     libui_component_button_event_on_mouse_click(void *component,
    t_libui_event event_data, void *args);
int     libui_component_button_event_on_mouse_release(void *component,
    t_libui_event event_data, void *args);
#endif