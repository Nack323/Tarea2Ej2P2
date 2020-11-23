#ifndef FacultyManager_hpp
#define FacultyManager_hpp
#include "Faculty.hpp"
#include <fstream>
#include <iostream>

class UserManager;


class FacultyManager{
private:
    Faculty* profesores;
    int totalProfesores; // cambiar cuando aprendamos array lists
    std::string pathFaculty;
    void loadFaculty();
    void updateFaculty();
public:
    ~FacultyManager();
    FacultyManager(std::string);
    FacultyManager(){};
    //void createNewFaculty(UserManager*);
    Faculty* getFacultyByID(std::string);
    Faculty* getAllFaculty(int&);
    void editFaculty(Faculty*);
    void showFaculty(std::string);
    void deleteFaculty(std::string);
};

#endif /* FacultyManager_hpp */
