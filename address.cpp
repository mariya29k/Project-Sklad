#include <iostream>
using namespace std;

class Address 
{
    private :
    char section;
    int raft;
    int number;

    public :
    
    Address ()
    {

    }

    Address (char section, int raft, int number)
    {
        SetSection(section);
        SetRaft(raft);
        SetNumber(number);
    }

    void SetSection (const char &section_)
    {
        if(section_ < 'A' || section > 'Z')
        {
            cout<<"Section must be an upper letter!"
        }
            else section = section_;
    }

    char GetSection () const
    {
        return section;
    }

    void SetRaft (const int &raft_)
    {
        if(raft_ < 1 || raft > 200)
        {
            cout<< "No place left in storage";
        }
            else raft = raft_;
    }

    int GetRaft () const
    {
        return raft;
    }

    void SetNumber (const int &number_)
    {
        if (number_ < 1 || number_ > 300)
        {
            cout<< "No place left in storage";
        }
            else number = number_;
    }

    int GetNumber () const
    {
        return number;
    }

    


};