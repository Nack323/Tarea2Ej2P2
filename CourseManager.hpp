
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
    int numCursos;
    char* pathCursos;
    char pathCursos;
    StudentManager* sm;
    FacultyManager* fm;
    void loadCourses();
    void updateCourses();
public:
    CourseManager(char*,StudentManager*, FacultyManager*);
    void createNewCourse();
    void editCourse();
    void showCourses();
    void showClassByID(std::string);
    void deleteCourse(std::string);
};

#endif /* CourseManager_hpp */
