//
// Created by teone on 22-Apr-18.
//

#include "NFA.h"

 void NFA:: convertion(DFA & N, ofstream & fout) {
    queue<string> states;
    states.push(initialState);
    map<string, bool> viz;
    N.setInitialState(initialState);
    N.setNrStates(1);
    viz[initialState] = true;

     fout << N.getInitialState() << " \n";
    while (!states.empty()) {
        bool final = false;
        string currentState = states.front();
        states.pop();
        N.appendState(currentState);
        fout << currentState << " ";
        for (int i = 0; i < currentState.size(); i++) {
            string c;
            c.push_back(currentState[i]);
            if (isFinal(c))
                final = true;
        }
        if(final == true){
            N.increaseNrFinalStates(1);
            N.setFinal(currentState);
        }

        if (find(S.begin(), S.end(), currentState) != S.end()) {
            for (int i = 0; i < alphabet.size(); i++) {
                pair<string, char> p;
                p.first = currentState;
                p.second = alphabet[i];
                N.setTransition(p, M[p]);
                if (viz[M[p]] == false) {
                    states.push(M[p]);
                    viz[M[p]] = 1;
                }
            }
        } else {
            for (int i = 0; i < alphabet.size(); i++) {
                pair<string, char> p;
                p.first = currentState;
                p.second = alphabet[i];
                string newState;

                for (int j = 0; j < currentState.size(); j++) {
                    pair<string, char> q;
                    q.first = currentState[j];
                    q.second = alphabet[i];

                    if (M[q] != "*" && newState.find(M[q]) == -1) {
                        newState = newState + M[q];
                    }
                    sort(newState.begin(), newState.end());
                }
                N.setTransition(p, newState);
                if (viz[newState] == false) {
                    viz[newState] = true;
                    states.push(newState);
                }
            }
        }

    }
}

ifstream &NFA::read(ifstream &fin) {
    fin >> alphabet;
    fin >> nrStates >> nrTransitions >> nrFinalStates;
    for (int i = 0; i < nrStates; i++) {
        char x;
        fin >> x;
        string dummy;
        dummy.push_back(x);
        S.push_back(dummy);
    }
    for (int i = 0; i < nrStates; i++)
        for (int j = 0; j < alphabet.size(); j++) {
            pair<string, char> p;
            string dummy = "*";
            p.first = S[i];
            p.second = alphabet[j];
            M[p] = dummy;
        }
    for (int i = 0; i < nrFinalStates; i++) {
        char x;
        fin >> x;
        string dummy;
        dummy.push_back(x);
        finalStates[dummy] = true;
    }

    for (int i = 0; i < nrTransitions; i++) {
        string q1, q2;
        char c;
        pair<string, char> p;
        fin >> q1 >> c >> q2;
        p.first = q1;
        p.second = c;
        if(M[p] == "*") {
            M[p] = q2;
        } else {
            M[p]= M[p]+ q2;
        }
    }
    return fin;
}
