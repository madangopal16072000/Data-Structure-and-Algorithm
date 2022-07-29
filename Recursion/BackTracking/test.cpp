#include <iostream>
#include<vector>
#include<string>
using namespace std;

bool check(vector<string> sub, string out)
{
    for(auto s : sub)
    {
        if(out.find(s) == string::npos)
        return false;
    }
    return true;
}
bool generateNecklaces(vector<string> sub, int n, string &out, string &res, int count)
{
    if(n == 0 && check(sub, out))
    {
        count++;
        res = out;
        return false;
    }
    
    if(n <= 0 || count >=1)
    return false;


    // rec case
    out.push_back('B');
    bool inc = generateNecklaces(sub, n-1, out, res, count);
    out.pop_back();
    out.push_back('G');
    bool exc = generateNecklaces(sub, n-1, out, res, count);
    out.pop_back();
    if(inc || exc)
    return true;
    
    return false;
}
int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
	    int K;
	    cin >> K;
	    vector<string> necklaces;
	    necklaces.reserve(K);
	    for(int i=1; i<=K; i++)
	    {
	        string necklace;
	        cin >> necklace;
	        necklaces.push_back(necklace);
	    }
	    int max = 0;
	    for(auto str : necklaces)
	    {
	        if(str.size() > max)
	        max = str.size();
	    }
	    string out;
        string res;
	    generateNecklaces(necklaces, max+1, out, res, 0);
	    cout << res << endl;
	}
	return 0;
}
