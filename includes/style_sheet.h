/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style_sheet.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:01:35 by abiri             #+#    #+#             */
/*   Updated: 2021/07/10 20:43:59 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_SHEET_H
# define STYLE_SHEET_H
# include "libui.h"

typedef struct  s_libui_color_preset
{
    char        *name;
    Uint32      color;
}               t_libui_color_preset;

extern const t_libui_color_preset g_libui_color_presets[];

t_style_prop    css_parse_color(char *value);

#endif