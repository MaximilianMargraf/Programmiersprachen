#include <iostream>

int main()
{
	// int, bool, char etc sind Datentypen
	// a, b, c, d, five, e sind die Variablen
	// Alles hinter dem = sind die Werte der jeweiligen Variablen

	int a = 9;
	bool b = false;
	char c = 'a';
	double d = 1.3;

	// Bei const handelt es sich um einen speziellen Zusatz
	// Man erklärt hiermit, dass sich diese Variable niemals verändern wird
	int const five = 5;
	
	// Bei einer Typkonvertierung handelt es sich um eine Konvertierung eines
	// Datentyps in einen anderen. Hier würde zum Beispiel aus einem int (a)
	// ein double werden. Die Variable "two" existiert jedoch noch nicht.

	double e = a/two;

	// Der konstanten Variable wird ein neuer Wert zugeordnet
	five = d;

	return 0;
}