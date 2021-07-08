/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:42:51 by abiri             #+#    #+#             */
/*   Updated: 2021/07/08 14:59:25 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H
# include <SDL.h>
# include <SDL_ttf.h>
# include "libft.h"
# include "ttslist.h"
# include "ft_simplesdl.h"
# include "default_theme.h"
# include "component_user_events.h"
# include "typedefs.h"
# include "input_tools.h"
# include "events.h"
# include "windows.h"
# include "components.h"
# include "button.h"

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

/*
**  libui internal API
*/

void            libui_draw(t_libui_env *env);

#endif