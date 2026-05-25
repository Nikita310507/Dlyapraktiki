#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Student.h"
#include "Sort.h"
#include "MyList.h"


using namespace std;

int main()
{
    ifstream in("text.txt");

    if (!in)
    {
        cout << "File error\n";
        return 1;
    }

    MyList<Student> list;
    MyList<Student> sortedList;

    Student s;

    while (in >> s)
    {
        list.addEnd(s);
        sortedList.addOrdered(s); 
    }

    cout << "Original list:\n\n";
    cout << list;

    cout << "\nSorted list:\n\n";
    cout << sortedList;


    cout << "\nIs list empty? ";
    cout << (list.isEmpty() ? "Yes" : "No") << "\n";

    Student demo = s;

    cout << "\nFind demo element:\n";
    if (list.find(demo))
        cout << "Found\n";
    else
        cout << "Not found\n";

    cout << "\nAfter delete demo element:\n";
    list.deleteNode(demo);
    cout << list;

    Student newStudent("TEST", 99, new int[5]{2,2,2,2,2});

    list.addBegin(newStudent);
    list.addEnd(newStudent);

    cout << "\nAfter addBegin + addEnd:\n";
    cout << list;

    return 0;
}
//ifstream in("text.txt");

//if (!in)
//{
//    cout << "File error\n";
//    return 1;
//}

//Student gr[10];
//int n = 0;

//while (in >> gr[n])
//{
//    n++;
//}

//// библиотечный qsort
//qsort(gr, n, sizeof(Student), Student::compStudentGroup);

//cout << "Sorted students:\n\n";

//for (int i = 0; i < n; i++)
//    cout << gr[i] << "\n";

//return 0;


//Student student("Novikov", 11, new int[5] {3, 4, 4, 3, 4});

/* Student group[10];*/
 //{{"Gubkin", 11, new int[5] {3,4,4,2,5}},{"Romancev", 11, new int[5] {4,4,4,3,5}},{"Yarovoy", 11, new int [5] {3,4,3,4,5}}, {"Radkevich", 11, new int[5] {5,5,4,5,5}}, {"Petrova",11, new int[5] {5,5,4,5,3}},{"Malahov", 11, new int [5] {4,5,2,4,3}},{"Pushkin", 11, new int[5] {4,5,3,3,5}},{"Andreev", 11, new int[5] {3,4,5,2,4}},{"Rukin", 11, new int[5] {5,5,4,3,4}},{"Vinogradov", 11, new int[5] {3,3,3,4,4}}};


 //ofstream of = ofstream("man.bin");
 //int k = sizeof(Student);
 //of.write((char*)gr, n * sizeof(Student));
 //of.close();
 //ifstream in1 = ifstream("man.bin");
 ////длина файла
 //in1.seekg(0, in1.end);//устанавливает указатель файла в конец
 //int dl_fila = in1.tellg();
 ////кол-во записей
 //int nZ = dl_fila / sizeof(Student);
 //in1.seekg(0, 0);
 //Student* arr = new Student[nZ];
 //in1.read((char*)arr, nZ * sizeof(Student));
 //in1.close();
 //for (int i = 0; i < nZ; i++)
 //    cout << arr[i] << "\n";
 //fstream in2 = fstream("man.bin", ios_base::binary |
 //    ios_base::ate | ios_base::in | ios_base::out);
 //in2.seekg(sizeof(Student), ios_base::beg);
 //Student student;
 //in2.read((char*)&student, sizeof(Student));
 //cout << student;
 //student.marks[3] += 2;
 //in2.seekp(sizeof(Student), ios_base::beg);
 //in2.write((char*)&student, sizeof(Student));
 //in2.close();

 //ifstream in3 = ifstream("man.bin");
 //in3.read((char*)arr, nZ * sizeof(Student));
 //cout << "\n after write\n";
 //for (int i = 0; i < nZ; i++)
 //    cout << arr[i] << "\n";
