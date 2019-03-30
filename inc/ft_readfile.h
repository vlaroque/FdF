/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:55:03 by vlaroque          #+#    #+#             */
/*   Updated: 2019/03/30 15:37:01 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READFILE_H
# define FT_READFILE_H
# include <unistd.h>
# define BUFF 1

char	*ft_readfile(const char *path);
typedef struct s_strpart t_part;
struct s_strpart
{
	size_t	len;
	char	str[BUFF];
	t_part	*next;
};

#endif