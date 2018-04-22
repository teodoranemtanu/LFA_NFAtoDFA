//
// Created by teone on 22-Apr-18.
//

#include "DFA.h"

DFA::DFA() {
    nrStates = 0;
    nrFinalStates = 0;
    nrTransitions = 0;
}

void DFA::setInitialState(string x) {
    initialState = x;
}

string DFA::getInitialState() {
    return initialState;
}

bool DFA::isFinal(string x) {
    return finalStates[x];
}

void DFA::setFinal(string x) {
    finalStates[x] = true;
}

void DFA::increaseNrFinalStates(int x) {
    nrFinalStates += x;
}

void DFA::setTransition(pair<string, char> x, string y) {
    M[x] = y;
}

void DFA::setNrStates(int x) {
    nrStates = x;
}

void DFA::increaseNrStates(int x) {
    nrStates += x;
}

ifstream &DFA::read(ifstream &fin) {
    return fin;
}

ifstream &operator>>(ifstream &fin, DFA &N) {
    N.read(fin);
    return fin;
}

ofstream &operator<<(ofstream &fout, DFA &N) {
    fout << N.alphabet << " ";
    fout << N.nrStates;

    return fout;
}