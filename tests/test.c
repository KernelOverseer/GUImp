/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:24 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 13:33:14 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include <stdio.h>

int	test_loop_hook(void *arg)
{
	(void)arg;

	return (1);
}

int main(void)
{
	t_libui_env	env;
	t_libui_window *window;

	libui_init(&env);
	window = ft_memalloc(sizeof(t_libui_window));
	libui_window_init(window);
	window->props.title = ft_strdup("libui window test");
	window->props.flags = SDL_WINDOW_RESIZABLE;
	libui_window_create(&env, window);

	t_libui_component	*component;
	t_libui_component	*component2;
	component = libui_defaults_create_component();
	libui_window_insert_component(window, component);	
	component = libui_defaults_create_component();
	component->style.pos_x += 200;
	libui_window_insert_component(window, component);	
	window = libui_defaults_create_window(&env);
	component = libui_defaults_create_component();
	libui_window_insert_component(window, component);	
	component2 = libui_defaults_create_component();
	component2->style.width = 25;
	component2->style.height = 25;
	libui_component_insert_component(component, component2);
	component = libui_new_button((t_libui_style){
		.background_color=0xCDCDCD,
		.height=100,
		.width=200,
		.pos_x=window->props.width/2 - 100,
		.pos_y=window->props.height/2 - 50,
	});
	libui_window_insert_component(window, component);

	if (!libui_get_error())
		printf("SUCCESS INITIALIZING\n");
	else
		printf("ERRORS : %s\n", libui_get_error());
	libui_main_loop(&env);
	return (0);
}
