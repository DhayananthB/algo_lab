// rabin karp algorithm
#include <iostream>
using namespace std;
#define d 10

void rabinKarp(string txt, string pat, int q)
{
    int m = txt.size();
    int n = pat.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for (int i = 0; i < n - 1; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < n; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }
    for (i = 0; i <= m - n; i++)
    {
        if (p == t)
        {
            for (j = 0; j < n; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                cout << "pattern found at " << i + 1 << endl;
            }
        }
        t = (d * (t - txt[i] * h) + txt[i + n]) % q;
        if (t < 0)
        {
            t = t + q;
        }
    }
}
int main()
{
    rabinKarp("Hello", "el", 13);
}