/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:50:47 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:09:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIV_H
# define DIV_H
# include "libui.h"
# include "builtin_commons.h"

t_libui_component   *libui_new_div(t_libui_style props);
int                 libui_div_draw(t_libui_component *component);

/*
**  External Button API
*/

/*
**  Internal Button API
*/

void    libui_div_load_mouse_events(t_libui_component *component);
void    libui_div_load_wheel_events(t_libui_component *component);
void    libui_div_load_keyboard_events(t_libui_component *component);
void    libui_div_load_style(t_libui_component *div);
#endif