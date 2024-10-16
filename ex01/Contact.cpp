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
		first_name_ = response;
	else if (input_label == "Last Name")
		last_name_ = response;
	else if (input_label == "Nickname")
		nickname_ = response;
	else if (input_label == "Phone Number")
		phone_number_ = response;
	else if (input_label == "Darkest Secret")
		darkest_secret_ = response;
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
	return (first_name_);
}

/**
 * @brief Get the last name of the contact
 *
 * @return string
 */
string	Contact::getLastName(void) {
	return (last_name_);
}

/**
 * @brief Get the nickname of the contact
 *
 * @return string
 */
string	Contact::getNickname(void) {
	return (nickname_);
}

/**
 * @brief Print all the information about this contact in a human-redable
 * format.
*/
void	Contact::printInfo(void) {
	cout << "First Name: " << first_name_ << "\n";
	cout << "Last Name: " << last_name_ << "\n";
	cout << "Nickname: " << nickname_ << "\n";
	cout << "Phone Number: " << phone_number_ << "\n";
	cout << "Darkest Secret: " << darkest_secret_ << "\n";
}
