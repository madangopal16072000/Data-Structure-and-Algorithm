#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &string_list)
{
    unordered_map<char, int> m;
    vector<vector<string>> ans;
    for (int i = 0; i < string_list.size(); i++)
    {
        for (int j = 0; j < string_list[i].size(); j++)
        {
            m[string_list[i][j]]++;
        }
        vector<string> row;
        for (int k = i + 1; k < string_list.size(); k++)
        {
            int l;
            for (l = 0; l < string_list[k].size(); l++)
            {                char ch = string_list[k][l];
                if (!m[ch])
                    break;
            }
            if (l == string_list[k].size())
            {
                row.push_back(string_list[k]);
            }
        }
        ans.push_back(row);
    }
    return ans;
}
int main()
{
    vector<string> words{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(words);
    for(vector<string> row : ans)
    {
        cout << "[ ";
        for(string word : row)
        cout << word << " ";
        cout << "]" << endl;
    }
}