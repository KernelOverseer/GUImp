/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:24 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 14:28:45 by azouiten         ###   ########.fr       */
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
	// t_libui_env	env;
	// t_libui_window *window;

	// libui_init(&env);
	// window = ft_memalloc(sizeof(t_libui_window));
	// libui_window_init(window);
	// window->props.title = ft_strdup("libui window test");
	// window->props.flags = SDL_WINDOW_RESIZABLE;
	// libui_window_create(&env, window);

	// t_libui_component	*component;
	// t_libui_component	*component2;
	// component = libui_defaults_create_component();
	// libui_window_insert_component(window, component);	
	// component = libui_defaults_create_component();
	// component->style.pos_x += 200;
	// libui_window_insert_component(window, component);	
	// window = libui_defaults_create_window(&env);
	// component = libui_defaults_create_component();
	// libui_window_insert_component(window, component);	
	// component2 = libui_defaults_create_component();
	// component2->style.width = 500;
	// component2->style.height = 50;
	// libui_component_insert_component(component, component2);
	// component = libui_new_button((t_libui_style){
	// 	.background_color=0xCDCDCD,
	// 	.height=50,
	// 	.width=100,
	// 	.pos_x=window->props.width/2 - 50,
	// 	.pos_y=window->props.height/2 - 25,
	// });
	// libui_window_insert_component(window, component);

	// if (!libui_get_error())
	// 	printf("SUCCESS INITIALIZING\n");
	// else
	// 	printf("ERRORS : %s\n", libui_get_error());
	// libui_main_loop(&env);
	// return (0);
	
	t_libui_env	env;
	// t_libui_window *window;
	
	libui_init(&env);
	// window = ft_memalloc(sizeof(t_libui_window));
	// libui_window_init(window);
	// window->props.title = ft_strdup("just testing stuff");
	// window->props.flags = SDL_WINDOW_RESIZABLE;
	// libui_window_create(&env, window);
	// font_manager("blob the fish", "raleway", BOLD_FONT);
	// libui_main_loop(&env);

	font_manager("/Users/azouiten/Desktop/GUImp/fonts/raleway/Raleway-ExtraLight.ttf");
	return (0);
}