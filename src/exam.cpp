#include "exam.hpp"

// To use namespaces without editing the functions
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

//------------------------------------------------------------------
// A copier dans exam.cpp et ne modifier!
void run_compas()
{
	Compas me;
	cout << "starting point = " << me.where_am_i() << endl;
	me.north(4).east(5).south(6).west(2);
	cout << "ending point = " << me.where_am_i() << endl;
}

//------------------------------------------------------------------
// EXO 4
// code à copier dans exam.hpp / exam.cpp ou main.cpp
// ce code ne doit pas etre modifié
// void eval_exo4()
// {
// 	EXO4 a1;
// 	EXO4 a2;
// 	a1.value *= 2;
// 	a2.value += 6;
// 	EXO4::value -= 4;
// 	cout << "EXO4 resultat :" << a1.value << "." << a2.value << "." << EXO4::value << endl;
// }

// -------------------------------------
// EXO5
string mix(Couleur a, Couleur b) {
    string final_mix = "";

    final_mix += COLOR_NAME(a);
    final_mix += COLOR_NAME(b);

    return final_mix;
}

// la fonction eval_exo5 doit etre copiée dans exam.cpp et ne doit pas être modifiée 
void eval_exo5()
{
    Couleur r(RGB::r);
    Couleur g(RGB::g);
    Couleur b(RGB::b);
	cout<<"result : "
        <<mix(r,g)<<","<<mix(r,b)<<","<<mix(g,b)<<","
        <<mix(r,r)<<","<<mix(g,g)<<","<<mix(b,b)<<endl;
}

// expected output
//result : rg,rb,gb,r,g,b
// or
//result : rg,rb,gb,rr,gg,bb 


//------------------------------------------------------------------
// EXO 6
// code à copier dans exam.cpp
void eval_exo6()
{
    // à vous de coder:
	//instancier un chien, un chat et une vache
	Dog doggo;
	Cat gatto;
	Cow marguerite;

	// Déclarer et remplir un vecteur animals de pointeurs d'Animal

	// Making almost fizzbuzz test with animals because why not
	vector<Animal *> ferme(11);
	for (int i(0) ; i < ferme.size() ; i++) {
		if (i % 3 == 0) {
			ferme[i] = new Dog();
		} else if (i % 5 == 0) {
			ferme[i] = new Cow();
		} else {
			ferme[i] = new Cat();
		}
	}

	// appeler make_sound() pour chaque animal du vecteur
	for (auto animal: ferme) {
		animal->make_sound();
	}
}

//------------------------------------------------------------------
// EXO 7
// code à copier dans exam.cpp
void eval_exo7()
{
    // à vous de coder

	vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Rectangle>(2, 3));
    shapes.push_back(make_unique<Rectangle>(4, 5));
    shapes.push_back(make_unique<Rectangle>(1, 6));
    shapes.push_back(make_unique<Rectangle>(3, 4));
    shapes.push_back(make_unique<Rectangle>(2.5, 2.5));

    shapes.push_back(make_unique<Circle>(1.5));
    shapes.push_back(make_unique<Circle>(2.5));
    shapes.push_back(make_unique<Circle>(3));
    shapes.push_back(make_unique<Circle>(4));
    shapes.push_back(make_unique<Circle>(2));

    double totalArea = calculateTotalArea(shapes);

    cout << "Surface cumulée de toutes les formes : " << totalArea << endl;

    for (const auto& shape : shapes) {
        auto copy = shape->get_clone();
        cout << "Surface de la copie : " << copy->getArea() << endl;
    }
}