#include <ft.h>
#include <ft_list.h>
#include <ft_dict.h>
#include <ft_fparser.h>

int main(int argc, char **argv)
{
	t_list *dictionary;
	int file;

	if (argc == 2)
		file = open("./numbers.txt", O_RDONLY);
	if (argc == 3)
		file = open(argv[1], O_RDONLY);
	parsedict(file, dictionary);
}