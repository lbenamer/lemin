#include "lemin.h"

int		ft_check_room(char *line)
{
	char	**tab;
	int		i;
	size_t	len;

	tab = ft_strsplit(line, ' ');
	len = ft_strlen_p(line) - 1;
	if (line[len] == ' ')
		return (0);
	if (ft_size_tab(tab) != 3)
		return (0);
	else if (tab[0][0] == 'L')
		return (0);
	i = -1;
	while (tab[1][++i])
		if (!ft_isdigit(tab[1][i]))
			return (0);
	i = -1;
	while (tab[2][++i])
		if (!ft_isdigit(tab[2][i]))
			return (0);
	return (1);
}

int		ft_check_com(char *line, t_lst **room)
{
	if (!ft_strcmp("##end", line))
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		else if (ft_check_room(line))
		{
			*room = ft_add_lst(*room, line, 0, 1);
			return (1);
		}
	}
	else if(!ft_strcmp("##start", line))
	{
		if (get_next_line(0, &line) <= 0)
			return (0);
		else if (ft_check_room(line))
		{
			*room = ft_add_lst(*room, line, 1, 0);
			return (1);
		}
	}
	return (0);
}

int		ft_check_tube(char *line)
{
	size_t len;

	len = ft_strlen(line);
//	printf("line = %s\n", line);
	if (line[0] == 'L')
		return (0);
	else if (line[0] == '-')
		return (0);
	else if (line[len - 1] == '-')
		return (0);
	else if(ft_strchr(line, ' '))
		return (0);
	line = ft_strchr(line, '-');
	if(line[1] == 'L')
		return (0);
	return (1);
}

int 	ft_check_lst(t_lst *room, char *name)
{
	int i;

	while(room != NULL)
	{	
		i = 0;
		while(room->line[i] != ' ' && room->line[i])
			++i;
		room->line = ft_strsub(room->line, 0, i);
		if(!ft_strcmp(name, room->line))
			return (1);
		else
			room = room->next;
	}
	return (0);
}

int		ft_checkname(t_lst *room, t_lst *tube)
{
	int i;
	char *room1;
	char *room2;

	if(!room->line || !tube->line)
		return(0);
	while(tube != NULL)
	{	
		i  = 0;
		while(tube->line[i] != '-' && tube->line[i])
			++i;
		room1 = ft_strsub(tube->line, 0, i);
		room2 = tube->line + i + 1;
		if(!ft_strcmp(room1, room2))
			return(0);
		if(!ft_check_lst(room, room1))
			return(0);
		if(!ft_check_lst(room, room2))
			return(0);
		tube = tube->next;
	}
	return (1);
}