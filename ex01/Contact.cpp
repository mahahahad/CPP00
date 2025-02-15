/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:44:12 by maabdull          #+#    #+#             */
/*   Updated: 2025/02/15 13:44:13 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Common.hpp"
#include "Contact.hpp"

/**
 * @brief Get input from the standard input until a string is received
 *
 * @param prompt The prompt to display before the input is read.
 *
 * @return string
 */
string    promptAndGetString(string prompt) {
    string  response;

    do {
        cout << prompt;
        getline(cin, response);
        response = trim(response);
		handleEOF();
        if (response.empty())
		    cout << "Value cannot be empty. Please try again.\n";
   } while (response.empty());
    return response;
}

/**
 * @brief Get input from the standard input until an integer is received
 *
 * @param prompt The prompt to display before the input is read.
 * @return int
 */
int    promptAndGetInt(string prompt) {
    string  response;
    int     converted;

    do {
        response = promptAndGetString(prompt);
        converted = atoi(response.c_str());
        if (!converted) {
            cout << "Value is invalid or 0. Please try again.\n";
        }
    } while (!converted);
    return converted;
}

/**
 * @brief Prompt the user to input the contacts: first_name, last_name, nickname, phone_number, and darkest_secret.
 * Create a contact using this information and return it.
 *
 * @return Contact
 */
Contact Contact::initialize(void) {
    _first_name = promptAndGetString("First Name> ");
    _last_name = promptAndGetString("Last Name> ");
    _nickname = promptAndGetString("Nickname> ");
    _phone_number = promptAndGetInt("Phone Number> ");
    _darkest_secret = promptAndGetString("Darkest Secret> ");
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
