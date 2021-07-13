/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: azouiten <azouiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:42:51 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 16:07:24 by azouiten         ###   ########.fr       */
=======
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:42:51 by abiri             #+#    #+#             */
/*   Updated: 2021/07/12 21:18:14 by abiri            ###   ########.fr       */
>>>>>>> 44328d0a02c94ebf576bfa938ab4efa9c9a57c83
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H
# include <SDL.h>
# include <SDL_ttf.h>
# include "libft.h"
# include "ttslist.h"
# include "css_parser.h"
# include "ft_simplesdl.h"
# include "default_theme.h"
# include "style.h"
# include "style_sheet.h"
# include "component_user_events.h"
# include "typedefs.h"
# include "input_tools.h"
# include "events.h"
# include "windows.h"
# include "components.h"
# include "button.h"
# include "font.h"

struct  s_libui_env
{
    t_list_head         windows;
    t_libui_window      *active_window;
    t_libui_component   *active_component;
    t_libui_component   *hovered_component;
    t_libui_component   *focused_component;
    int                 quit;
};


/*
**  libui api
*/

int                 libui_init(t_libui_env *env);
char                *libui_set_error(char *error);
char                *libui_get_error(void);
t_libui_window      *libui_defaults_create_window(t_libui_env *env);
t_libui_component   *libui_defaults_create_component(void);
int                 libui_main_loop(t_libui_env *env);
t_libui_component   *libui_component_get_by_id(t_libui_window *window, char *id);

/*
**  libui internal API
*/

void            libui_draw(t_libui_env *env);
void            libui_draw_blit_image(t_rect pos, t_sdl_image *canvas,
    t_sdl_image *image);

#endif