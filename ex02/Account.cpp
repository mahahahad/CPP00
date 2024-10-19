#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

using std::cout;
using std::string;

enum	TerminatingChars {
	SEMICOLON,
	NEWLINE,
};

/**
 * @brief Print a string key and int value pair.
 * End with a semicolon by default.
 * Optionally, pass the NEWLINE value from the TerminatingChars enum to display
 * a newline instead of a semicolon at the end.
 * 
 * @param key 
 * @param value 
 * @param tc 
 */
inline void	printKeyValue(string key, int value, TerminatingChars tc = SEMICOLON) {
	cout << key << ":" << value;
	(tc == NEWLINE) ? cout << std::endl : cout << ';';
}

/**
 * @brief Print a string key and string value pair.
 * End with a semicolon by default.
 * Optionally, pass the NEWLINE value from the TerminatingChars enum to display
 * a newline instead of a semicolon at the end.
 * 
 * @param key 
 * @param value 
 * @param tc 
 */
inline void	printKeyValue(string key, string value, TerminatingChars tc = SEMICOLON) {
	cout << key << ":" << value;
	(tc == NEWLINE) ? cout << std::endl : cout << ';';
}

/**
 * Constructor for an Account class.
 * 
 * Follows this format:
 * [TIMESTAMP] index:[ACC_ID];amount:[AMOUNT];created
 */
Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;

	_displayTimestamp();
	printKeyValue("index", _accountIndex);
	printKeyValue("amount", _amount);
	cout << "created" << std::endl;
}

/**
 * Destructor for an Account class.
 * 
 * Follows this format:
 * [TIMESTAMP] index:[ACC_ID];amount:[AMOUNT];closed
 */
Account::~Account() {
	_displayTimestamp();
	printKeyValue("index", _accountIndex);
	printKeyValue("amount", _amount);
	cout << "closed" << std::endl;
}

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;
int		Account::getNbAccounts( void ) {
	return (_nbAccounts);
}
int		Account::getTotalAmount( void ) {
	return (_totalAmount);
}
int		Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}
int		Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

/**
 * Display the cumulative accounts information
 * Follows this format:
 * accounts:[NB_ACCS];total:[TOTAL_AMOUNT];deposits:[NB_DEPOSITS];withdrawals:[NB_WITHDRAWALS]
 */
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	printKeyValue("accounts", getNbAccounts());
	printKeyValue("total", _totalAmount);
	printKeyValue("deposits", getNbDeposits());
	printKeyValue("withdrawals", getNbWithdrawals(), NEWLINE);
}

/**
 * Make a deposit from the account at index position.
 * Add the deposit amount to the balance and increment the number of deposits
 * variable.
 * 
 * Follows this format:
 * [TIMESTAMP] index:[ACC_ID];p_amount:[AMOUNT];deposit:[DEPOSIT];amount:[AMOUNT];nb_deposits:[NB_DEPOSITS]
 */
void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	printKeyValue("index", _accountIndex);
	printKeyValue("p_amount", _amount);
	printKeyValue("deposit", deposit);
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	printKeyValue("amount", _amount);
	printKeyValue("nb_deposits", _nbDeposits, NEWLINE);
}

/**
 * Util function for getting the current accounts amount.
 * 
 * @return int 
 */
int		Account::checkAmount( void ) const {
	return (_amount);
}

/**
 * Make a withdrawal from the account at index position.
 * Subtract the withdrawal amount from the balance if possible. Otherwise,
 * print the refused message and abort the transaction.
 * 
 * Follows this format:
 * (INSUFFICIENT FUNDS) [TIMESTAMP] index:[ACC_ID];p_amount:[AMOUNT];withdrawal:refused
 * (NORMAL) [TIMESTAMP] index:[ACC_ID];p_amount:[AMOUNT];withdrawal:[WITHDRAWAL];amount:[AMOUNT];nb_withdrawals:[NB_WITHDRAWALS]
 */
bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	printKeyValue("index", _accountIndex);
	printKeyValue("p_amount", _amount);
	if (checkAmount() - withdrawal < 0) {
		printKeyValue("withdrawal", "refused", NEWLINE);
		return (false);
	}
	else {
		printKeyValue("withdrawal", withdrawal);
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		printKeyValue("amount", _amount);
		printKeyValue("nb_withdrawals", _nbWithdrawals, NEWLINE);
	}
	return (true);
}

/**
 * Display the status of the account at index position.
 * 
 * Follows this format:
 * [TIMESTAMP] index:[ACC_ID];amount:[AMOUNT];deposits:[NB_DEPOSITS];withdrawals:[NB_WITHDRAWALS]
 */
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	printKeyValue("index", _accountIndex);
	printKeyValue("amount", _amount);
	printKeyValue("deposits", _nbDeposits);
	printKeyValue("withdrawals", _nbWithdrawals, NEWLINE);
}

/**
 * Display the current time
 * This is meant to be used before the other functions in this class.
 * Follow this format:
 * [YYYYMMDD_HHMMSS]
 */
void	Account::_displayTimestamp( void ) {
	std::time_t	current_time = std::time(NULL);
	tm	*local_time = localtime(&current_time);

	cout << std::setfill('0');
	cout << "["
		 << std::setw(4) << local_time->tm_year + 1900
		 << std::setw(2) << local_time->tm_mon + 1
		 << std::setw(2) << local_time->tm_mday
		 << "_"
		 << std::setw(2) << local_time->tm_hour
		 << std::setw(2) << local_time->tm_min
		 << std::setw(2) << local_time->tm_sec
		 << "] ";
}
