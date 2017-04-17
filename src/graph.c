/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:04:00 by lbenamer          #+#    #+#             */
/*   Updated: 2017/04/17 19:04:01 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_count_cnx(char *room, t_lst *tube)
{
	int		count;
	char	**tab;

	count = 0;
	while (tube)
	{
		tab = ft_strsplit(tube->line, '-');
		if (!ft_strcmp(room, tab[0]) || !ft_strcmp(tab[1], room))
			++count;
		tube = tube->next;
	}
	return (count);
}

t_lst		*ft_create_cnx(t_lst *room, t_lst *tube)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	char	**tab;
	int		n;

	tmp = tube;
	tmp2 = room;
	while (tmp2)
	{
		tube = tmp;
		n = ft_count_cnx(tmp2->line, tube);
		if (!(tmp2->cnx = (char**)malloc(sizeof(char*) * n + 1)))
			return (0);
		tmp2->cnx[n] = NULL;
		while (tube && n)
		{
			tab = ft_strsplit(tube->line, '-');
			if (!ft_strcmp(tmp2->line, tab[0]) ||
			!ft_strcmp(tab[1], tmp2->line))
				tmp2->cnx[--n] = ft_get_cnx(tmp2->line, tube->line);
			tube = tube->next;
		}
		tmp2 = tmp2->next;
	}
	return (room);
}

char		*ft_get_cnx(char *room, char *tube)
{
	char **tab;
	char *ret;

	ret = NULL;
	tab = ft_strsplit(tube, '-');
	if (!ft_strcmp(tab[0], room))
		ret = ft_strdup(tab[1]);
	else if (!ft_strcmp(tab[1], room))
		ret = ft_strdup(tab[0]);
	return (ret);
}

void		ft_display_graph(t_lst *room, t_lst *tube, int n)
{
	ft_printf("%d\n", n);
	while (room)
	{
		if (room->start)
			ft_printf("##start\n");
		if (room->end)
			ft_printf("##end\n");
		ft_printf("%s\n", room->save);
		room = room->next;
	}
	while (tube)
	{
		ft_printf("%s\n", tube->line);
		tube = tube->next;
	}
	ft_printf("\n");
}
