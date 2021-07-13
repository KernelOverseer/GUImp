/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:16:58 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:13:05 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKBOX_H
# define CHECKBOX_H
# include "libui.h"
# include "builtin_commons.h"

t_libui_component   *libui_new_checkbox(t_libui_style props);
int                 libui_checkbox_draw(t_libui_component *component);

/*
**  External Button API
*/

/*
**  Internal Button API
*/

void    libui_checkbox_load_mouse_events(t_libui_component *component);
void    libui_checkbox_load_wheel_events(t_libui_component *component);
void    libui_checkbox_load_keyboard_events(t_libui_component *component);
void    libui_checkbox_load_style(t_libui_component *checkbox);
#endif