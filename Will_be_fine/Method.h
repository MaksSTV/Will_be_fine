#ifndef Method_h
#define Method_h
#pragma once
void AddNewElem(L1*& p);
void AddNewElemElem(list*& p);
void Go_To(L1*& from, L1*& to);
void Go_To_to(list*& from, list*& to);
void Go_NULL(L1** p);
void Go_NULL_null(list** p);
void Go_Marker(Form_L1* p, int& i);
void Go_Input(Form_L1* p, int& i, ifstream& f);
void Go_Output(Form_L1* p, int& i, ofstream& f);
#endif // !Method_h