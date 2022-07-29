#include<iostream>
#include<queue>
#include<string>

using namespace std;
class Person
{
    public:
    string name;
    int age;
    Person(string name, int age) 
    : name(name), age(age) {}
};
class personCompare
{
    public:
    bool operator()(Person A, Person B)
    {
        return A.age < B.age;
    }
};
int main()
{
    priority_queue<Person, vector<Person>, personCompare> pq;
    int size;
    cout << "Enter size : ";
    cin >> size;
    for(int i=1; i<=size; i++)
    {
        string name;
        int age;
        cin >> name >> age;
        Person p(name, age);
        pq.push(p);
    }

    for(int i = 1; i<=3; i++)
    {
        cout << pq.top().name << " " << pq.top().age << " " << endl;
        pq.pop();
    }
}