void	ft_putchar(char c);

void	rush(int x, int y)
{
	long tox;
	long toy;
	
	y--;
	x--;
	tox = 0;
	toy = 0;
	while (toy <= y)
	{	
		while (tox <= x)
		{
			if (toy == 0)
			{
				if (tox == 0)
				{
					ft_putchar('A');
				}
				else if (tox == x)
				{
					ft_putchar('C');
				}
				else
				{
					ft_putchar('B');
				}
			}
			else if (toy == y)
			{
				if (tox == 0)
				{
					ft_putchar('C');
				}
				else if (tox == x)
				{
					ft_putchar('A');
				}
				else
				{
					ft_putchar('B');
				}

			}	
 			else if ((tox == 0) || (tox == y))
			{
				ft_putchar('B'); 
			}
			else
			{
				ft_putchar(' ');
			}
			tox++;
		}
		ft_putchar('\n');
		toy++;
		tox = 0;
	}
}
