#ifndef Def_h
#define Def_h
#pragma once
#include <iostream>
#include <fstream>
#include "Types.h"
using namespace std;

void In_txt(ifstream& f, ifstream& f2, ifstream& f3, ofstream& f_out);
void Input_List(ifstream& f, Form_L1& list1, int& last);
void Out(ofstream& f_out, Form_L1& list1, int& last);
int Check(Form_L1& list1, Form_L1& list3, int& last);
int Add(Form_L1& list1, Form_L1& list2);
void Delete(Form_L1& list);
#endif // !Def_h