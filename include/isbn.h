#ifndef ISBN_H
#define ISBN_H

#include <string>
#include <ostream>

class Isbn {
public:
    class ISBN_invalid {};

    Isbn(const std::string Isbn);

    /// region - Getters
    const std::string &isbn() const { return isbn_; }
    /// endregion - Getters

    /// region - Setters
    void set_isbn(std::string Isbn) { isbn_ = Isbn; }
    /// endregion - Setters

    bool IsValid(std::string isbn);

private:
    std::string isbn_;
};

std::ostream &operator<<(std::ostream &os, const Isbn &isbn);
bool operator==(const Isbn &a, const Isbn &b);

#endif // ISBN_H
