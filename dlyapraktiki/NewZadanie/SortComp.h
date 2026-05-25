#pragma once
#include "Student.h"
#include <cstring>

class SortComp {
public:

    // Сравнение студентов по имени
    static bool lessByName(const Student& a, const Student& b) {
        return strcmp(a.name, b.name) < 0;
    }

    static bool greaterByName(const Student& a, const Student& b) {
        return strcmp(a.name, b.name) > 0;
    }

    // Сравнение по группе
    static bool lessByGroup(const Student& a, const Student& b) {
        return a.groupnum < b.groupnum;
    }

    static bool greaterByGroup(const Student& a, const Student& b) {
        return a.groupnum > b.groupnum;
    }

    // Сравнение по среднему баллу
    static double avg(const Student& s) {
        double sum = 0;
        for (int i = 0; i < 5; i++)
            sum += s.marks[i];
        return sum / 5.0;
    }

    static bool lessByAvg(const Student& a, const Student& b) {
        return avg(a) < avg(b);
    }

    static bool greaterByAvg(const Student& a, const Student& b) {
        return avg(a) > avg(b);
    }

    // Для стандартного qsort
    static int compByName(const void* a, const void* b) {
        const Student* sa = (const Student*)a;
        const Student* sb = (const Student*)b;
        return strcmp(sa->name, sb->name);
    }

    static int compByGroup(const void* a, const void* b) {
        const Student* sa = (const Student*)a;
        const Student* sb = (const Student*)b;
        return sa->groupnum - sb->groupnum;
    }

    static int compByAvg(const void* a, const void* b) {
        const Student* sa = (const Student*)a;
        const Student* sb = (const Student*)b;
        double diff = avg(*sa) - avg(*sb);
        if (diff > 0) return 1;
        if (diff < 0) return -1;
        return 0;
    }
};