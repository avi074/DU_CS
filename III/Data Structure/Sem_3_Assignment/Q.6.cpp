#include <iostream>
#include <queue>
#include <stack>

using namespace std;

string s = "";

bool check(queue<int> i, queue<int> o){
    stack <int> tempStack;

	while (!i.empty())
    {
		int ele = i.front();
		i.pop();
		if (ele == o.front())
		{
			o.pop();
            s += "\n Enqueue(o_queue, Dequeue(i_queue))"; 
			while (!tempStack.empty())
			{
				if (tempStack.top() == o.front())
				{
					tempStack.pop();
					o.pop();
                    s += "\n Enqueue(o_queue, Pop(stack))"; 
				}
				else
					break;
			}
		}
		else{
			tempStack.push(ele);
            s += "\n Push(stack, Dequeue(i_queue))";
        }
	}

	return (i.empty() && tempStack.empty());
}

int main()
{
    uint n;
    int v;
    queue<int> input, output;

    cout << "\n Enter the number count : ";
    cin >> n;

    cout << "\n Enter the permutation of numbers.... \n\n Input Queue : ";

    for(int i = 0; i < n; i++){
        cin >> v;
        input.push(v);
    }
    cout << "\n Output Queue : ";
    for(int i = 0; i < n; i++){
        cin >> v;
        output.push(v);   
    }

    if(check(input,output))
        cout << "\n Steps of Stack Permutation : \n" << s << endl << endl;
    else
        cout << "\n Stack Permutation is not possible !!!\n";
    
}