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
    Faculty* getFacultyByID(std::string);//listo
    Faculty* getAllFaculty(int&);//cambiar si aprendemos arraylist
    void editFaculty(Faculty*);//listo
    void showFaculty(std::string);//listo. Depende de to_string
    void deleteFaculty(std::string);//listo. Posible core dumped
};

#endif /* FacultyManager_hpp */
