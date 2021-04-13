/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:32:35 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 17:39:21 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# define LIBUI_NATIVE_EVENT_COUNT   3

typedef struct  s_libui_event
{
    int         type;
    int         mouse_x;
    int         mouse_y;
    int         scancode;
}               t_libui_event;

typedef int (*t_libui_event_handler)(void *component, t_libui_event event_data, void *args);

#endif