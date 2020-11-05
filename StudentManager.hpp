#include "Student.hpp"
#include <fstream>
#include "Proxy.hpp"
#include "UnderGraduateStudent.hpp"

#ifndef StudentManager_hpp
#define StudentManager_hpp
#include "Student.hpp"
#include "UserManager.hpp"
#include <fstream>

class UserManager;

class StudentManager{
private:
    Student* estudiantes;
    int totalEstudiantes;//cambiar por arraylist
    int totalUnderGraduate;
    int totalGraduate;
    char* pathUndergraduate;
    void loadUnderGrads();//cambiar agregar lo mismo para grads
    char* pathGraduate;
    void loadGrads();
    void updateUnderGrads();
public:
    StudentManager(char*, char*);
    void createNewStudent(UserManager*);
    Student* getStudentByID(std::string);
    Student* getAllStudents(int&);//cambiar quitar int por referencia cuando sepamos arraylist
    void editStudent();
    void showStudents();
    void deleteStudent();
};

#endif /* StudentManager_hpp */
