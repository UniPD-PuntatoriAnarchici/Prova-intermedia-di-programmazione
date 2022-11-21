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
    Date(const unsigned short day = 1, const Month &month = Month::Jan, const long year = 1970);
    Date(const std::string &date);

    /// region - Getters

    /**
     * @brief Day's getter
     * @return Day as `unsigned short`
     */
    unsigned short day(void) const { return day_; }

    /**
     * @brief Month's getter
     * @return Month as `std::string`
     */
    std::string month(void) const { return MONTHS_MAP[month_ - 1]; }

    /**
     * @brief Month's number getter
     * @return Month's number as `Month`
     */
    Month month_number(void) const { return month_; }

    /**
     * @brief Year's getter
     * @return Year as `long`
     */
    long year (void) const { return year_; }
    /// endregion - Getters

    /// region - Setters

    /**
     * @brief Day's setter
     * @param [in] day as `const unsigned short`
     */
    void set_day(const unsigned short day) { day_ = day; }

    /**
     * @brief Month's setter
     * @param [in] month as `month by const reference`
     */
    void set_month(const Month &month) { month_ = month; }

    /**
     * @brief Year's setter
     * @param [in] year as `const long`
     */
    void set_year(const long year) { year_ = year; }
    /// endregion - Setters

    static bool IsLeapYear(const long year);

    static Date Today(void);

private:
    unsigned short day_;
    Month month_;
    long year_;

    std::string MONTHS_MAP[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    bool IsValid(const unsigned short day, const Month &month, const long year);
    static unsigned short IntToUshortDay(int unsafe_int);
};

std::ostream &operator<<(std::ostream &os, const Date &date);

#endif // DATE_H
