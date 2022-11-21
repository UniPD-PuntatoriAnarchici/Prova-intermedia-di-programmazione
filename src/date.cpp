#include "../include/date.h"

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

//region - Static data members

const std::string MONTHS_MAP[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

//endregion

//region - Constructors

Date::Date(const unsigned short day, const Month &month, const long year)
        : day_{day}, month_{month}, year_{year} {
    if (!Date::IsValid(day, month, year)) throw DATE_invalid();
}

Date::Date(const std::string &date) {
    std::string elems[3] = {"", "", ""};
    std::stringstream date_stream(date);
    std::string elem;

    // std::getline() reads characters from an input stream and places  
    // them into a string
    for (short i = 0; i < 3; i++) {
        std::getline(date_stream, elem, '/');
        elems[i] = elem;
    }

    int unsafe_day = stoi(elems[2]);
    day_ = Date::IntToUshortDay(unsafe_day);
    month_ = Month(std::stoi(elems[1]));
    year_ = std::stoi(elems[0]);

    if (!Date::IsValid(day_, month_, year_)) throw DATE_invalid();
}

//endregion

/**
 * @brief Checks if a date is valid. This means day between 0 and 31 with edge cases
 * for leap years and months with 30 days and month between 1 and 12
 * @param day day
 * @param month month
 * @param year year
 * @return true if date is valid, false otherways
*/
bool Date::IsValid(const unsigned short day, const Month &month, const long year) {
    if (day <= 0) return false;
    if (month < Month::Jan || month > Month::Dec) return false;

    int days_in_month = 31;

    switch (month) {
        case Month::Feb:
            days_in_month = (Date::IsLeapYear(year)) ? 29 : 28;
            break;
        case Month::Apr:
        case Month::Jun:
        case Month::Sep:
        case Month::Nov:
            days_in_month = 30;
            break;
    }

    if (day > days_in_month) return false;

    return true;
}

/**
 * @brief if year is divisible by 4 and not divisible by 100 or if it's divisible 
 * by 400 it's a leap year
 * @param year year to check
 * @return true if it's a leap year, faslse if it's not
*/
bool Date::IsLeapYear(const long year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
    return false;
}

/**
 * @brief returns the date of today by converting time_t now (the offset in
 * seconds from the unix timestamp, a positive integer) to tm (structure holding 
 * a calendar date and time broken down into its components)
 * @return today's date
*/
Date Date::Today(void) {
    time_t now = time(0); // seconds offset since 1 Jan 1970
    tm *ltm = localtime(&now); // ltm is local time abbreviated
    
    unsigned short safe_day = IntToUshortDay(ltm->tm_mday);

    return Date{safe_day, Month(ltm->tm_mon), (1900 + ltm->tm_year)};
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    return os << date.day() << " " << date.month() << " " << date.year();
}

/**
 * @brief function member to do a safe int to unsigned short cast for the day of the month
 * @param unsafe_int the int variable to check
 * @return the unsigned short which has been casted safely
*/
unsigned short Date::IntToUshortDay(int unsafe_int) {
    if (unsafe_int < 0 || unsafe_int > 65535) throw Date::DATE_invalid();
    return static_cast<unsigned short>(unsafe_int); // now it's safe because i checked bounds
}