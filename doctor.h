#ifndef DOCTOR_H_
#include <iostream>
#include "person.h"
using namespace std;
struct LSDOC
{
    string first_name = "temp", last_name, prf, id_number;
    LSDOC *next = NULL;
};
struct DOC
{
    LS person;
    string prf;
};
class doctor : public person
{
private:
    string prf;
    doctor *next = NULL;

public:
    doctor();
    doctor(string, string, string, string, string, string, date);
    void operator+(doctor &);
    LSDOC ls(string);
    LSDOC ls(string, string);
    DOC out();
    bool is(string);
    DOC cd(string);
};
doctor::doctor()
{
    person();
    prf = "---";
}
doctor::doctor(string id, string fn = "---", string ln = "---", string pn = "---", string ad = "---", string pr = "---", date bd = date())
{
    id_number = id;
    first_name = fn;
    last_name = ln;
    phone_number = pn;
    address = ad;
    birthday = bd;
    prf = pr;
}
void doctor::operator+(doctor &a)
{
    if (!next)
        next = &a;
    else
        next->operator+(a);
}
DOC doctor::out()
{
    DOC temp;
    temp.person = person::out();
    temp.prf = prf;
    return temp;
}
bool doctor::is(string id)
{
    if (person::is(id))
        return true;
    else if (next)
        return next->is(id);
    else
        return false;
}
DOC doctor::cd(string id)
{
    if (id_number == id)
        return out();
    else if (next)
    {
        return next->cd(id);
    }
    else
    {
        LS t = {"not found", "not found", "not found", "not found", "not found", date()};
        DOC temp = {t, "not found"};
        return temp;
    }
}
LSDOC doctor::ls(string fn)
{
    LSDOC *t = NULL, *temp;
    doctor *doctor_temp;
    doctor_temp = next;
    if (first_name == fn)
    {
        t = new LSDOC;
        temp = t;
        t->first_name = first_name;
        t->last_name = last_name;
        t->id_number = id_number;
        t->prf = prf;
    }
    do
    {
        if (doctor_temp->first_name == fn)
        {
            if (t)
            {
                t->next = new LSDOC;
                t = t->next;
            }
            else
            {
                t = new LSDOC;
                temp = t;
            }
            t->first_name = doctor_temp->first_name;
            t->last_name = doctor_temp->last_name;
            t->id_number = doctor_temp->id_number;
            t->prf = doctor_temp->prf;
        }
        doctor_temp = doctor_temp->next;
    } while (doctor_temp);
    return *temp;
}
LSDOC doctor::ls(string fn, string ln)
{
    LSDOC *t = NULL, *temp;
    doctor *doctor_temp;
    doctor_temp = next;
    if (first_name == fn and last_name == ln)
    {
        t = new LSDOC;
        temp = t;
        *t = {first_name,last_name,id_number,prf};
    }
    do
    {
        if (doctor_temp->first_name == fn and doctor_temp->last_name == ln)
        {
            if (t)
            {
                t->next = new LSDOC;
                t = t->next;
            }
            else
            {
                t = new LSDOC;
                temp = t;
            }
            t->first_name = doctor_temp->first_name;
            t->last_name = doctor_temp->last_name;
            t->id_number = doctor_temp->id_number;
            t->prf = doctor_temp->prf;
        }
        doctor_temp = doctor_temp->next;
    } while (doctor_temp);
    return *temp;
}
#endif