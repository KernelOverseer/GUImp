/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   css_size_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 02:34:19 by abiri             #+#    #+#             */
/*   Updated: 2021/07/11 03:10:38 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static int      parse_number(t_style_prop *prop, char *value)
{
    int num;
    int offset;

    offset = parse_int(&num, value);
    if (offset == 0)
        return (0);
    value += offset;
    printf("resuming from |%s|\n", value);
    while (*value && ft_ischarin(WHITESPACES, *value))
        value++;
    if (!*value || ft_strequ(value, "px"))
        prop->value.integer = num;
    else if (ft_strequ(value, "%"))
    {
        prop->value.decimal = (float)num / 100.0;
        prop->type = STYLE_RELATIVE;
    }
    else
        return (0);
    return (1);
}

t_style_prop    css_parse_size(char *value)
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
    if (parse_number(&result, value))
    {
        free(value);
        return (result);
    }
    free(value);
    return (result);
}