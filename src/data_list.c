#include "lemin.h"


t_lst	*ft_init_lst(t_lst *lst)
{
	lst->line = NULL;
	lst->start = 0;
	lst->end = 0;
	lst->next = NULL;
	return (lst);
}


t_lst	*ft_new_lst(char *line, int start, int end)
{
	t_lst *room;
	if(!(room = malloc(sizeof(t_lst))))
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
	if(!room->line)
	{
		room = ft_new_lst(line, start, end);
		return(room);
	}
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_new_lst(line, start, end);
	}
	return (room);
}