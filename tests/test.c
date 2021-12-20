/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer.pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:24 by abiri             #+#    #+#             */
/*   Updated: 2021/12/20 17:07:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"
#include <stdio.h>

void test_button_event(void *internal_arg, void *user_arg)
{
	(void)internal_arg;
	printf("PRESSED BUTTON %p\n", user_arg);
}

// int main(int argc, char **argv)
// {
// 	t_libui_env	env;
// 	t_libui_window *window;
// 	t_libui_component *component;

// 	// if (!libui_get_error())
// 	// 	printf("SUCCESS INITIALIZING\n");
// 	// else
// 	// 	printf("ERRORS : %s\n", libui_get_error());
// 	// libui_main_loop(&env);
// 	// return (0);
	
// //	t_libui_env	env;
// 	// t_libui_window *window;
	
// 	libui_init(&env);
// 	window = ft_memalloc(sizeof(t_libui_window));
// 	libui_window_init(window);
// 	window->props.title = ft_strdup("libui window test");
// 	window->props.flags = SDL_WINDOW_RESIZABLE;
// 	libui_window_create(&env, window);
// 	t_libui_component	*root_div;
// 	root_div = libui_new_div((t_libui_style){
// 		.width=window->props.width,
// 		.height=window->props.height
// 	});
// 	component = libui_new_button((t_libui_style){
// 		.height=50,
// 		.width=100,
// 		.pos_x=window->props.width/2 - 50,
// 		.pos_y=window->props.height/2 - 25,
// 	});
// 	component->status.id = "FIRST";
// 	component->status.class = "main-button";
// 	libui_window_insert_component(window, root_div);
// 	libui_component_insert_component(root_div, component);
// 	component->user_events.on_click.handler = test_button_event;
// 	component->user_events.on_click.arg = (void *)0xFF00FF;
// 	component = libui_new_button((t_libui_style){
// 		.height=50,
// 		.width=100,
// 		.pos_x=window->props.width/2 - 150,
// 		.pos_y=window->props.height/2 - 100,
// 	});
// 	component->status.id = "SECOND";
// 	component->status.class = "main-button special-button";
// 	libui_component_insert_component(root_div, component);
// 	if (!libui_get_error())
// 		printf("SUCCESS INITIALIZING\n");
// 	else
// 		printf("ERRORS : %s\n", libui_get_error());

// 	component = libui_new_checkbox((t_libui_style){});
// 	libui_component_insert_component(root_div, component);

// 	t_libui_component	*radio_div;
// 	radio_div = libui_new_div((t_libui_style){});
// 	radio_div->status.id = "radio_div";
// 	libui_component_insert_component(root_div, radio_div);
// 	component = libui_new_radio((t_libui_style){});
// 	component->status.id = "radio1";
// 	libui_component_insert_component(radio_div, component);
// 	component = libui_new_radio((t_libui_style){});
// 	component->status.id = "radio2";
// 	libui_component_insert_component(radio_div, component);
// 	component = libui_new_radio((t_libui_style){});
// 	component->status.id = "radio3";
// 	libui_component_insert_component(radio_div, component);

// 	t_css_context	*css_context;

// 	css_context = css_parse_file("./tests/test_css.css");
// 	if (css_context)
// 		printf("SUCCESS style parsed\n");
// 	if (css_apply_to_window(window, css_context))
// 		printf("STYLE \e[32mapplied\e[0m\n");
// 	else
// 		printf("STYLE \e[31merror\e[0m\n");
// 	libui_main_loop(&env);
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_libui_env	env;
	t_libui_window *window;
	t_libui_component *component;
	
	libui_init(&env);

	libui_font_manager_open(&env.font_manager, "./fonts/raleway/Raleway-Light.ttf");
	libui_font_manager_open(&env.font_manager, "./fonts/roboto/Roboto_test.ttf");
	libui_font_manager_open(&env.font_manager, "./fonts/open-sans/OpenSans-Light.ttf");

	window = ft_memalloc(sizeof(t_libui_window));
	libui_window_init(window);
	window->props.title = ft_strdup("libui window test");
	window->props.flags = SDL_WINDOW_RESIZABLE;
	libui_window_create(&env, window);

	// Checking for initialization errors
	if (!libui_get_error())
		printf("SUCCESS INITIALIZING\n");
	else
		printf("ERRORS : %s\n", libui_get_error());

	// Created a root div
	t_libui_component	*root_div;
	root_div = libui_new_div((t_libui_style){
		.width=window->props.width,
		.height=window->props.height
	});
	libui_window_insert_component(window, root_div);

	// Created a new text
	component = libui_new_text((t_libui_style){
		.height=50,
		.width=100,
		.pos_x=window->props.width/4 - 50,
		.pos_y=window->props.height/4 - 25,
		.font_family=NULL,
	});
	component->data = ft_strdup("hello there");
	component->status.id = "TEXT";
	libui_component_insert_component(root_div, component);

	// Created a new button
	component = libui_new_button((t_libui_style){
		.height=50,
		.width=100,
		.pos_x=window->props.width/2 - 50,
		.pos_y=window->props.height/2 - 25,
	});
	component->status.id = "FIRST";
	component->status.class = "main-button";
	component->user_events.on_click.handler = test_button_event;
	component->user_events.on_click.arg = (void *)0xFF00FF;
	libui_component_insert_component(root_div, component);

	// Creating text inside the button
	t_libui_component	*text;
	text = libui_new_text((t_libui_style){
		.font_family=NULL,
	});
	text->status.id = "button_label";
	text->data = ft_strdup("Click Me !");
	libui_component_insert_component(component, text);

	// Creating a checkbox
	component = libui_new_checkbox((t_libui_style){});
	libui_component_insert_component(root_div, component);

	// Creating a div for radio buttons
	t_libui_component	*radio_div;
	radio_div = libui_new_div((t_libui_style){});
	radio_div->status.id = "radio_div";
	libui_component_insert_component(root_div, radio_div);

	// Creating radio button 1
	component = libui_new_radio((t_libui_style){});
	component->status.id = "radio1";
	libui_component_insert_component(radio_div, component);


	// Creating radio button 2
	component = libui_new_radio((t_libui_style){});
	component->status.id = "radio2";
	libui_component_insert_component(radio_div, component);

	// Creating radio button 3
	component = libui_new_radio((t_libui_style){});
	component->status.id = "radio3";
	libui_component_insert_component(radio_div, component);

	// Parsing the CSS into a new css_context
	t_css_context	*css_context;
	css_context = css_parse_file("./tests/test_css.css");
	if (css_context)
		printf("SUCCESS style parsed\n");
	
	// Applying the CSS
	if (css_apply_to_window(window, css_context))
		printf("STYLE \e[32mapplied\e[0m\n");
	else
		printf("STYLE \e[31merror\e[0m\n");

	// Calling the main loop
	libui_main_loop(&env);
	return (0);
}
