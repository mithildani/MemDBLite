#include "cli.h"

#include <iostream>

CLI::CLI(DB& db) : db_(db) {}

void CLI::run() {
    std::cout << "============================== \n"
                 "Welcome to the MemDBLite CLI.  \n"
                 "============================== \n"
                 "Available commands: SET, GET, DELETE, EXIT\n\n";

    std::string command;

    while (true) {
        std::cout << "> ";
        std::cin >> command;
        handleCommand(command);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void CLI::handleCommand(const std::string& command) {
    if (command == "SET") {
        std::string key, value;
        std::cin >> key >> value;
        db_.set(key, value);
    } else if (command == "GET") {
        std::string key;
        std::cin >> key;
        db_.get(key);
    } else if (command == "DELETE") {
        std::string key;
        std::cin >> key;
        db_.del(key);
    } else if (command == "EXIT") {
        exit(0);
    } else {
        std::cout << "Unknown command\n";
    }
}