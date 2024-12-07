#ifndef PERSON_H_
#include <iostream>
#include "date.h"
using namespace std;
struct LS
{
    string id_number, first_name, last_name, phone_number, address;
    date birthday;
};
class person
{
protected:
    string id_number, first_name, last_name, phone_number, address;
    date birthday;

public:
    person(string, string, string, string, string, date);
    person();
    LS out();
    bool is(string);
};

person::person(string id, string fn = "---", string ln = "---", string pn = "---", string adrs = "---", date bd = date())
{
    id_number = id;
    first_name = fn;
    last_name = ln;
    phone_number = pn;
    address = adrs;
    birthday = bd;
}
person::person()
{
    id_number = "---";
    first_name = "---";
    last_name = "---";
    phone_number = "---";
    address = "---";
}
LS person::out()
{
    LS temp;
    temp.id_number = id_number;
    temp.first_name = first_name;
    temp.last_name = last_name;
    temp.phone_number = phone_number;
    temp.address = address;
    temp.birthday = birthday;
    return temp;
}
bool person::is(string id)
{
    return (id == id_number ? true : false);
}
#endif // !PERSON_H_