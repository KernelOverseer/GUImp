/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer.pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:22:41 by abiri             #+#    #+#             */
/*   Updated: 2021/12/20 17:01:12 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static void libui_draw_text(t_libui_component *text)
{
    printf("font family : %s\n", text->style.font_family);
    t_font  *font;

    font = libui_get_font(&text->window->env->font_manager,
        text->style.font_family, NULL);
    if (font)
        printf("drawing using font : %s %s\n", font->family_name, font->style_name);
    if (text->data)
        libui_builtin_draw_text(text->data, font, text->image, &text->style);
}

int libui_text_draw(t_libui_component *component)
{
    libui_component_recalculate_image(component);
    ft_bzero(component->image->pixels, sizeof(Uint32) *
        component->image->width * component->image->height);
    libui_builtin_draw_background(component);
    libui_draw_text(component);
    return (0);
}