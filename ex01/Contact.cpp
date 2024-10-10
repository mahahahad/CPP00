#include "Common.hpp"
#include "Contact.hpp"

/**
 * @brief Prompt the user to input the contacts: first_name, last_name, nickname, phone_number, and darkest_secret.
 * Create a contact using this information and return it.
 *
 * @return Contact
 */
Contact Contact::initialize(void) {
	cout << "First name> ";
	getline(cin, first_name_);
	cout << "Last name> ";
	getline(cin, last_name_);
	cout << "Nickname> ";
	getline(cin, nickname_);
	cout << "Phone Number> ";
	getline(cin, phone_number_);
	cout << "Darkest Secret> ";
	getline(cin, darkest_secret_);
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
