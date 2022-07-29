// Given a wall of size 4XN and titles of dimension 4X1 and 1X4. In how many ways you can build the wall

/*          first way can be veritcal when first title place verticle remaining n-1 can be placed in f(n-1) ways
            in second case when title is place horizontal 3 title above must also filled horizontal because it is the
            only way remaining n-4 title can be place in f(n-4) way
            so total ways. f(n) = f(n-1) + f(n-4)
            */
#include <iostream>

using namespace std;
int numOfWays(int b)
{
    if (b <= 3)
        return 1;
    else
        return numOfWays(b - 1) + numOfWays(b - 4);
}
int main()
{
    int l = 4, b;
    cout << "Enter breadth : ";
    cin >> b;
    cout << numOfWays(b) << endl;
    return 0;
}