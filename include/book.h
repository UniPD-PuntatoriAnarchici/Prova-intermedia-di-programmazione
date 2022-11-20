#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "date.h"
#include "isbn.h"

class Book {

public:
    enum Status {
        LENDING,
        AVAILABLE
    };
    static const std::string STATUS_MAP[];

    /// region - Getters

    /**
     * @brief Title's getter
     * @return string title as `std::string`
     */
    std::string title(void) const { return title_; }

    /**
     * @brief Author_fname's getter
     * @return Author's first name as `std::string`
     */
    std::string author_fname(void) const { return author_fname_; }

    /**
     * @brief Author_lname's getter
     * @return Author's last name as `std::string`
     */
    std::string author_lname(void) const { return author_lname_; }

    /**
     * @brief Status' getter
     * @return Status as `Status [enum]`
     */
    Status status(void) const { return status_; }

    /**
     * @brief Copyright date's getter
     * @return Copyright date as `Date`
     */
    Date copyright_date(void) const { return copyright_date_; }

    /**
     * @brief Isbn's getter
     * @return Isbn as `Date`
     */
    Isbn isbn(void) const { return isbn_; }

    /// endregion - Getters

    /// region - Setters

    /**
     * @brief Title's setter
     * @param [in] title as `std::string by const reference`
     */
    void set_title(const std::string &title) { title_ = title; }

    /**
     * @brief Author first name's setter
     * @param [in] author_fname as `std::string by const reference`
     */
    void set_author_fname(const std::string &author_fname) { author_fname_ = author_fname; }

    /**
     * @brief Author last name's setter
     * @param [in] author_lname as `std::string by const reference`
     */
    void set_author_lname(const std::string &author_lname) { author_lname_ = author_lname; }

    /**
    * @brief status' setter
    * @param [in] status as `Status[enum] by value`
    */
    void set_status(Status status) { status_ = status; }

    /**
    * @brief Copyright date's setter
    * @param [in] copyright_date as `Date by const reference`
    */
    void set_copyright_date(const Date &copyright_date) {
        copyright_date_ = copyright_date;
    }

    /**
    * @brief Copyright date's setter
    * @param [in] copyright_date as `std::string by const reference`
    */
    void set_copyright_date(const std::string &copyright_date) {
        copyright_date_ = Date(copyright_date);
    }

    /**
    * @brief Isbn's setter
    * @param [in] isbn as `Isbn by by const reference`
    */
    void set_isbn(const Isbn &isbn) {
        isbn_ = isbn;
    }

    /// endregion - Setters

    ///region - Constructors

    /**
     * [Default] Constructor: accept from 0 to 6 arguments
     * @param [in] authorFname as `std::string by const reference`
     * @param [in] authorLname as `std::string by const reference`
     * @param [in] title as `std::string by const reference`
     * @param [in] isbn as `std::string by const reference`
     * @param [in] copyrightDate as `std::string by const reference`
     * @param [in] status as `Status[enum] by value`
     */
    explicit Book(const std::string &authorFname = "", const std::string &authorLname = "",
                  const std::string &title = "",
                  const std::string &isbn = "000-000-000-a", const std::string &copyrightDate = "1970/01/01",
                  Status status = AVAILABLE);

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
    Book(const std::string &authorFname, const std::string &authorLname, const std::string &title, const Isbn &isbn,
         const std::string &copyrightDate, Status status);

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
    Book(const std::string &authorFname, const std::string &authorLname, const std::string &title,
         const std::string &isbn,
         const Date &copyrightDate, Status status);

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
    Book(const std::string &authorFname, const std::string &authorLname, const std::string &title, const Isbn &isbn,
         const Date &copyrightDate, Status status);


    // endregion - Constructors

    ///region - utilities

    void setAvailable(void) {
        status_ = Status::AVAILABLE;
        return;
    }

    void setLending(void) {
        status_ = Status::LENDING;
        return;
    }

    ///endregion

private:

    Isbn isbn_;
    std::string title_;

    std::string author_fname_; // Author first name
    std::string author_lname_; // Author last name

    Date copyright_date_;

    Status status_;
};


//region - Operators
//region - Output Stream
/**
 * Book's' stream output operator.
 * @param os output stream
 * @param [in] book  as `Book by const reference`
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Book &book);


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
std::ostream &operator<<(std::ostream &os, Book::Status status);
//endregion

//region - Equality
bool operator==(const Book &a, const Book &b);

bool operator!=(const Book &a, const Book &b);
//endregion

//endregion

#endif // BOOK_H
