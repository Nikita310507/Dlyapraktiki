#pragma once

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class Student
{
public:

    char name[50];
    int groupnum;
    int marks[5];

    Student();
    Student(const char* name, int group, int* marks);

    Student(const Student& s);

    Student& operator=(const Student& s);

    bool operator < (const Student& s) const;
    bool operator > (const Student& s) const;
    bool operator == (const Student& s) const;

    static int compStudentName(const void* a, const void* b);
    static int compStudentGroup(const void* a, const void* b);

    friend ostream& operator<<(ostream& os,
        const Student& m)
    {
        os << m.name << " ";
        os << m.groupnum << " ";

        for (int i = 0; i < 5; i++)
            os << m.marks[i] << " ";

        return os;
    }

    friend istream& operator>>(istream& is,
        Student& m)
    {
        is >> m.name;
        is >> m.groupnum;

        for (int i = 0; i < 5; i++)
            is >> m.marks[i];

        return is;
    }
};