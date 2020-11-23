//
//  Exceptions.hpp
//  997_Tarea02
//
//  Created by Daniel Riofrio on 22/11/20.
//

#ifndef Exceptions_hpp
#define Exceptions_hpp

#include <stdexcept>

class EmptyQueue: public std::runtime_error{
public:
    EmptyQueue(): std::runtime_error("The queue is empty"){}
};

class EmptyArrayList: public std::runtime_error{
public:
    EmptyArrayList(): std::runtime_error("The array list is empty"){}
};

class IndexOutOfBounds: public std::runtime_error{
public:
    IndexOutOfBounds(): std::runtime_error("Index out of bounds"){}
};

#endif /* Exceptions_hpp */
