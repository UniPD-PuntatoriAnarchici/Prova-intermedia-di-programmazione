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
    Date(const int day = 1, const Month month = Month::Jan, const int year = 1970);

    /// region - Getters

    int day(void) const { return day_; }

    std::string month(void) const { return months[month_ - 1]; }

    Month month_number(void) const { return month_; }

    int year(void) const { return year_; }
    /// endregion - Getters

    /// region - Setters

    void set_day(const int day) { day_ = day; }

    void set_month(const Month month) { month_ = month; }

    void set_year(const int year) { year_ = year; }
    /// endregion - Setters

    bool IsLeapYear(int year);

private:
    int day_;
    Month month_;
    int year_;
    
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    bool IsValid(int day, Month month, int year);
};

std::ostream &operator<<(std::ostream &os, Date date);

#endif // DATE_H
