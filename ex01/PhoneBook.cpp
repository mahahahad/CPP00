/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:09:49 by maabdull          #+#    #+#             */
/*   Updated: 2025/02/15 14:10:32 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book object and set the active index to 0.
 * This value will be used later to add contacts to the phonebook.
 */
PhoneBook::PhoneBook() {
	_active_index = 0;
}

/**
 * @brief Add a new contact to the list of contacts in the phonebook
 * If the phonebook is full i.e. already contains 8 contacts, the oldest
 * contact is replaced and every contact is shifted to the left and the new
 * contact is added at the end of the list.
 */
void	PhoneBook::addContact(void) {
	Contact	new_contact;

	if (_active_index == 8) {
		string response;
		cout << "Warning: This will overwrite your oldest contact\n";
		cout << "Continue? [y/n]> ";
		getline(cin, response);
		if (response == "y") {
			for (int i = 0; i < 8; i++) {
				if (i == 7) {
					contacts[7] = new_contact.initialize();
					return ;
				}
				contacts[i] = contacts[i + 1];
			}
		}
		else {
			cout << "Ignoring...\n";
		}
	}
	else
		contacts[_active_index++] = new_contact.initialize();
}

/**
 * @brief List all of the contacts in the phonebook
 */
int	PhoneBook::listContacts(void) {
	if (_active_index == 0) {
		cout << "You have no contacts in your phonebook\n";
		return (-1);
	}
	printValue("Index", '|');
	printValue("F. Name", '|');
	printValue("L. Name", '|');
	printValue("Nickname", '\n');
	for (int i = 0; i < _active_index; i++) {
		printValue(numToStr(i + 1), '|');
		printValue(contacts[i].getFirstName(), '|');
		printValue(contacts[i].getLastName(), '|');
		printValue(contacts[i].getNickname(), '\n');
	}
	return (0);
}

/**
 * @brief Print the provided string with the prefix and suffix and 10 character
 * padding.
 * If the string exceeds the 10 character limit, it is truncated and a '.' is
 * displayed as the last character.
 *
 * @param str
 */
void	PhoneBook::printValue(string str, char suffix) {
	if (str.size() <= 10) {
		cout << str.insert(0, 10 - str.size(), ' ');
	}
	else {
		cout << str.substr(0, 9) << ".";
	}
	if (suffix != '\0') {
		cout << suffix;
	}
}

/**
 * @brief Find a specific contact from the phonebook
 */
void	PhoneBook::findContact(void) {
	string	contact_index;
	int int_id;

	if (listContacts() == -1) {
		return ;
	}
	do {
		cout << "Index to display [";
		for (int i = 0; i < _active_index; i++) {
			cout << i + 1;
			if (i + 1 != _active_index)
				cout << "/";
		}
		cout << "]> ";
		getline(cin, contact_index);
		handleEOF();
		int_id = atoi(contact_index.c_str());
		if (int_id - 1 < 0 || int_id - 1 >= _active_index)
			cout << "Please enter a valid index\n";
	} while (int_id - 1 < 0 || int_id - 1 >= _active_index);
	contacts[int_id - 1].printInfo();
}
