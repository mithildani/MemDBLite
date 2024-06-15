#include "db.h"

#include <iostream>

void DB::set(const std::string& key, const std::string& value) {
    store_[key] = value;
    std::cout << "OK\n";
}

void DB::get(const std::string& key) const {
    auto it = store_.find(key);
    if (it != store_.end()) {
        std::cout << it->second << "\n";
    } else {
        std::cout << "Key not found\n";
    }
}

void DB::del(const std::string& key) {
    auto it = store_.find(key);
    if (it != store_.end()) {
        store_.erase(it);
        std::cout << "Deleted\n";
    } else {
        std::cout << "Key not found\n";
    }
}
