/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 18:12:07 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 19:36:04 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void libui_draw_windows(t_libui_env *env)
{
    t_list_head     windows_list;
    t_libui_window  *window;

    windows_list = env->windows;
    windows_list.iterator = windows_list.first;
    while ((window = ttslist_iter_content(&windows_list)))
        libui_draw_window(window);
}

void            libui_draw(t_libui_env *env)
{
    libui_draw_windows(env);
}