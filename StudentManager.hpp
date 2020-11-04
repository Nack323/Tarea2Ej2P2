#include "Student.hpp"
#include <fstream>
#include "Proxy.hpp"
#include "UnderGraduateStudent.hpp"

#ifndef StudentManager_hpp
#define StudentManager_hpp

class UserManager{};

class StudentManager{
private:
    Student* estudiantes;
    char pathUndergraduate[];
    void loadUnderGrads();
    void updateUnderGrads();
public:
    StudentManager(char*);
    void createNewStudent(UserManager*);
    Student* getStudentByID(std::string);
    Student* getAllStudents();
    void editStudent();
    void showStudents();
    void deleteStudent();
};

#endif /* StudentManager_hpp */
