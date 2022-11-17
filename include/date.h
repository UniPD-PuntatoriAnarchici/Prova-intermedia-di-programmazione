#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <string>

class Date {
public:
    class DATE_invalid {};

    enum Month {
        Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
    };

    // default Date is Unix start time
    Date(const unsigned short day = 1, const Month month = Month::Jan, const long year = 1970);

    /// region - Getters

    unsigned short day(void) const { return day_; }

    std::string month(void) const { return months[month_ - 1]; }

    Month month_number(void) const { return month_; }

    long year (void) const { return year_; }
    /// endregion - Getters

    /// region - Setters

    void set_day(const unsigned short day) { day_ = day; }

    void set_month(const Month month) { month_ = month; }

    void set_year(const long year) { year_ = year; }
    /// endregion - Setters

    static bool IsLeapYear(const long year);

    static Date Today(void);

private:
    unsigned short day_;
    Month month_;
    long year_;
    
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    bool IsValid(const unsigned short day, const Month month, const long year);
};

std::ostream &operator<<(std::ostream &os, Date date);

#endif // DATE_H
