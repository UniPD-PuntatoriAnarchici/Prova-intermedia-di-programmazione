#include "../include/isbn.h"

#include <string>

Isbn::Isbn(const std::string Isbn)
        : isbn_{Isbn} {
    if (!IsValid(isbn_)) {
        throw ISBN_invalid();
    }
}

bool Isbn::IsValid(std::string isbn) {
    if (isbn.length() != 13) return false;
    int start = 0;
    std::string delimitator = "-";
    std::string append;

    int end = isbn.find(delimitator);
    while (end != -1) {
        append += isbn.substr(start, end - start);

        start = end + delimitator.size();
        end = isbn.find(delimitator, start);
    }
    for (short i = 0; i < append.length(); i++) {
        if (!isdigit(append[i])) {
            return false;
        }
    }
    if (!isalnum(isbn[12])) return false;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Isbn &isbn) {
    os << isbn.isbn();
    return os;
}

bool operator==(const Isbn &a, const Isbn &b) {
    return a.isbn() == b.isbn();
}
