#include <algorithm>
#include "Deanery.h"

Deanery::Deanery() {
    srand(time(nullptr));
    getDataAboutGroupsFromFile();
    getDataAboutStudentsFromFile();
}

void Deanery::getDataAboutGroupsFromFile() {
    std::string line;
    std::ifstream from(groupsSaveFileName);
    if (from.is_open()) {
        while (getline(from, line)) {
            std::string groupTitle;
            std::string groupSpec;
            int wordType = 0;
            for (char charOfLine : line) {
                if (charOfLine != ' ') {
                    if (wordType == 0) {
                        groupTitle += charOfLine;
                    } else {
                        groupSpec += charOfLine;
                    }
                } else {
                    wordType++;
                }
            }
            auto *group = new Group(groupTitle, groupSpec);
            groups.push_back(group);
        }
    }
}

void Deanery::getDataAboutStudentsFromFile() {
    std::string line;
    int counter = 0;
    std::ifstream from(studentsSaveFileName);

    if (from.is_open()) {
        while (getline(from, line)) {

            std::string studentFio;
            std::string groupTitle;
            std::string groupSpec;
            int type = 0;

            for (char i : line) {
                if (i != ' ') {
                    if (type == 0) {
                        studentFio += i;
                    } else if (type == 1) {
                        groupTitle += i;
                    } else if (type == 2) {
                        groupSpec += i;
                    }
                } else {
                    type++;
                }
            }

            for (Group *group: groups) {
                if (group->getTitle() == groupTitle && group->getSpec() == groupSpec) {
                    group->addStudent(new Student(studentFio, group, counter++));
                    break;
                }
            }
        }
    }
    from.close();
}

void Deanery::addMarksForStudents() {
    for (Group *group: groups) {
        for (Student *student: group->getStudents()) {
            student->addMark(rand() % (maxMark + 1));
        }
    }
}

void Deanery::showStatisticForAllStudents() {
    for (Group *group: groups) {
        std::cout << "\nGroup: " << group->getTitle() << " " << group->getSpec() << "\n";
        for (Student *student: group->getStudents()) {
            std::cout << student->getId() << " " << student->getFio();
            std::cout << " Mean: " << student->getAverageMark() << "\n";
        }
    }
}

void Deanery::kickBadStudents() {
    for (Group *group: groups) {
        for (Student *student: group->getStudents()) {
            if (student->getAverageMark() < minNormalMark)
                group->kickStudent(student->getId());
        }
    }
}

void Deanery::election() {
    for (Group *group: groups) {
        if (group->getStudents().size() != 0)
            group->setRandomHead();
    }
}

std::vector<Group *> Deanery::getGroups() {
    return groups;
}

void Deanery::showGroupsHeads() {
    for (Group *group: groups) {
        std::cout << group->getTitle() << " " << group->getSpec() << " Head: ";
        if (group->getStudents().size() != 0 && group->getHead() != nullptr)
            std::cout << group->getHead()->getFio();
        std::cout << "\n";
    }
}

void Deanery::transfer(int id, const std::string &groupTitle, const std::string &groupSpec) {
    Group *toGroup = nullptr;
    Student *transferStudent = nullptr;

    for (Group *group: groups) {

        if (group->getTitle() == groupTitle && group->getSpec() == groupSpec)
            toGroup = group;

        for (Student *student: group->getStudents()) {
            if (student->getId() == id)
                transferStudent = student;
        }

        if (toGroup != nullptr && transferStudent != nullptr) {

            if (toGroup != transferStudent->getGroup()) {

                auto *patternOfStudentForTransfer = new Student(transferStudent->getFio(), toGroup, transferStudent->getId());

                for (int mark: transferStudent->getMarks())
                    patternOfStudentForTransfer->addMark(mark);

                toGroup->addStudent(patternOfStudentForTransfer);
                transferStudent->getGroup()->kickStudent(transferStudent->getId());
            }
            break;
        }
    }
}

void Deanery::saveDataAboutStudentsAndGroups() {

    saveDataAboutGroups();
    saveDataAboutStudents();
}

void Deanery::saveDataAboutGroups() {
    std::ofstream to(groupsSaveFileName);
    for (Group *group: groups) {
        to << group->getTitle() << " " << group->getSpec() << "\n";
    }
    to.close();
}

void Deanery::saveDataAboutStudents(){
    std::ofstream to(studentsSaveFileName);
    for (Group *group: groups) {
        for (Student *student: group->getStudents()) {
            to << student->getFio() << " " << group->getTitle() << " " << group->getSpec() << "\n";
        }
    }
    to.close();
}