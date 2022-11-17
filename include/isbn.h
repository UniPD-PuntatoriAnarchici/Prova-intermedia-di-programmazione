#ifndef ISBN_H
#define ISBN_H
#include <string>

class Isbn {
public:
class ISBN_invalid{};

//Constructor
Isbn(const std::string Isbn);

//Get
const std::string& getIsbn()const {return isbn_;}

//Set
void set_isbn(std::string Isbn){isbn_=Isbn;}



private:
 std::string isbn_;
 bool IsValid(std::string isbn);
};


#endif // ISBN_H
