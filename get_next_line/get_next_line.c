/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturksoy <mturksoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:54:16 by mturksoy          #+#    #+#             */
/*   Updated: 2023/02/24 12:27:15 by mturksoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_str(int fd, char *str)
{
	int		read_byte;
	char	*temp_str;

	temp_str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp_str)
		return (0);
	read_byte = 1;
	while (!ft_strchr(str, '\n') && read_byte != 0)
	{
		read_byte = read(fd, temp_str, BUFFER_SIZE);
		printf("%s",temp_str);

		if (read_byte == -1)
		{
			free (temp_str);
			return (0);
		}
		temp_str[read_byte] = '\0';
		str = ft_strjoin(str, temp_str);
	}
	free(temp_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_get_str(fd, str);
	if (!str)
		return (0);
	line = ft_get_line(str);
	str = ft_get_new_str(str);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

	int main(void)
	{
		char *line;
		int fd;
		int i = 0;

		fd = open("deneme.txt", O_RDONLY);
		//line = get_next_line(fd);
		while(i < 4)
		{
			line = get_next_line(fd);
			printf("%s", line);
			i++;
		}
	}*/

	#include <fcntl.h>
	#include <stdio.h>

	int main()
	{
		char *line;
		int fd;
		int i = 0;

		fd = open("deneme.txt",O_RDONLY);
		line = get_next_line(fd);
		/*while(i < 7)
		{
			if(line == NULL)
				return(0);
			line = get_next_line(fd);
			printf("%s",line);
			i++;
		}*/
	}