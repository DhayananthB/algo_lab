// Find the pattern in the text using the Knuth-Morris-Pratt algorithm (KMP algorithm)
#include <iostream>
using namespace std;
void kmp_search(string txt, string pat)
{
    int m = txt.size();
    int n = pat.size();
    int i = 1, j = 0;
    // creating lps array
    int lps[n];
    lps[0] = 0;
    while (i < n)
    {
        if (pat[i - 1] == pat[i])
        {
            lps[i] = j + 1;
            j++;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i]=0;
                i++;
                
            }
        }
    }
    i = 0;
    j = 0;
    while (i < m)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == n)
        {
            cout << "pattern found at " << (i - j) << endl;
            j = lps[j - 1];
        }
        else if (txt[i] != pat[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    kmp_search("helolo", "lo");
}