#include "Account.hpp"

/**
 * Constructor for an Account class.
 */
// index:0;amount:42;created
Account::Account( int initial_deposit ) { }
// index:0;amount:47;closed
Account::~Account() { }

int		Account::getNbAccounts( void ) { }
int		Account::getTotalAmount( void ) { }
int		Account::getNbDeposits( void ) { }
int		Account::getNbWithdrawals( void ) { }

/**
 * Display the cumulative accounts information
 * Follow this format:
 * accounts:8;total:20049;deposits:0;withdrawals:0
 */
void	Account::displayAccountsInfos( void ) { }

/**
 * Make a deposit from the account at index position.
 * Add the deposit amount to the balance and increment the number of deposits
 * variable.
 * Follow this format:
 * index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
 */
void	Account::makeDeposit( int deposit ) { }

/**
 * Make a withdrawal from the account at index position.
 * Subtract the withdrawal amount from the balance if possible. Otherwise,
 * print the refused message and abort the transaction. 
 * Follow this format:
 * index:0;p_amount:47;withdrawal:refused
 * index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
 */
bool	Account::makeWithdrawal( int withdrawal ) { }
int		Account::checkAmount( void ) const { }

/**
 * Display the status of the account at index position.
 * Follow this format:
 * index:0;amount:47;deposits:1;withdrawals:0
 */
void	Account::displayStatus( void ) const { }

/**
 * Display the current time
 * This is meant to be used before the other functions in this class.
 * Follow this format:
 * [YYYYMMDD_HHMMSS]
 */
void	Account::_displayTimestamp( void ) { }
