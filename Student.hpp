//
//  Student.hpp
//  02_SolucionTarea01_C
//
//  Created by Daniel Riofrio on 6/10/20.
//  Copyright © 2020 Daniel Riofrio. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

//=================================
// forward declared dependencies
class Course;

#include <stdio.h>
#include <string>
#include "User.hpp"
#include "Course.hpp"

class Student : public User{
private:
    std::string carrera;
    Course *clases;
    int totalClases;
public:
    Student();
    virtual ~Student();
    Student(std::string, std::string, std::string, std::string, std::string, std::string);
    void setCarrera(std::string);
    void setClases(Course*, int);
    void calculateGPA();
    std::string getCarrera();
    Course* getClases(int&);
    float getGPA();
};

#endif /* Student_hpp */
