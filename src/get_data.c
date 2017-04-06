#include "lemin.h"

int ft_getnb_antz(void)
{
	char *line;
	int i;

	i = -1;
	line = NULL;
	get_next_line(0, &line);
	while(line[++i])
		if(!ft_isdigit(line[i]))
			return(0);
	return(ft_atoi(line));
}



int		ft_disp_data(char *line, t_lst **room, t_lst **tube)
{
	if(line[0] == '#')
	{
		ft_check_com(line, room);
		return (1);
	}
	else if(ft_strchr(line, '-'))
	{
		if(ft_check_tube(line))
		{
			printf("check ok\n");
			*tube = ft_add_lst(*tube, line, 0, 0);
			return (1);
		}
	}
	else
	{
		if(ft_check_room(line))
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
	while(get_next_line(0, &line) > 0)
	{	
		if(!ft_strlen(line))
			return (0);
		else if(!ft_disp_data(line, room, tube))
			return (0);
	}
	return (1);
}

void	ft_displaylst(t_lst *lst)
{
	if(lst)
		while(lst != NULL)
		{
			ft_printf("%s\n", lst->line);
			if(lst->start)
				ft_printf("start\n");
			if(lst->end)
				ft_printf("end\n");
			lst = lst->next;
		}
}

int main(void)
{
	int n;
	t_lst *room;
	t_lst *tube;

	if(!(room = malloc(sizeof(t_lst*))))
		return (0);
	if(!(tube = malloc(sizeof(t_lst*))))
		return (0);
	room = ft_init_lst(room);
	tube = ft_init_lst(tube);
	if(!(n = ft_getnb_antz()))
		return (0);
	ft_printf("nb fourmi = %d\n", n);
	ft_getdata(&room, &tube);
	ft_printf("##room##\n");
	ft_displaylst(room);
	ft_printf("##tube##\n");
	ft_displaylst(tube);
	//printf("segfault\n");
	return (0);
}