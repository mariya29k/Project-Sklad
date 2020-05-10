//I used a file from finance.bi.no as reference
#include <iostream>
#include "date.h"

using namespace std;

    Date::Date ()
    {
        year = 0;
        month = 0;
        day = 0;
    }
/* no need for this constructor since the other one fits better
    Date::Date (int GivenYear, int GivenMonth, int GivenDay)
    {
        year = GivenYear;
        month = GivenMonth;
        day = GivenDay;
    }
*/
    Date::Date (int year, int month, int day)
    {
        SetYear(year);
        SetMonth(month);
        SetDay(day);

    }


    int Date::GetYear () const
    {
        return year;
    }

    int Date::GetMonth () const
    {
        return month;
    }

    int Date::GetDay () const
    {
        return day;
    }

    void Date::SetDay (const int &d)
    {
        Date::day=d;
    }

    void Date::SetMonth (const int &m)
    {
        Date::month=m;
    }

    void Date::SetYear (const int &y)
    {
        Date::year=y;
    }

    void Date::print ()
    {
        cout << year << "-" << month << "-" << day << endl;
    }

    bool Date::isValid () const //checks whether the entered date is valid
    {   
        if (year < 0) return false;
        if (month > 12 || month < 1) return false;
        if (day > 31 || day < 1) return false;
        if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11 || month == 2)) return false;
        if (month == 2 && day == 30 ) return false;
        if (month == 2 && (isLeap(year) == 0) && day == 29) return false;
        return true;


    }

    bool Date::isLeap (int y) const
    {
        if (y % 4 == 0)
        {
            if (y % 100 == 0) 
            {
                if ( y % 400 == 0) return true;
                else return false;
            }  else return true;
        } else return false;
        
    }

    /*DESTRUKTOR
    Date::~Date(){
        delete[] Date;
    }*/

//we need operators so that we can check for example the experation date
   bool operator == (const Date &date1, const Date &date2)
   {
       if (date1.isValid() == 0 || date2.isValid() == 0) return false;
       if ((date1.GetDay()==date2.GetDay()) && (date1.GetMonth()==date2.GetMonth()) && (date1.GetYear()==date2.GetYear()))
       {
           return true;
       } else return false;
       
   }
    
    bool operator != (const Date &date1, const Date &date2)
    {
        return !(date1 == date2);
    }

    bool operator < (const Date &date1, const Date &date2)
    {
        if(date1.GetYear()<date2.GetYear()) return true;
        else if (date1.GetYear()>date2.GetYear()) return false;
        else
        {
            if (date1.GetMonth()<date2.GetMonth()) return true;
            else if (date1.GetMonth()>date2.GetMonth()) return false;
        else
        {
            if (date1.GetDay()<date2.GetDay()) return true;
        else return false;
        }
        }
        
        return false;
    }

    bool operator > (const Date &date1, const Date &date2)
    {
        if (date1 == date2) return false;
        if (date1 < date2)  return false;
        return true;

    }

    bool operator >= (const Date &date1, const Date &date2)
    {
        if (date1==date2) return true;
        return date1>date2;
    }

    bool operator <= (const Date &date1, const Date &date2)
    {
        if (date1==date2) return true;
        return date1<date2;
    }

   // bool operator = ()

   ostream& operator << (ostream& output, const Date &date)
    {
        output << date.year<<"-"<<date.month<<"-"<<date.day<<endl;
        return output;
    }

    istream& operator >> (istream& input, Date &date)
    {
        input >> date.year >> date.month >> date.day;
        return input;
    }

 