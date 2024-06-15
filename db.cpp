#include "db.h"

#include "db_impl.h"

DB::DB(size_t max_memory) : dbImpl(new DBImpl(max_memory)) {
}

DB::~DB() {
    delete dbImpl;
}

void DB::set(const std::string& key, const std::string& value) {
    dbImpl->set(key, value);
}

void DB::get(const std::string& key) {
    dbImpl->get(key);
}

void DB::del(const std::string& key) {
    dbImpl->del(key);
}
