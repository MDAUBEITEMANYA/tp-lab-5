#pragma once
#include <string>
#include <vector>
#include "Group.h"

class Student {

private:

    int id;
    std::string fio;
    class Group* group;
    std::vector<int> marks;

public:
    Student(std::string fio, Group* group, int id);
    ~Student();

    void setId(int actualId);
    int getId();

    void setGroup(Group* actualGroup);
    Group* getGroup();

    void setFio(std::string fio);
    std::string getFio();

    void setMarks(std::vector<int> marks);
    std::vector<int> getMarks();
    void addMark(int mark);

    double getAverageMark();
};