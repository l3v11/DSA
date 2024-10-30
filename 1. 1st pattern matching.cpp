#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string txt = "aabbbabb";
    string pat = "baby";
    int N = txt.size();  // 8
    int M = pat.size();  // 3

    for (int i = 0; i < N - M + 1; i++) {
        int j;
        for (j = 0; j < M; j++) // j = 3 
            if (txt[i + j] != pat[j]) // j = 2
                break;

        if (j == M)
            cout << "Pattern found at index " << i << '\n';
        else
            cout << "Pattern not found" << '\n';
    }
    
    return 0;
}
