#pragma once

#include <unordered_map>
#include <vector>

#include "db.h"

class DB::DBImpl {
public:
    DBImpl(size_t max_memory);

    void set(const std::string& key, const std::string& value);
    void get(const std::string& key);
    void del(const std::string& key);

private:
    size_t calculate_memory_usage(const std::string& key, const std::string& value) const;
    void run_eviction(size_t new_memory);
    size_t find_evict_candidate();
    void evict(const std::string& key);

    std::unordered_map<std::string, std::string> store_;

    std::unordered_map<std::string, size_t> key_to_clock_index_;
    std::vector<std::string> keys_;
    std::vector<bool> reference_bits_;

    size_t max_memory_;
    size_t used_memory_;
    size_t clock_hand_;
};