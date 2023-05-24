#ifndef __EXAM_HPP__
#define __EXAM_HPP__

#include <iostream>

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
        EXO11(int initial_val = DEFAULT_VAL) {
            val = initial_val;
        }

        inline int value() {return val;}
};

#endif