/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 00:16:58 by abiri             #+#    #+#             */
/*   Updated: 2021/07/06 00:43:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTON_H
# define BUTTON_H
# include "libui.h"
# include "builtin_commons.h"

typedef struct  s_libui_button_data
{   
}               t_libui_button_data;


t_libui_component   *libui_new_button(t_libui_style props);
int                 libui_button_draw(t_libui_component *component);
#endif