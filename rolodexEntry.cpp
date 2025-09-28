#include "rolodexEntry.h"

rolodexEntry::rolodexEntry() {
    strcpy(name, "");
    strcpy(address, "");
    strcpy(phone, "");
    strcpy(email, "");
}

rolodexEntry::rolodexEntry(const char *n, const char *a, const char *p, const char *e) {
    setName(n);
    setAddress(a);
    setPhone(p);
    setEmail(e);
}

void rolodexEntry::setName(const char *n) { strncpy(name, n, MAX_NAME); }
void rolodexEntry::setAddress(const char *a) { strncpy(address, a, MAX_ADDR); }
void rolodexEntry::setPhone(const char *p) { strncpy(phone, p, MAX_PHONE); }
void rolodexEntry::setEmail(const char *e) { strncpy(email, e, MAX_EMAIL); }

const char* rolodexEntry::getName() const { return name; }
const char* rolodexEntry::getAddress() const { return address; }
const char* rolodexEntry::getPhone() const { return phone; }
const char* rolodexEntry::getEmail() const { return email; }

void rolodexEntry::print() const {
    std::cout << name << " | " << address << " | " 
              << phone << " | " << email << "\n";
}
