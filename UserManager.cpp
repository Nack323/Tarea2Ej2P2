#include <iostream>
#include "UserManager.hpp"

UserManager::UserManager(FacultyManager* _facultyManager, StudentManager* _studentManager):facultyManager(_facultyManager), studentManager(_studentManager){
  std::cout<<"UserManager constructor"<<std::endl;
};

User* UserManager::validateCredentials(std::string userName, std::string contrasenia){
  std::cout<<"Ingrese nombre de nsuario"<<std::endl;
  std::cin>>userName;
  std::cout<<"Ingrese contrasenia"<<std::endl;
  std::cin>>contrasenia;
  
  if (userName==User::getUser() and contrasenia==User::getContrasenia){
      std::cout<<"Credenciales validas"<<std::endl;
  }
  else{ 
    std::cerr<<"Credenciales no validas" << std::endl;
  }
  //return nullptr;
};

void UserManager::editUser(User* usuario){
  //averiguar como modificar funciones de user (setUser)
};

void UserManager::showUser(User* usuario){
  std::cout<<"Usuario"<<User::getUsuario()<<std::endl;
};

std::string UserManager::getNewBannerID(){
  //averiguar como modificar funciones de user (setBannerID)
    std::string s{""};
  return s;
};
