#include "lemin.h"

int ft_getnb_antz(void)
{
	char *line;
	int i;

	i = -1;
	line = NULL;
	get_next_line(0, &line);
	while (line[++i])
		if (!ft_isdigit(line[i]))
			return (0);
	return (ft_atoi(line));
}

int		ft_disp_data(char *line, t_lst **room, t_lst **tube)
{
	if (line[0] == '#')
	{
		ft_check_com(line, room);
		return (1);
	}
	else if (ft_strchr(line, '-'))
	{
		if (ft_check_tube(line))
		{
			*tube = ft_add_lst(*tube, line, 0, 0);
			return (1);
		}
	}
	else
	{
		if (ft_check_room(line))
		{
			*room = ft_add_lst(*room, line, 0, 0);
			return (1);
		}
	}
	return (0);
}

int		ft_getdata(t_lst **room, t_lst **tube)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{	
		if (!ft_strlen_p(line))
			return (0);
		else if (!ft_disp_data(line, room, tube))
			return (0);
	}
	return (1);
}

int 	ft_check_data(t_lst *room , t_lst *tube, int n)
{
	if (!ft_checkname(room, tube) || !ft_checkdouble(room) || !ft_check_stend(room) || n <= 0)
	{
		ft_printf("ERROR 1\n");
		return (0);
	}
	else
		return (1);
}

int main(void)
{
	int n;
	t_lst *room;
	t_lst *tube;
	t_lst *fil;
	t_lst *way;

	room = ft_init_lst();
	tube = ft_init_lst();
	n = ft_getnb_antz();
	ft_getdata(&room, &tube);
	room = ft_save_line(room);
	if (!ft_check_data(room, tube, n))
		return (0);
	room = ft_create_cnx(room, tube);
	fil = ft_fifo(room);
	way = ft_getway(fil);
	if (ft_check_way(fil, room))
	{
		ft_display_graph(room, tube, n);
		ft_golem(way, n);
		return (1);
	}
	ft_printf("ERROR\n");
	return (0);
}