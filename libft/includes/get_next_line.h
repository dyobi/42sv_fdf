/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:14:22 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/11 22:03:38 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 1024

typedef struct	s_gnl_list
{
	char				*str;
	int					content_size;
	struct s_gnl_list	*next;
}				t_gnl_list;

int				get_next_line(const int fd, char **line);

#endif
