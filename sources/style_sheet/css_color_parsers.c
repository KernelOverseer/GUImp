/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   css_color_parsers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <kerneloverseer@pm.me>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:01:18 by abiri             #+#    #+#             */
/*   Updated: 2021/07/13 17:41:04 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style_sheet.h"
#include "libui.h"

static int  parse_hex(Uint32 *value, char *str)
{
    if (str[0] != '#')
        return (0);
    *value = ft_atoi_base(str+1, HEX_CHARSET);
    return (1);
}

int parse_int(int *value, char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (ft_isdigit(str[i]))
        i++;
    *value = ft_atoi(str);
    return (i);
}

static int  parse_rgb(Uint32 *value, char *str)
{
    int             rgb[3];
    int             skip;

    if (ft_strstr(str, "rgb(") != str)
        return (0);
    str += 4;
    if (!(skip = parse_int(&rgb[0], str)) || str[skip] != ',')
        return (0);
    str += skip + 1;
    if (!(skip = parse_int(&rgb[1], str)) || str[skip] != ',')
        return (0);
    str += skip + 1;
    if (!(skip = parse_int(&rgb[2], str)) || str[skip] != ')')
        return (0);
    *value = RGB((unsigned char)rgb[0],
        (unsigned char)rgb[1], (unsigned char)rgb[2], 0xFF);
    return (1);
}

static int  parse_color_presets(Uint32 *value, char *str)
{
    int     i;

    i = 0;
    while (g_libui_color_presets[i].name)
    {
        if (ft_strequ(str, g_libui_color_presets[i].name))
        {
            *value = g_libui_color_presets[i].color | 0xFF000000;
            return (1);
        }
        i++;
    }
    return (0);
}

static int  parse_rgba(Uint32 *value, char *str)
{
    int             rgb[4];
    int             skip;

    if (ft_strstr(str, "rgba(") != str)
        return (0);
    str += 5;
    if (!(skip = parse_int(&rgb[0], str)) || str[skip] != ',')
        return (0);
    str += skip + 1;
    if (!(skip = parse_int(&rgb[1], str)) || str[skip] != ',')
        return (0);
    str += skip + 1;
    if (!(skip = parse_int(&rgb[2], str)) || str[skip] != ',')
        return (0);
    str += skip + 1;
    if (!(skip = parse_int(&rgb[3], str)) || str[skip] != ')')
        return (0);
    *value = RGB((unsigned char)rgb[0], (unsigned char)rgb[1],
        (unsigned char)rgb[2], (unsigned char)rgb[3]);
    return (1);
}

t_style_prop    css_parse_color(char *value)
{
    t_style_prop    result;

    ft_bzero(&result, sizeof(result));
    value = ft_strtrim(value);
    if (ft_strequ(value, "inherit"))
    {
        result.type = STYLE_INHERIT;
        free(value);
        return (result);
    }
    if (ft_strequ(value, "transparent"))
    {
        result.value.integer = 0x0;
        free(value);
        return (result);
    }
    if (parse_hex(&result.value.integer, value) ||
        parse_rgb(&result.value.integer, value) ||
        parse_rgba(&result.value.integer, value) ||
        parse_color_presets(&result.value.integer, value))
    {
        free(value);
        return (result);
    }
    free(value);
    return (result);
}