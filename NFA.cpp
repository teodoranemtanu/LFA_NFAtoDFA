//
// Created by teone on 22-Apr-18.
//

#include "NFA.h"
#include <iostream>
/**
 * makes the conversion from a nfa to dfa
 * @return
 */
DFA NFA::convertion() {
    DFA N(alphabet);
    queue<string> states;
    states.push(initialState);
    map<string, bool> viz;
    viz["*"] = true;
    while (!states.empty()) {
        bool final = false;
        string currentState = states.front();
        states.pop();
        if(currentState!= "") N.appendState(currentState); // adds the current state to the new automaton,
        // being certain that it hasnt been added before

        for (int i = 0; i < currentState.size(); i++) { // verifies if this state is final for the new autom.
            // by checking if at least one of its components is a final state for the NFA
            string c;
            c.push_back(currentState[i]);
            if (isFinal(c))
                final = true;
        }
        if (final == true) {
            N.increaseNrFinalStates(1);
            N.setFinal(currentState);
        }

        if (find(S.begin(), S.end(), currentState) != S.end()) { // if the current state can be found in the initial
            // list of states (one-lettered words) then its list of transitions will be copied
            for (int i = 0; i < alphabet.size(); i++) {
                pair<string, char> p;
                p.first = currentState;
                p.second = alphabet[i];
                N.setTransition(p, M[p]);
                if (viz[M[p]] == false) {
                    states.push(M[p]);
                    viz[M[p]] = true;
                }
            }
        } else { // otherwise a reunion of the transitions of the components will be made
            for (int i = 0; i < alphabet.size(); i++) {
                pair<string, char> p;
                p.first = currentState;
                p.second = alphabet[i];
                string newState;

                for (int j = 0; j < currentState.size(); j++) {
                    pair<string, char> q;
                    q.first = currentState[j];
                    q.second = alphabet[i];

                    if (M[q] != "*" && newState.find(M[q]) == string::npos) {
                        newState = newState + M[q];
                        auto last = newState.end();
                        for (auto first = newState.begin(); first != last; ++first) {
                            last = remove(next(first), last, *first);
                        }
                        newState.erase(last, newState.end());
                    }
                    sort(newState.begin(),
                         newState.end()); // we want to keep them ordered so as not to put a state twice
                }

                N.setTransition(p, newState);

                if (viz[newState] == false) {
                    viz[newState] = true;
                    states.push(newState); // new states will be added to the queue only if they
                    // haven't been in the queue before
                }
            }
        }

    }

    return N;
}
/**
 *
 * @param fin - the input file
 * @return
 * reads a nfa
 */
ifstream &NFA::read(ifstream &fin) {
    fin >> alphabet;
    fin >> initialState;
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
        if (M[p] == "*") {
            M[p] = q2;
        } else {
            M[p] = M[p] + q2;
        }
    }
    return fin;
}
