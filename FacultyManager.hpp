#ifndef FacultyManager_hpp
#define FacultyManager_hpp
#include "Faculty.hpp"
#include "UserManager.hpp"
#include <fstream>
#include <iostream>
#include <deque>

class UserManager;


class FacultyManager{
private:
    std::deque<Faculty> profesores;
    std::string pathFaculty;
    void loadFaculty();
    void updateFaculty();
public:
    ~FacultyManager();
    FacultyManager(std::string);
    FacultyManager(){};
    void createNewFaculty(UserManager*);
    Faculty* getFacultyByID(std::string);//listo
    std::deque<Faculty> getAllFaculty();//listo
    void editFaculty(Faculty*);//listo
    void showFaculty(std::string);//listo. Depende de to_string
    void deleteFaculty(std::string);//listo. Posible core dumped
};

#endif /* FacultyManager_hpp */
