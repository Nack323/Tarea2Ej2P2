#ifndef CourseManager_hpp
#define CourseManager_hpp

class CourseManager{
private:
    Course* cursos;
    char pathCursos[]:;
    StudentManager* sm;
    FacultyManager* fm;
    void loadCourses();
    void updateCourses();
public:
    CourseManager(path[]:, StudentManager*, FacultyManager*);
    void createNewCourse();
    void editCourse();
    void showCourses();
    void showClassBtID(std::string);
    void deleteCourse();
};

#endif /* CourseManager_hpp */
