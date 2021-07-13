/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_sheet.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:01:35 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 16:05:39 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_SHEET_H
# define STYLE_SHEET_H
# include "libui.h"
# define STYLE_QUERY_TAG 0
# define STYLE_QUERY_CLASS 1
# define STYLE_QUERY_ID 2

typedef struct  s_libui_color_preset
{
    char        *name;
    Uint32      color;
}               t_libui_color_preset;

typedef int     (*t_libui_css_prop_handler)(t_css_prop *prop,
    t_libui_raw_style *style);

typedef struct  s_libui_css_prop_handler_map
{
    char                        *name;
    t_libui_css_prop_handler    handler;
}               t_libui_css_prop_handler_map;


extern const t_libui_css_prop_handler_map   g_libui_css_prop_handlers[];
extern const t_libui_color_preset           g_libui_color_presets[];

t_style_prop    css_parse_color(char *value);
int             parse_int(int *value, char *str);
t_style_prop    css_parse_size(char *value);
int             css_apply_to_window(t_libui_window *window, t_css_context *css);

#endif