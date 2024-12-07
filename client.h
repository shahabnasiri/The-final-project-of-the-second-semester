#ifndef CLIENT_H_
#include <iostream>
#include "doctor.h"
using namespace std;
struct CASE
{
    date start;
    bool smoking = false;
    bool alcohal = false;
    float weight = 0;
    float height = 0;
    string doc_id = "---";
    string complaint = "---";
    string family_history = "---";
    string druge_history = "---";
    string past_medical_history = "---";
    string allergy_history = "---";
    string details = "---";
    string druges[5] = {"---", "---", "---", "---", "---"};
    //---
    CASE *next = NULL;
};
struct CLILS
{
    string first_name = "not found", last_name = "not found", id_number = "not found";
    CLILS *next;
};
struct cc
{
    LS person;
    string j, marg, gndr;
    CASE *cs;
};
class client : public person
{
private:
    string job;
    string marriage;
    string gender;
    //
    CASE *cases;
    client *next = NULL;

public:
    client();
    client(string, string, string, string, string, string, string, string, date);
    void operator<<(CASE &);
    void operator+(client &);
    bool is(string);
    bool a(string);
    cc out(string);
    CLILS ls(string);
    CLILS ls(string, string);
    client *cd_point_lasdfigvawlefrgblskdfvbs(string);
};
cc client::out(string id)
{
    if (id_number == id)
    {
        LS p = {id, first_name, last_name, phone_number, address, birthday};
        cc t = {p, job, marriage, gender, cases};
        return t;
    }
    else
    return next->out(id);
}
client::client()
{
    person();
    job = "---";
    marriage = "---";
    gender = "---";
}
client::client(string id, string fn = "---", string ln = "---", string pn = "---", string ad = "---", string j = "---", string mrg = "---", string gdr = "---", date bd = date())
{
    id_number = id;
    first_name = fn;
    last_name = ln;
    phone_number = pn;
    address = ad;
    job = j;
    mrg = marriage;
    gdr = gender;
    birthday = bd;
}
void client::operator<<(CASE &a)
{
    CASE *t = cases;
    while (t != NULL)
    {
        if (t->next == NULL)
        {
            t->next = &a;
            return;
        }
        t = t->next;
    }
    cases = &a;
}
void client::operator+(client &a)
{
    if (!next)
        next = &a;
    else
        next->operator+(a);
}
bool client::a(string id)
{
    if (id_number == id)
        return true;
    return false;
}
bool client::is(string id)
{
    if (person::is(id))
        return true;
    else if (next)
        return next->is(id);
    else
        return false;
}
CLILS client::ls(string fn)
{
    CLILS *t = NULL, *temp;
    client *client_temp;
    client_temp = next;
    if (first_name == fn)
    {
        t = new CLILS;
        temp = t;
        t->first_name = first_name;
        t->last_name = last_name;
        t->id_number = id_number;
    }
    do
    {
        if (client_temp->first_name == fn)
        {
            if (t)
            {
                t->next = new CLILS;
                t = t->next;
            }
            else
            {
                t = new CLILS;
                temp = t;
            }
            t->first_name = client_temp->first_name;
            t->last_name = client_temp->last_name;
            t->id_number = client_temp->id_number;
        }
        client_temp = client_temp->next;
    } while (client_temp);
    return *temp;
}
CLILS client::ls(string fn, string ln)
{
    CLILS *t = NULL, *temp;
    client *client_temp;
    client_temp = next;
    if (first_name == fn and last_name == ln)
    {
        t = new CLILS;
        temp = t;
        t->first_name = first_name;
        t->last_name = last_name;
        t->id_number = id_number;
    }
    do
    {
        if (client_temp->first_name == fn and client_temp->last_name == ln)
        {
            if (t)
            {
                t->next = new CLILS;
                t = t->next;
            }
            else
            {
                t = new CLILS;
                temp = t;
            }
            t->first_name = client_temp->first_name;
            t->last_name = client_temp->last_name;
            t->id_number = client_temp->id_number;
        }
        client_temp = client_temp->next;
    } while (client_temp);
    return *temp;
}
client *client::cd_point_lasdfigvawlefrgblskdfvbs(string id)
{
    client *t;
    t = next;
    while (t)
    {
        if (t->id_number == id)
            return t;
        t = t->next;
    }
    return NULL;
}
client *cd_point(client &a, string id)
{
    client *t;
    t = &a;
    if (t->a(id))
        return t;
    else
        return a.cd_point_lasdfigvawlefrgblskdfvbs(id);
}
#endif // !