#include "Common.hpp"
#include "Contact.hpp"

void	Contact::getInput(string input_label) {
	string	response;

	cout << input_label << "> ";
	getline(cin, response);
	response = trim(response);
	while (response.empty()) {
		handleEOF();
		cout << input_label << " cannot be empty. Please try again.\n";
		cout << input_label << "> ";
		getline(cin, response);
		response = trim(response);
	}
	if (input_label == "First Name")
		_first_name = response;
	else if (input_label == "Last Name")
		_last_name = response;
	else if (input_label == "Nickname")
		_nickname = response;
	else if (input_label == "Phone Number")
		_phone_number = response;
	else if (input_label == "Darkest Secret")
		_darkest_secret = response;
}

/**
 * @brief Prompt the user to input the contacts: first_name, last_name, nickname, phone_number, and darkest_secret.
 * Create a contact using this information and return it.
 *
 * @return Contact
 */
Contact Contact::initialize(void) {
	getInput("First Name");
	getInput("Last Name");
	getInput("Nickname");
	getInput("Phone Number");
	getInput("Darkest Secret");
	return (*this);
}

/**
 * @brief Get the first name of the contact
 *
 * @return string
 */
string	Contact::getFirstName(void) {
	return (_first_name);
}

/**
 * @brief Get the last name of the contact
 *
 * @return string
 */
string	Contact::getLastName(void) {
	return (_last_name);
}

/**
 * @brief Get the nickname of the contact
 *
 * @return string
 */
string	Contact::getNickname(void) {
	return (_nickname);
}

/**
 * @brief Print all the information about this contact in a human-redable
 * format.
*/
void	Contact::printInfo(void) {
	cout << "First Name: " << _first_name << "\n";
	cout << "Last Name: " << _last_name << "\n";
	cout << "Nickname: " << _nickname << "\n";
	cout << "Phone Number: " << _phone_number << "\n";
	cout << "Darkest Secret: " << _darkest_secret << "\n";
}
