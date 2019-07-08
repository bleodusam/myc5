#include <unistd.h>

int check_next_poitions_in_colonne(int old_value, int colon_number)
{
	int i;
	int j;

	i = colon_number;
	j = old_value + 1;
	while(j <= 9)	//si cetait deja 9 on return direct, sinon on essaie une valeur j superieure
	{
		while(i >= 0)	//on parcoure le tableau pour tester j ds cette colonne
		{
				if(tab[i] == j || (tab[i] == (i - j)) || (tab[i] == (i + j)))
				{
					j++; // cest bas bon => on essai +1 ds la colonne
					i = 0;
				}
				if(i == 9)
					return (j);
				i--;
		}
	}
	return(50);
}

int ft_ten_queens_puzzle()
{
	int output;
	int tab[]= {0,2,5,7,9,4,8,1,3,6};
	int i;

	output = 1;
	i = -1;
	while(++i < 10)
		write(1, '0' + &tab[i], 1);
	i = 9;
	while(i >= 0 && i < 10)
	{
		tab[i] = check_next_poitions_in_colonne(tab[i], i);		// si pas possible => val 10

		if(check_next_poitions_in_colonne(tab[i], i) == 50)
			i--;
		else
			i++;
	}
	if(i == 10)
	{
		i = -1;
		while(++i < 10)
			write(1,'0' + &tab[i],1);
		output++;
		find_next_solution(tab)
	}
	if(i == 0)
		return(output)
}
