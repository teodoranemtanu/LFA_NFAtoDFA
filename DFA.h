//
// Created by teone on 22-Apr-18.
//

#ifndef UNTITLED_DFA_H
#define UNTITLED_DFA_H

#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class DFA {
protected:
    map<pair<string, char>, string> M;
    map<string, bool> finalStates;
    string initialState;
    int nrStates, nrFinalStates, nrTransitions;
    string alphabet;
    vector<string> S;

public:
    DFA();

    DFA(string x);

    DFA(const DFA &a);

    DFA &operator=(const DFA &a);

    ~DFA();

    void appendState(string x);

    void setInitialState(string x);

    int getNrStates();

    string getInitialState() const;

    bool isFinal(string x);

    void setFinal(string x);

    void increaseNrFinalStates(int x);

    void setNrStates(int x);

    void setTransition(pair<string, char> p, string x);

    virtual ifstream &read(ifstream &fin);

    ofstream &print(ofstream &fout);

    friend ifstream &operator>>(ifstream &fin, DFA &N);

    friend ofstream &operator<<(ofstream &fout, DFA &N);
};

#endif //UNTITLED_DFA_H
