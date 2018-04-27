#include <fstream>
#include <iostream>
#include "NFA.h"

using namespace std;

ifstream fin("..\\nfa.in");
ofstream fout("..\\dfa.out");

int main() {
    int t;
    NFA n;
    fin >> (DFA&)n;
    cout << "Choose option:";
    cin >> t;
    if(t == 1){
        string word;
        cout << "Insert the word to be tested by the NFA: ";
        cin >> word;
        if(n.testWord(word)){
            fout << "Word accepted";
        }else{
            fout << "Word not accepted";
        }
    }else{
        DFA d = n.convertion();
        fout << d;
    }
    return 0;

}