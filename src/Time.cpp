#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int totalMinutes = minutes + other.minutes;
    int totalHours = hours + other.hours;

    if (totalMinutes >= 60) {
        totalHours += totalMinutes / 60;
        totalMinutes = totalMinutes % 60;
    }

    return Time(totalHours, totalMinutes);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
    minutes += other.minutes;
    hours += other.hours;

    if (minutes >= 60) {
        hours += minutes / 60;
        minutes = minutes % 60;
    }

    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{
    int totalThis = hours * 60 + minutes;
    int totalOther = other.hours * 60 + other.minutes;
    return totalThis < totalOther;
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    int totalThis = hours * 60 + minutes;
    int totalOther = other.hours * 60 + other.minutes;
    return totalThis > totalOther;
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return (hours == other.hours && minutes == other.minutes);
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    os << tm.hours << "h " << tm.minutes << "m";
    return os;
}
