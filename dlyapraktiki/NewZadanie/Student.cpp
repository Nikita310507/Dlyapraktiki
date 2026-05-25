#include "Student.h"

Student::Student()
{
    strcpy_s(name, 50, "");

    groupnum = 0;

    for (int i = 0; i < 5; i++)
        marks[i] = 0;
}

Student::Student(const char* name,
    int group,
    int* marks)
{
    strcpy_s(this->name, 50, name);

    groupnum = group;

    for (int i = 0; i < 5; i++)
        this->marks[i] = marks[i];
}

Student::Student(const Student& s)
{
    strcpy_s(name, 50, s.name);

    groupnum = s.groupnum;

    for (int i = 0; i < 5; i++)
        marks[i] = s.marks[i];
}

Student& Student::operator=(const Student& s)
{
    if (this != &s)
    {
        strcpy_s(name, 50, s.name);

        groupnum = s.groupnum;

        for (int i = 0; i < 5; i++)
            marks[i] = s.marks[i];
    }

    return *this;
}

bool Student::operator<(const Student& s) const
{
    return strcmp(name, s.name) < 0;
}

bool Student::operator>(const Student& s) const
{
    return strcmp(name, s.name) > 0;
}

bool Student::operator==(const Student& s) const
{
    return strcmp(name, s.name) == 0
        && groupnum == s.groupnum;
}

int Student::compStudentName(const void* a,
    const void* b)
{
    Student* pa = (Student*)a;
    Student* pb = (Student*)b;

    return strcmp(pa->name, pb->name);
}

int Student::compStudentGroup(const void* a,
    const void* b)
{
    Student* pa = (Student*)a;
    Student* pb = (Student*)b;

    return pa->groupnum - pb->groupnum;
}