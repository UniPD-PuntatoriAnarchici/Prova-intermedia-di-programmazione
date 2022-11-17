#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "date.h"

class Book {

public:
    enum Status {
        LENDING,
        AVAILABLE
    };

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
     * @return Status' as `Status [enum]`
     */
    Status status(void) const { return status_; }

    /**
     * @brief Copyright date's getter
     * @return Copyright date's as `Date`
     */
    Date copyright_date(void) const { return copyright_date_; }

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
    * @param [in] copyright_date as `Date by value`
    */
    void set_copyright_date(Date copyright_date) {
        copyright_date_ = copyright_date;
    }

    /**
    * @brief Copyright date's setter
    * @param [in] copyright_date as `std::string by const reference`
    */
    /*void set_copyright_date(const std::string& copyright_date) {
        copyright_date_ = new Date(copyright_date);
    } TODO: string to date*/

    /// endregion - Setters

    ///region - Constructors

    explicit Book(std::string title = "", std::string authorFname = "", std::string authorLname = "",
         const Date &copyrightDate = Date{}, Status status = AVAILABLE);
//    explicit Book(std::string title = "", std::string authorFname = "", std::string authorLname = "",
//                  std::string copyrightDate = "", Status status = AVAILABLE);

    ///endregion - Constructors

private:

    //ISBN isbn_; // TODO: Implement ISBN class
    std::string title_;

    std::string author_fname_; // Author first name
    std::string author_lname_; // Author last name

    Date copyright_date_;

    Status status_;

};

std::ostream &operator<<(std::ostream &os, const Book &book);

std::ostream &operator<<(std::ostream &os, Book::Status status);


#endif // BOOK_H
