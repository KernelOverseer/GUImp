/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   element_getters.c								  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: abiri <kerneloverseer@pm.me>			   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/07/12 21:10:00 by abiri			 #+#	#+#			 */
/*   Updated: 2021/07/13 14:10:25 by abiri			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libui.h"

t_libui_component   *get_child_by_id(t_libui_component *parent, char *id)
{
	t_list_head children;
	t_libui_component *child;

	children = parent->children;
	children.iterator = children.first;
	while ((child = ttslist_iter_content(&children)))
	{
		if (ft_strequ(child->status.id, id))
			return (child);
		child = get_child_by_id(child, id);
		if (child)
			return (child);
	}
	return (NULL);
}

t_libui_component   *libui_component_map_function(t_list_head components,
    int (*search)(t_libui_component *comp, void *arg),
    int (*effect)(t_libui_component *comp, void *arg),
    void *arg)
{
    t_libui_component   *component;

    components.iterator = components.first;
    while ((component = ttslist_iter_content(&components)))
    {
        if (search(component, arg))
            effect(component, arg);
        else
        {
            libui_component_map_function(component->children,
                search, effect, arg);
        }
    }
    return (NULL);
}

t_libui_component	*libui_component_get_by_id(t_libui_window *window, char *id)
{
	t_list_head		 children;
	t_libui_component   *child;

	children = window->components;
	children.iterator = children.first;
	while ((child = ttslist_iter_content(&children)))
	{
		if (ft_strequ(child->status.id, id))
			return (child);
		child = get_child_by_id(child, id);
		if (child)
			return (child);
	}
	return (NULL);
}		   