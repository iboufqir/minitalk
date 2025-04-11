/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboufqir <iboufqir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 09:53:08 by iboufqir          #+#    #+#             */
/*   Updated: 2024/04/28 14:40:57 by iboufqir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*read_map(char *file)
{
	char	*line;
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = ft_strjoin(str, line);
		free(line);
	}
	close(fd);
	return (str);
}

void	lenline(t_long *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->nbline = 0;
	while (data->lines[data->nbline])
		data->nbline++;
	while (data->lines[i][j])
		j++;
	data->lenline = j;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
			j++;
		if (j != data->lenline)
			msg_error(-1, "Error\n💥Inconsistent lines.", data);
		i++;
	}
	if (data->e != 1 || data->c < 1 || data->n < 1 || data->p != 1)
		msg_error(-1, "Error\n💥Invalid number of items", data);
}

void	checkchar(char **map, t_long *data)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				data->e += 1;
			else if (map[i][j] == 'N')
				data->n += 1;
			else if (map[i][j] == 'P')
			{
				data->x = i;
				data->y = j;
				data->p += 1;
			}
			else if (map[i][j] == 'C')
				data->c += 1;
			else if (map[i][j] != '0' && map[i][j] != '1')
				msg_error(-1, "Error\n💥Incorrect character", data);
		}
	}
}

void	checkwall(t_long *data)
{
	int	i;
	int	last_line;

	i = -1;
	last_line = data->nbline - 1;
	if (last_line < 1)
		msg_error(-1, "Error\n💥Only one line of map found.", data);
	while (data->lines[0][++i])
		if (data->lines[0][i] != '1')
			break ;
	if (i != ft_strlen(data->lines[0]))
		msg_error(-1, "Error\n💥Hole in the wall.", data);
	i = 0;
	while (++i < last_line)
		if (data->lines[i][0] != '1' ||
			data->lines[i][ft_strlen(data->lines[i]) - 1] != '1')
			msg_error(-1, "Error\n💥Hole in the wall.", data);
	i = -1;
	while (data->lines[last_line][++i])
		if (data->lines[last_line][i] != '1')
			break ;
	if (i != ft_strlen(data->lines[0]))
		msg_error(-1, "Error\n💥Hole in the wall.", data);
}

void	flood_fill(int x, int y, t_long *data)
{
	if (data->lines[x][y] == '1' || data->lines[x][y] == 'N')
		return ;
	else if (data->lines[x][y] == '0')
		data->lines[x][y] = '1';
	else if (data->lines[x][y] == 'C')
	{
		data->lines[x][y] = '1';
		data->c -= 1;
	}
	else if (data->lines[x][y] == 'E')
	{
		data->lines[x][y] = '1';
		data->e -= 1;
		return ;
	}
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}
