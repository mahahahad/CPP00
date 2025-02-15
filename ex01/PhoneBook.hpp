/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabdull <maabdull@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:45:06 by maabdull          #+#    #+#             */
/*   Updated: 2025/02/15 14:47:13 by maabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	Contact contacts[8];
	void	addContact( void );
	int		listContacts( void );
	void	findContact( void );

private:
	int		_active_index;
	void	printValue( string str, char suffix );
};

#endif
