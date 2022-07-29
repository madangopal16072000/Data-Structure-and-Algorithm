#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, char> H = {{1, 'A'}, {2, 'B'}, {3, 'C'}, {4, 'D'}, {5, 'E'}, {6, 'F'}, {7, 'G'}, {8, 'H'}, {9, 'I'}, {10, 'J'}, {11, 'K'}, {12, 'L'}, {13, 'M'}, {14, 'N'}, {15, 'O'}, {16, 'P'}, {17, 'Q'}, {18, 'R'}, {19, 'S'}, {20, 'T'}, {21, 'U'}, {22, 'V'}, {23, 'W'}, {24, 'X'}, {25, 'Y'}, {26, 'Z'}};
void mappedStrings(char in[], char out[], int i, int j)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << " ";
        return;
    }

    int digit = in[i] - '0';
    out[j] = H[digit];
    mappedStrings(in, out, i + 1, j + 1);
    if (in[i + 1] != '\0')
    {
        int secondDigit = in[i + 1] - '0';
        int number = digit * 10 + secondDigit;
        if (number <= 26)
        {
            out[j] = H[number];
            mappedStrings(in, out, i + 2, j + 1);
        }
    }
    return;
}
int main()
{
    char input[10];
    cin >> input;
    char out[10];
    mappedStrings(input, out, 0, 0);
    return 0;
}