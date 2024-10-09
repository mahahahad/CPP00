#include "Common.hpp"
#include "PhoneBook.hpp"

/**
 * @brief Construct a new Phone Book object and set the active index to 0.
 * This value will be used later to add contacts to the phonebook.
 */
PhoneBook::PhoneBook() {
	active_index_ = 0;
}

/**
 * @brief Add a new contact to the list of contacts in the phonebook
 * If the phonebook is full i.e. already contains 8 contacts, the oldest 
 * contact is replaced and every contact is shifted to the left and the new 
 * contact is added at the end of the list.
 */
void	PhoneBook::AddContact() {
	Contact	new_contact;

	if (active_index_ == 8) {
		string response;
		cout << "Warning: This will overwrite your oldest contact\n";
		cout << "Continue? [y/n]> ";
		getline(cin, response);
		if (response == "y") {
			for (int i = 0; i < 8; i++) {
				if (i == 7) {
					contacts[7] = new_contact.Initialize();
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
		contacts[active_index_++] = new_contact.Initialize();
}

/**
 * @brief List all of the contacts in the phonebook
 */
void	PhoneBook::ListContacts(void) {
	if (active_index_ == 0) {
		cout << "You have no contacts in your phonebook\n";
		return ;
	}
	for (int i = 0; i < active_index_; i++) {

		PrintValue("Index", '|');
		PrintValue("F. Name", '|');
		PrintValue("L. Name", '|');
		PrintValue("Nickname", '\n');
		PrintValue(NumToStr(i + 1), '|');
		PrintValue(contacts[i].GetFirstName(), '|');
		PrintValue(contacts[i].GetLastName(), '|');
		PrintValue(contacts[i].GetNickname(), '\n');
	}
}

/**
 * @brief Print the provided string with the prefix and suffix and 10 character 
 * padding.
 * If the string exceeds the 10 character limit, it is truncated and a '.' is 
 * displayed as the last character.
 * 
 * @param str 
 */
void	PhoneBook::PrintValue(string str, char suffix) {
	int	str_length = str.length();
	int	pad_length = 10 - str_length;

	if (pad_length < 0) {
		cout << str.substr(0, 9) << '.';
	}
	else {
		for (int i = 0; i < pad_length; i++) {
			cout << ' ';
		}
		cout << str;
	}
	if (suffix != '\0') {
		cout << suffix;
	}
}

/**
 * @brief Find a specific contact from the phonebook
 */
void	PhoneBook::FindContact(void) {
	ListContacts();
}
