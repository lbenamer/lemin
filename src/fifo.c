/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:54:51 by lbenamer          #+#    #+#             */
/*   Updated: 2017/04/17 18:54:52 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_check_visit(t_lst *visit, char *room)
{
	while (visit)
	{
		if (!ft_strcmp(visit->line, room))
			return (1);
		visit = visit->next;
	}
	return (0);
}

t_lst	*ft_add_back(t_lst *way, char *room)
{
	t_lst *tmp;

	if (!way->line)
	{
		way = ft_new_lst(room, 0, 0);
		return (way);
	}
	else
	{
		tmp = ft_new_lst(room, 0, 0);
		tmp->next = way;
	}
	return (tmp);
}

t_lst	*ft_fifo(t_lst *room)
{
	t_lst	*fil;
	t_lst	*start;
	t_lst	*tmp;
	t_lst	*tmp2;
	int		i;

	fil = (t_lst*)malloc(sizeof(t_lst));
	start = ft_goto_start(room);
	fil = ft_add_fil(fil, start->line, NULL);
	tmp = fil;
	tmp2 = room;
	while (fil)
	{
		tmp2 = ft_goto_room(room, fil->line);
		i = -1;
		while (tmp2->cnx[++i])
		{
			if (!ft_check_visit(tmp, tmp2->cnx[i]))
				tmp = ft_add_fil(tmp, tmp2->cnx[i], fil->line);
		}
		if (tmp2->end)
			fil->next = NULL;
		fil = fil->next;
	}
	return (tmp);
}

int		ft_check_way(t_lst *fil, t_lst *room)
{
	while (fil->next)
		fil = fil->next;
	room = ft_goto_end(room);
	if (!ft_strcmp(room->line, fil->line))
		return (1);
	else
		return (0);
}

t_lst	*ft_getway(t_lst *fil)
{
	t_lst	*way;
	t_lst	*tmp;
	t_lst	*tmp2;
	char	*prev;

	way = (t_lst*)malloc(sizeof(t_lst));
	tmp = fil;
	while (tmp->next)
		tmp = tmp->next;
	way = ft_add_back(way, tmp->line);
	prev = tmp->prev;
	while (prev)
	{
		tmp2 = ft_goto_room(fil, prev);
		way = ft_add_back(way, tmp2->line);
		prev = tmp2->prev;
	}
	return (way);
}
