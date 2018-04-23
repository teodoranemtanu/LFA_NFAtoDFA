#include <fstream>
#include <iostream>
#include "NFA.h"

using namespace std;

ifstream fin("..\\nfa.in");
ofstream fout("..\\dfa.out");

int main() {
    NFA n;
    fin >> (DFA&)n;
    DFA d = n.convertion();
    fout << d;
    return 0;

}