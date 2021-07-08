/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:53:42 by abiri             #+#    #+#             */
/*   Updated: 2021/07/07 19:53:19 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H

typedef struct  s_libui_raw_style
{
    int             width;
    int             height;
    int             pos_x;
    int             pos_y;
    Uint32          background_color;
}               t_libui_raw_style;

typedef struct  s_libui_raw_styles
{
    t_libui_raw_style   regular;
    t_libui_raw_style   hovered;
    t_libui_raw_style   focused;
    t_libui_raw_style   active;
}               t_libui_raw_styles;


typedef struct  s_libui_style
{
    int                 width;
    int                 height;
    int                 pos_x;
    int                 pos_y;
    Uint32              background_color;
}               t_libui_style;

#endif