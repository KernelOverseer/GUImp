/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonts_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer.pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:53:40 by abiri             #+#    #+#             */
/*   Updated: 2021/12/20 16:06:39 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_font  *libui_get_default_font(t_font_manager *manager)
{
    if (manager->fonts.first)
        return (manager->fonts.first->content);
    return (NULL);
}

t_font  *libui_get_font(t_font_manager *manager, char *family, char *style)
{
    t_list_head font_list;
    t_font      *font;

    if (!family)
        return (libui_get_default_font(manager));
    font_list = manager->fonts;
    font_list.iterator = font_list.first;
    while ((font = ttslist_iter_content(&font_list)))
    {
        if (ft_strequ(font->family_name, family))
        {
            if (!style || ft_strequ(font->style_name, style))
                return (font);
        }
    }
    return (libui_get_default_font(manager));
}