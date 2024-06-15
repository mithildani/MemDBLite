#pragma once

#include <string>
#include <unordered_map>

class DB {
public:
    void set(const std::string &key, const std::string &value);
    void get(const std::string &key) const;
    void del(const std::string &key);

private:
    std::unordered_map<std::string, std::string> store_;
};