#include <iostream>
#include <string>

#include "cli.h"
#include "db.h"

int main() {
    DB db(50);
    CLI cli(db);
    cli.run();
    return 0;
}
