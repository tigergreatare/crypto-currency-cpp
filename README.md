"# crypto-currency-cpp" 
Cryptocurrency Management System
A Project from the Object-Oriented Programming Specialization by the University of London on Coursera
📋 Overview
This project is a Cryptocurrency Management System implemented in C++. The project demonstrates core object-oriented programming (OOP) principles such as encapsulation, inheritance, polymorphism, and abstraction. It is designed to manage and simulate transactions, wallets, and cryptocurrencies while showcasing best practices in C++ programming.


🎯 Features
Cryptocurrency Wallets: Create, manage, and store balances for various cryptocurrencies.
Transaction Simulation: Transfer cryptocurrencies between wallets with transaction history tracking.
Market Price Updates: Update and retrieve real-time cryptocurrency prices (mock data for this project).
Secure Wallet Operations: Implement encryption to ensure secure wallet access.
Modular Design: Each component, such as Wallet, Transaction, and Market, is implemented using OOP principles.
🛠️ Tools & Technologies
Programming Language: C++
Development Environment: Visual Studio, Code::Blocks, or any preferred IDE supporting C++17.
Libraries Used:
Standard Template Library (STL)

💡 Concepts Demonstrated
Classes and Objects: Core entities like Wallet, Transaction, and Market are modeled as classes.
Inheritance: Specialized wallet types derived from a base wallet class.
Polymorphism: Dynamic behavior for handling various cryptocurrency operations.
Encapsulation: Secure data storage and controlled access to sensitive information.
Abstraction: Simplified interfaces for managing wallets and transactions.
📂 Project Structure
/cryptocurrency-management
├── src
│   ├── main.cpp                # Entry point of the application
│   ├── Wallet.h, Wallet.cpp    # Wallet class and implementation
│   ├── Transaction.h, .cpp     # Transaction class and implementation
│   ├── Market.h, Market.cpp    # Market class for price tracking
│   ├── OrderBook.h, .cpp       # OrderBook management and operations
│   ├── CSVReader.h, .cpp       # CSV parsing for input data
│   ├── MerkelMain.h, .cpp      # Core functionality and simulation logic

├── tests
│   └── tes.cpp                 # Experimental file for testing and saving code snippets
├── data
│   └── 20200317.csv            # Sample data file for testing and simulation // you can use your own data file , i forgot to include it in the built 
├── README.md                   # Project documentation
├── Makefile                    # Build instructions
└── .gitignore                  # Ignored files for Git


📚 Learning Objectives
Apply OOP principles to solve real-world problems.
Build modular and reusable components in C++.
Understand and manage complex interactions between objects in a system.
🔗 Relevant Course Links
Object-Oriented Programming Specialization by University of London
