#include<iostream>

using namespace std;

void numToDigit(int number)
{
    string word[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    if(number == 0)
    return;

    numToDigit(number/10);
    int digit = number%10;
    cout << word[digit] << " ";
}
int main()
{
    int num;
    cout << "Enter number : ";
    cin >> num;
    numToDigit(num);
    return 0;
}