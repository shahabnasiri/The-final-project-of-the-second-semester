#ifndef TIME_H_
#include <iostream>
using namespace std;
int ha = 10, mi = 10;
void now()
{
    int hour , min;
    cin >> hour >> min;
    ha = hour % 24;
    mi = min % 60;
}
// ####################
namespace mytimelib
{
    class time
    {
    private:
        struct
        {
            int hour, min;
        } Time;

    public:
        time(int, int);
        time()
        {
            Time.hour = ha;
            Time.min = mi;
        }
        void operator=(int[2]);
        void print();
    };
    // ####################

    time::time(int hour, int min = 0)
    {
        Time.hour = hour % 24;
        Time.min = min % 60;
    }
    void time::print()
    {
        cout << (Time.hour < 10 ? "0" : "") << Time.hour << " : " << (Time.min < 10 ? "0" : "") << Time.min;
    }
    void time::operator=(int arr[2])
    {
        Time.hour = arr[0] % 24;
        Time.min = arr[1] % 60;
    }
}
#endif