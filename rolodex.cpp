#include "rolodex.h"
#include <iostream>
#include <cctype>
#include <cstring>

rolodex::rolodex() : current(0) {}

bool rolodex::add(const rolodexEntry &entry) {
    if (current >= MAX_ENTRIES) return false;
    list[current++] = entry;
    return true;
}

bool rolodex::edit(size_t index, const rolodexEntry &newEntry) {
    if (index >= current) return false;
    list[index] = newEntry;
    return true;
}

bool rolodex::remove(size_t index) {
    if (index >= current) return false;
    for (size_t i = index; i < current - 1; i++) {
        list[i] = list[i + 1];
    }
    current--;
    return true;
}

void rolodex::printAll() const {
    for (size_t i = 0; i < current; i++) {
        std::cout << i + 1 << ". ";
        list[i].print();
    }
}

// helper for case-insensitive strstr
bool ci_contains(const char *haystack, const char *needle) {
    std::string h(haystack), n(needle);
    for (auto &c : h) c = std::tolower(c);
    for (auto &c : n) c = std::tolower(c);
    return h.find(n) != std::string::npos;
}

int rolodex::findByName(const char *search) const {
    for (size_t i = 0; i < current; i++) {
        if (ci_contains(list[i].getName(), search)) return i;
    }
    return -1;
}

int rolodex::findByAddress(const char *search) const {
    for (size_t i = 0; i < current; i++) {
        if (ci_contains(list[i].getAddress(), search)) return i;
    }
    return -1;
}

int rolodex::findByPhone(const char *search) const {
    for (size_t i = 0; i < current; i++) {
        if (ci_contains(list[i].getPhone(), search)) return i;
    }
    return -1;
}

int rolodex::findByEmail(const char *search) const {
    for (size_t i = 0; i < current; i++) {
        if (ci_contains(list[i].getEmail(), search)) return i;
    }
    return -1;
}
