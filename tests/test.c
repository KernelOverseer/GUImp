/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:24 by abiri             #+#    #+#             */
/*   Updated: 2021/04/10 18:37:11 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int main(void)
{
	t_libui_env	ui_env;
	
	if (!libui_init(&ui_env))
	{
		printf("ERROR : %s\n", libui_get_error());
		return (1);
	}

	t_libui_window window;

	libui_window_init(&window);
	libui_window_set_size(&window, 300, 100);
	libui_window_set_title(&window, "Hello There");
	if (!libui_window_create(&ui_env, &window))
	{
		printf("ERROR : %s\n", libui_get_error());
		return (1);
	}
	libui_main_loop(&ui_env);
	return (0);
}
