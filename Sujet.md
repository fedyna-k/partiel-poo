# EXAMEN POO (24 mai 2023)

Créer un dossier sous la forme *nom.prénom*, par exemple: ```dupond.michel```. 

Dans ce dossier, créez 2 fichiers: ```exam.hpp``` et ```exam.cpp```: ce sont les seuls fichiers qui seront évalués.

Nous vous fournissons un fichier ```main.cpp``` à la fin de ce document. Celui-ci doit vous permettre de vous assurer que vos fichiers *exam* sont correctement formatés.

Les exercices suivants devront être rédigés uniquement dans vos 2 fichiers exam.

Vous êtes invité à commenter vos fichiers de sorte à expliquer votre démarche et utiliser des noms de variables explicites: la lisibilité du code sera prise en compte pour la notation.  

Les extraits de codes présentés dans les énoncés suivants peuvent et doivent être copiés/collés dans vos fichiers ```exam.cpp``` et/ou ```exam.hpp```. 

Vous pouvez commenter/décommenter les appels aux fonctions qui sont dans le fichier ```main.cpp``` : **votre fichier ```main.cpp``` ne sera pas pris en compte pour l'évaluation**.

<br/><br/>

## EXO 1

EXO1 est une classe qui contient une variable **privée** "val" et la fonction membre public ```int value()```

Construire dans le fichier ```exam.hpp``` la classe EXO1 avec un constructeur par défaut qui assure l'initialisation  ```val=-1```.

Copier la fonction ```void eval_exo1()``` dans le fichier *exam.cpp*, ne la modifiez pas et faites en sorte qu'elle s'éxécute correctement en produisant la sortie attendue.

```cpp
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
```

La classe EXO11 hérite de EXO1, elle a la particularité supplémentaire de pouvoir être initialisée avec une valeur. Construire la classe **EXO11** dans le fichier *exam.hpp* pour que la fonction *eval_exo11* suivante affiche les 10 valeurs attendues. (Ne modifiez pas le corps de la fonction *eval_exo11*)

```cpp
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
```

## EXO 2

Compléter la classe voiture pour que la fonction ```void test_voiture()``` fonctionne correctement.

```cpp
//------------------------------------------------------------------
// EXO 2
// code à copier et modifier dans exam.hpp
class Voiture
{
private:
	float _vitesse;
	const float _engine_limit;
public:

	string control() 
	{
		return _vitesse > _engine_limit ? "\ttoo fast !" : "\tok";
	}
	
	void speedUp() 
	{	cout << "speed = " << (_vitesse == 0 ? _vitesse = 1 : _vitesse *= 1.3) << 
		control() << endl; 
	}

	void speedDown() 
	{
		cout << "speed = " << (_vitesse *= 0.9) << control() << endl; 
	}

	void run(float targetSpeed)
	{
		while (abs(targetSpeed - _vitesse) > 5.f)
		{
			while (_vitesse < targetSpeed)
				speedUp();
			while (_vitesse > targetSpeed)
				speedDown();
		}
	}
};

//------------------------------------------------------------------
// code à copier dans exam.cpp (ne pas modifier)
void test_voiture()
{
	float limite_moteur = 160;
	Voiture voiture(limite_moteur);
	voiture.run(130);
}
```

## EXO3

Compléter la classe Compas pour que la fonction ```void run_compas()``` fournisse le résultat attendu.

Les règles de déplacement sont les suivantes:

- un déplacement de ```n``` pas vers le Nord incrémente la coordonnée ```y``` d'une quantité ```n```
- un déplacement de ```n``` pas vers le sud décrémente la coordonnée ```y``` d'une quantité ```n```
- un déplacement de ```n``` pas vers l'Est incrémente la coordonnée ```x``` d'une quantité ```n```
- un déplacement de ```n``` pas vers l'Ouest décrémente la coordonnée ```x``` d'une quantité ```n```


```cpp
//------------------------------------------------------------------
// EXO 3
// code à copier et modifier dans exam.hpp et/ou exam.cpp
class Compas
{
private:
    int x,y;
    
public:
    Compas()
    {
        x = 27;
        y = 39;
    }
    string where_am_i(){return "(" + to_string(x) + "," + to_string(y) + ")"; }
};

//------------------------------------------------------------------
// A copier dans exam.cpp et ne modifier!
void run_compas()
{
	Compas me;
	cout << "starting point = " << me.where_am_i() << endl;
	me.north(4).east(5).south(6).west(2);
	cout << "ending point = " << me.where_am_i() << endl;
}
```

## EXO4

Nous voulons le résultat suivant :
```code
resultat :12.12.12
```
Construire la classe ```EXO4``` et initialiser la variable ```value``` pour avoir le résultat attendu.

