/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:52:56 by abiri             #+#    #+#             */
/*   Updated: 2021/04/13 19:13:43 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
**	Changes the window height
**	!! Should only be used before creating a window
*/

void			libui_window_set_position(t_libui_window *win,
		int pos_x, int pos_y)
{
	win->props.pos_x = pos_x;
	win->props.pos_y = pos_y;
}

void			libui_window_set_title(t_libui_window *win,
		char *title)
{
	if (!title)
		return ;
	free(win->props.title);
	win->props.title = ft_strdup(title);
}

void			libui_window_set_size(t_libui_window *win,
		int width, int height)
{
	if (width < 0 || height < 0)
		return ;
	win->props.width = width;
	win->props.height = height;
}

void			libui_window_init(t_libui_window *win)
{
	ft_bzero(win, sizeof(t_libui_window));
	win->props = (t_libui_window_props){.title=NULL,
		.width=500,
		.height=500,
		.pos_x = SDL_WINDOWPOS_UNDEFINED,
		.pos_y = SDL_WINDOWPOS_UNDEFINED,
		.sdl_flags = SDL_WINDOW_SHOWN
	};
	ttslist_init(&win->components);
}

static int		libui_window_create_renderer_texture(t_libui_window *win)
{
	if (!(win->sdl_renderer = SDL_CreateRenderer(win->sdl_window, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		libui_set_error("Cannot create renderer for window\n");
		return (0);
	}
	if (!(win->sdl_texture = SDL_CreateTexture(win->sdl_renderer,
					SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC,
					win->props.width, win->props.height)))
	{
		libui_set_error("Cannot create texture for window\n");
		return (0);
	}
	return (1);
}

int				libui_window_create(t_libui_env *env, t_libui_window *win)
{
	if (!win)
		return (0);
	win->sdl_window = SDL_CreateWindow(win->props.title, win->props.pos_x,
			win->props.pos_y, win->props.width,
			win->props.height, win->props.sdl_flags);
	if (!win->sdl_window)
	{
		libui_set_error("Cannot create new window\n");
		return (0);
	}
	if (!libui_window_create_renderer_texture(win))
	{
		libui_set_error("Cannot get texture from window\n");
		return (0);
	}
	win->main_image = newimage(win->props.width, win->props.height);
	if (!win->main_image)
	{
		libui_set_error("Cannot allocate image for window\n");
		return (0);
	}
	env->windows.push(&(env->windows), win);
	return (1);
}

int				libui_window_insert_component(t_libui_window *win,
	t_libui_component *component)
{
	if (!component || !win)
		return (0);
	component->window = win;
	win->components.push(&(win->components), component);
	return (1);
}