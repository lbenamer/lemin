#include "lemin.h"

int		ft_check_room(char *line)
{
	char **tab;
	int i;

	tab = ft_strsplit(line, ' ');
	if(ft_size_tab(tab) != 3)
		return (0);
	if(tab[0][0] == 'L')
		return (0);
	i = -1;
	while(tab[1][++i])
		if(!ft_isdigit(tab[1][i]))
			return (0);
	i = -1;
	while(tab[2][++i])
		if(!ft_isdigit(tab[2][i]))
			return (0);
	return (1);
}

int		ft_check_com(char *line, t_lst **room)
{
	if(!ft_strcmp("##end", line))
	{
		if(get_next_line(0, &line) <= 0)
			return (0);
		if(ft_check_room(line))
		{
			*room = ft_add_lst(*room, line, 0, 1);
			return (1);
		}
	}
	else if(!ft_strcmp("##start", line))
	{
		if(get_next_line(0, &line) <= 0)
			return (0);
		if(ft_check_room(line))
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
	if(line[0] == 'L')
		return (0);
	if(line[0] == '-')
		return (0);
	if(line[len - 1] == '-')
		return (0);
	return (1);
}
