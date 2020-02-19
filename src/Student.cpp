#include "Student.h"

Student::Student(std::string fio, Group *group, int id) {
    this->id = id;
    this->fio = fio;
    this->group = group;
}

Student::~Student() {
    this->marks.clear();
}

void Student::setId(int actualId) {
    this->id = actualId;
}

int Student::getId() {
    return id;
}

void Student::setFio(std::string actualFio) {
    this->fio = actualFio;
}

std::string Student::getFio() {
    return fio;
}

void Student::setGroup(Group *actualGroup) {
    this->group = actualGroup;
}

Group *Student::getGroup() {
    return group;
}

std::vector<int> Student::getMarks() {
    return marks;
}

double Student::getAverageMark() {

    if (marks.empty()) {
        return 0;
    } else {
        double mean = 0;
        for (int i = 0; i < marks.size(); i++)
            mean += marks[i];

        return mean / marks.size();
    }
}

void Student::addMark(int mark) {
    marks.push_back(mark);
}
