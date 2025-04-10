/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerrakeb <nerrakeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:28:58 by hiamedja          #+#    #+#             */
/*   Updated: 2023/11/28 06:59:48 by nerrakeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/cub3d.h"

char	*ft_save(char *str_sttc)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (str_sttc[i] && str_sttc[i] != '\n')
		i++;
	if (!str_sttc[i])
	{
		free(str_sttc);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(str_sttc) - i));
	if (!str)
		return (NULL);
	i++;
	while (str_sttc[i])
		str[j++] = str_sttc[i++];
	str[j] = '\0';
	free (str_sttc);
	return (str);
}

char	*ft_get_line(char *str_sttc)
{
	int		i;
	char	*str;

	i = 0;
	if (!str_sttc[i])
		return (NULL);
	while (str_sttc[i] && str_sttc[i] != '\n')
		i++;
	str = malloc(sizeof(char ) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (str_sttc[i] && str_sttc[i] != '\n')
	{
		str[i] = str_sttc[i];
		i++;
	}
	if (str_sttc[i] == '\n')
	{
		str[i] = str_sttc[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_join(char *str, int fd)
{
	char	*buffer;
	int		read_byte;

	read_byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		str = ft_strjoin1(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str_sttc;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("fd = %d\n", fd);
		return (0);
	}
	str_sttc = ft_read_join(str_sttc, fd);
	if (!str_sttc)
		return (NULL);
	line = ft_get_line(str_sttc);
	str_sttc = ft_save(str_sttc);
	return (line);
}
