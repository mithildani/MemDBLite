#include "db_impl.h"

#include <iostream>

DB::DBImpl::DBImpl(size_t max_memory)
    : max_memory_(max_memory), used_memory_(0), clock_hand_(0) {
    keys_.resize(max_memory_);
    reference_bits_.resize(max_memory_, false);
}

size_t DB::DBImpl::calculate_memory_usage(const std::string& key, const std::string& value) const {
    return key.size() + value.size();
}

void DB::DBImpl::set(const std::string& key, const std::string& value) {
    size_t new_memory = calculate_memory_usage(key, value);
    if (new_memory > max_memory_) {
        std::cout << "[Error] Key-Value Size is larger than MAX_MEMORY" << std::endl;
        return;
    }

    if (store_.find(key) == store_.end()) {
        run_eviction(new_memory);
    } else {
        // Subtract the memory used by the existing entry
        used_memory_ -= calculate_memory_usage(key, store_[key]);
    }

    store_[key] = value;
    used_memory_ += new_memory;

    if (key_to_clock_index_.find(key) == key_to_clock_index_.end()) {
        // Insert the key into the clock structure
        keys_[clock_hand_] = key;
        reference_bits_[clock_hand_] = true;
        key_to_clock_index_[key] = clock_hand_;
        clock_hand_ = (clock_hand_ + 1) % max_memory_;
    } else {
        // Key already in clock structure, just update its reference bit
        size_t index = key_to_clock_index_[key];
        reference_bits_[index] = true;
    }

    std::cout << "OK\n";
}

void DB::DBImpl::get(const std::string& key) {
    auto it = store_.find(key);
    if (it != store_.end()) {
        std::cout << it->second << std::endl;
        auto clock_it = key_to_clock_index_.find(key);
        if (clock_it != key_to_clock_index_.end()) {
            reference_bits_[clock_it->second] = true;
        }
    } else {
        std::cout << "Key not found\n";
    }
}

void DB::DBImpl::del(const std::string& key) {
    auto it = store_.find(key);
    if (it != store_.end()) {
        evict(key);
        std::cout << "Deleted\n";
    } else {
        std::cout << "Key not found\n";
    }
}

void DB::DBImpl::run_eviction(size_t new_memory) {
    while (used_memory_ + new_memory > max_memory_) {
        size_t evict_index = find_evict_candidate();
        std::string key_to_evict = keys_[evict_index];
        evict(key_to_evict);
    }
}

void DB::DBImpl::evict(const std::string& key) {
    size_t index = key_to_clock_index_[key];

    used_memory_ -= calculate_memory_usage(key, store_[key]);
    store_.erase(key);
    key_to_clock_index_.erase(key);
    keys_[index].clear();
    reference_bits_[index] = false;
}

size_t DB::DBImpl::find_evict_candidate() {
    while (true) {
        // check if reference bit is set to false and also if key is empty.
        // key can be empty if memory limit is reached before clock size is reached
        if (!reference_bits_[clock_hand_] && !keys_[clock_hand_].empty()) {
            return clock_hand_;
        }
        reference_bits_[clock_hand_] = false;
        clock_hand_ = (clock_hand_ + 1) % max_memory_;
    }
}