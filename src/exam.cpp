#include "exam.hpp"

using namespace std;

//------------------------------------------------------------------
// EXO 1
// code à copier dans exam.cpp (ne pas modifier)
void eval_exo1()
{
	EXO1 tab[10];
	for (int i = 0; i < 10; i++)
		cout << i+tab[i].value() << ".";
}
// output :
// -1.0.1.2.3.4.5.6.7.8.

//------------------------------------------------------------------
// EXO 1.1
// code à copier dans exam.cpp (ne pas modifier)
void eval_exo11()
{
	EXO11* tab[10];
	for (int i = 0; i < 10; i++)
		tab[i] = new EXO11(5*i+4);
	for (int i = 0; i < 10; i++)
		cout << tab[i]->value() << ".";
    for (int i = 0; i < 10; i++)
        delete tab[i];
}

// output:
// 4.9.14.19.24.29.34.39.44.49.

//------------------------------------------------------------------
// code à copier dans exam.cpp (ne pas modifier)
void test_voiture()
{
	float limite_moteur = 160;
	Voiture voiture(limite_moteur);
	voiture.run(130);
}