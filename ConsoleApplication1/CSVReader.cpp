#include "CSVReader.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
CSVReader::CSVReader() {

};
vector<OrderBookEntry>CSVReader::readCSV(string csvFilename) {
	vector<OrderBookEntry> entries;
	ifstream csvFile{ csvFilename };
	string line;
	if (csvFile.is_open()) {

		while (getline(csvFile, line))
		{

			try {
				OrderBookEntry Obe = stringToOBE(tokenise(line, ','));
				entries.push_back(Obe);
			}
			catch (const exception& e)
			{
				cout << "CSVReader::readCSV bad data" << endl;

			}
		}
		cout << "CSVReader::readCSV read " << entries.size() << "entries" << endl;
		return entries;
	};
}
	vector<string> CSVReader::tokenise(string csvLine, char separator) {
		vector<string> tokens;


		if (csvLine.empty()) {
			return tokens;
		}

		signed int start, end;
		string token;


		start = csvLine.find_first_not_of(separator, 0);

		do {

			end = csvLine.find(separator, start);

			if (start == csvLine.length()) {
				break;
			}
			else if (end != string::npos) {
				token = csvLine.substr(start, end - start);
				tokens.push_back(token);
				start = end + 1;
			}
			else {
				token = csvLine.substr(start, csvLine.length() - start);
				tokens.push_back(token);
				break;
			}

		} while (end != string::npos);

		return tokens;

	}


OrderBookEntry CSVReader::stringToOBE(vector<string> tokens) {
	double price, amount;
	if (tokens.size() != 5) {
		cout << "Bad line: Expected 5 tokens but got " << endl;
		throw exception{};
	}
	try {
		price = stod(tokens[3]);  // Convert the 4th element to double
		amount = stod(tokens[4]); // Convert the 5th element to double
		cout << price << ":" << amount << endl;
	}
	catch (const exception& e) {
		cout << " CSVReader::stringToOBE bad float! " << tokens[3] << endl;
		cout << " CSVReader::stringToOBE bad float! " << tokens[4] << endl;
		throw;
	}

	// Return the populated OrderBookEntry
	OrderBookEntry Obe{ price, amount, tokens[0], tokens[1], OrderBookEntry::stringToOrderBookType(tokens[2]) };
	return Obe;
}
 OrderBookEntry CSVReader::stringToOBE(string pricestring, string amountstring, string timestamp, string products, OrderBookType OrderType) {
	 double price, amount;
	try {
		price = stod(pricestring);  // Convert the 4th element to double
		amount = stod(amountstring); // Convert the 5th element to double
		cout << price << ":" << amount << endl;
	}
	catch (const exception& e) {
		cout << " CSVReader::stringToOBE bad float! " << pricestring << endl;
		cout << " CSVReader::stringToOBE bad float! " << amountstring << endl;
		throw;
	}
	OrderBookEntry Obe{ price, amount, timestamp, products, OrderType };
	return Obe;
}