#include <utility>

#include "../include/book.h"

std::ostream &operator<<(std::ostream &os, Book::Status status) {
    return os << (status == Book::Status::AVAILABLE ? "AVAILABLE" : "LENDING");
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    return os << "Book -> " + book.title() + " (" << book.author_fname() + " - " + book.author_lname() + "): "
              << book.status();
}

Book::Book(std::string title, std::string authorFname, std::string authorLname,
           const Date &copyrightDate, Book::Status status) : title_(std::move(title)),
                                                             author_fname_(std::move(authorFname)),
                                                             author_lname_(std::move(authorLname)),
                                                             copyright_date_(copyrightDate),
                                                             status_(status) {}
/*
Book::Book(std::string title, std::string authorFname, std::string authorLname,
           std::string copyrightDate, Book::Status status) : title_(std::move(title)),
                                                             author_fname_(std::move(authorFname)),
                                                             author_lname_(std::move(authorLname)),
                                                             copyright_date_(new Date(std::move(copyrightDate))),
                                                             status_(status) {}*/
