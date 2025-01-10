#pragma once
#include <iostream>
#include <string>
#include <map>
#include "OrderBookEntry.h"
using namespace std;
class Wallet {
public:
	Wallet();
	// insert currency to the wallet
	void insertCurrency(string type, double amount);
	bool removeCurrency(string type, double amount);

	//check if the wallet contains this much currency or more
	bool containsCurrency(string type, double amount);
	bool canFulfillOrder(OrderBookEntry order);
	//generate a string representation of the wallet
	string toString();
private:
	map<string, double> currencies;

};