#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int n;
int freq[26];
vector<string> permutations;

void backtrack(string &current) {
    // Se o tamanho da string atual for igual ao de s, chegamos em uma permutação completa
    if (current.size() == n) {
        permutations.push_back(current);
        return;
    }

    // Caso contrário, tenta colocar outra letra
    for (int c = 0; c < 26; ++c) {
        // Se não tem mais a letra disponível, ignore
        if (freq[c] == 0) {
            continue;
        }

        // Caso ainda tenha a letra disponível, decremente sua frequência e a insira na string
        freq[c]--;
        current.push_back('a' + c);

        // Coloca mais letras usando backtracking
        backtrack(current);

        // Retira a letra colocada (c) para fazer os outros ramos do backtracking
        current.pop_back();
        freq[c]++;
    }
}

void solve() {
    cin >> s;
    n = s.size();

    for (char c : s) {
        freq[c - 'a']++;
    }

    string current;
    backtrack(current);

    cout << permutations.size() << "\n";
    for (string &x : permutations) {
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
