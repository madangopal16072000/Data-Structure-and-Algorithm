#include<iostream>
#include<queue>

using namespace std;
int main()
{
    int N; 
    cin >> N;
    queue<int> calling;
    queue<int> ideal;

    for(int i=0; i<N; i++)
    {
        int data;
        cin >> data;
        calling.push(data);
    }
    for(int i=1; i<=N; i++)
    {
        int data;
        cin >> data;
        ideal.push(data);
    }

    int time = 0;
    while(!calling.empty())
    {
        if(calling.front() != ideal.front())
        {
            while(!calling.empty() && calling.front() != ideal.front())
            {
                time++;
                int front = calling.front();
                calling.pop();
                calling.push(front);
            }
        }
        time++;
        calling.pop();
        ideal.pop();
    }
    cout << time << endl;

}