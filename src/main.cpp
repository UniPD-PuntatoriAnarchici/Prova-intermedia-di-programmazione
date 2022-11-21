#include <iostream>
#include <vector>
#include "date.h"
#include "book.h"

using namespace std;

int passedCounter = 0;
int failedCounter = 0;

void passed(bool passed, std::ostream &os) {
#ifdef __linux__
    if (passed) {
        os << "\033[1;32m PASSED \033[0m";
        passedCounter++;
    } else {
        os << "\033[1;31m FAILED \033[0m";
        failedCounter++;
    }
#else
    if (passed) {
        os << "PASSED";
        passedCounter++;
    } else {
        os << "FAILED";
        failedCounter++;
    }
#endif

    os << std::endl;
    return;
}

int main() {

    //region @Automatic basic tes

    Book test;

    //region - Default value

    cout << "===== DEFAULT VALUE =======" << std::endl;
    cout << "Default Title: ";
    if (test.title().empty()) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Default Author First Name: ";
    if (test.author_fname().empty()) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Default Author Last Name: ";
    if (test.author_lname().empty()) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Default ISBN: ";
    if (test.isbn() == Isbn{"000-000-000-a"}) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Default copyright Date: ";
    if (test.copyright_date() == Date{}) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Default status: ";
    if (test.status() == Book::AVAILABLE) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "===== END DEFAULT VALUE =======" << std::endl;

    //endregion

    //region - Setter/Getter
    cout << "===== Setter/Getter =======" << std::endl;
    cout << "Title: ";
    test.set_title("TITLE");
    if (test.title() == "TITLE") {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Author First Name: ";
    test.set_author_fname("FNAME");
    if (test.author_fname() == "FNAME") {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Author Last Name: ";
    test.set_author_lname("LNAME");
    if (test.author_lname() == "LNAME") {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "ISBN - string: ";
    test.set_isbn("123-456-789-a");
    if (test.isbn() == Isbn{"123-456-789-a"}) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "ISBN - object: ";
    test.set_isbn(Isbn{"987-654-321-b"});
    if (test.isbn() == Isbn{"987-654-321-b"}) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Copyright Date string: ";
    test.set_copyright_date("12-10-1990");
    if (test.copyright_date() == Date{"12-10-1990"}) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Copyright Date object: ";
    test.set_copyright_date(Date{"12-10-1990"});
    if (test.copyright_date() == Date{"12-10-1990"}) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Status: ";
    test.set_status(Book::LENDING);
    if (test.status() == Book::LENDING) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "===== END Setter/Getter =======" << std::endl;
    //endregion

    //region - Status Function

    cout << "===== Status Function =======" << std::endl;

    cout << "Set available: ";
    test.setAvailable();
    if (test.status() == Book::AVAILABLE) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "Set lending: ";
    test.setLending();
    if (test.status() == Book::LENDING) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "===== END Status Function =======" << std::endl;
    //endregion

    //region - Invalid Status
    cout << "===== Invalid Status =====" << std::endl;

    cout << "Date - string";
    try {
        test.set_copyright_date("aaaa");
        passed(false, cout);
    } catch (const std::exception &ex) {
        passed(true, cout);
    }


    cout << "Set lending: ";
    test.setLending();
    if (test.status() == Book::LENDING) {
        passed(true, cout);
    } else {
        passed(false, cout);
    }

    cout << "===== END Status Function =======" << std::endl;
    //endregion


    //endregion


    /*
     * TEST ISBN
     */
    cout << "=== ISBN TESTS ===" << endl;
    // default isbn
    Isbn default_isbn{};
    cout << "default isbn: " << default_isbn << endl;
    // some invalid isbns
    try {
        Isbn p1{"123-634-377-?"};
    } catch (Isbn::ISBN_invalid) {
        cout << "Invalid isbn" << endl;
    }
    try {
        Isbn p2{"123-6345377-m"};
    } catch (Isbn::ISBN_invalid) {
        cout << "Invalid isbn" << endl;
    }
    try {
        Isbn p3{"123-6a4-377-m"};
    } catch (Isbn::ISBN_invalid) {
        cout << "Invalid isbn" << endl;
    }
    // a valid isbn
    Isbn p4{"887-521-837-4"};
    cout << p4 << endl;
    cout << endl;

    /* 
     * DATE TESTING
     */
    cout << "=== DATES TESTS ===" << endl;
    // default date
    Date default_date{};
    cout << "default date: " << default_date << endl;
    // leap year tests
    cout << "IsLeapYear(2022) -> " << Date::IsLeapYear(2022) << endl;
    cout << "IsLeapYear(2012) -> " << Date::IsLeapYear(2012) << endl;
    // an invalid date
    try {
        Date date1{30, Date::Month::Feb, 2022};
    } catch (Date::DATE_invalid) {
        cout << "Invalid date" << endl;
    }
    // a valid date
    Date date2{20, Date::Month::Nov, 2001};
    cout << date2 << endl;
    // today's date
    cout << "Today: " << Date::Today() << endl;
    // date as a string with format yyyy/mm/dd
    Date date3{"2001/11/20"};
    cout << date3 << endl;
    // invalid string date
    try {
        Date date3{"2022/13/14"};
    } catch (Date::DATE_invalid) {
        cout << "Invalid date" << endl;
    }
    cout << endl;

    /*
     * MINIMAL TESTING
     */
    cout << "=== BOOKS TESTS ===" << endl;
    // required tests
    std::vector<Book> shelf(10);
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");

    // default constructor tests
    Book book1;
    Book book2{"Nome"};
    Book book3{"Nome", "Cognome"};
    Book book4{"Nome", "Cognome", "Titolo"};
    Book book5{"Nome", "Cognome", "Titolo", "000-000-000-0", "2022/11/17"};
    Book book7{"Nome", "Cognome", "Titolo", "000-000-000-0", "2022/11/17", Book::LENDING};

    Book book6{"Nome", "Cognome", "Titolo", Isbn{"123-456-789-X"}, Date{}, Book::LENDING};

    std::cout << book1 << std::endl;
    std::cout << book2 << std::endl;
    std::cout << book3 << std::endl;
    std::cout << book4 << std::endl;
    std::cout << book5 << std::endl;
    std::cout << book7 << std::endl;
    std::cout << book6 << std::endl;

    // operators overload tests
    Book a, b;
    std::cout << "Is Book a == Book b ? " << (a == b) << std::endl;
    std::cout << "Is Book a == Book6 ? " << (a == book6) << std::endl;

    std::cout << "Is Book a != Book b ? " << (a != b) << std::endl;
    std::cout << "Is Book a != Book6 ? " << (a != book6) << std::endl;

    return 0;
}


