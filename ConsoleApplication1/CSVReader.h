#pragma once
#include "OrderBookEntry.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class CSVReader {
public:
	CSVReader();
	
	static vector<OrderBookEntry>readCSV(string csvFile);
	static vector<string> tokenise(string csvLine, char separator);
	static OrderBookEntry stringToOBE(string price, string amount,string timestamp, string products,OrderBookType OrderBookType);

private:
	
	static OrderBookEntry stringToOBE(vector<string> strings);
};