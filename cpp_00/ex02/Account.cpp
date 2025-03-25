/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedina- <emedina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:41:14 by emedina-          #+#    #+#             */
/*   Updated: 2025/03/25 16:36:18 by emedina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
using namespace std;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

//Este constructor se invoca cuando se crea un objeto con un depósito inicial
Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;

	_displayTimestamp();
	cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"created" <<
	endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"closed" <<
	endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	cout <<
	"accounts:" << getNbAccounts() << ";" <<
	"total:" << getTotalAmount() << ";" <<
	"deposits:" << getNbDeposits() << ";" <<
	"withdrawals:" << getNbWithdrawals() <<
	endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";" <<
	"deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	cout <<
	"amount:" << this->checkAmount() << ";" <<
	"nb_deposits:" << this->_nbDeposits <<
	endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";";
	if (this->checkAmount() < withdrawal)
	{
		cout << "withdrawal:refused" << endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		cout <<
		"withdrawal:" << withdrawal << ";" << "amount:" << this->checkAmount() << ";" << "nb_withdrawals:" << this->_nbWithdrawals << endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	cout <<
	"index:" << this->_accountIndex << ";" << "amount:" << this->checkAmount() << ";" << "deposits:" << this->_nbDeposits << ";" << "withdrawals:" << this->_nbWithdrawals << endl;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(NULL);
	struct tm *time;
	time = localtime(&now);
	cout << "[" << time->tm_year + 1900;
	if(time->tm_mon < 10)
		cout << "0"; 
	cout << time->tm_mon + 1;
	if(time->tm_mday < 10)
		cout << "0"; 
	cout << time->tm_mday << "_";
	if(time->tm_hour < 10)
		cout << "0"; 
	cout << time->tm_hour;
	if(time->tm_min < 10)
		cout << "0"; 
	cout << time->tm_min;
	if(time->tm_sec < 10)
		cout << "0"; 
	cout << time->tm_sec  << "]";
}
