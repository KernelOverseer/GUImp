/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:43:03 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 15:36:43 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_init(t_libui_env  *env)
{
    ft_bzero(env, sizeof(t_libui_env));
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        libui_set_error("Cannot initialize the gtraphical server\n");
        return (0);
    }
    if (TTF_Init() < 0)
    {
        libui_set_error("Cannot initialize font library\n");
        return (0);
    }
    ttslist_init(&env->windows);
    return (1);
}