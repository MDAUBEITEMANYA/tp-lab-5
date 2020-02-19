#include "Group.h"

Group::Group(std::string title, std::string spec) {
    this->title = title;
    this->spec = spec;
    this->head = nullptr;
}

void Group::setTitle(std::string actualTitle) {
    this->title = actualTitle;
}

std::string Group::getTitle() {
    return title;
}

void Group::setSpec(std::string actualSpec) {
    this->spec = actualSpec;
}

std::string Group::getSpec() {
    return spec;
}

void Group::setRandomHead() {

    if (students.size() != 0)
        head = students[rand() % students.size()];
}

Student *Group::getHead() {
    return head;
}

void Group::addStudent(class Student *student) {
    students.push_back(student);
    student->setGroup(this);
}

Student *Group::getStudentById(int id) {
    for (Student *student : students) {
        if (student->getId() == id) {
            return student;
        }
    }
    return nullptr;
}

Student *Group::getStudentByFio(std::string fio) {
    for (Student *student : students) {
        if (student->getFio() == fio) {
            return student;
        }
    }
    return nullptr;
}

std::vector<class Student *> Group::getStudents() {
    return students;
}

void Group::kickStudent(Student *student) {
    kickStudent(student->getFio());

}

void Group::kickStudent(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getId() == id) {
            delete (students[i]);
            students.erase(students.begin() + i);
        }
    }
}

void Group::kickStudent(std::string fio) {

    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getFio() == fio) {
            delete (students[i]);
            students.erase(students.begin() + i);
        }
    }
}