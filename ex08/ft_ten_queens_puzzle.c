/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tin <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:26:39 by tin               #+#    #+#             */
/*   Updated: 2019/07/09 17:22:10 by tin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_tab(int *tab)
{
	int		i;
	char	c;

	i = -1;
	while (++i <= 10)
	{
		c = tab[i] + '0';
		if (i == 10)
			c = '\n';
		write(1, &c, 1);
	}
}

int		check_next_poitions_in_colonne(int value, int col, int *tab)
{
	int col_c;

	if (value == 51)
		value = 0;
	if (col == 0 && value <= 9)
		return (value);
	while (value < 10)
	{
		col_c = 0;
		while (col_c < col)
		{
			if (tab[col_c] == value || (tab[col_c] == (value + col - col_c)) ||
				(tab[col_c] == (value - col + col_c)))
				break ;
			if (col_c == (col - 1))
				return (value);
			col_c++;
		}
		value++;
	}
	return (50);
}

int		*next_board(int *tab, int *output)
{
	int i;

	i = 9;
	while (i >= -1 && i < 10)
	{
		tab[i] = check_next_poitions_in_colonne(tab[i] + 1, i, tab);
		if (tab[i] == 50)
			i--;
		else
			i++;
	}
	if (i == 10)
	{
		print_tab(tab);
		*output = *output + 1;
		next_board(tab, output);
	}
	return (output);
}

int		ft_ten_queens_puzzle(void)
{
	int tab[10];
	int *output;
	int out_int;

	tab[0] = 0;
	tab[1] = 2;
	tab[2] = 5;
	tab[3] = 7;
	tab[4] = 9;
	tab[5] = 4;
	tab[6] = 8;
	tab[7] = 1;
	tab[8] = 3;
	tab[9] = 6;
	out_int = 0;
	output = &out_int;
	print_tab(tab);
	output = next_board(tab, output);
	return (out_int);
}
