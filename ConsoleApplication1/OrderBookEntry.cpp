// OrderBookEntry.cpp
#include "OrderBookEntry.h"
#include <string>

OrderBookEntry::OrderBookEntry(double p, double a, std::string t, std::string pr, OrderBookType o)
    : price(p), amount(a), timestamp(t), product(pr), orderType(o) {
}
OrderBookType OrderBookEntry::stringToOrderBookType(std::string s) {
    if (s == "ask") {
        return OrderBookType::ask;
    }
    if (s == "bid") {
        return OrderBookType::bid;
    }
    return OrderBookType::unknown;
}