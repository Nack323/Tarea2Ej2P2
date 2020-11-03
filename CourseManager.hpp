#ifndef CourseManager_hpp
#define CourseManager_hpp
#include <iostream>
#include "Course.hpp"
class StudentManager;
class FacultyManager;

class CourseManager{
private:
    Course* cursos;
    char pathCursos;
    StudentManager* sm;
    FacultyManager* fm;
    void loadCourses();
    void updateCourses();
public:
    CourseManager(char * , StudentManager*, FacultyManager*);
    void createNewCourse();
    void editCourse();
    void showCourses();
    void showClassByID(std::string);
    void deleteCourse();
};

#endif /* CourseManager_hpp */
