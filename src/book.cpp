#include "../include/book.h"

//region - Static data members

const std::string Book::STATUS_MAP[] = {"LENDING", "AVAILABLE"};

//endregion

//region - Constructors

/**
* [Default] Constructor: accept from 0 to 6 arguments
* @param [in] authorFname as `std::string by const reference`
* @param [in] authorLname as `std::string by const reference`
* @param [in] title as `std::string by const reference`
* @param [in] isbn as `std::string by const reference`
* @param [in] copyrightDate as `std::string by const reference`
* @param [in] status as `Status[enum] by value`
*/
Book::Book(const std::string &authorFname, const std::string &authorLname, const std::string &title,
           const std::string &isbn,
           const std::string &copyrightDate, Book::Status status) : title_{title},
                                                                    author_fname_{authorFname},
                                                                    author_lname_{authorLname},
                                                                    copyright_date_{copyrightDate},
                                                                    isbn_{isbn},
                                                                    status_{status} {}

/**
 * Constructor: accept from 6 arguments
 * First variation needed to accept isbn as ISBN
 * @param [in] authorFname as `std::string by const reference`
 * @param [in] authorLname as `std::string by const reference`
 * @param [in] title as `std::string by const reference`
 * @param [in] isbn as `Isbn by const reference`
 * @param [in] copyrightDate as `std::string by const reference`
 * @param [in] status as `Status[enum] by value`
 */
Book::Book(const std::string &authorFname, const std::string &authorLname, const std::string &title,
           const Isbn &isbn, const std::string &copyrightDate, Status status) : title_{title},
                                                                                author_fname_{authorFname},
                                                                                author_lname_{authorLname},
                                                                                copyright_date_{copyrightDate},
                                                                                isbn_{isbn},
                                                                                status_{status} {}

/**
 * Constructor: accept from 6 arguments
 * Second variation needed to accept copyrightDate as Date
 * @param [in] authorFname as `std::string by const reference`
 * @param [in] authorLname as `std::string by const reference`
 * @param [in] title as `std::string by const reference`
 * @param [in] isbn as `std::string by const reference`
 * @param [in] copyrightDate as `Date by const reference`
 * @param [in] status as `Status[enum] by value`
 */
Book::Book(const std::string &authorFname, const std::string &authorLname, const std::string &title,
           const std::string &isbn, const Date &copyrightDate, Book::Status status) : title_{title},
                                                                                      author_fname_{authorFname},
                                                                                      author_lname_{authorLname},
                                                                                      copyright_date_{copyrightDate},
                                                                                      isbn_{isbn},
                                                                                      status_{status} {}

/**
 * Constructor: accept from 6 arguments
 * Third variation needed to accept isbn as ISBN and copyrightDate as Date
 * @param [in] authorFname as `std::string by const reference`
 * @param [in] authorLname as `std::string by const reference`
 * @param [in] title as `std::string by const reference`
 * @param [in] isbn as `std::string by const reference`
 * @param [in] copyrightDate as `Date by const reference`
 * @param [in] status as `Status[enum] by value`
 */
Book::Book(const std::string &authorFname, const std::string &authorLname, const std::string &title, const Isbn &isbn,
           const Date &copyrightDate, Book::Status status) : title_{title},
                                                             author_fname_{authorFname},
                                                             author_lname_{authorLname},
                                                             copyright_date_{copyrightDate},
                                                             isbn_{isbn},
                                                             status_{status} {}
//endregion

//region - Operators
//region - Output Stream
/**
 * Book::Status' stream output operator.
 * @brief Uses a array association to cast the Enum Value to a custom String
 * @details We decided not to use a ternary operator to ensure greater scalability.
 * @pro Grater scalability
 * @cons Necessity to export an array of string as static const
 * @param os output stream
 * @param [in] status as `Status by copy`
 * @return
 */
std::ostream &operator<<(std::ostream &os, Book::Status status) {
    return os << Book::STATUS_MAP[status];
    //return os << (status == Book::Status::AVAILABLE ? "AVAILABLE" : "LENDING"); //Alternative solution
}

/**
 * Book's' stream output operator.
 * If book is not itiliazied it prints:  <book not initialized>
 * @param os output stream
 * @param [in] book  as `Book by const reference`
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Book &book) {
    if (book.title().empty() && book.author_fname().empty() && book.author_lname().empty())
        return os << "--    Book    --" << std::endl
                  << "<book not initialized>" << std::endl
                  << "-- End of Book --" << std::endl;

    return os << "--    Book    --" << std::endl
              << "- Title: " << book.title() << std::endl
              << "- Author: " << book.author_fname() << " " << book.author_lname() << std::endl
              << "- ISBN: " << (book.isbn() == Isbn{"000-000-000-a"} ? "null" : book.isbn().isbn()) << std::endl
              << "- Copyright: " << book.copyright_date() << std::endl
              << "- Availability: " << book.status() << std::endl /* TODO: Remove this line!*/
              << "-- End of Book --" << std::endl;
}
//endregion

bool operator==(const Book &a, const Book &b) {
    return a.isbn() == b.isbn();
}

bool operator!=(const Book &a, const Book &b) {
    return !(a.isbn() == b.isbn());
}

//endregion
