
// MerkelMain.h
#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"
using namespace std;
class MerkelMain {
public:
    MerkelMain();
    void init();

private:
    void loadOrderBook();
    void printMenu();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    int getUserOption();
    void processUserOption(int userOption);

   /* double AveragePrice(const vector<OrderBookEntry>& orders);
    double lowestPrice(const vector<OrderBookEntry>& orders);
    double highestPrice(const vector<OrderBookEntry>& orders);*/
    string currentTime;
    OrderBook orderBook{ "C:\\Users\\alaad\\Desktop\\bullshit\\to be organized 2.0\\20200317.csv" };

    //vector<OrderBookEntry> orders;
    Wallet wallet;
};
