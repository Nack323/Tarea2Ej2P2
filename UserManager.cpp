#include <iostream>
#include "UserManager.hpp"

UserManager::UserManager(FacultyManager* _facultyManager, StudentManager* _studentManager):facultyManager(_facultyManager), studentManager(_studentManager){
};

User* UserManager::validateCredentials(std::string userName, std::string contrasenia){
  std::cout<<"Ingrese nombre de Usuario"<<std::endl;
  std::cin>>userName;
  std::cout<<"Ingrese Contrasenia"<<std::endl;
  std::cin>>contrasenia;

  
<<<<<<< HEAD
  if (userName==User::getNombre() and contrasenia==User::getContrasenia()){
    std::cout<<"Credenciales validas"<<std::endl;
  }
  else{   
    std::cerr<<"Credenciales no validas"<<std::endl;
=======
  if (userName==User::getUser() and contrasenia==User::getContrasenia){
      std::cout<<"Credenciales validas"<<std::endl;
  }
  else{ 
    std::cerr<<"Credenciales no validas" << std::endl;
>>>>>>> 0b486ab78e619afc68a0593d7fa56c82ac3f2b0a
  }
  //return nullptr;
};

void UserManager::editUser(User* usuario){
  //averiguar como modificar funciones de user (setUser)
};

void UserManager::showUser(User* usuario){
  std::cout<<"Usuario"<< User::getUsuario()<<std::endl;
};

std::string UserManager::getNewBannerID(){
  //averiguar como modificar funciones de user (setBannerID)
    std::string s{""};
  return s;
};
