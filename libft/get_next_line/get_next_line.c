/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 00:07:14 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/11 22:29:20 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_gnl_list	*ft_setlst(t_gnl_list *lst, const int fd)
{
	if (!lst)
		return (NULL);
	lst->content_size = fd;
	lst->next = NULL;
	return (lst);
}

t_gnl_list	*ft_history(t_gnl_list **link, const int fd)
{
	t_gnl_list	*history;
	t_gnl_list	*temp;

	temp = *link;
	while (temp)
	{
		history = temp;
		if (temp->content_size == fd)
			return (history);
		temp = temp->next;
	}
	if (!(history = (t_gnl_list*)malloc(sizeof(t_gnl_list))))
		return (NULL);
	if (!(history->str = ft_strnew(0)))
		return (NULL);
	history = ft_setlst(history, fd);
	if (!*link)
		*link = history;
	else if ((temp = *link))
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = history;
	}
	return (history);
}

int			get_read(const int fd, t_gnl_list **now_list)
{
	char	temp[BUFF_SIZE + 1];
	char	*temp2;
	int		count;

	if (read(fd, temp, 0) < 0)
		return (-1);
	while ((count = read(fd, temp, BUFF_SIZE)))
	{
		temp[count] = '\0';
		temp2 = ft_strjoin((*now_list)->str, temp);
		free((*now_list)->str);
		(*now_list)->str = temp2;
	}
	return (count);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl_list	*curr = NULL;
	t_gnl_list			*temp;
	int					count_read;
	int					i;

	if (fd < 0 || !line || !(temp = ft_history(&curr, fd)))
		return (-1);
	if ((count_read = get_read(fd, &temp)) < 0)
		return (-1);
	i = 0;
	while (temp->str[i] != '\0' && temp->str[i] != '\n')
		i++;
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, temp->str, i);
	if (*(temp->str) || (**line && *line))
	{
		temp->str = ft_strcut(temp->str, '\n');
		return (1);
	}
	free(temp->str);
	return (count_read);
}
