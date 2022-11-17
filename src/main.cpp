#include <iostream>
#include <vector>
#include "date.h"
#include "book.h"

int main() {
    /* 
     * DATE TESTING
     */
    Date default_date{};
    std::cout << default_date.day() << " " << default_date.month() << " " << default_date.year() << std::endl;
    /*
     * MINIMAL TESTING
     */
    std::vector<Book> shelf(10);
    //Book my_favourite_book("David", "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");

    Book book1;
    Book book2{"Titolo"};
    Book book3{"Titolo", "Nome"};
    Book book4{"Titolo", "Nome", "Cognome"};
    Book book5{"Titolo", "Nome", "Cognome", Book::LENDING};

    std::cout << book1 << std::endl;
    std::cout << book2 << std::endl;
    std::cout << book3 << std::endl;
    std::cout << book4 << std::endl;
    std::cout << book5 << std::endl;

    return 0;
}


