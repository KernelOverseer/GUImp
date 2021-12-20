/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer.pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:07:00 by azouiten          #+#    #+#             */
/*   Updated: 2021/12/20 16:46:07 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int     libui_font_manager_init(t_libui_env *env)
{
    if (TTF_Init() < 0)
    {
        libui_set_error("Cannot initialize font library\n");
        return (0);
    }
    ttslist_init(&env->font_manager.fonts);
    return (1);
}

t_font  *libui_font_manager_open(t_font_manager *manager, char *path)
{
    t_font  *font;

    font = ft_memalloc(sizeof(t_font));
    if (!font)
        return (NULL);
    font->font = TTF_OpenFont(path, FONT_PTSIZE);
    if (!font->font)
        return (free(font), NULL);
    font->path = ft_strdup(path);
    font->family_name = TTF_FontFaceFamilyName(font->font);
    font->style_name = TTF_FontFaceStyleName(font->font);
    font->style = TTF_GetFontStyle(font->font);
    printf("Opened new font : %s, %s\n", font->family_name, font->style_name);
    manager->fonts.push(&manager->fonts, font);
    return (font);
}