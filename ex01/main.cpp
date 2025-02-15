/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:09:58 by maabdull          #+#    #+#             */
/*   Updated: 2025/02/15 14:10:58 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Utility function to convert integers to strings
 * Used in printing the index of contacts with padding.
 *
 * @param num
 * @return string
 */
string	numToStr(int num) {
	std::ostringstream str_stream;
	str_stream << num;
	return (str_stream.str());
}

string	trim(string original) {
	const string whitespaces = " \t\r\n\f\v";
	original.erase(0, original.find_first_not_of(whitespaces));
	original.erase(original.find_last_not_of(whitespaces) + 1);
	return original;
}

void	handleEOF(void) {
	if (cin.eof()) {
		cout << endl;
		cout << "Exiting...";
		std::exit(0);
	}
}

int	main(void) {
	string		input;
	PhoneBook	phonebook;

	do {
		cout << "Enter a command [ADD/SEARCH/EXIT]> ";
		getline(cin, input);
		handleEOF();

		if (input == "ADD") {
			phonebook.addContact();
		}
		else if (input == "SEARCH") {
			phonebook.findContact();
		}
		else if (input == "EXIT") {
			return (0);
		}
		else {
			cout << "Please enter a valid command\n";
		}
	} while (input != "EXIT" && !cin.eof());
	return (0);
}
