#ifndef StudentManager_hpp
#define StudentManager_hpp
#include "Student.hpp"
#include "UserManager.hpp"
#include <fstream>

class StudentManager{
private:
    Student* estudiantes;
    int totalEstudiantes;//cambiar por arraylist
    char* pathUndergraduate;
    void loadUnderGrads();//cambiar agregar lo mismo para grads
    void updateUnderGrads();
public:
    StudentManager(char*);
    void createNewStudent(UserManager*);
    Student* getStudentByID(std::string);
    Student* getAllStudents(int&);//cambiar quitar int por referencia cuando sepamos arraylist
    void editStudent();
    void showStudents();
    void deleteStudent();
};

#endif /* StudentManager_hpp */
