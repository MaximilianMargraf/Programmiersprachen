# include <iostream>

int var = 3; // Die Variable var ist eine globale Variable. Sie existiert in allen Scopes

// Die Signatur einer Funktion besteht aus ihrem Namen, den Namen der Inputparameter
// und dem Datentyp der Inputparameter. Der Rückgabetyp der Funktion ist nicht Teil der S.

double sum (double a, double b)
{
	// Die Variablen a und b existieren nur in dieser Funktion
	return a + b;
}

int square (int var)
{
	// In dieser Funktion wird die globale Variable innherhalb dieses Blockes überschrieben
	// ::var würde hier = 3 liefern. 
	return var * var ;
}

int main ()
{
	for ( int i = 0; i != 100; i++)
	{
		// i existiert nur in dem Block der For-Schleife
		std::cout << "i^2 = " << square (i) << "\n";
		std::cout << "i + i = " << sum (i, i) << "\n";
	}

	return 0;
}
