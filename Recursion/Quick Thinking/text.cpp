#include<iostream>
#include<string.h>
using namespace std;
void replacePI(char input[], int length)
{
  if(length == 1)
    return;

  if(input[0] == 'p' && input[1] == 'i')
  {
    for(int i = length+2; i>=2; i--)
      input[i] = input[i-2];

    input[0]  = '3';
    input[1]  = '.';
    input[2] = '1';
    input[3] = '4';

    replacePI(input + 4, length-2);
  }

  replacePI(input+1, length-1);
  
}
int main()
{
  int T;
  cin >> T;
  while(T--)
    {
      char input[1001];
      cin >> input;
      replacePI(input, strlen(input));
      cout << input << endl;
    }
  return 0;
}