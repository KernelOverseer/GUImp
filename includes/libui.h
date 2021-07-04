/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:42:51 by abiri             #+#    #+#             */
/*   Updated: 2021/07/04 18:36:17 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H
# include <SDL.h>
# include <SDL_ttf.h>
# include "libft.h"
# include "ttslist.h"
# include "typedefs.h"
# include "ft_simplesdl.h"
# include "events.h"
# include "windows.h"
# include "components.h"

struct  s_libui_env
{
    t_sdl_env       *sdl_env;
    t_libui_window  *focused_window;
    t_list_head     windows;
    int         quit;
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

/*
**  libui internal API
*/

void            libui_draw(t_libui_env *env);

#endif