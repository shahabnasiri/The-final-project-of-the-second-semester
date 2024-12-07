#ifndef DOCI_H_
#include <iostream>
#include "client.h"
using namespace std;
string line = "\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
string space5 = "\n\n\n\n\n";
string space10 = "\n\n\n\n\n\n\n\n\n\n";
string wellcom = "                                                                                wellcom                                                                                 \n                                                                               ---------                                                                                ";
void print(LSDOC a)
{
    LSDOC *t = &a;
    while (t)
    {
        cout << t->first_name << endl
             << t->last_name << endl
             << t->prf << endl
             << t->id_number << endl
             << "----------" << endl;
        t = t->next;
    }
}
// ### cin << a : get(a);
// after every line enter "."  and at the end enter ".."
void get(string &s)
{
    s = "";
    string a;
    while (true)
    {
        cin >> a;
        s.append((a == "." ? a + '\n' : (a == ".." ? "\n" : a + ' ')));
        if (a == "..")
            return;
    }
}
mytimelib::time nowtime;
void getheder()
{
    cout << "Enter date of today: ";
    today();
    cout << "Enter time: ";
    now();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    date nowdate;
    mytimelib::time nowtime;
    cout << line;
    cout << "today: ";
    nowdate.print();
    cout << "                time: ";
    nowtime.print();
    cout << "  clock is off                ** clinic project **                              shahab nasiri       402 103 246";
    cout << line;
}
void heder()
{
    date nowdate;
    mytimelib::time nowtime;
    cout << line;
    cout << "today: ";
    nowdate.print();
    cout << "                time: ";
    nowtime.print();
    cout << "  |clock is off|              ** clinic project **                              shahab nasiri       402 103 246";
    cout << line;
}
void take(string aa, string &t)
{
    heder();
    cout << aa;
    cout << "\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cin >> t;
}
void takeget(string aa, string &t)
{
    heder();
    cout << aa;
    cout << "\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    get(t);
}
int page_0()
{ // start
    heder();
    cout << wellcom;
    cout << "\n\n\n            1) clients                                                                                             2) doctors" << endl
         << "\n            3) setting                                                                                             0) exit" << endl;
    cout << "\n            ---------------------------------------------------------------------------------------------------------------\n";
    cout << "              Enter your answer:";
    cout << "\n\n\n             !please enter one of the (1,2,3,0)\n";
    cout << space5 << "             ";
    int a;
    cin >> a;
    return a;
}
int page_0_1()
{ // client
    heder();
    cout << "\n\n\n";
    cout << "\n\n\n            1) add new clients                                                                                     2) open a client file" << endl
         << "\n            3) find a client                                                                                       0) back" << endl;
    cout << "\n            ---------------------------------------------------------------------------------------------------------------\n";
    cout << "              Enter your answer:";
    cout << "\n\n\n             !please enter one of the (1,2,3,0)\n";
    cout << space5 << "             ";
    int a;
    cin >> a;
    return a;
}
void page_0_1_1(client &r)
{ // add new client

    string id, fn, ln, pn, ad, job, marg, gndr;
    date bd;
    heder();
    cout << "first name:";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    cin >> fn;
    //
    heder();
    cout << "last name:";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    cin >> ln;
    //
    heder();
    cout << "id number:";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    cin >> id;
    //
    heder();
    cout << "phone number:";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    cin >> pn;
    //
    heder();
    cout << "address:(Enter .. at the end)";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    get(ad);
    //
    heder();
    cout << "job:";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    cin >> job;
    //
    heder();
    cout << "marrige:";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    cin >> marg;
    //
    heder();
    cout << "gender:";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    cin >> gndr;
    //
    heder();
    cout << "birthday:";
    cout << "\n\n\n\n\n\n\n              please write somthing and click enter (without space!!!!)\n\n\n\n\n\n\n\n\n\n";
    int a, s, d;
    cin >> a >> s >> d;
    bd = date(a, s, d);
    client t(id, fn, ln, pn, ad, job, marg, gndr, bd);
    r + t;
}
void casee(client &a)
{
    CASE t;
    string doc_id, complaint, family_history, druge_history, past_medical_history, allergy_history, details, druges[5];
    float weight, height;
    bool smoking, alcohal;
    date start;

    heder();
    cout << "start: ";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    int ww, rr, yy;
    cin >> ww >> rr >> yy;
    start = date(ww,rr,yy);
    takeget("doctor id number:(Enter .. at the end) ", t.doc_id);
    takeget("complaint:(Enter .. at the end) ", t.complaint);
    takeget("family history:(Enter .. at the end) ", t.family_history);
    takeget("druge history:(Enter .. at the end) ", t.druge_history);
    takeget("past medical history:(Enter .. at the end) ", t.past_medical_history);
    takeget("allergy histiry:(Enter .. at the end) ", t.allergy_history);
    takeget("datails:(Enter .. at the end) ", t.details);

    for (int i = 5; i; i--)
    {
        heder();
        cout << "Enter datails about druge:(Enter .. at the end)";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        get(druges[i]);
    }
    heder();
    cout << "weight: ";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cin >> weight;
    heder();
    cout << "height: ";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cin >> height;
    heder();
    cout << "height: ";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cin >> smoking;
    heder();
    cout << "height: ";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cin >> alcohal;
    t = {start,smoking,alcohal,weight,height,doc_id,complaint,family_history,druge_history,past_medical_history,allergy_history,details,druges[5]};
    a << t;
}
void page_0_1_2(client &a)
{ // open a client file
    heder();
    cout << "Enter the clients id number:";
    cout << "\n\n\n\n\n\n\nEnter ziro (0) if wanna back\n\n\n\n\n\n\n\n\n\n\n\n";
    string id;
    cin >> id;
    if (id == "0")
        return;
    if (!a.is(id))
    {
        heder();
        cout << "not found!!";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter a number if you wanna back\n\n\n\n";
        int y;
        cin >> y;
        return;
    }
    else
    {
        cc t;
        t = a.out(id);
        heder();
        cout << "first name: " << t.person.first_name;
        cout << "                              last name: " << t.person.last_name;
        cout << "                              id number: " << t.person.id_number;
        cout << "\n\n\nphone number: " << t.person.phone_number;
        cout << (t.person.phone_number == "---" ? "        " : "") << "                    address: " << t.person.address;
        cout << "\n\nbirthday: ";
        t.person.birthday.print();
        cout << "                     job:" << t.j;
        cout << "\n\nmarriage" << t.marg;
        cout << "                gender" << t.gndr;
        cout << "\n\n\n\n\n\n\n\nEnter a number if you wanna back\nEnter 1 if you wanna make a new case for this client\n\n";
        string y;
        cin >> y;
        if (y == "1")
            casee(a);
        return;
    }
}
void page_0_1_3(client &t)
{ // find a client
    heder();
    cout << "Enter first name and last name:";
    cout << "\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n_______please enter ziro if you wanna back\n\n\n\n";
    string a, d;
    cin >> a;
    if (a == "0")
        return;
    cin >> d;
    CLILS *r;
    *r = t.ls(a, d);
    heder();
    while (r)
    {
        cout << "       first name: " << r->first_name;
        cout << "\n                       last name: " << r->last_name;
        cout << "\n                       id number: " << r->id_number << "\n\n       ----------\n";
        r = r->next;
    }
    cout << "\n\n\n\n\n\n\n\n\n\n_______please enter  a number to get back\n\n\n\n";
    cin >> a;
    return;
}
int page_0_2()
{ // doctor
    heder();
    cout << "\n\n\n";
    cout << "\n\n\n            1) add a new doctor                                                                                    2) open a doctor file" << endl
         << "\n            3) find a doctor file                                                                                  0) back" << endl;
    cout << "\n            ---------------------------------------------------------------------------------------------------------------\n";
    cout << "              Enter your answer:";
    cout << "\n\n\n             !please enter one of the (1,2,3,0)\n";
    cout << space5 << "             ";
    int a;
    cin >> a;
    return a;
}
void page_0_2_1(doctor &a)
{ // add a new doctor
    string id, fn, ln, pn, ad, pr;
    date bd;
    take("first name:  ", fn);
    take("last name:  ", ln);
    take("id number:  ", id);
    //
    heder();
    cout << "birthday: ";
    cout << "\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    int s, d, f;
    bd = date(s, d, f);
    //
    take("phone number:  ", pn);
    heder();
    cout << "address :(enter .. at the end)";
    cout << "\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    get(ad);
    take("proficiency: ", pr);
    doctor w(id, fn, ln, pn, ad, pr, bd);
    a + w;
    return;
}
void page_0_2_2(doctor &a)
{ // open a doctor file
    heder();
    cout << "Enter the doctor id number:";
    cout << "\n\n\n\n\n\n\nEnter ziro (0) if wanna back\n\n\n\n\n\n\n\n\n\n\n\n";
    string id;
    cin >> id;
    if (id == "0")
        return;
    if (!a.is(id))
    {
        heder();
        cout << "not found!!";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter a number if you wanna back\n\n\n\n";
        string y;
        cin >> y;
        return;
    }
    else
    {
        DOC t;
        t = a.cd(id);
        heder();
        cout << "first name: " << t.person.first_name;
        cout << "                              last name: " << t.person.last_name;
        cout << "                              id number: " << t.person.id_number;
        cout << "\n\n\nphone number: " << t.person.phone_number;
        cout << (t.person.phone_number == "---" ? "        " : "") << "                    address: " << t.person.address;
        cout << "\n\nbirthday: ";
        t.person.birthday.print();
        cout << "                     job:" << t.prf;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\nEnter a number if you wanna back\n\n\n\n";
        string y;
        cin >> y;
        return;
    }
}
void page_0_2_3(doctor &t)
{ // find a doctor file
    heder();
    cout << "Enter first name and last name:";
    cout << "\n\n\n\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n_______please enter ziro if you wanna back\n\n\n\n";
    string a, d;
    cin >> a;
    if (a == "0")
        return;
    cin >> d;
    LSDOC *r;
    *r = t.ls(a, d);
    heder();
    while (r)
    {
        cout << "       first name: " << r->first_name;
        cout << "\n                       last name: " << r->last_name;
        cout << "\n                       proficiency:" << r->prf;
        cout << "\n                       id number: " << r->id_number << "\n\n       ----------\n";
        r = r->next;
    }
    cout << "\n\n\n\n\n\n\n\n\n\n_______please enter  a number to get back\n\n\n\n";
    cin >> a;
    return;
}
void page_0_3()
{ // setting
    heder();
    cout << "coming soon !!!\n\n\n\n\n\n\n\n\n\n\n\n\nEnter a number if you wanna back\n\n\n\n\n";
    int a;
    cin >> a;
    return;
}
#endif