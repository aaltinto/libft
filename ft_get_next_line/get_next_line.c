/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaltinto <aaltinto@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:39:05 by aaltinto          #+#    #+#             */
/*   Updated: 2023/08/02 13:39:09 by aaltinto         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trim_str(char *str)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	if (str[i + 1] == '\0')
		return (free_str(&str, 0));
	res = ft_substr(str, i + 1, ft_strlen(str));
	if (!res)
	{
		free_str(&str, 0);
		return (NULL);
	}
	free_str(&str, 0);
	return (res);
}

static char	*get_line(char *str)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i + 1)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*integrate_str(char *str, char *buf) //içerisine birleştirmek için str ve buf'u alır 
{
	char	*res;

	res = 0;
	if (!str && buf) // str ilk başta boş olacağı için içerisine buf'u kopyalıyoruz. Bu durumu kontrol ediyoruz.
	{
		res = ft_strdup(buf);
		if (!res) //kopyalama işlemini kontrol
			return (NULL);
		return (res);
	}
	res = ft_strjoin(str, buf); //str'ye buf kopyalama
	free_str(&str, 0);
	return (res);
}

static int	nl_check(char *str)
{
	int	i; 

	if (!str) //str'yi kontrol eder.
		return (0);
	i = -1;
	while (str[++i] != '\0')
		if (str[i] == '\n') //eğer nl'a denk gelirse 1 döndürür.
			return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1]; //read fonksiyonunun her döngüsünde okuyacağı veri depolaması.
	long		rd; // read fonksiyonun her döngüde okuduğu veri mikrarı, döngüyü kırmak için kullanılıyor.
	static char	*str = NULL;
	char		*line;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0) //file directory ve buff_size kontrolü
		return (free_str(&str, 0));
	while (rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE); // read fonksiyonu bir dosya içerisindeki verileri okur.
		if ((rd <= 0 && !str) || rd == -1)
			return (free_str(&str, 0));
		buf[rd] = '\0'; // içeriye atılan verilerin sonuna NULL eklenir.
		str = integrate_str(str, buf); // buf içerisindeki verileri str içerisine kopyalar.
		if (nl_check(str)) //str içerisinde newLine olup olmadığını kontrol eder.
		{ //newLine olması durumunda
			line = get_line(str); // str içerisindeki stringi newline'a kadar line içerisine atar.
			if (!line) //line kontrolü
				return (free_str(&str, 0));
			return (str = trim_str(str), line); // str içerisinde newline a kadar olan kısmı keser. Daha sonra satırı tekrar yazdırmamak için.
		}
	}
	return (free_str(&str, 1)); 
}
