#include <iostream>

int	shout(char *str)
{
	int	i = 0;

	while (str[i])
		std::cout << (char) toupper(str[i++]);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	i = 0;
	argv++;
	while (i + 1 < argc)
		shout(argv[i++]);
	std::cout << "\n";
	return (0);
}
