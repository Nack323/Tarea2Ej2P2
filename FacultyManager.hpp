#ifndef FacultyManager_hpp
#define FacultyManager_hpp
<<<<<<< HEAD
#include "Faculty.hpp"


class FacultyManager{
private:
    Faculty* profesores;
    char pathFaculty[];
=======
class Faculty;
class UserManager;
class FacultyManager{
private:
    Faculty* profesores;
    char* pathFaculty;
>>>>>>> 0b486ab78e619afc68a0593d7fa56c82ac3f2b0a
    void loadFaculty();
    void updateFaculty();
public:
    FacultyManager(char*);
<<<<<<< HEAD
    //void createNewFaculty(UserManager*);
=======
    void createNewFaculty(UserManager*);
>>>>>>> 0b486ab78e619afc68a0593d7fa56c82ac3f2b0a
    Faculty* getFacultyByID(std::string);
    Faculty* getAllFaculty();
    void editFaculty();
    void showFaculty();
    void deleteFaculty();
};

#endif /* FacultyManager_hpp */
