/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:33:31 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 18:17:57 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	libui_main_loop(t_libui_env *env)
{
	SDL_Event	e;

	while (!env->quit)
	{
		while (libui_event_poll(env))
		{
			// do something
		}
		libui_draw_loop(env);
	}
	return (1);
}