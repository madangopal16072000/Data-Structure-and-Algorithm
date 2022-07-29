#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

struct Student
{
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string rollno)
    : firstname(f), lastname(l), rollno(rollno) {}

    bool operator==(const Student &s) const
    {
        return rollno == s.rollno;
    }
};
class HashFn
{
    public:
    size_t operator()(const Student &s) const{
        return s.firstname.length() + s.lastname.length();
    }
};

int main()
{
    unordered_map<Student, int, HashFn> student_map;
    Student s1("Prateek", "Narang", "010");
    Student s2("Rahul", "Kumar", "023");
    Student s3("Prateek", "Gupta", "030");
    Student s4("Rahul", "Kumar", "120");

    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 11;
    student_map[s4] = 45;

    for(pair s : student_map)
    cout << s.first.firstname << " " << s.first.lastname << " " << s.first.rollno << " " << s.second << endl;
}