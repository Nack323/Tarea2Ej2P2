
#include "Course.hpp"
#include "StudentManager.hpp"
#include "FacultyManager.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include <iomanip>
#include <fstream>
#include "Grade.hpp"

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
    std::string pathCursos;
    StudentManager* sm;
    FacultyManager* fm;
    void loadCourses();
    void updateCourses();
public:
    CourseManager(std::string,StudentManager*, FacultyManager*);
    void createNewCourse();
    void editCourse();
    void showCourses();
    void showClassByID(std::string);
    void deleteCourse(std::string);

    Course* getCourseByNRC(std::string);
    void addStudentToClass(Course*,Student*);
    void addFacultyToClass(Course*,Faculty*);
};

#endif /* CourseManager_hpp */
