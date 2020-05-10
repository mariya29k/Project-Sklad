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
    int GetYear () const;
    int GetMonth () const;
    int GetDay () const;
    void SetDay (const int &d);
    void SetMonth (const int &d);
    void SetYear (const int &d);
    void print ();
    bool isValid () const; 
    bool isLeap (int y) const;
    //~Date();
    friend ostream& operator << (ostream& output, const Date &date);
    friend istream& operator >> (istream& input, Date &date);
};
    bool operator == (const Date &date1, const Date &date2);
    bool operator != (const Date &date1, const Date &date2);
    bool operator < (const Date &date1, const Date &date2);
    bool operator > (const Date &date1, const Date &date2);
    bool operator >= (const Date &date1, const Date &date2);
    bool operator <= (const Date &date1, const Date &date2);

    
