// Will_be_fine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "Types.h"
#include "Def.h"
using namespace std;
int main()
{
    int last = 0;
    int old_end;
    int new_end;
    int third_end;
    Form_L1 list1, list2, list3;
    ifstream f;
    ifstream f2;
    ifstream f3;
    ofstream f_out;
    In_txt(f, f2, f3,f_out);
    Input_List(f, list1, last);
    old_end = last;
    if (old_end == 0) {
        cout << "First List empty\n";
        return -1;
    }
    Out(f_out, list1, last);
    f_out << "\n\n";
    Input_List(f2, list2, last);
    new_end = last;
    if (new_end == 0) {
        cout << "Second List empty\n";
        return -1;
    }
    Out(f_out, list2, last);
    f_out << "\n\n";
    Input_List(f3, list3, last);
    third_end = last;
    if (third_end == 0) {
        cout << "Third List empty\n";
        return -1;
    }
    Out(f_out, list3, last);
    f_out << "\n\n";
    if (Check(list1, list3 ,old_end)) {
        cout << "String found\n";
    }
    else {
        cout << "Not found\n";
        return -1;
    }
    f_out << "\n\n";
    if (Add(list1, list2)) {
        last = old_end;
    }
    else {
        last = new_end;
    }
    Out(f_out, list1, last);
    Delete(list1);
    Delete(list3);
    system("pause");
    return 0;
}