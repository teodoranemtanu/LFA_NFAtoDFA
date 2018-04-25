//
// Created by teone on 22-Apr-18.
//

#include "DFA.h"

DFA::DFA() {
    nrStates = 0;
    nrFinalStates = 0;
    nrTransitions = 0;
}

DFA::DFA(string x) {
    alphabet = x;
    nrStates = 0;
    nrFinalStates = 0;
    nrTransitions = 0;
}

DFA::DFA(const DFA &a) {
    M = a.M;
    finalStates = a.finalStates;
    initialState = a.initialState;
    nrStates = a.nrStates;
    nrFinalStates = a.nrFinalStates;
    nrTransitions = a.nrTransitions;
    alphabet = a.alphabet;
    S = a.S;
}

DFA &DFA::operator=(const DFA &a) {
    if (this != &a) {
        M = a.M;
        finalStates = a.finalStates;
        initialState = a.initialState;
        nrStates = a.nrStates;
        nrFinalStates = a.nrFinalStates;
        nrTransitions = a.nrTransitions;
        alphabet = a.alphabet;
        S = a.S;
    }
    return *this;
}

DFA::~DFA() {
    map<pair<string, char>, string> M;
    map<string, bool> finalStates;
    M.clear();
    finalStates.clear();
    initialState.clear();
    alphabet.clear();
    for (int i = 0; i < S[i].size(); i++)
        S[i].clear();
    S.clear();
}

void DFA::setInitialState(string x) {
    initialState = x;
}

string DFA::getInitialState() const {
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

int DFA::getNrStates() {
    return S.size();
}

void DFA::setTransition(pair<string, char> x, string y) {
    M[x] = y;
    nrTransitions++;
}

void DFA::setNrStates(int x) {
    nrStates = x;
}

void DFA::appendState(string x) {
    nrStates++;
    S.push_back(x);
}

ifstream &DFA::read(ifstream &fin) {
    return fin;
}

ifstream &operator>>(ifstream &fin, DFA &N) {
    N.read(fin);
    return fin;
}

ofstream &operator<<(ofstream &fout, DFA &N) {
    fout << "The alphabet of the automaton is: " << N.alphabet << "\n";
    fout << "The automaton has " << N.nrStates << " states, from which " << N.nrFinalStates << " are final. \n";
    fout << "The automaton has the following states: ";
    for (int i = 0; i < N.S.size(); i++) {
        fout << N.S[i] << " ";
        if (N.finalStates[N.S[i]] == true) fout << "(this one being a final state) ";
        if (N.initialState == N.S[i]) fout << "(this one being the initial state) ";
    }
    fout << "\n";
    fout << "and the following transitions:\n";
    for (int i = 0; i < N.S.size(); i++) {
        for (int j = 0; j < N.alphabet.size(); j++) {
            pair<string, char> p;
            p.first = N.S[i];
            p.second = N.alphabet[j];
            if (N.M[p] != "*" && p.first != "" && N.M[p] != "") {
                fout << "(" << p.first << ", " << p.second << ") ->" << N.M[p] << "\n";
            }
        }
    }
    return fout;
}