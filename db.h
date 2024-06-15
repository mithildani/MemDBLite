#pragma once

#include <string>

class DB {
public:
    DB(size_t max_memory);
    ~DB();

    void set(const std::string &key, const std::string &value);
    void get(const std::string &key);
    void del(const std::string &key);

private:
    struct DBImpl;
    DBImpl* dbImpl;
};