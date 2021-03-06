/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenamer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:08:21 by lbenamer          #+#    #+#             */
/*   Updated: 2016/11/17 20:46:13 by lbenamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}
