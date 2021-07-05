/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 20:53:42 by abiri             #+#    #+#             */
/*   Updated: 2021/07/06 00:28:26 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H

typedef struct  s_libui_style
{
    int         width;
    int         height;
    int         pos_x;
    int         pos_y;
    Uint32      background_color;
}               t_libui_style;

#endif