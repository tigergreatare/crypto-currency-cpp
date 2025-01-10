// MerkelMain.cpp
#include "MerkelMain.h"
#include <iostream>
#include<algorithm>
#include "CSVReader.h"
using namespace std;
MerkelMain::MerkelMain() {

}

void MerkelMain::init() {
   //loadOrderBook();
    int input;
    
    currentTime = orderBook.getEarliestTime();
    wallet.insertCurrency("BTC", 10);
    while (true) {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

//void MerkelMain::loadOrderBook() {
////    /*orders.push_back(OrderBookEntry{ 1000, 0.2222, "2022/03/17 18:01:24.88449", "BTC/USDT", OrderBookType::bid });
////    orders.push_back(OrderBookEntry{ 100, 0.2222, "2022/03/17 18:01:24.88449", "BTC/USDT", OrderBookType::bid });*/
//   orders = CSVReader::readCSV("C:\\Users\\alaad\\Desktop\\bullshit\\to be organized 2.0\\20200317.csv");
//}

void MerkelMain::printMenu() {
    std::cout << "1: Print help\n2: Print exchange stats\n3: Make an offer\n4: Make a bid\n5: Print wallet\n6: Continue\n==============\n";
    cout << "Current time is : " << currentTime << endl;
}

void MerkelMain::printHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers.\n";
}

void MerkelMain::printMarketStats() {
    for (string const& p : orderBook.getKnownProducts()) {
        cout << "Product: " << p << endl;
        vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        cout << "Asks seen : " << entries.size() << endl;
        cout << " Max ask : " << OrderBook::getHighPrice(entries) << endl;
        cout << "Min ask : " << OrderBook::getLowPrice(entries) << endl;
    }
    /*cout << "OrderBook contains : " << orders.size() << " entries " << endl;
    unsigned int bids = 0;
    unsigned int asks = 0;
    for (OrderBookEntry& e : orders) {
        if (e.orderType == OrderBookType::ask) {
            asks++;
        }
        if (e.orderType == OrderBookType::bid) {
            bids++;
        }
    }
    cout << "OrderBook asks : " << asks << " bids : " << bids << endl;*/
    
}

void MerkelMain::enterAsk() {
    std::cout << "Make a ask -enter the amount: product, price, amount, eg ETH/BTC,200,0.5\n";
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    vector<string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() !=3) {
        cout << " bad input! " << input << endl;
        
    }
    else {
        try {
            OrderBookEntry Obe = CSVReader::stringToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask

            );
            if (wallet.canFulfillOrder(Obe)) {
                cout << "wallet looks good. " << endl;
                orderBook.insertOrder(Obe);
            }
            else {
                cout << "wallet has insufficient funds. " << endl;
            }
        }
        catch (const exception& e) {
            cout << "MerkelMain::enterask Bad input! " << endl;
       }
    }

   

}

void MerkelMain::enterBid() {
    std::cout << "Make a bid enter the amount: product, price, amount, eg ETH/BTC,200,0.5\n";
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    vector<string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3) {
        cout << "MerkelMain::enterBid  bad input! " << input << endl;

    }
    else {
        try {
            OrderBookEntry Obe = CSVReader::stringToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid

            );
            if (wallet.canFulfillOrder(Obe)) {
                cout << "wallet looks good. " << endl;
                orderBook.insertOrder(Obe);
            }
            else {
                cout << "wallet has insufficient funds. " << endl;
            }
        }
        catch (const exception& e) {
            cout << "MerkelMain::enterBid Bad input! " << endl;
        }
    }
   

}

void MerkelMain::printWallet() {
    /*std::cout << "Your wallet is empty.\n";*/
   cout << wallet.toString() << endl;
}

void MerkelMain::gotoNextTimeframe() {
    std::cout << "Going to next time frame.\n";
    vector<OrderBookEntry> sales=orderBook.matchAsksToBids("ETH/BTC", currentTime);
    cout << "Sales : " << sales.size() << endl;
    for (OrderBookEntry& sale : sales) {
        cout << "Sale price: " << sale.price << "amount" << sale.amount << endl;
    }
    currentTime = orderBook.getNextTime(currentTime);
}

int MerkelMain::getUserOption() {
    int userOption =0;
    string line;
    std::cout << "Type in 1-6\n";
    getline(cin, line);
    try {
        userOption = stoi(line);
    }
    catch (const exception& e) {
        //
    }
    /*std::cin >> userOption;*/
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption) {
    if (userOption == 1) printHelp();
    if (userOption == 2) printMarketStats();
    if (userOption == 3) enterAsk();
    if (userOption == 4) enterBid();
    if (userOption == 5) printWallet();
    if (userOption == 6) gotoNextTimeframe();
    
}
//
//double MerkelMain::AveragePrice(const std::vector<OrderBookEntry>& orders) {
//    double total = 0;
//    for (const auto& order : orders) {
//        total += order.price;
//    }
//    return total / orders.size();
//}
//
//double MerkelMain::lowestPrice(const std::vector<OrderBookEntry>& orders) {
//    double lowPrice = orders[0].price;
//    for (const auto& order : orders) {
//        if (order.price < lowPrice) {
//            lowPrice = order.price;
//        }
//    }
//    return lowPrice;
//}
//
//double MerkelMain::highestPrice(const std::vector<OrderBookEntry>& orders) {
//    double highPrice = orders[0].price;
//    for (const auto& order : orders) {
//        if (order.price > highPrice) {
//            highPrice = order.price;
//        }
//    }
//    return highPrice;
//}
