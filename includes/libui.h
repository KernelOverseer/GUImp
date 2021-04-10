/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:51 by abiri             #+#    #+#             */
/*   Updated: 2021/04/10 18:38:23 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H
# include "ft_simplesdl.h"
# include "libft.h"
# include "ttslist.h"

/*
**================================ STRUCTS ====================================
*/

typedef	struct	s_libui_env
{
	t_list_head		windows;
	unsigned char	quit;
}				t_libui_env;

typedef struct	s_libui_window_props
{
	char		*title;
	size_t		width;
	size_t		height;
	int			pos_x;
	int			pos_y;
	int			sdl_flags;
}				t_libui_window_props;

typedef struct	s_libui_window
{
	SDL_Window				*sdl_window;
	SDL_Renderer			*sdl_renderer;
	SDL_Texture				*sdl_texture;
	t_libui_window_props	props;
}				t_libui_window;

/*
**============================== LIBRARY API ==================================
*/

/*
**	Initialization
*/

int		libui_init(t_libui_env *env);

/*
**	Events
*/

int		libui_main_loop(t_libui_env *env);

/*
**	Windows
*/

void	libui_window_set_position(t_libui_window *win, int pos_x, int pos_y);
void	libui_window_set_title(t_libui_window *win, char *title);
void	libui_window_set_size(t_libui_window *win, int width, int height);
void	libui_window_init(t_libui_window *win);
int		libui_window_create(t_libui_env *env, t_libui_window *win);

/*
**	Error Management
*/

char	*libui_get_error(void);

/*
**================================ PRIVATE ====================================
*/

/*
**	Initialization
*/



/*
**	Error Management
*/

char	*libui_set_error(char *error);

#endif
