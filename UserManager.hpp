
#ifndef UserManager_hpp
#define UserManager_hpp
#include "User.hpp"
#include <stdio.h>
#include <string>
<<<<<<< HEAD
#include "User.hpp"
#include "StudentManager.hpp"
#include "FacultyManager.hpp"


=======
class FacultyManager;
class StudentManager;
>>>>>>> 0b486ab78e619afc68a0593d7fa56c82ac3f2b0a
class UserManager{
private:
    User* usuarios;
public:
    UserManager(FacultyManager*, StudentManager*);
    User* validateCredentials(std::string, std::string);
    void editUser(User*);
    void showUser(User*);
    std::string getNewBannerID();
};


#endif /* UserManager_hpp */
