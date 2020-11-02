#ifndef UserManager_hpp
#define UserManager_hpp

#include <stdio.h>
#include <string>

class UserManager{
private:
    User* usuarios;
public:
    UserManager(FacultyManager*, StudentManager*);
    User* ValidateCredentials(std::string, std::string);
    void editUser(User*);
    void showUser(User*);
    std::string getNewBannerID();
};

#endif /* UserManager_hpp */
