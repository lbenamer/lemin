#include "lemin.h"

int		ft_checkdouble(t_lst *room)
{
	t_lst 	*tmp;
	t_lst 	*tmp2;
	int		n;

	tmp = room;
	tmp2 = room;
	while (tmp)
	{
		room = tmp2;
		n = 0;
		while (room)
		{
			if (!ft_strcmp(room->line, tmp->line) && !n)
				++n;
			else if (!ft_strcmp(room->line, tmp->line) && n)
				return (0);
			room = room->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int		ft_check_stend(t_lst *room)
{
	int start;
	int	end;

	start = 0;
	end = 0;
	while (room)
	{
		if (room->start)
			++start;
		if (room->end)
			++end;
		room = room->next;
	}
	if (end != 1 || start != 1)
		return (0);
	return (1);
}


t_lst	*ft_next(t_lst *way)
{
	way->next->antz = way->antz;
	return (way);
}

t_lst	*ft_conn_prev(t_lst *way)
{
	t_lst *tmp;

	tmp = way;
	while (tmp)
	{
		if (tmp->next)
			tmp->next->pr = tmp;
		tmp = tmp->next; 
	}
	return (way);
}

t_lst	*ft_zero_antz(t_lst *way)
{
	t_lst *tmp;

	tmp = way;
	while (tmp)
	{
		tmp->antz = 0;
		tmp = tmp->next;
	}
	return (way);
}

