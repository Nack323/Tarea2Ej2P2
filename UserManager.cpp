#include <iostream>
#include "UserManager.hpp"

UserManager::UserManager(FacultyManager* _facultyManager, StudentManager* _studentManager):facultyManager(_facultyManager), studentManager(_studentManager){
};

User* UserManager::validateCredentials(std::string userName, std::string contrasenia){
  for(int i=0;i<userSize;i++)
  {
    if(usuario->getUsuario()==usuarios[i].getUsuario() and usuario->getContrasenia()==usuarios[i].getContrasenia())
       {
        std::cout<<"Ingrese nombre de Usuario"<<std::endl;
        std::cin>>userName;
        std::cout<<"Ingrese Contrasenia"<<std::endl;
        std::cin>>contrasenia;


        if (userName==usuarios[i].getUsuario() and contrasenia==usuario[i].getContrasenia()){
          std::cout<<"Credenciales validas"<<std::endl;
        }
        else{   
          std::cerr<<"Credenciales no validas"<<std::endl;
      }
  }
};

void UserManager::editUser(User* usuario){
  for(int i=0;i<userSize;i++)
  {
    if(usuario->getUsuario()==usuarios[i].getUsuario() and usuario->getBannerID()==usuarios[i].getBnnerID() and usuario->getContrasenia()==usuarios[i].getContrasenia() and usuario->getNombre()==usuarios[i].getNombre() and usuario->getApellido()==usuarios[i].getApellido()
       {
         std::string usuario_;
         std::string bannerID_;
         std::string contrasenia_;
         std::string nombre_;
         std::string apellido_;
         
         std::cout<<"Editar Usuario:"<<std::endl;
         std::cin>>usuario_;
         usuarioa[i].setUsuario(usuario_);
         
         std::cout<<"Editar Banner ID:"<<std::endl;
         std::cin>>bannerID_;
         usuarioa[i].setBannerID(bannerID_);
         
         std::cout<<"Editar Contrasenia:"<<std::endl;
         std::cin>>contrasenia_;
         usuarioa[i].setContrasenia(contrasenia_);
         
         std::cout<<"Editar Nombre:"<<std::endl;
         std::cin>>nomnre_;
         usuarioa[i].setNombre(nombre_);
         
         std::cout<<"Editar Apellido:"<<std::endl;
         std::cin>>apellido_;
         usuarioa[i].setApellido(apellido_);
       }
  }
};

void UserManager::showUser(User* usuario){
  for(int i=0;i<userSize;i++)
  {
    if(usuario->getUsuario()==usuarios[i].getUsuario() and usuario->getBannerID()==usuarios[i].getBnnerID() and usuario->getContrasenia()==usuarios[i].getContrasenia() and usuario->getNombre()==usuarios[i].getNombre() and usuario->getApellido()==usuarios[i].getApellido()
       {
         std::cout<<"Usuario:"<< usuarios[i].getUsuario()<<std::endl;
         std::cout<<"Banner ID:"<< usuarios[i].getBannerID()<<std::endl;
         std::cout<<"Contrasenia:"<< usuarios[i].getContrasenia()<<std::endl;
         std::cout<<"Nombre:"<< usuarios[i].getNombre()<<std::endl;
         std::cout<<"Apellido:"<< usuarios[i].getApellido()<<std::endl;
       }
    
};

std::string UserManager::getNewBannerID(){
  //averiguar como modificar funciones de user (setBannerID)
    std::string s{""};
  return s;
};
