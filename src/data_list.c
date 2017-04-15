#include "lemin.h"

t_lst 	*ft_init_lst(void)
{
	t_lst *lst;

	if (!(lst = (t_lst*)malloc(sizeof(t_lst*))))
		return (NULL);
	lst->line = NULL;
	lst->start = 0;
	lst->end = 0;
	lst->save = NULL;
	lst->next = NULL;
	return (lst);
}


t_lst	*ft_new_lst(char *line, int start, int end)
{
	t_lst *room;
	if (!(room = malloc(sizeof(t_lst))))
		return (NULL);
	room->line = ft_strdup(line);
	room->start = start;
	room->end = end;
	room->next = NULL;
	return (room);
}


t_lst	*ft_add_lst(t_lst *room, char *line, int start, int end)
{
	t_lst *tmp;

	tmp = room;
	if (!room->line)
	{
		room = ft_new_lst(line, start, end);
		return (room);
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_new_lst(line, start, end);
	}
	return (room);
}

t_lst 	*ft_new_fil(char *room, char *prev)
{
	t_lst *fil;

	if (!(fil = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	fil->line = room;
	fil->prev = prev;
	fil->next = NULL;
	return (fil);
}

t_lst	*ft_add_fil(t_lst *fil, char *room, char *prev)
{
	t_lst *tmp;

	tmp = fil;
	if (!fil->line)
	{
		fil = ft_new_fil(room, prev);
		return (fil);
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_new_fil(room, prev);
	}
	return (fil);
}
