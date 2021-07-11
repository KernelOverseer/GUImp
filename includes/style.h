/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:53:42 by abiri             #+#    #+#             */
/*   Updated: 2021/07/11 03:10:55 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H
# define STYLE_ABSOLUTE 0
# define STYLE_RELATIVE 1
# define STYLE_INHERIT 2
# define STYLE_INLINE 3
# define STYLE_BLOCK 4
# define STYLE_FIXED 5
# define STYLE_POS_RELATIVE 6
# define STYLE_FONT_WEIGHT_COUNT 3
# define STYLE_FONT_REGULAR 0
# define STYLE_FONT_LIGHT 1
# define STYLE_FONT_BOLD 2

typedef union   u_libui_raw_style_prop_value
{
    Uint32      integer;
    float       decimal;
    char        *string;
}               t_libui_raw_style_prop_value;


typedef struct  s_libui_raw_style_prop
{
    int                             type;
    t_libui_raw_style_prop_value    value;
}               t_libui_raw_style_prop;

typedef t_libui_raw_style_prop t_style_prop;

typedef struct  s_libui_raw_style
{
    t_style_prop    width;
    t_style_prop    height;
    t_style_prop    background_color;
    t_style_prop    border_color;
    t_style_prop    border_weight;
    t_style_prop    border_opacity;
    t_style_prop    border_radius;
    t_style_prop    box_shadow_color;
    t_style_prop    box_shadow_weight;
    t_style_prop    box_shadow_opacity;
    t_style_prop    font_family;
    t_style_prop    font_size;
    t_style_prop    font_weight;
    t_style_prop    color;
    int             position;
    int             pos_x;
    int             pos_y;
    t_style_prop    display;
    t_style_prop    opacity;
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
    Uint32              border_color;
    int                 border_weight;
    float               border_opacity;
    int                 border_radius;
    Uint32              box_shadow_color;
    int                 box_shadow_weight;
    float               box_shadow_opacity;
    // font_family to be added
    int                 font_size;
    int                 font_weight;
    Uint32              color;
    float               opacity;
}               t_libui_style;

#endif