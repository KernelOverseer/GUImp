/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 13:17:39 by abiri             #+#    #+#             */
/*   Updated: 2021/07/15 13:54:24 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef radio_H
# define radio_H
# include "libui.h"
# include "builtin_commons.h"

t_libui_component   *libui_new_radio(t_libui_style props);
int                 libui_radio_draw(t_libui_component *component);

/*
**  External Button API
*/

/*
**  Internal Button API
*/

void    libui_radio_load_mouse_events(t_libui_component *component);
void    libui_radio_load_wheel_events(t_libui_component *component);
void    libui_radio_load_keyboard_events(t_libui_component *component);
void    libui_radio_load_style(t_libui_component *radio);
int     libui_radio_group_switch(t_libui_component *active);
#endif