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

Course::Course(std::string _nrc, int totalCreditos):nrc(nrc),totalCreditos(totalCreditos){
    ArrayList<Student> est;
    this->estudiantes=est;

    ArrayList<Grade> notas;
    this->notas+notas;
}

void Course::addStudentGrade(Student*,Grade*){
    estudiantes.addObject(Student*);
    notas.addObject(Grade);
}

Grade* Course::getGradeByStudent(Student * estudiante){
    for(int i=0; i<totalEstudiantes; i++){
        if(estudiantes[i].getBannerID() == estudiante->getBannerID()){
            return &notas[i];
        }
    }
    return nullptr;
}


ArrayList<Student> Course::getAllStudents(){
    return this->estudiantes;
}

ArrayList<Grade> Course::getAllGrades(){
    return this->notas:
}

void Course::setProfesor(Faculty* _profesor){
    this->profesor = _profesor;
}

Faculty* Course::getProfesor(){
    return this->profesor;
}

int Course::getCreditos(){
    return this->totalCreditos;
}

void Course::setCreditos(int creditos){
    this->totalCreditos=creditos;

}


std::string Course::getNRC(){
    return nrc;
}

void Course::setNRC(std::string NRC_){
    this->nrc=NRC_;

}

std::string Course::getPath(){
    return path;
}

void Course::setPath(std::string path_){
    this->path=path_;
}