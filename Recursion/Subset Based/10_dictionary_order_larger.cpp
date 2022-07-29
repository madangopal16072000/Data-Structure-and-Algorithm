#include<iostream>
#include<cstring>
using namespace std;

void permute(char in[], char *temp, int i)
{
    if(in[i] == '\0')
    {
        // if(strcmp(in, temp) > 0)
        // cout << in << " ";
        int j;
        for(j = 0; in[j] == temp[j] && in[j] != '\0'; j++);
        
        if(in[j] > temp[j])
        cout << in << endl;
        return;
    }

    for(int k=i; in[k] != '\0'; k++)
    {
        swap(in[i], in[k]);
        permute(in, temp, i+1);
        swap(in[i], in[k]);
    }
    return;
}
int main()
{
    char in[11];
    cin >> in;
    char temp[11];
    strcpy(temp, in);
    permute(in, temp, 0);
    return 0;
}