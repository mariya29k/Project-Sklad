#include "date.cpp"
#include "date.h"


    int main ()
    {
        Date date1, date2;
        date1.SetDay(1);
        date1.SetMonth(6);
        date1.SetYear(2010);
        date2.SetDay(2);
        date2.SetMonth(6);
        date2.SetYear(2010);
        Date date3(2000,5,6);

        date1.print();
        date2.print();

        cout <<date1;
        if (date1 >= date2)
        {
            cout << "Expiration date is today"<<endl;
        }
        cout<<date3;

        
        

        return 0;
    
    }