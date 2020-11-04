#include "Student.hpp"
#include <fstream>
#include "Proxy.hpp"
#include "UnderGraduateStudent.hpp"

#ifndef StudentManager_hpp
#define StudentManager_hpp
#include "Student.hpp"
#include "UserManager.hpp"
#include <fstream>

class UserManager{};

class StudentManager{
private:
    Student* estudiantes;
<<<<<<< HEAD
    char pathUndergraduate[];
=======
    int totalEstudiantes;//preguntar le agregue esto, ta bien?
    char* pathUndergraduate;
>>>>>>> 0b486ab78e619afc68a0593d7fa56c82ac3f2b0a
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
