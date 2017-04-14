#include "lemin.h"

t_lst 	*ft_goto_room(t_lst *room, char *name)
{
	while(room)
	{
		if(!ft_strcmp(room->line, name))
			return(room);
		room = room->next;
	}
	return (room);
}

t_lst 	*ft_goto_start(t_lst *room)
{
	while(room)
	{
		if(room->start)
			return (room);
		room = room->next;
	}
	return (room);
}

t_lst	*ft_goto_end(t_lst *room)
{
	while(room)
	{
		if(room->end)
			return (room);
		room = room->next;
	}
	return (room);
}

int		ft_check_visit(t_lst *visit, char *room)
{
	while(visit)
	{
		if(!ft_strcmp(visit->line, room))
			return (1);
		visit = visit->next;
	}
	return (0);
}

t_lst 	*ft_new_fil(char *room, char *prev)
{
	t_lst *fil;

	if(!(fil = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	fil->line = room;
	fil->prev = prev;
	fil->next = NULL;
	return (fil);
}


//  t_lst 	*ft_new_visit(char *room
// {
// 	t_lst *visit;

// 	if(!(visit = (t_lst*)malloc(sizeof(t_lst))))
// 		return (NULL);
// 	visit->line = room;
// 	visit->prev = prev;
// 	visit->next = NULL;
// 	return (visit);
// }


t_lst	*ft_add_fil(t_lst *fil, char *room, char *prev)
{
	t_lst *tmp;

	tmp = fil;
	if(!fil->line)
	{
		fil = ft_new_fil(room, prev);
		return (fil);
	}
	else
	{
		while(tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_new_fil(room, prev);
	}
	return (fil);
}

 t_lst	*ft_add_back(t_lst *way, char *room)
{
	t_lst *tmp;

	if(!way->line)
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

void	ft_display_fil(t_lst *fil)
{
	while(fil)
	{
		ft_printf("room  = %s || prev = %s \n", fil->line, fil->prev);
		fil = fil->next;
	}
}

t_lst 	*ft_fifo(t_lst *room)
{
	t_lst 	*fil;
	t_lst 	*start;
	t_lst	*tmp;
	t_lst 	*tmp2;
	int		i;

	fil = (t_lst*)malloc(sizeof(t_lst*));
	start = ft_goto_start(room);
	fil = ft_add_fil(fil, start->line, NULL);
	tmp = fil;
	tmp2 = room;
	//ft_display_fil(fil);
	while(fil)
	{	
		tmp2 = ft_goto_room(room, fil->line);
		i = -1;
	//	ft_printf("room->line = %s\n", tmp2->line);
		while(tmp2->cnx[++i])
		{
			if(!ft_check_visit(tmp, tmp2->cnx[i]))
				tmp = ft_add_fil(tmp, tmp2->cnx[i], fil->line);
		}
	//	ft_display_fil(tmp);
		//printf("fil->line = %s\n", fil->line);
		if(tmp2->end)
			fil->next = NULL;
		fil = fil->next;
	}
	return (tmp);
}

int ft_check_way(t_lst *fil, t_lst *room)
{
	while(fil->next)
		fil = fil->next;
	room = ft_goto_end(room);
	if(!ft_strcmp(room->line, fil->line))
		return (1);
	else
		return (0);
}

t_lst	*ft_getway(t_lst *fil)
{
	t_lst *way;
	t_lst *tmp;
	t_lst *tmp2;
	char *prev;

	way = (t_lst*)malloc(sizeof(t_lst));
	tmp = fil;
	while(tmp->next)
		tmp = tmp->next;
	way = ft_add_back(way ,tmp->line);
	prev = tmp->prev;
	while(prev)
	{		
		tmp2 = ft_goto_room(fil, prev);
		way = ft_add_back(way, tmp2->line);
		prev = tmp2->prev;
	}
	return (way);
}

