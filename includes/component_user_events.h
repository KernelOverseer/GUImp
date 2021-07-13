/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component_user_events.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:40:40 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 14:58:56 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPONENT_USER_EVENTS_H
# define COMPONENT_USER_EVENTS_H

typedef void    (*t_libui_component_user_event_handler)(void *internal_arg,
    void *user_arg);

typedef struct  s_libui_component_user_event
{
    t_libui_component_user_event_handler    handler;
    void                                    *arg;
}               t_libui_component_user_event;

typedef struct  s_libui_component_user_events
{
    t_libui_component_user_event    on_click;
    t_libui_component_user_event    on_submit;
    t_libui_component_user_event    on_change;
}               t_libui_component_user_events;


#endif