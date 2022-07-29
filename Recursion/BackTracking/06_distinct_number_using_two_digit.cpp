#include <iostream>
using namespace std;

static int countNum = 0;
void possibleNum(int N, int j, char out[])
{
    if (N == 0)
    {
        out[j] = '\0';
        // cout << out << " ";
        countNum++;
        return;
    }

    // rec case
    out[j] = 'a';
    possibleNum(N - 1, j + 1, out);
    if (out[j - 1] != 'b')
    {
        out[j] = 'b';
        possibleNum(N - 1, j + 1, out);
    }
    return;
}
int main()
{
    int T;
    cin >> T;
    int caseNum = 0;
    while (T--)
    {
        int N;
        cin >> N;
        char out[26];
        int preCount = countNum;
        possibleNum(N, 0, out);
        int count = countNum - preCount;
        caseNum = caseNum + 1;
        cout << "#" << caseNum << " : " << count << endl;
    }
    return 0;
}