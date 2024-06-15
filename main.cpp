#include <iostream>
#include <string>

#include "db.h"
#include "cli.h"

int main() {
    DB db;
    CLI cli(db);
    cli.run();
    return 0;
}
