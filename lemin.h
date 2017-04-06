#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/libft.h"
#include <stdio.h>

typedef struct		s_lst
{
	char			*line;
	int				start;
	int				end;
	struct s_lst 	*next;
}					t_lst;

t_lst				*ft_init_lst(t_lst *lst);
t_lst				*ft_new_lst(char *line, int start, int end);
t_lst				*ft_add_lst(t_lst *room, char *line, int start, int end);
int					ft_getnb_antz(void);
int					ft_check_room(char *line);
int					ft_check_com(char *line, t_lst **room);
int					ft_check_tube(char *line);
int					ft_disp_data(char *line, t_lst **room, t_lst **tube);
int					ft_getdata(t_lst **room, t_lst **tube);




#endif