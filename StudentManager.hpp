#ifndef StudentManager_hpp
#define StudentManager_hpp
#include "Student.hpp"
#include "UserManager.hpp"
#include <fstream>

class StudentManager{
private:
    Student* estudiantes;
    int totalEstudiantes;//preguntar le agregue esto, ta bien?
    char* pathUndergraduate;
    void loadUnderGrads();
    void updateUnderGrads();
public:
    StudentManager(char*);
    void createNewStudent(UserManager*);
    Student* getStudentByID(std::string);
    Student* getAllStudents(int&);
    void editStudent();
    void showStudents();
    void deleteStudent();
};

#endif /* StudentManager_hpp */
