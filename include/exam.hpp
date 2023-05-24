#ifndef __EXAM_HPP__
#define __EXAM_HPP__

// Includes for all files

#include <iostream>
#include <string>
#include <cmath>

// ----- Classe EXO1 -----

#define DEFAULT_VAL -1

class EXO1 {
    private:
        int val;
    
    public:

        // Default constructor
        EXO1() : val(DEFAULT_VAL) {}

        // Inline function to speed up runtime
        // Using virtual to be able to redefine the function
        // in EXO11
        virtual inline int value() {return val;}
};


// ----- Classe EXO11 -----

class EXO11 : public EXO1 {
    private:
        int val;

    public:

        // Constructor
        EXO11(int initial_val = DEFAULT_VAL) :
            val(initial_val)
        {}

        // Redefine value function
        inline int value() {return val;}
};

//------------------------------------------------------------------
// EXO 2
// code à copier et modifier dans exam.hpp

class Voiture {
    private:
        float _vitesse;
        const float _engine_limit;

    public:

        // Add constructor
        Voiture(float engine_limit) :
            _engine_limit(engine_limit),
            _vitesse(0.)
        {}

        // Add std:: and include <string>
        std::string control() {
            return _vitesse > _engine_limit ? "\ttoo fast !" : "\tok";
        }

        // Add std:: and reduce acceleration ratio 1.3 => 1.1
        void speedUp() {
            std::cout << "speed = " << (_vitesse == 0 ? _vitesse = 1 : _vitesse *= 1.1) << control() << std::endl; 
        }

        // Add std::
        void speedDown() {
            std::cout << "speed = " << (_vitesse *= 0.9) << control() << std::endl; 
        }

        void run(float targetSpeed) {
            while (std::abs(targetSpeed - _vitesse) > 5.f)
            {
                while (_vitesse < targetSpeed)
                    speedUp();
                while (_vitesse > targetSpeed)
                    speedDown();
            }
        }
};

//------------------------------------------------------------------
// EXO 3
// code à copier et modifier dans exam.hpp et/ou exam.cpp
class Compas
{
private:
    int x,y;
    
public:
    
    Compas() {
        x = 27;
        y = 39;
    }

    //// Directions
    // Return address in order to chain directions
    // and edit position in place.

    // North
    Compas& north(int n) {
        y += n;
        return *this;
    }

    // South
    Compas& south(int n) {
        y -= n;
        return *this;
    }

    // East
    Compas& east(int n) {
        x += n;
        return *this;
    }

    // West
    Compas& west(int n) {
        x -= n;
        return *this;
    }
    
    inline std::string where_am_i() { return "(" + std::to_string(x) + "," + std::to_string(y) + ")"; }
};

// ----- Classe EXO4 -----

class EXO4 {
    public:
        static const int value = 12;
};

//------------------------------------------------------------------
// EXO 5
// code à copier dans exam.hpp / exam.cpp

// Useful macro to get colorname
#define COLOR_NAME($1) (string[]){"r", "g", "b"}[(int)log2($1())]

enum RGB {r=0b001,g=0b010,b=0b100};
class Couleur
{
 private:
    RGB c;
 public:
    Couleur(RGB a):c(a){}
    int operator()(){return c;}
};

//------------------------------------------------------------------
// EXO 6
// code à copier dans exam.hpp
class Animal
{
public:
    virtual void make_sound() = 0;
};

/*
class Dog ...
class Cat ...
class Cow ...
A vous de coder ces classes
*/

#endif