#include "Student.hpp"
#include <fstream>
#include "Proxy.hpp"
#include "UnderGraduateStudent.hpp"
#include "GraduateStudent.hpp"
#ifndef StudentManager_hpp
#define StudentManager_hpp
#include "Student.hpp"
#include "UserManager.hpp"
#include "GraduateStudent.hpp"
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
    StudentManager(){};
    void createNewStudent(UserManager*);
    Student* getStudentByID(std::string);
    Student* getAllStudents(int&);//cambiar quitar int por referencia cuando sepamos arraylist
    void editStudent(Student*);
    void showStudent(Student*);
    void deleteStudent(std::string);
    


};

#endif /* StudentManager_hpp */
