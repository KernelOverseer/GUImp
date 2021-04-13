/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:24 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 18:58:55 by abiri            ###   ########.fr       */
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

	t_libui_window	window;

	libui_window_init(&window);
	libui_window_set_size(&window, 500, 500);
	libui_window_set_title(&window, "Hello There");
	if (!libui_window_create(&ui_env, &window))
	{
		printf("ERROR : %s\n", libui_get_error());
		return (1);
	}

	// t_libui_window	window2;

	// libui_window_init(&window2);
	// libui_window_set_size(&window2, 500, 500);
	// libui_window_set_title(&window2, "Hello There 2");
	// if (!libui_window_create(&ui_env, &window2))
	// {
	// 	printf("ERROR : %s\n", libui_get_error());
	// 	return (1);
	// }

/*
**	To do:
**		Expose the api functions for creating a button,
**		Make a drawing loop to see the button
*/

	t_libui_component	*new_button;
	t_libui_component	*new_button2;
	t_libui_component	*new_div;

	new_button = libui_create_button_default();
	new_button2 = libui_create_button_default();
	new_button2->props.posX += 100;
	new_div = libui_create_div_default();
	libui_window_insert_component(&window, new_div);
	libui_component_insert_component(new_div, new_button);
	libui_component_insert_component(new_div, new_button2);


	// new_button = libui_create_button_default();
	// new_button2 = libui_create_button_default();
	// new_button2->props.posX += 250;
	// new_div = libui_create_div_default();
	// libui_component_insert_component(new_div, new_button);
	// libui_component_insert_component(new_div, new_button2);
	libui_main_loop(&ui_env);
	return (0);
}
