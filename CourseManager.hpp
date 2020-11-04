
#include "Course.hpp"
#include "StudentManager.hpp"
#include "FacultyManager.hpp"
#include <iomanip>
#include <fstream>

#ifndef CourseManager_hpp
#define CourseManager_hpp
#include <iostream>
#include "Course.hpp"
class StudentManager;
class FacultyManager;

class CourseManager{
private:
    Course* cursos;
<<<<<<< HEAD
    int numCursos;
    char* pathCursos;
=======
    char pathCursos;
>>>>>>> 0b486ab78e619afc68a0593d7fa56c82ac3f2b0a
    StudentManager* sm;
    FacultyManager* fm;
    void loadCourses();
    void updateCourses();
public:
<<<<<<< HEAD
    CourseManager(char*,StudentManager*, FacultyManager*);
=======
    CourseManager(char * , StudentManager*, FacultyManager*);
>>>>>>> 0b486ab78e619afc68a0593d7fa56c82ac3f2b0a
    void createNewCourse();
    void editCourse();
    void showCourses();
    void showClassByID(std::string);
<<<<<<< HEAD
    void deleteCourse(std::string);
=======
    void deleteCourse();
>>>>>>> 0b486ab78e619afc68a0593d7fa56c82ac3f2b0a
};

#endif /* CourseManager_hpp */
