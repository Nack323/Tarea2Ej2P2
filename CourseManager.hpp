
#include "Course.hpp"
#include "StudentManager.hpp"
#include "FacultyManager.hpp"
#include <fstream>

#ifndef CourseManager_hpp
#define CourseManager_hpp

class CourseManager{
private:
    Course* cursos;
    char* pathCursos;
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
    void deleteCourse();
};

#endif /* CourseManager_hpp */
