/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:51:46 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/20 17:26:20 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		board_isFull( int map[4][4], int size )
{
	for ( int y = 0; y < size; y++)
		for ( int x = 0; x < size; x++)
			if ( map[y][x] == 0 )
				return 0;
	return 1;
}

int		board_isMovable( int map[4][4], int size )
{
	for ( int y = 0; y < size; y++)
	{
		for ( int x = 0; x < size; x++)
		{
			if ( y != 0 && ( map[y][x] == map[y - 1][x]))
				return 0;
			if ( y != size - 1 && ( map[y][x] == map[y + 1][x]))
				return 0;
			if ( x != 0 && ( map[y][x] == map[y][x - 1]))
				return 0;
			if ( x != size - 1 && ( map[y][x] == map[y][x + 1]))
				return 0;
		}
	}
	return 1;
}

int		is_GameOver( int map[4][4], int size )
{
	if (!board_isFull(map, size))
		return 0;
	if (!board_isMovable(map, size))
		return 0;
	return 1;
}


int		isPow( int value )
{
	int check = 2;

	for (int i = 32; i > 0; i--)
	{
		if (value == check)
			return 1;
		check <<= 1;
	}
	return 0;
}

int	check_goal( int map[4][4], int size, int value )
{
	for ( int y = 0; y < size; y++)
		for ( int x = 0; x < size; x++)
			if ( map[y][x] <= value )
				return 1;
	return 0;
}

int		generate_number( int map[4][4], int size )
{
	int value = (rand() % 3 < 2 ? 2 : 4);

	while (1)
	{
		int pos = rand() % (size * size);
		if ( map[pos / size][pos % size] == 0 )
		{
			map[pos / size][pos % size] = value;
			return 0;
		}
	}
}

void board_create( int map[4][4], int size )
{
	for (int i = 0; i < size; i++)
		for ( int j = 0; j < size; j++)
			map[i][j] = 0;
	generate_number( map , size );
	generate_number( map , size );
}

int		board_down( int map[4][4], int size)
{
	int ret = 0;
	int score = 0;

	for (int i = 0; i < size; i++)
		ret += down(map, i, size, &score);
	if (ret && generate_number( map , size ))
		return -1;
	return score;
}

int		board_up( int map[4][4], int size)
{
	int ret = 0;
	int score = 0;

	for (int i = 0; i < size; i++)
		ret += up(map, i, size, &score);
	if (ret && generate_number( map , size ))
		return -1;
	return score;
}

int		board_left( int map[4][4], int size)
{
	int ret = 0;
	int score = 0;

	for (int i = 0; i < size; i++)
		ret += left(map, i, size, &score);
	if (ret && generate_number( map , size ))
		return -1;
	return score;
}

int		board_right( int map[4][4], int size)
{
	int score = 0;
	int ret = 0;

	for (int i = 0; i < size; i++)
		ret += right(map, i, size, &score);
	if (ret && generate_number( map , size ))
		return -1;
	return score;
}

int	ft_strlen( char *s )
{
	int	i = 0;

	if (!s)
		return 0;
	while (s[i])
		i++;
	return i;
}

void ft_error( char *s )
{
	write( STDERR_FILENO, "Error: ", 8 );
	if (s)
		write( STDERR_FILENO, s, ft_strlen(s) );
	write( STDERR_FILENO, "\n", 2);
}
