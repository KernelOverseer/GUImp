/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:26:57 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 14:14:53 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H
# define STYLE_UNDEFINED -1
# define STYLE_INHERIT -2
# define STYLE_DISPLAY_BLOCK 0
# define STYLE_DISPLAY_INLINE 1

typedef unsigned int t_color;

enum            e_libui_component_sides
{
    SIDE_TOP, SIDE_RIGHT, SIDE_BOTTOM, SIDE_LEFT
};

typedef struct  s_libui_component_style
{
    t_color     color;
    t_color     background_color;
    int         fontSize;
    char        *fontFamily;
    int         display;
    int         width;
    int         height;
    int         max_width;
    int         max_height;
    int         min_width;
    int         min_height;
    int         padding[4];
    int         margin[4];
    int         border[4];
}               t_libui_component_style;

#endif