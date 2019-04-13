#include <iostream>

// Bei einer Deklaration teilt man dem Compiler mit, dass es eine Variable gibt:
// Hierbei wird die Variable nicht initialisiert.
// Die Deklaration besteht aus dem Datentypen und dem Bezeichner der Variable.

class YesOrNo;

bool yayOrNay();

extern bool i;


// Bei einer Definition wird nun die deklarierte Variable/Funktion/Klasse genau beschrieben
// und das Verhalten wird definiert. 
class YesOrNo
{
	// Ohne true wäre dies wieder nur eine Deklaration
	bool yn = true;
};


bool yayOrNay()
{
	return true;
}


int main()
{
	yayOrNay();
	return 0;
}

// Den Unterschied zwischen Deklaration und Definition benutzt man häufig in header und source files 
// Im .h wird alles deklariert, und im .cpp dann definiert.