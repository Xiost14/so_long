/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsamina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:02:11 by thsamina          #+#    #+#             */
/*   Updated: 2021/10/11 17:16:31 by thsamina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut_memory(char *memo)
{
	char			*str;
	int				i;
	int				c;

	i = 0;
	while (memo[i] && memo[i] != '\n')
		i++;
	if (!memo[i])
	{
		free(memo);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(memo) - i + 1));
	if (!str)
		return (NULL);
	i++;
	c = 0;
	while (memo[i])
		str[c++] = memo[i++];
	str[c] = '\0';
	free(memo);
	return (str);
}

char	*ft_cut(char *memo)
{
	char			*str;
	int				i;

	i = 0;
	if (!memo[i])
		return (NULL);
	while (memo[i] && memo[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (memo[i] && memo[i] != '\n')
	{
		str[i] = memo[i];
		i++;
	}
	if (memo[i] == '\n')
	{
		str[i] = memo[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_reading(int fd, char *memo)
{
	char			*buff;
	int				i;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 1;
	while (!ft_strchr(memo, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		memo = ft_strjoin(memo, buff);
	}
	free(buff);
	return (memo);
}

char	*get_next_line(int fd)
{
	static char		*memo;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memo = ft_reading(fd, memo);
	if (!memo)
		return (NULL);
	str = ft_cut(memo);
	memo = ft_cut_memory(memo);
	return (str);
}
