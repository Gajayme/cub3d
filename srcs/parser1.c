/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladrian <ladrian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:53:09 by ladrian           #+#    #+#             */
/*   Updated: 2022/09/04 17:07:19 by ladrian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_line_map(t_parser *parser, char *line, int *row_cnt)
{
    int i;

    i = -1;
    if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) 
            || !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
        return (1);
	else if (!ft_strncmp(line, "F ", 2) ||	!ft_strncmp(line, "C ", 2))
		return (1);
    parser->map[*row_cnt] = malloc(sizeof(int) * ft_strlen(line));
    while (line[++i])
        parser->map[*row_cnt][i] = line[i] - '0';
    parser->map[*row_cnt][i] = 31;
    *row_cnt += 1;
    return (1);
}

int parse_map(int fd, t_parser *parser, int row_nmbr)
{
    char	    *line;
	int		    ptr;
    int         row_cnt;

    row_cnt = 0;
    parser->map = malloc(sizeof(parser->map) * (row_nmbr + 1));
	while ((ptr = get_next_line(fd, &line)) > 0)
	{
		parse_line_map(parser, line, &row_cnt);
		free(line);
	}
}

int	open_fd(char *path)
{
	int	fd;

	if (ft_strlen(path) < 4 || !(ft_strrchr(path, '.')))
		printf("Not a cub file.\n");
	if (ft_strncmp(ft_strrchr(path, '.'), ".cub", 4) == 0)
		fd = open(path, O_RDONLY);
	else
		printf("Not a cub file.\n");
	return (fd);
}

int parse_fc(char *line, t_parser *parser)
{
    int     i;
    int     j;
    int     num;

    if (!ft_strncmp(line, "F ", 2))
    {
        i = 1;
        j = -1;
        while (++j < 3)
        {
            num = 0;
            while (line[++i] && line[i] != ',')
            {
                if (line[i] != ' ')
                    num *= 10;
                num += line[i] - '0';
            }
            parser->floor[j] = num;
        }
        printf("parser.floor = %d, %d, %d\n", parser->floor[0], parser->floor[1], parser->floor[2]);
    }
    else if (!ft_strncmp(line, "C ", 2))
    {
        i = 1;
        j = -1;
        while (++j < 3)
        {
            num = 0;
            while (line[++i] && line[i] != ',')
            {
                if (line[i] != ' ')
                    num *= 10;
                num += line[i] - '0';
            }
            parser->ceiling[j] = num;
        }
        printf("parser.ceiling = %d, %d, %d\n", parser->ceiling[0], parser->ceiling[1], parser->ceiling[2]);
    }
    return (1);
}

int parse_textures(char *line, t_parser *parser)
{
    int i;

    i = 0;
    if (!ft_strncmp(line, "NO ", 3))
    {
        parser->north = malloc(sizeof(line) * (ft_strlen(line) - 3));
        i = 2;
        while (line[++i])
            parser->north[i - 3] = line[i];
        parser->north[i - 3] = '\0';
        printf("parser.north = %s\n", parser->north);
    }
    if (!ft_strncmp(line, "SO ", 3))
    {
        parser->south = malloc(sizeof(line) * (ft_strlen(line) - 3));
        i = 2;
        while (line[++i])
            parser->south[i - 3] = line[i];
        parser->south[i - 3] = '\0';
        printf("parser.south = %s\n", parser->south);
    }
    if (!ft_strncmp(line, "WE ", 3))
    {
        parser->west = malloc(sizeof(line) * (ft_strlen(line) - 3));
        i = 2;
        while (line[++i])
            parser->west[i - 3] = line[i];
        parser->west[i - 3] = '\0';
        printf("parser.west = %s\n", parser->west);
    }
    if (!ft_strncmp(line, "EA ", 3))
    {
        parser->east = malloc(sizeof(line) * (ft_strlen(line) - 3));
        i = 2;
        while (line[++i])
            parser->east[i - 3] = line[i];
        parser->east[i - 3] = '\0';
        printf("parser.east = %s\n", parser->east);
    }
    return (1);
}

int		parse_line(t_parser *parser, char *line, int *row_cnt)
{
	if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) 
            || !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3))
        return (parse_textures(line, parser));
	else if (!ft_strncmp(line, "F ", 2) ||	!ft_strncmp(line, "C ", 2))
		return (parse_fc(line, parser));
    *row_cnt += 1;
	return (1);
}

int	parser_start(int fd, t_parser *parser)
{
	char	    *line;
	int		    ptr;
    int         row_cnt;

    row_cnt = 0;
	while ((ptr = get_next_line(fd, &line)) > 0)
	{
		parse_line(parser, line, &row_cnt);
		free(line);
	}
    return (row_cnt);
}   