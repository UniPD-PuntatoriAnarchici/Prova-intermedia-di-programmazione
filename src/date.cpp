#include "../include/date.h"

#include <iostream>
#include <ctime>
#include <sstream>

Date::Date(const unsigned short day, const Month month, const long year)
    : day_{day}, month_{month}, year_{year} {
    if (!IsValid(day, month, year)) throw DATE_invalid();
}

Date::Date(const std::string &date) {
    std::string elems[3] = {"", "", ""};
    std::stringstream ss(date);
    std::string elem;
    
    // std::getline() reads characters from an input stream and places  
    // them into a string
    for (short i = 0; i < 3; i++) {
        std::getline(ss, elem, '/');
        elems[i] = elem;
    }

    day_ = std::stoi(elems[2]);
    month_ = Month(std::stoi(elems[1]));
    year_ = std::stoi(elems[0]);

    if(!IsValid(day_, month_, year_)) throw DATE_invalid();
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
 * @brief if year is divisible by 4 and not divisible by 100 or if it's divisible 
 * by 400 it's a leap year
 * @param year year to check
 * @return true if it's a leap year, faslse if it's not
*/
bool Date::IsLeapYear(const long year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
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
    return Date{ltm->tm_mday, Month(ltm->tm_mon), (1900 + ltm->tm_year)};
}

std::ostream &operator<<(std::ostream &os, Date date) {
    return os << date.day() << " " << date.month() << " " << date.year();
}