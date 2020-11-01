/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:50:56 by mstefani          #+#    #+#             */
/*   Updated: 2019/09/22 16:15:37 by mstefani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_strdel(char **as)
{
	if (as != 0)
	{
		ft_strclr(*as);
		ft_memdel((void**)as);
	}
	else
		return ;
}