```cpp
//------------------------------------------------------------------
// EXO 4
// code à copier dans exam.hpp / exam.cpp ou main.cpp
// ce code ne doit pas etre modifié
void eval_exo4()
{
	EXO4 a1;
	EXO4 a2;
	a1.value *= 2;
	a2.value += 6;
	EXO4::value -= 4;
	cout << "EXO4 resultat :" << a1.value << "." << a2.value << "." << EXO4::value << endl;
}
```


## EXO 5
La classe Couleur est définie de la manière suivante:

```cpp
//------------------------------------------------------------------
// EXO 5
// code à copier dans exam.hpp / exam.cpp

enum RGB {r=0b001,g=0b010,b=0b100};
class Couleur
{
 private:
    RGB c;
 public:
    Couleur(RGB a):c(a){}
    int operator()(){return c;}
};
```

Construire la fonction **mix**, assistante de la classe ```Couleur```, capable de mixer les couleur et fournir 1 des 2 résultats suivants en réponse à l'appel de fonction d'évaluation suivante:

```cpp
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

```

## EXO 6

A partir de la classe ```Animal``` suivante :

```cpp
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
```

Déclarez un vecteur *animals* de pointeurs d'*Animal* et ajoutez dans ce vecteur : 
- l'instance *chien* d'un objet d'une classe *Dog*, 
- l'instance *chat* d'une classe *Cat* 
- l'instance *vache* d'une clase *Cow*.

Dans la fonction ```void eval_exo6()``` de votre fichier exam.cpp: parcourez le vecteur et appelez la fonction make_sound() pour chaque animal du vecteur.

Créez une nouvelle classe d'animal: une classe Cow, et ajoutez-la à la hiérarchie.  Modifiez la boucle de parcours pour inclure l'objet Cow et appelez la fonction make_sound() pour chaque animal du vecteur. Assurez-vous que la fonction make_sound() est correctement appelée pour chaque objet dans le vecteur, y compris la vache nouvellement ajoutée.

```cpp
//------------------------------------------------------------------
// EXO 6
// code à copier dans exam.cpp
void eval_exo6()
{
    // à vous de coder:
	//instancier un chien, un chat et une vache

	// Déclarer et remplir un vecteur animals de pointeurs d'Animal

	// appeler make_sound() pour chaque animal du vecteur
}

```
## EXO 7

Créez une classe de base Shape, qui contient une méthode virtuelle pure getArea(). La fonction  getArea() renvoie la surface de la forme.

Créez deux classes dérivées de Shape : Rectangle et Circle. Les deux classes doivent avoir des constructeurs appropriés à leur forme et constructeur par copie.

Créez une fonction assistante template qui prend un Shape en entrée et retourne la surface de cette forme - calculé à l'aide de la méthode getArea().

Dans la fonction ```void eval_exo7()```: 
- créez 5 Rectangles de tailles différentes et 5 Circles de rayon différent
- Ajoutez-les dans un vecteur Shape
- Parcourir le vecteur 
  - calculer la surface cumulée de toutes ces formes
  - Utilisez le constructeur par copie pour créer une copie de chaque forme, afficher la surface de la copie.

**contrainte** :  le parcours du vecteur de forme doit être fait avec un itérateur.

**Conseils** : 
 - utiliser le constructeur par copie dans une fonction membre virtuelle ```get_clone()``` pour ne pas avoir à connaitre la nature de la forme que vous copiez
 - penser à détruire correctement vos objets
```cpp
//------------------------------------------------------------------
// EXO 7
// code à copier dans exam.cpp
void eval_exo7()
{
    // à vous de coder
}
```

## main.cpp

```cpp
#include <iostream>
#include "exam.hpp"

using namespace std;

void eval_exo1();
void eval_exo11();
void test_voiture();
void run_compas();
void eval_exo4();
void eval_exo5();
void eval_exo6();
void eval_exo7();

int main()
{
	cout << "\n-----------------------------------------------" << endl
		<< "eval_exo1" << endl;
	//eval_exo1();

	cout << "\n-----------------------------------------------" << endl
		<< "eval_exo11" << endl;
	//eval_exo11();

	cout << "\n-----------------------------------------------" << endl
		<< "test_voiture" << endl;
	//test_voiture();

	cout << "\n-----------------------------------------------" << endl
		<< "run_compas" << endl;
	//run_compas();

	cout << "\n-----------------------------------------------" << endl
		<< "EXO 4" << endl;
	//eval_exo4();

	cout << "\n-----------------------------------------------" << endl
		<< "EXO 5" << endl;
	//eval_exo5();

	cout << "\n-----------------------------------------------" << endl
		<< "EXO 6" << endl;
	//eval_exo6();

	cout << "\n-----------------------------------------------" << endl
		<< "EXO 7" << endl;
	//eval_exo7();
}
```