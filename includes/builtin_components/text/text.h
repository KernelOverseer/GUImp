/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:50:47 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:09:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_H
# define TEXT_H
# include "libui.h"
# include "builtin_commons.h"

t_libui_component   *libui_new_text(t_libui_style props);
int                 libui_text_draw(t_libui_component *component);

/*
**  External Button API
*/

/*
**  Internal Button API
*/

void    libui_text_load_mouse_events(t_libui_component *component);
void    libui_text_load_wheel_events(t_libui_component *component);
void    libui_text_load_keyboard_events(t_libui_component *component);
void    libui_text_load_style(t_libui_component *text);
#endif