#pragma once

#include <iostream>
using namespace std;

class Date 
{
    private: //YEAR-MONTH-DAY
    int year;
    int month;
    int day;

    public:

    Date ();
    //Date (int GivenYear, int GivenMonth, int GivenDay);
    Date (int year, int month, int day);
    Date (const Date &other);
    void SetDate (const int &year, const int &month, const int &day);
    Date &operator= (const Date &other);
    int GetYear () const;
    int GetMonth () const;
    int GetDay () const;
    void SetDay (const int &d);
    void SetMonth (const int &d);
    void SetYear (const int &d);
    void print ();
    bool isValid () const; 
    bool isLeap (int y) const;
    int long_date(const Date &date);
    Date today_date();
    friend bool compareDate (const Date &date1, const Date &date2);
    friend ostream& operator << (ostream& output, const Date &date);
    friend istream& operator >> (istream& input, Date &date);
    bool operator == (const Date &other) const;
    bool operator != (const Date &other) const;
    bool operator < (const Date &other) const;
    bool operator > (const Date &other) const;
    bool operator >= (const Date &other) const;
    bool operator <= (const Date &other) const;
};
   
   

    
