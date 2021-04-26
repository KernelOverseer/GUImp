/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_style.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:07:23 by abiri             #+#    #+#             */
/*   Updated: 2021/04/26 14:55:54 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

static t_rect   compute_initial_container(t_libui_component *comp)
{
    t_rect  container;

    container = (t_rect){0, 0, 0, 0};
    container.h = comp->props.computed_style.height;
    container.w = comp->props.computed_style.width;
    return (container);
}

static int     limit_value_min_max(int value, int min, int max)
{
    if (value < min)
        return (min);
    if (value > max)
        return (max);
    return (value);
}
// set the new values for the children X and Y if they are not defined
static void     add_component_to_block_container(t_libui_component *child,
    t_libui_component_style *style, t_rect  *container)
{
    container->h += child->props.computed_style.height;
    if (container->w < child->props.computed_style.width)
        container->w = child->props.computed_style.width;
    //Don't use the min here, leave it to the end
    container->w = limit_value_min_max(container->w, style->min_width,
        style->max_width);
    container->h = limit_value_min_max(container->h, style->min_height,
        style->max_height);
}

static void     add_component_to_inline_container(t_libui_component *child,
    t_libui_component_style *style, t_rect *container)
{
    if (container->x + child->props.computed_style.width <= style->max_width)
    {
        container->x += child->props.computed_style.width;
        if (container->x > container->w)
            container->w = container->x;
        if (container->y + child->props.computed_style.height > container->h)
            container->h = container->y + child->props.computed_style.width;
    }
    container->x = 0;
    container->y += child->props.computed_style.height;
    // check here the constraints for max and min, width and height
}

static void     set_children_size_constraints(t_libui_component *parent,
    t_libui_component   *child)
{
    t_libui_component_style *parent_computed;
    t_libui_component_style *child_computed;

    child->props.computed_style = child->props.style;
    child_computed = &child->props.computed_style;
    parent_computed = &parent->props.computed_style;
    // There is a special case where the child has his own min and max
    //  and you should not mess them
    if (parent_computed->min_height != STYLE_UNDEFINED)
        child_computed->min_height = parent_computed->min_height;
    if (parent_computed->max_height != STYLE_UNDEFINED)
        child_computed->max_height = parent_computed->max_height;
    if (parent_computed->min_width != STYLE_UNDEFINED)
        child_computed->min_width = parent_computed->min_width;
    if (parent_computed->max_width != STYLE_UNDEFINED)
        child_computed->max_width = parent_computed->max_width;
}

void    libui_compute_component_own_style(t_libui_component *comp)
{
    // Here do calculations for the component's own style, like components
    // who does not have children like text
}

void    libui_compute_component_style(t_libui_component *comp)
{
    t_list_head         children;
    t_libui_component   *child;
    t_rect              container;

    children = comp->children;
    children.iterator = children.first;
    container = (t_rect){0, 0, 0, 0};
    while ((child = ttslist_iter_content(&children)))
    {
        set_children_size_constraints(comp, child);
        libui_compute_component_style(child);
        if (comp->props.computed_style.display == STYLE_DISPLAY_BLOCK)
            add_component_to_block_container(child,
                &comp->props.computed_style, &container);
        else
            add_component_to_inline_container(child,
                &comp->props.computed_style, &container);
    }
    libui_compote_component_own_style(comp);
}

void    libui_compute_window_style(t_libui_window *win)
{
}