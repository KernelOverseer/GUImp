/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:08:36 by merras            #+#    #+#             */
/*   Updated: 2021/07/04 17:58:29 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_simplesdl_memalloc(size_t size)
{
	unsigned char	*memloc;
	size_t	i;

	i = 0;
	memloc = (unsigned char *)malloc(size);
	if (memloc == NULL)
		return (NULL);
	while (i < size)
	{
		memloc[i] = 0;
		i++;
	}
	return (memloc);
}
