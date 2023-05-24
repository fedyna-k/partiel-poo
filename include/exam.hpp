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

#endif