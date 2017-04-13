#include "filler.h"

t_lst *ft_goto_room(t_lst *room, char *name)
{
	while(room)
	{
		if(!ft_strcmp(room->line, name))
			return(room)
		room = room->next;
	}
	return (room);
}

t_lst 	*ft_goto_start(t_lst *room)
{
	while(room)
	{
		if(room->start)
			retunr(room)
		room = room->next;
	}
	return (room);
}