#ifndef ISBN_H
#define ISBN_H

#include <string>
#include <ostream>

class Isbn {
public:
    class ISBN_invalid {};

    /**
     * [Default] Constructor: Set the ISBN as '000-000-000-a'
    */
    Isbn(const std::string &Isbn = "000-000-000-a");

    /// region - Getters

    /**
     * @brief ISBN's getter
     * @return string isbn as 'std::string'
    */
    const std::string &isbn() const { return isbn_; }
    /// endregion - Getters

    /// region - Setters

    /**
     * @brief ISBN's setter
     * @param Isbn as 'std::string'
    */
    void set_isbn(std::string Isbn) { isbn_ = Isbn; }
    /// endregion - Setters


private:
    std::string isbn_;
    bool IsValid(std::string isbn);
};

std::ostream &operator<<(std::ostream &os, const Isbn &isbn);
bool operator==(const Isbn &a, const Isbn &b);

#endif // ISBN_H
