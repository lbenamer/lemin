/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_goto.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:57:29 by lbenamer          #+#    #+#             */
/*   Updated: 2017/04/17 18:57:31 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst	*ft_goto_room(t_lst *room, char *name)
{
	while (room)
	{
		if (!ft_strcmp(room->line, name))
			return (room);
		room = room->next;
	}
	return (room);
}

t_lst	*ft_goto_start(t_lst *room)
{
	while (room)
	{
		if (room->start)
			return (room);
		room = room->next;
	}
	return (room);
}

t_lst	*ft_goto_end(t_lst *room)
{
	while (room)
	{
		if (room->end)
			return (room);
		room = room->next;
	}
	return (room);
}

t_lst	*ft_goto_lastantz(t_lst *way)
{
	while (way->next->next)
	{
		if (!way->next->antz)
			return (way);
		way = way->next;
	}
	return (way);
}
