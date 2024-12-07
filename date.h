#ifndef DATE_H_
#include <iostream>
#include "time.h"
using namespace std;
int ye = 1403, mo = 3, da = 13;
void today()
{
    int year , month ,day;
    cin >> year >> month >> day; 
    ye = year;
    mo = month % 12;
    da = day % (6 < mo ? 30 : 31);
}
class date
{
private:
    struct
    {
        int year, month, day;
    } Date;

public:
    date(int, int, int);
    date()
    {
        Date.year = ye;
        Date.month = mo;
        Date.day = da;
    }
    void operator=(int [3]);
    void print();
};
date::date(int year , int month = 1, int day = 1)
{
    Date.year = year;
    Date.month = month % 12;
    Date.day = day % (6 < Date.month ? 30 : 31);
}
void date::print()
{
    {
        cout << (Date.year < 10 ? "0" : "") << Date.year << " / " << (Date.month < 10 ? "0" : "") << Date.month << " / " << (Date.day < 10 ? "0" : "") << Date.day;
    }
}
void date::operator=(int arr[3])
{
    int i = 3;
    while(i--)
        arr[i] += (!arr[i] ? 1 : 0);
    Date.year = arr[0];
    Date.month = arr[1]%12;
    Date.day = arr[2]%(Date.month <7 ? 31 : 30);
}
#endif