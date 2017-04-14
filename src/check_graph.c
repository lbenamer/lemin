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


