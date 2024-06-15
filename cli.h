#pragma once

#include "db.h"

class CLI {
public:
    CLI(DB& db);
    void run();

private:
    void handleCommand(const std::string& command);
    DB& db_;
};