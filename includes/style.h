/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:26:57 by abiri             #+#    #+#             */
/*   Updated: 2021/04/12 14:30:59 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H

typedef unsigned int t_color;

typedef struct  s_libui_component_style
{
    t_color     color;
    t_color     background_color;
    int         width;
    int         height;
}               t_libui_component_style;


#endif