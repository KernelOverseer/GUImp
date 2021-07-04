/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:05:03 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 18:33:54 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_main_loop(t_libui_env *env)
{
    while (!env->quit)
    {
        while (libui_event_poll(env))
            ;
        libui_draw(env);
    }
    return (1);
}