#include "../include/date.h"

Date::Date(const unsigned short day, const Month month, const long year)
    : day_{day}, month_{month}, year_{year} {
    if (!IsValid(day, month, year)) throw DATE_invalid();
}

bool Date::IsValid(const unsigned short day, const Month month, const long year){
    if (day <= 0) return false;
    if (month < Month::Jan || month > Month::Dec) return false;

    int days_in_month = 31;

    switch (month) {
    case Month::Feb:
        days_in_month = (IsLeapYear(year)) ? 29 : 28;
        break;
    case Month::Apr: case Month::Jun: case Month::Sep: case Month::Nov:
        days_in_month = 30;
        break;
    }

    if (day > days_in_month) return false;

    return true;
}

/**
 * @brief if year is divisible by 4 and not divisible by 100
 * or if it's divisible by 400 it's a leap year
 * @param year year to check
 * @return true if it's a leap year, faslse if it's not
*/
bool Date::IsLeapYear(const long year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    return false;
}

std::ostream &operator<<(std::ostream &os, Date date) {
    return os << date.day() << " " << date.month() << " " << date.year();
}