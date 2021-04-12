/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:32:35 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 15:45:33 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# define LIBUI_NATIVE_EVENT_COUNT   3

typedef struct  s_libui_event
{
    int         type;
    int         mouseX;
    int         mouseY;
    int         keycode;
}               t_libui_event;

typedef int (*t_libui_event_handler)(void *component, t_libui_event event_data, void *args);

#endif