/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 10:56:25 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 11:28:18 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H
# define FONT_TYPES_COUNT 1
# include "libui.h"

enum    e_libui_font_weights
{
    LIBUI_FONT_REGULAR
};


typedef struct  s_libui_asset_font
{
    char        *name;
    TTF_Font    *fonts[FONT_TYPES_COUNT];
}               t_libui_asset_font;


typedef struct  s_libui_assets
{
    t_list_head fonts;
}               t_libui_assets;

#endif