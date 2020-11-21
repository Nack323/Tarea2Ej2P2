//
//  Course.cpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#include "Course.hpp"
#include <iostream>

Course::Course(){ }

Course::~Course(){
    std::cout<<"La clase con NRC:"<<nrc<<" fue eliminada.";
}

Course::Course(std::string _nrc, Faculty* _profesor, Student* _estudiantes, Grade *_notas, int _totalEstudiantes, int _totalCreditos,std::string _path):
nrc(_nrc), profesor(_profesor), estudiantes(_estudiantes), totalEstudiantes(_totalEstudiantes),totalCreditos(_totalCreditos), notas(_notas),path(_path)
{
}

void Course::setProfesor(Faculty* _profesor){
    profesor = _profesor;
}

void Course::setNotas(Student* _estudiantes, Grade* _notas, int _totalEstudiantes){
    estudiantes = _estudiantes;
    notas = _notas;
    totalEstudiantes = _totalEstudiantes;
}

Faculty* Course::getProfesor(){
    return profesor;
}

Grade* Course::getGradeByStudent(Student * estudiante){
    for(int i=0; i<totalEstudiantes; i++){
        if(estudiantes[i].getBannerID() == estudiante->getBannerID()){
            return &notas[i];
        }
    }
    return nullptr;
}

Student* Course::getStudents(){
    return estudiantes;
}

int Course::getTotalEstudiantes(){
    return totalEstudiantes;
}

std::string Course::getNRC(){
    return nrc;
}

int Course::getCreditos(){
    return totalCreditos;
}


std::string Course::getPath(){
    return path;
}

void Course::setNRC(std::string NRC_){
    this->nrc=NRC_

}

void Course::setCreditos(int creditos){
    this->totalCreditos=creditos

}