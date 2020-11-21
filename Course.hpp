//
//  Course.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef Course_hpp
#define Course_hpp

//=================================
// forward declared dependencies
class Student;
class Faculty;

#include <stdio.h>
#include <string>
#include "Student.hpp"
#include "Faculty.hpp"
#include "Grade.hpp"

class Course{
private:
    std::string nrc;
    std::string name;
    Faculty *profesor;
    Student *estudiantes;
    Grade *notas;
    int totalEstudiantes;
    int totalCreditos;
    std::string path;
public:
    Course();
    ~Course();
    Course(std::string, Faculty*, Student*, Grade*, int, int,std::string);
    void setProfesor(Faculty*);
    void setNotas(Student*, Grade*, int);
    Faculty* getProfesor();
    Grade *getGradeByStudent(Student*);
    Student* getStudents();
    int getTotalEstudiantes();
    int getCreditos();
    void setTotalEstudiantes();
    std::string getNRC();
    std::string getPath();
    void setNRC(std::string);
    void setCreditos(int);
};

#endif /* Course_hpp */
