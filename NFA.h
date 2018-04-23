//
// Created by teone on 22-Apr-18.
//

#ifndef UNTITLED_NFA_H
#define UNTITLED_NFA_H
#include "DFA.h"
using namespace std;

class NFA : public DFA {
public:
    ifstream &read(ifstream &fin);
    DFA convertion();
};

#endif //UNTITLED_NFA_H
