
#ifndef UserManager_hpp
#define UserManager_hpp
#include "User.hpp"
#include <stdio.h>
#include <string>
#include "User.hpp"
#include "StudentManager.hpp"
#include "FacultyManager.hpp"



class FacultyManager;
class StudentManager;

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
