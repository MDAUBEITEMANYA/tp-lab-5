#ifndef MYLAB5_DEANERY_H
#define MYLAB5_DEANERY_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "Group.h"
#include "Student.h"

class Deanery {
private:
    std::string studentsSaveFileName = "Students.txt";
    std::string groupsSaveFileName = "Groups.txt";
    int maxMark = 10;
    double minNormalMark = 4;
    std::vector<Group *> groups;

    void getDataAboutGroupsFromFile();
    void getDataAboutStudentsFromFile();

    void saveDataAboutGroups();
    void saveDataAboutStudents();

public:
    Deanery();

    void addMarksForStudents();
    void showStatisticForAllStudents();
    void saveDataAboutStudentsAndGroups();
    void kickBadStudents();

    void election();
    void showGroupsHeads();
    std::vector<Group *> getGroups();

    void transfer(int id, const std::string &groupTitle, const std::string &groupSpec);
};


#endif //MYLAB5_DEANERY_H
