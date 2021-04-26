/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:29:51 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 11:42:58 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H
# include "ft_simplesdl.h"
# include "libft.h"
# include "ttslist.h"
# include "events.h"
# include "style.h"
# include "components.h"
# include "assets.h"
# include "components/text/text.h"

/*
**================================ STRUCTS ====================================
*/

typedef	struct	s_libui_env
{
	t_list_head		windows;
	t_libui_assets	assets;
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
	t_sdl_image				*main_image;
	t_list_head				components;
	t_libui_window_props	props;
	t_libui_component		*focused_component;
	t_libui_component		*hovered_component;
	t_libui_env				*env;
}				t_libui_window;

typedef int		(*t_libui_event_dispatcher)(t_libui_env *env, t_libui_window *window, SDL_Event *e); 

typedef struct  s_libui_event_dispatcher_map
{
    Uint32                      event_type;
    t_libui_event_dispatcher    dispatcher;
}               t_libui_event_dispatcher_map;

extern const    t_libui_event_dispatcher_map    g_libui_event_dispatcher_map[LIBUI_NATIVE_EVENT_COUNT];

/*
**============================== LIBRARY API ==================================
*/

/*
**	Initialization
*/

int		libui_init(t_libui_env *env);

/*
**	Constructors
*/

t_libui_component   *libui_create_button_default(void);
t_libui_component   *libui_component_button_new(t_libui_component_props props);
t_libui_component   *libui_create_div_default(void);
t_libui_component   *libui_component_div_new(t_libui_component_props props);
int					libui_window_insert_component(t_libui_window *win,
	t_libui_component *component);
int				    libui_component_insert_component(t_libui_component *parent,
    		t_libui_component *child);

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
**	Event management
*/

int         libui_component_apply_event(t_libui_component *component,
    t_libui_event_handler handler, t_libui_event event);
t_libui_event libui_event_create_from_sdl(SDL_Event *e);
int		libui_event_poll(t_libui_env *env);
int     libui_event_dispatcher_on_mouse_click(t_libui_env *env, t_libui_window *window,
                        SDL_Event *e);
int     libui_event_dispatcher_on_mouse_release(t_libui_env *env, t_libui_window *window,
                        SDL_Event *e);
int     libui_event_dispatcher_on_mouse_move(t_libui_env *env, t_libui_window *window,
                        SDL_Event *e);

/*
**	Drawing
*/

int		libui_draw_loop(t_libui_env *env);

/*
**	Helper Functions
*/

t_libui_component   *libui_event_get_hovered_component_in_window(
    t_libui_window *window, int mouse_x, int mouse_y);
t_libui_window  *libui_window_get_by_index(t_libui_env *env, int id);
t_libui_event_dispatcher    libui_event_get_dispatcher_from_type(Uint32 type);
t_libui_asset_font  *libui_asset_get_font(t_libui_env *env, char *name);
int libui_draw_image_blit(t_sdl_image *canvas, t_sdl_image *to_draw, t_rect off);

/*
**	Error Management
*/

char	*libui_set_error(char *error);

#endif
