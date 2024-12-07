#include <iostream>
#include "doci.h"
using namespace mytimelib;
using namespace std;
int main()
{
    client cli;
    doctor doci;
    int a = 1;
    while (a)
    {
        a = page_0();
        switch (a)
        {
        case 1:
        {
            int s = 1;

            while (s)
            {

                s = page_0_1();

                switch (s)
                {
                case 1:
                {
                    page_0_1_1(cli);
                    break;
                }
                case 2:
                {
                    page_0_1_2(cli);
                    break;
                }
                case 3:
                {
                    page_0_1_3(cli);
                    break;
                }
                case 0:
                    break;
                }
            }
        }
        case 2:
        {

            int s = 1;

            while (s)
            {

                s = page_0_2();

                switch (s)
                {
                case 1:
                {
                    page_0_2_1(doci);
                    break;
                }
                case 2:
                {
                    page_0_2_2(doci);
                    break;
                }
                case 3:
                {
                    page_0_2_3(doci);
                    break;
                }
                case 0:
                    break;
                }
            }
        }
        case 3:
        {
            page_0_3();
            break;
        }
        case 0:
            break;
        }
    }
}