#ifndef BOOK_H
#define BOOK_H

#include <string>

class book {

public:
    enum Statuses {
        LENDING,
        AVAILABLE
    };

    /// region - Getters

    std::string titolo(void) const {
        return titolo_;
    }

    std::string nomeAutore(void) const {
        return nomeAutore_;
    }

    std::string cognomeAutore(void) const {
        return nomeAutore_;
    }

    Statuses stato(void) const {
        return stato_;
    }
    /// endregion - Getters

    /// region: Setters

    void setTitolo(const std::string &titolo) {
        titolo_ = titolo;
    }

    void setNomeAutore(const std::string &nomeAutore) {
        nomeAutore_ = nomeAutore;
    }

    void setCognomeAutore(const std::string &cognomeAutore) {
        cognomeAutore_ = cognomeAutore;
    }

    void setStato(Statuses stato) {
        stato_ = stato;
    }

    /// endregion - Setters


private:


    //ISBN isbn_; // TODO: Implement ISBN class
    std::string titolo_;
    std::string nomeAutore_;
    std::string cognomeAutore_;
    //Date copyrightDate_; // TODO: Implement Date class

    Statuses stato_;
};


#endif // BOOK_H
