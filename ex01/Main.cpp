#include "Common.hpp"
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

int	main(void) {
	string		input;
	PhoneBook	phonebook;

	while (input != "EXIT") {
		cout << "Enter a command [ADD/SEARCH/EXIT]> ";
		getline(cin, input);

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
	}
	return (0);
}
