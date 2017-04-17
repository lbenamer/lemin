/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:52:40 by lbenamer          #+#    #+#             */
/*   Updated: 2017/04/17 18:52:42 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst	*ft_shot(t_lst *way, int antz, int nb)
{
	t_lst *shot;

	shot = way;
	if (antz <= nb)
		way->antz = antz;
	way = ft_goto_lastantz(way);
	while (way)
	{
		way = ft_next(way);
		way = way->pr;
	}
	return (shot);
}

int		ft_check_end(t_lst *way, int nb)
{
	while (way->next)
		way = way->next;
	if (way->antz == nb)
		return (1);
	else
		return (0);
}

void	ft_disp_shot(t_lst *way)
{
	while (way->next)
		way = way->next;
	while (way->pr)
	{
		if (way->antz)
		{
			if (way->next)
				if (way->next->antz != way->antz)
					ft_printf("L%d-%s ", way->antz, way->line);
			if (!way->next)
				ft_printf("L%d-%s ", way->antz, way->line);
		}
		way = way->pr;
	}
	ft_printf("\n");
}

void	ft_golem(t_lst *way, int nb)
{
	int antz;

	antz = 1;
	way = ft_zero_antz(way);
	way = ft_conn_prev(way);
	while (!ft_check_end(way, nb))
	{
		way = ft_shot(way, antz, nb);
		ft_disp_shot(way);
		++antz;
	}
}

t_lst	*ft_save_line(t_lst *room)
{
	t_lst *tmp;

	tmp = room;
	while (tmp)
	{
		tmp->save = ft_strdup(tmp->line);
		tmp = tmp->next;
	}
	return (room);
}
