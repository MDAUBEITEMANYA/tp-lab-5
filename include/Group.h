#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <cstdlib>
#include "Student.h"

class Group {
private:

    std::string title;
    std::string spec;
    std::vector<class Student *> students;
    Student *head;

public:

    Group(std::string title, std::string spec);

    void setTitle(std::string actualTitle);
    std::string getTitle();

    void setSpec(std::string actualSpec);
    std::string getSpec();

    void setRandomHead();
    Student *getHead();

    void addStudent(class Student *student);
    Student *getStudentById(int id);
    Student *getStudentByFio(std::string fio);
    std::vector<class Student *> getStudents();

    void kickStudent(Student *student);
    void kickStudent(int id);
    void kickStudent(std::string fio);

};
#endif //GROUP_H
