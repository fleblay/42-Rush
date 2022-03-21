/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlormois <mlormois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 00:27:59 by mlormois          #+#    #+#             */
/*   Updated: 2022/03/20 17:16:42 by mlormois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		fusion( int map[4][4], int y1, int x1, int y2, int x2)
{
	map[y1][x1] <<= 1;
	map[y2][x2] = 0;
	return map[y1][x1];
}

int		make_move( int map[4][4], int y1, int x1, int y2, int x2)
{
	map[y1][x1] = map[y2][x2];
	map[y2][x2] = 0;
	return 1;
}

int		down( int map[4][4], int index, int size, int *score )
{
	int done = 0;
	for (int node = size - 1; node >= 0; node--)
	{
		if (map[node][index] != 0)
		{
			for ( int check = node - 1; check >= 0; check--)
			{
				if (map[node][index] == map[check][index])
				{
					done++;
					*score += fusion(map, node, index, check, index);
					break ;
				}
				else if ( map[check][index] != 0 )
					break ;
			}
		}
	}
	for (int node = size - 1; node >= 0; node--)
	{
		if (map[node][index] == 0)
		{
			for ( int check = node - 1; check >= 0; check--)
			{
				if (map[check][index] != 0)
				{
					done++;
					make_move(map, node, index, check, index);
					break ;
				}
			}
		}
	}
	return done;
}

int		up( int map[4][4], int index, int size, int *score )
{
	int done = 0;
	for (int node = 0; node < size; node++)
	{
		if (map[node][index] != 0)
		{
			for ( int check = node + 1; check < size; check++)
			{
				if (map[node][index] == map[check][index])
				{
					done++;
					*score += fusion(map, node, index, check, index);
					break ;
				}
				else if ( map[check][index] != 0 )
					break ;
			}
		}
	}
	for (int node = 0; node < size; node++)
	{
		if (map[node][index] == 0)
		{
			for ( int check = node + 1; check < size; check++)
			{
				if (map[check][index] != 0)
				{
					done++;
					make_move(map, node, index, check, index);
					break ;
				}
			}
		}
	}
	return done;
}

int		left( int map[4][4], int index, int size, int *score )
{
	int done = 0;
	for (int node = 0; node < size; node++)
	{
		if (map[index][node] != 0)
		{
			for ( int check = node + 1; check< size; check++)
			{
				if (map[index][node] == map[index][check])
				{
					done++;
					*score += fusion(map, index, node, index, check);
					break ;
				}
				else if ( map[index][check] != 0 )
					break ;
			}
		}
	}
	for (int node = 0; node < size; node++)
	{
		if (map[index][node] == 0)
		{
			for ( int check = node + 1; check < size; check++)
			{
				if (map[index][check] != 0)
				{
					done++;
					make_move(map, index, node, index, check);
					break ;
				}
			}
		}
	}
	return done;
}

int		right( int map[4][4], int index, int size , int *score )
{
	int done = 0;
	for (int node = size - 1; node >= 0; node--)
	{
		if (map[index][node] != 0)
		{
			for ( int check = node - 1; check >= 0; check--)
			{
				if (map[index][node] == map[index][check])
				{
					done++;
					*score += fusion(map, index, node, index, check);
					break ;
				}
				else if ( map[index][check] != 0 )
					break ;
			}
		}
	}
	for (int node = size - 1; node >= 0; node--)
	{
		if (map[index][node] == 0)
		{
			for ( int check = node - 1; check >= 0; check--)
			{
				if (map[index][check] != 0)
				{
					done++;
					make_move(map, index, node, index, check);
					break ;
				}
			}
		}
	}
	return done;
}
