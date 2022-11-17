#include "../include/book.h"

Book::Book(const std::string &titolo, const std::string &nomeAutore, const std::string &cognomeAutore,
           Book::Statuses stato) : titolo_(titolo), nomeAutore_(nomeAutore),
                                   cognomeAutore_(cognomeAutore),
                                   stato_(stato) {}


std::ostream &operator<<(std::ostream &os, Book book) {
    return os << "Book -> " + book.titolo() + " (" << book.nomeAutore() + " - " + book.cognomeAutore() + "): " +
                                                      (book.stato() == Book::AVAILABLE ? "DISPONIBILE" : "IN PRESTITO");
}