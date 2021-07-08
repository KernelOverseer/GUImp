/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components_user_events.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:51:51 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 15:01:03 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void    libui_component_user_event_call(t_libui_component_user_event event,
    void *internal_arg)
{
    if (event.handler)
        event.handler(internal_arg, event.arg);
}