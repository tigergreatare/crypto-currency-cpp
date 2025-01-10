
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
enum class OrderBookType { bid, ask, unknown, sale };

class OrderBookEntry {
public:
    OrderBookEntry(double p, double a, std::string t, std::string pr, OrderBookType o);
   static OrderBookType stringToOrderBookType(std::string s);
   static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2) {
       return e1.timestamp < e2.timestamp;
   }
   static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2) {
       return e1.price < e2.price;
   }
   static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2) {
       return e1.price > e2.price;
   }
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;

    // Optionally you can add other member functions here if needed.
};
