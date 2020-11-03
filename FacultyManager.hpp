#include"Faculty.hpp"
#include"UserManager.hpp"

#ifndef FacultyManager_hpp
#define FacultyManager_hpp

class FacultyManager{
private:
    Faculty* profesores;
    char pathFaculty[];
    void loadFaculty();
    void updateFaculty();
public:
    FacultyManager(char*);
    void createNewFaculty(UserManager*);
    Faculty* getFacultyByID(std::string);
    Faculty* getAllFaculty();
    void editFaculty();
    void showFaculty();
    void deleteFaculty();
};

#endif /* FacultyManager_hpp */
