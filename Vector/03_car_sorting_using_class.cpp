#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Car
{
    public:
    string carName;
    int x, y;
    Car()
    {
        carName = " ";
        x = y = 0;
    }
    Car(string name, int x, int y)
    {
        carName = name;
        this->x = x;
        this->y = y;
    }
    int distance()
    {
        return x*x + y*y;
    }
};

bool compare(Car A, Car B)
{
    if(A.distance() == B.distance())
    return A.carName.length() < B.carName.length();
    
    return A.distance() < B.distance();
}
int main()
{
    int n;
    cin >> n;
    vector<Car> vec;
    vec.reserve(n);
    string name;
    int x, y;
    for(int i = 0; i<n; i++)
    {
        cin >> name >> x >> y;
        Car temp(name, x, y);
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end(), compare);

    for(auto c : vec)
    cout << "Name : " << c.carName << " Coordinates : ( " << c.x << ", " << c.y << " )" << endl;
    return 0;
}