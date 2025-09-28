#ifndef ROLODEX_H
#define ROLODEX_H

#include "rolodexEntry.h"

const size_t MAX_ENTRIES = 100;

class rolodex {
    rolodexEntry list[MAX_ENTRIES];
    size_t current;

public:
    rolodex();

    bool add(const rolodexEntry &entry);
    bool edit(size_t index, const rolodexEntry &newEntry);
    bool remove(size_t index);
    void printAll() const;

    int findByName(const char *search) const;
    int findByAddress(const char *search) const;
    int findByPhone(const char *search) const;
    int findByEmail(const char *search) const;

    // 👇 Add this getter
    rolodexEntry get(size_t index) const { return list[index]; }

    size_t size() const { return current; }
};

#endif
