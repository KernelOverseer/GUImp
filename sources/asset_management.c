/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:00:46 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 11:38:36 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_libui_asset_font  *libui_asset_load_font(t_libui_env *env, char *name)
{
    t_libui_asset_font  *font_asset;
    TTF_Font            *new_font;

    if (!(new_font = TTF_OpenFont(name, 26)))
        return (NULL);
    if (!(font_asset = ft_memalloc(sizeof(t_libui_asset_font))))
        return (NULL);
    font_asset->name = ft_strdup(name);
    font_asset->fonts[0] = new_font;
    ttslist_push_new(&env->assets.fonts, font_asset);
    return (font_asset);
}

t_libui_asset_font  *libui_asset_get_font(t_libui_env *env, char *name)
{
    t_list_head         fonts;
    t_libui_asset_font  *font;

    fonts = env->assets.fonts;
    fonts.iterator = fonts.first;
    while ((font = ttslist_iter_content(&fonts)))
    {
        if (!ft_strcmp(font->name, name))
            return (font);
    }
    return (libui_asset_load_font(env, name));
}