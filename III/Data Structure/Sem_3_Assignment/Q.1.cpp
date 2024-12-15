#include <iostream>

using namespace std;

// (a) Print triangle pattern with 2(n-m+1) lines
void triangle(uint m, const uint &n)
{
    static bool once = false;
    static const uint _m = m;

    if (m < 0 || n <= 0)
        return;

    if (m > n)
    {
        once = true;
        m--;
    }

    for (int i = 0; i < m; i++)
        cout << '*';
    cout << endl;

    if (once)
    {
        if (m == _m)
            return;
        triangle(m - 1, n);
    }
    else if (m <= n)
        triangle(m + 1, n);
}

/* (b) TeddyBear game
 * return true if win is possible else false
 */
bool TeddyGame(const int& n)
{
    if (n == 42)
        return 1;

    else if(n > 42)
        if (!(n % 5))
            return TeddyGame(n - 42);
        
        else if (!(n % 3))
            return TeddyGame(n - n % 10 * (n % 100 / 10));
        
        else if(!(n % 4)){
            int a = n % 10 * (n % 100 / 10);
            if(!a) 
                return TeddyGame(n / 2);
            else
                return TeddyGame(n - a);
        }

        else if (!(n % 2))
            return TeddyGame(n / 2);
        

    return 0;
}

// (c) character pattern
void pattern(const char &x)
{
    if (x == 'A')
        cout << x;
    else if (x > 'A')
    {
        pattern(x - 1);
        cout << x;
        pattern(x - 1);
    }
    else
        return;
}

// (d) Print permutation of string
void permute(string s, int i, const int &n)
{
    if (i == n - 1)
        cout << "\n\t" << s;
    else
        for (int j = i; j < n; j++)
        {
            swap(s[i], s[j]);
            permute(s, i + 1, n);
            swap(s[i], s[j]);
        }
}

int main()
{
    cout << "\n\t\t Question 1 \n";
    cout << "\n(a) Triangle pattern with m = 3 & n = 5 : \n\n";
    triangle(3, 5);
    cout << boolalpha << "\n(b) TeddyBear Game can be won with 250 bears : " << TeddyGame(250);
    cout << "\n(b) TeddyBear Game can be won with 252 bears : " << TeddyGame(252);
    cout << "\n\n(c) Character Pattern with D : ";
    pattern('D');
    cout << "\n\n(d) String Permutation of ABC : \n";
    permute("ABC", 0, 3);
    cout << "\n\n";
}