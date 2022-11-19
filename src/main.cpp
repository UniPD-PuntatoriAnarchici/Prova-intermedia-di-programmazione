#include <iostream>
#include <vector>
#include "date.h"
#include "book.h"

using namespace std;

int main() {
    /*
     * TEST ISBN
     */
    cout << "123-634-377-?" << endl;
    try {
        Isbn p1{"123-634-377-?"};
    } catch (Isbn::ISBN_invalid) {
        cout << "invalid isbn" << endl;
    }
    cout << "123-6345377-m" << endl;
    try {
        Isbn p2{"123-6345377-m"};
    } catch (Isbn::ISBN_invalid) {
        cout << "invalid isbn" << endl;
    }
    cout << "123-6a4-377-m" << endl;
    try {
        Isbn p3{"123-6a4-377-m"};
    } catch (Isbn::ISBN_invalid) {
        cout << "invalid isbn" << endl;
    }
    Isbn p4{"887-521-837-4"};
    cout << "IsValid: " << p4 << " -> " << p4.IsValid(p4.isbn()) << endl;
    cout << endl;

    /* 
     * DATE TESTING
     */
    cout << "=== DATES TESTS ===" << endl;
    Date default_date{};
    cout << default_date << endl;
    cout << "IsLeapYear(2022) -> " << Date::IsLeapYear(2022) << endl;
    cout << "IsLeapYear(2012) -> " << Date::IsLeapYear(2012) << endl;
    Date date1{20, Date::Month::Nov, 2001};
    cout << date1 << endl;
    try {
        Date date2{30, Date::Month::Feb, 2022};
    } catch (Date::DATE_invalid) {
        cout << "Data invalida" << endl;
    }
    cout << "Today: " << Date::Today() << endl;
    Date date2{"2001/11/20"};
    cout << date2 << endl;
    try {
        Date date3{"2022/13/14"};
    } catch (Date::DATE_invalid) {
        cout << "Data invalida" << endl;
    }
    cout << endl;

    /*
     * MINIMAL TESTING
     */
    cout << "=== BOOKS TESTS ===" << endl;
    std::vector<Book> shelf(10);
    Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");

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

    Book a, b;
    std::cout << "Is Book a == Book b ? " << (a == b) << std::endl;
    std::cout << "Is Book a == Book6 ? " << (a == book6) << std::endl;

    std::cout << "Is Book a != Book b ? " << (a != b) << std::endl;
    std::cout << "Is Book a != Book6 ? " << (a != book6) << std::endl;

    return 0;
}


