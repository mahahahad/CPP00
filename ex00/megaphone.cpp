/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:43:37 by maabdull          #+#    #+#             */
/*   Updated: 2025/02/15 14:38:01 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	shout(char *str) {
	int	i = 0;

	while (str[i])
		std::cout << (char) toupper(str[i++]);
	return (0);
}

int	main(int argc, char **argv) {
	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);

	int	i = 0;
	argv++;
	while (i + 1 < argc)
		shout(argv[i++]);
	std::cout << "\n";
	return (0);
}
