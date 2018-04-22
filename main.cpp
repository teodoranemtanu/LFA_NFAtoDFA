#include <fstream>
#include "NFA.h"

using namespace std;

ifstream fin("..\\nfa.in");
ofstream fout("..\\dfa.out");

int main() {
    NFA n;
    DFA &N = n;
    fin >> N;
    DFA M;
    n.convertion(M, fout);
    fout << M;

    return 0;

}