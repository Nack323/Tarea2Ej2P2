#ifndef StudentManager_hpp
#define StudentManager_hpp
#include "Student.hpp"
#include <fstream>
#include "Proxy.hpp"
#include "UnderGraduateStudent.hpp"
#include "GraduateStudent.hpp"
#include "Student.hpp"
#include "UserManager.hpp"
#include "GraduateStudent.hpp"
#include <fstream>
#include <deque>

class UserManager;

class StudentManager{
private:
    std::deque<Student*> estudiantes;// tiene que ser un deque de punteros para poder hacer el cast
    char* pathUndergraduate;
    void loadUnderGrads();
    char* pathGraduate;
    void loadGrads();
    void updateUnderGrads();
public:
    StudentManager(char*, char*);
    StudentManager(){};
    void createNewStudent(UserManager*);
    Student* getStudentByID(std::string);
    std::deque<Student*> getAllStudents();
    void editStudent(Student*);
    void showStudents();
    void showStudent(std::string);
    void showStudent(Student*);
    void deleteStudent(std::string);
};

#endif /* StudentManager_hpp */
