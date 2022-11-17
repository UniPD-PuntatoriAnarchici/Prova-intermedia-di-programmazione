#ifndef ISBN_H
#define ISBN_H
#include <string>

class Isbn {
public:
    class ISBN_invalid{};

    Isbn(const std::string Isbn);

    /// region - Getters
    const std::string &isbn() const { return isbn_; }
    /// endregion - Getters

    /// region - Setters
    void set_isbn(std::string Isbn) { isbn_ = Isbn; }
    /// endregion - Setters


private:
    std::string isbn_;
    bool IsValid(std::string isbn);
};


#endif // ISBN_H
