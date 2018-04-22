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
    nrTransitions++;
}

void DFA::setNrStates(int x) {
    nrStates = x;
}
void DFA :: appendState(string x){
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

    }
    fout << "\n";
    fout << "and the following transitions:\n";
    for (int i = 0; i < N.S.size(); i++) {
        for (int j = 0; j < N.alphabet.size(); j++) {
            pair<string, char> p;
            p.first = N.S[i];
            p.second = N.alphabet[j];
            if (N.M[p] != "*") {
                fout << "(" << p.first << ", " << p.second << ") ->" << N.M[p] << "\n";
            }
        }
    }
    return fout;
}