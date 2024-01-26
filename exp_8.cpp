#include <bits/stdc++.h>
using namespace std;
#define CHARS 256
void boyer_moore(string txt, string pat)
{
    int m = txt.size();
    int n = pat.size();
    vector<int> badchar(CHARS, -1);
    for (int i = 0; i < n; i++)
    {
        badchar[pat[i]] = i;
    }
    int i = 0;
    while (i <= m - n) 
    {
        int j = n - 1;
        while (j >= 0 && pat[j] == txt[i + j])
        {
            j--;
        }
        if (j < 0)
        {
            cout << "found at " << i << endl;
            i += (i + n < m) ? m - badchar[txt[i + n]] : 1;
        }
        else
        {
            i += max(1, j - badchar[txt[i + j]]);
        }
    }
}

int main()
{
    boyer_moore("Hello", "el");
}