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

    //   virtual ifstream & read(ifstream & fin);
    void setInitialState(string x);

    string getInitialState();

    bool isFinal(string x);

    void setFinal(string x);

    void increaseNrFinalStates(int x);

    void setNrStates(int x);

    void increaseNrStates(int x);

    void setTransition(pair<string, char> p, string x);

    virtual ifstream &read(ifstream &fin);

    friend ifstream &operator>>(ifstream &fin, DFA &N);

    friend ofstream &operator<<(ofstream &fout, DFA &N);
};

#endif //UNTITLED_DFA_H
