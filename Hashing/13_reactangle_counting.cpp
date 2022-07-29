// Given N cartesian points find the number of axis parallel reactangles that can be found by them
#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct Point
{
    int x, y;
    Point(int x, int y)
    : x(x), y(y) {}
};

class Compare
{
    public:
    bool operator()(Point &p1, Point &p2)
    {
        if(p1.x == p2.x)
        return p1.y < p2.y;


        return p1.x < p2.x;
    }
};

int reactCount(vector<Point> coords)
{
    int n = coords.size();

    set<Point, Compare> s;
    for(auto p : coords)
    s.insert(p);

    int ans = 0;
    for(auto it = s.begin(); it!=prev(s.end()); it++)
    {
        for(auto jt = next(it); jt != s.end(); jt++)
        {
            Point p1 = *it;
            Point p2 = *jt;

            if(p1.x == p2.x || p1.y == p2.y)
            continue;

            Point p3(p2.x, p1.y);
            Point p4(p1.x, p2.y);

            if(s.find(p3) != s.end() && s.find(p4) != s.end())
            ans++;
        }
    }

    return ans/2;
}
int main()
{
    vector<Point> coords;

    Point p1(0,0);
    Point p2(0, 1);
    Point p3(1, 1);
    Point p4( 1, 0);
    Point p5(2, 1);
    Point p6(2, 0);
    Point p7(3, 1);
    Point p8(3, 0);

    coords.push_back(p1);
    coords.push_back(p2);
    coords.push_back(p3);
    coords.push_back(p4);
    coords.push_back(p5);
    coords.push_back(p6);
    coords.push_back(p7);
    coords.push_back(p8);

    cout << reactCount(coords);
    return 0;

}