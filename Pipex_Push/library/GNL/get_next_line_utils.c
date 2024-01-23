/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmohamma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:04:19 by rmohamma          #+#    #+#             */
/*   Updated: 2022/12/15 14:05:06 by rmohamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_char(t_line *head)
{
	int		i;
	t_line	*node;

	if (head == NULL)
		return (0);
	node = get_last_node(head);
	i = 0;
	while (node->data[i])
	{
		if (node->data[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_line	*get_last_node(t_line *head)
{
	t_line	*node;

	node = head;
	while (node && node->link)
		node = node->link;
	return (node);
}

void	allocate_line(char **line, t_line *head)
{
	int	i;
	int	len;

	len = 0;
	while (head)
	{
		i = 0;
		while (head->data[i])
		{
			if (head->data[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		head = head->link;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_list(t_line *head)
{
	t_line	*temp;
	t_line	*next;

	temp = head;
	while (temp)
	{
		free(temp->data);
		next = temp->link;
		free(temp);
		temp = next;
	}
	head = NULL;
}

int	f_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
