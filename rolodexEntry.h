#ifndef ROLODEXENTRY_H
#define ROLODEXENTRY_H

#include <iostream>
#include <cstring>

const size_t MAX_NAME = 50;
const size_t MAX_ADDR = 100;
const size_t MAX_PHONE = 20;
const size_t MAX_EMAIL = 50;

class rolodexEntry {
    char name[MAX_NAME];
    char address[MAX_ADDR];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];

public:
    rolodexEntry();
    rolodexEntry(const char *n, const char *a, const char *p, const char *e);

    void setName(const char *n);
    void setAddress(const char *a);
    void setPhone(const char *p);
    void setEmail(const char *e);

    const char* getName() const;
    const char* getAddress() const;
    const char* getPhone() const;
    const char* getEmail() const;

    void print() const;
};

#endif
