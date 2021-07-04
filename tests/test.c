/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:24 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 19:54:25 by abiri            ###   ########.fr       */
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
	component = libui_defaults_create_component();
	libui_window_insert_component(window, component);	

	if (!libui_get_error())
		printf("SUCCESS INITIALIZING\n");
	else
		printf("ERRORS : %s\n", libui_get_error());
	libui_main_loop(&env);
	return (0);
}
