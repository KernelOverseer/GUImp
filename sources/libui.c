/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:28:51 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 13:58:58 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int libui_init(t_libui_env *env)
{
	ft_bzero(env, sizeof(t_libui_env));
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		libui_set_error("Cannot initialize the graphical server\n");
		return (0);
	}
	ttslist_init(&env->windows);
	return (1);
}
