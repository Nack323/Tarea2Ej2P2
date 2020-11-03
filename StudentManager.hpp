#ifndef StudentManager_hpp
#define StudentManager_hpp
#include "Student.hpp"
#include "UserManager.hpp"
class StudentManager{
private:
    Student* estudiantes;
    char pathUndergraduate[]:;
    void loadUnderGrads();
    void updateUnderGrads();
public:
    StudentManager(char);
    void createNewStudent(UserManager*);
    Student* getStudentByID(std::string);
    Student* getAllStudents();
    void editStudent();
    void showStudents();
    void deleteStudent();
};

#endif /* StudentManager_hpp */
