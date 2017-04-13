#include "lemin.h"

int		ft_count_cnx(char *room, t_lst *tube)
{
	int count;

	count = 0;
	while (tube)
	{
		if (ft_strstr(tube->line, room))
			++count;
		tube = tube->next;
	}
	return (count);
}


char	*ft_get_cnx(char *room, char *tube)
{
	char **tab;

	tab = ft_strsplit(tube, '-');
	if (!ft_strcmp(tab[0], room))
		return(tab[1]);
	else
		return(tab[0]);
}

void	ft_display_cnx(t_lst *room)
{
	int i;

	while (room)
	{
		i = -1;
		printf("room = %s\n", room->line);
		while(room->cnx[++i])
			printf("connex %d = %s\n", i, room->cnx[i]);
		room = room->next;
	}
}

t_lst		*ft_create_cnx(t_lst *room, t_lst *tube)
{

	t_lst 	*tmp;
	t_lst 	*tmp2;
	int 	n;
	int 	i;

	tmp = tube;
	tmp2 = room;
	while (tmp2)
	{
		n = ft_count_cnx(tmp2->line, tube);
		i = 0;
		if (!(tmp2->cnx = (char**)malloc(sizeof(char*) * n + 1)))
			return (0);
		tube = tmp;
		while (tube)
		{
			if (ft_strstr(tube->line, tmp2->line))
				tmp2->cnx[i++] = ft_get_cnx(tmp2->line, tube->line);
			tube = tube->next;
		}
		tmp2->cnx[i] = NULL;
		tmp2 = tmp2->next;
	}
	return (room);
}