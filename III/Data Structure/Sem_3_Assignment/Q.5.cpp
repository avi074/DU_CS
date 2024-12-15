#include <iostream>
#include <fstream>
#include "Sem_3/stack.cpp"

using namespace std;

short prior(const char &c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    }
    return -1;
}

float calc(const char &c, const float &a, const float &b)
{
    switch (c)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    case '%':
        return int(a) % int(b);
    }
    return 0;
}

void evaluate(const string &s)
{
    stack_l<float> val;
    stack_l<char> sign;
    string str = "";

    for (int i = 0, pri = 0; i < s.length(); i++)
    {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '\n')
            continue;

        if (isdigit(s[i]))
        {
            while (isdigit(s[i]) || s[i] == '.')
                str += s[i++];
            val.push(stof(str));
            str = "";
        }
        else if (s[i] == '(')
            sign.push(s[i]);
        else if (s[i] == ')')
        {
            while (!sign.empty() && sign.top() != '(')
            {
                if (val.size() > 1)
                    val.push(calc(sign.pop(), val.pop(), val.pop()));
                else
                {
                    cerr << "\n Insufficient Variables\n";
                    return;
                }
            }
            if (!sign.empty() && sign.top() == '(')
                sign.pop();
            else
            {
                cerr << "\n Error : Unclosed Paretheses\n";
                return;
            }
        }
        else
        {
            pri = prior(s[i]);

            if (pri == -1)
            {
                cerr << "\n Unknown Operator Found !!!\n";
                return;
            }
            while (!sign.empty() && prior(sign.top()) > pri)
            {
                if (val.size() > 1)
                    val.push(calc(sign.pop(), val.pop(), val.pop()));
                else
                {
                    cerr << "\n Insufficient Variables\n";
                    return;
                }
            }
            sign.push(s[i]);
        }
    }

    while (!sign.empty() && !val.empty())
        val.push(calc(sign.pop(), val.pop(), val.pop()));

    cout << "\n Infix Expression : " << s << " = " << val.pop() << endl;
}

void f_read(string s)
{
    fstream fin;
    string data;

    fin.open(s.c_str(), ios::in | ios::binary);

    if (!fin)
        cerr << "Error in opening file !!!";
    else
    {
        while (!fin.eof())
        {
            getline(fin, data);
            evaluate(data);
        }
        fin.close();
    }
}

int main(int argc, char const *argv[])
{
    if (argc == 1 || argc > 2)
        cerr << "Enter a proper filepath after program name !!!";
    else
        f_read(argv[1]);
}