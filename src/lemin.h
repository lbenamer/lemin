#ifndef LEMIN_H
# define LEMIN_H

#include "../libft/libft.h"

typedef struct		s_lst
{
	struct s_lst 	*next;
	char			*line;
	int				start;
	int				end;
	char			**cnx;
	char			*prev;
	int 			antz;
	struct s_lst	*pr;
	char			*save;
}					t_lst;

t_lst				*ft_init_lst(void);
t_lst				*ft_new_lst(char *line, int start, int end);
t_lst				*ft_add_lst(t_lst *room, char *line, int start, int end);
int					ft_getnb_antz(void);
int					ft_check_room(char *line);
int					ft_check_com(char *line, t_lst **room);
int					ft_check_tube(char *line);
int					ft_disp_data(char *line, t_lst **room, t_lst **tube);
int					ft_getdata(t_lst **room, t_lst **tube);
int					ft_checkname(t_lst *room, t_lst *tube);
int					ft_checkdouble(t_lst *room);
int					ft_check_stend(t_lst *room);
int					ft_count_cnx(char *room, t_lst *tube);
char				*ft_get_cnx(char *room, char *tube);
t_lst				*ft_create_cnx(t_lst *room, t_lst *tube);
t_lst 				*ft_goto_room(t_lst *room, char *name);
t_lst 				*ft_goto_start(t_lst *room);
t_lst				*ft_goto_end(t_lst *room);
t_lst 				*ft_goto_lastantz(t_lst *way);
t_lst 				*ft_new_fil(char *room, char *prev);
t_lst				*ft_add_fil(t_lst *fil, char *room, char *prev);
t_lst 				*ft_zero_antz(t_lst *way);
t_lst				*ft_next(t_lst *way);
void				ft_display_fil(t_lst *fil);
t_lst 				*ft_fifo(t_lst *room);
t_lst				*ft_getway(t_lst *fil);
int 				ft_check_way(t_lst *fil, t_lst *room);
t_lst 				*ft_conn_prev(t_lst *way);
void				ft_golem(t_lst *way, int nb);
void				ft_display_graph(t_lst *room, t_lst *tube, int n);
void				ft_displaylst(t_lst *lst);
t_lst 				*ft_save_line(t_lst *room);
#endif