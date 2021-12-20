/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer.pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:42:49 by azouiten          #+#    #+#             */
/*   Updated: 2021/12/20 16:47:32 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FONT_H
# define FONT_H
# include <SDL.h>
# include "libft.h"
# include "ttslist.h"
# define FONT_PTSIZE 21

typedef struct  s_font_manager
{
    t_list_head fonts;
}               t_font_manager;

typedef struct  s_font
{
    char        *family_name;
    char        *style_name;
    char        *path;
    int         style;
    TTF_Font    *font;
}               t_font;

int     libui_font_manager_init(t_libui_env *env);
t_font  *libui_font_manager_open(t_font_manager *manager, char *path);
t_font  *libui_get_font(t_font_manager *manager, char *family, char *style);
int     libui_builtin_draw_text(char *text, t_font *font,
    t_sdl_image *image, t_libui_style *style);

#endif