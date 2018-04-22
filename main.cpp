#include <fstream>
#include "NFA.h"

using namespace std;

ifstream fin("..\\nfa.in");
ofstream fout("..\\dfa.out");

int main() {
    NFA n;
    DFA &N = n;
    DFA M;
    fin >> N;
    M = n.convertion();
    fout << M.isFinal("2");
    return 0;

}