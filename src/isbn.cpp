#include "../include/isbn.h"
#include <sstream> 
#include <string>

/**
 * Constructor: sets an ISBN, passed by parameter,if valid
 * @param isbn as 'std::string by const reference'
 * @throws ISBN_invalid if ISBN is invalid
*/
Isbn::Isbn(const std::string &isbn)
        : isbn_{isbn} {
    if (!IsValid(isbn_)) throw ISBN_invalid();
}

/**
 * @brief Checks if a isbn is valid.This means that the length must be 13,
 * the first nine positions must be numbers (0-9) while the last can also be a letter
 * @param isbn as 'std::string'
 * @return true if isbn is valid,otherwise false
*/
bool Isbn::IsValid(std::string isbn) {
    constexpr unsigned short ISBN_LENGTH = 13;
    if (isbn.length() != ISBN_LENGTH) return false;
    if (isbn.at(3) != '-' || isbn.at(7) != '-' || isbn.at(11) != '-') return false;
    std::string unformatted_isbn = ""; // string which contains the isbn without the hyphens
    std::stringstream isbn_stream(isbn);
    std::string elem;

    // joining isbn digits
    while (getline(isbn_stream, elem, '-'))
        unformatted_isbn += elem;
    
    for (int i = 0; i < unformatted_isbn.length(); i++) {
        // if on the last digit checks that the digit is alphanumeric, else check if isdigit
        if (i == (unformatted_isbn.length() - 1)) return isalnum(unformatted_isbn[i]);
        else if (!isdigit(unformatted_isbn[i])) return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Isbn &isbn) {
    return os << isbn.isbn();
}

bool operator==(const Isbn &a, const Isbn &b) {
    return a.isbn() == b.isbn();
}
