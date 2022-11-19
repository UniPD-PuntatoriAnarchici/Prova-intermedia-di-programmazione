#include "../include/isbn.h"
#include <sstream> 
#include <string>

Isbn::Isbn(const std::string Isbn)
        : isbn_{Isbn} {
    if (!IsValid(isbn_)) throw ISBN_invalid();
}

/**
 * @brief Checks if a isbn is valid.This means that the length must be 13,
 * the first nine positions must be numbers (0-9) while the last can also be a letter
 * @param isbn as 'std::string'
 * @return true if isbn is valid,otherwise false
*/
bool Isbn::IsValid(std::string isbn) {
    if (isbn.length() != 13) return false;
    if (isbn.at(3) != '-' || isbn.at(7) != '-' || isbn.at(11) != '-') return false;
    std::string append="";
    std::stringstream isbnstream(isbn);
    std::string el;
    while (getline(isbnstream,el,'-')) {
        append+=el;
    }
    for (int i = 0; i < append.length(); i++) {
        if(i==(append.length()-1)) return  isalnum(append[i]);
        else if(!isdigit(append[i]))return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Isbn &isbn) {
    return os << isbn.isbn();
}

bool operator==(const Isbn &a, const Isbn &b) {
    return a.isbn() == b.isbn();
}
