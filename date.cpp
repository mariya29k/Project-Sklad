#include <iostream>
#include <ctime>
#include "date.h"

using namespace std;

    Date::Date ()
    {
        year = -1;
        month = 1;
        day = 1;
    }

    Date::Date (int GivenYear, int GivenMonth, int GivenDay)
    {
        this->year = GivenYear;
        this->month = GivenMonth;
        this->day = GivenDay;
    }

    Date::Date (const Date &other)
    {
        this->year = other.year;
        this->month = other.month;
        this->day = other.day;
    }

    void Date::SetDate (const int &year, const int &month, const int &day)
    {
        this->year = year;
        this->month = month;
        this->day = day;   
    }
/*
    Date::Date (int year, int month, int day)
    {   
        SetYear(year);
        SetMonth(month);
        SetDay(day);

    }
*/

    Date &Date::operator= (const Date &other)
    {
        if (this!=&other)
        {
            this->year=other.year;
            this->month=other.month;
            this->day=other.day;
        }
        
        return *this;
    }

    int Date::GetYear () const
    {
        return this->year;
    }

    int Date::GetMonth () const
    {
        return this->month;
    }

    int Date::GetDay () const
    {
        return this->day;
    }

    void Date::SetDay (const int &d)
    {
        day=d; 
    }

    void Date::SetMonth (const int &m)
    {
        month=m;
    }

    void Date::SetYear (const int &y)
    {
        year=y;
    }

    void Date::print ()
    {  
        cout << year << "-" << month << "-" << day << endl;
    }

    bool Date::isValid () const //checks whether the entered date is valid
    {   
        if (year < 0)
        {
            if (year == -1) //tva zaradi default constructor tova mi se struva kato only variant za fiksvane na problema
            {
                return true;
            }
            return false;
        }    
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

//this function returns us a long date, although now i think i may not need one
//long date may be useful for sorting the products by date to make clean func more useful
    int Date::long_date(const Date &date)
    {  
        if (date.isValid())
        {
            return date.GetYear() * 10000 + date.GetMonth() * 100 + date.GetDay();
        } else return -1;

    }    

//this function returns us today's date so we can check the expiration date of a product
    Date Date::today_date()
    {
        time_t t = time(0);
        tm* timePtr = localtime(&t);
        day=timePtr->tm_mday;
        month=timePtr->tm_mon+1;
        year=timePtr->tm_year+1900;
    }


//we need operators so that we can check for example the experation date
//fixed operators so they take only 1 argument, not 2 as the earlier version

    bool Date::operator == (const Date &other) const
    {

        return year == other.year && month == other.month && day == other.day;

    }
    
    bool Date::operator != (const Date &other) const
    {
        return !(this == &other);
    }

    
    bool Date::operator < (const Date &other) const
    {   if (year <= 0 || other.year <= 0)
        {
            throw "Invalid comparison";
        }
        if(year < other.year) return true;
        else if (year > other.year) return false;
        else
        {
            if (month < other.month) return true;
            else if (month > other.month) return false;
        else
        {
            if (day < other.day) return true;
        else return false;
        }
        }
        
        return false;
    }

    bool Date::operator > (const Date &other) const
    {
        if (this == &other) return false;
        if (this < &other)  return false;
        return true;

    }

    bool Date::operator >= (const Date &other) const
    {
        if (this== &other) return true;
        return this > &other;
    }

    bool Date::operator <= (const Date &other) const
    {
        if (this == &other) return true;
        return this < &other;
    }
    //sort by date

    bool compareDate (const Date &date1, const Date &date2)
    {
        
        if (date1.year <= 0 || date2.year <= 0)
        {
            throw "Invalid comparison";
        }
        if(date1.year < date2.year) return true;
        else if (date1.year > date2.year) return false;
        else
        {
            if (date1.month < date2.month) return true;
            else if (date1.month > date2.month) return false;
            else
            {
                if (date1.day < date2.day) return true;
                else return false;
            }
        }

        return false;
    
    }


    ostream& operator << (ostream& output, const Date &date)
    {   if(date.isValid())
        {
        output << date.year<<"-"<<date.month<<"-"<<date.day;
        return output;
        } else cout<<"Invalid date!"<<endl;
    }

    istream& operator >> (istream& input, Date &date) //sloji validaciq
    {
       
        input >> date.year >> date.month >> date.day;

        return input;
    }




 