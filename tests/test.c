/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:24 by abiri             #+#    #+#             */
/*   Updated: 2021/07/11 02:49:16 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include <stdio.h>

void test_button_event(void *internal_arg, void *user_arg)
{
	(void)internal_arg;
	printf("PRESSED BUTTON %p\n", user_arg);
}

int main(int argc, char **argv)
{
	t_style_prop	prop;
	prop = css_parse_color(argv[1]);
	if (prop.type == STYLE_RELATIVE)
		printf("%f of the parent\n", prop.value.decimal);
	else
		printf("%d px\n", prop.value.integer);
	return (0);
	t_libui_env	env;
	t_libui_window *window;
	t_libui_component *component;

	libui_init(&env);
	window = ft_memalloc(sizeof(t_libui_window));
	libui_window_init(window);
	window->props.title = ft_strdup("libui window test");
	window->props.flags = SDL_WINDOW_RESIZABLE;
	libui_window_create(&env, window);
	component = libui_new_button((t_libui_style){
		.height=50,
		.width=100,
		.pos_x=window->props.width/2 - 50,
		.pos_y=window->props.height/2 - 25,
	});
	libui_window_insert_component(window, component);
	component->user_events.on_click.handler = test_button_event;
	component->user_events.on_click.arg = (void *)0xFF00FF;
	if (!libui_get_error())
		printf("SUCCESS INITIALIZING\n");
	else
		printf("ERRORS : %s\n", libui_get_error());
	libui_main_loop(&env);
	return (0);
}
