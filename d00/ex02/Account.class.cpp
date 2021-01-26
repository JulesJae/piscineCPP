#include <iostream>
#include <ctime>
#include "Account.class.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created\n";
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount 
		<< ";deposits:" << Account::_totalNbDeposits << ";withdrawals:"
		<< Account::_totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" 
		<< this->_nbDeposits << ";withdrawals:"<< this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int		p_amount;

	Account::_displayTimestamp();
	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits ++;
	Account::_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";deposits:" 
		<< deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int		p_amount;

	Account::_displayTimestamp();
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused\n";
		return false;
	}
	p_amount = this->_amount;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

void Account::_displayTimestamp()
{
	time_t	now;
	tm		*ltm;

	now = time(0);
	ltm = localtime(&now);
	std::cout << "[" << ltm->tm_year + 1900 << ltm->tm_mon + 1 << ltm->tm_mday << "_"
		<< ltm->tm_hour << ltm->tm_min << ltm->tm_sec
		<< "] ";
}