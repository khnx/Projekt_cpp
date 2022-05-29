# Operacje na wektorach

## Punkt

1. Konstruktory.

	- Domyslny, pusty, bez współrzędnych,
	- Inicjalizowany listą - obiektem postaci {},
	- Inicjalizowany tablicą [], z podaniem ilości elementówn
	- Inicjalizowawny tablicą dynamiczną.

2. Cechy.

	- Trzyma współrzędne w dynamicznej tablicy.

3. Dozwolone operacje.

	- Dodawanie punktów,
	- Odejmowanie punktów,
	- Przypisywanie innych współrzędnych,
	- Wypisanie współrzędnych.

## Wektor

1. Sposoby tworzenia wektorów:

	- Inicjalizowany listą - obiektem postaci {} jako współrzędne, punkt początkowy z odpowiednią ilością współrzędnych równych 0.
	- Inicjalizowany tablicą dynamiczną jako współrzędne punkt początkowy z odpowiednią ilością współrzędnych równych 0.
	- Inicjalizowany listą - obiektem postaci {} zarówno dla współrzędnych wektora, jak i punktu zaczepienia.
	- Współrzędne wektora jako tablica dynamiczna, punkt zaczepienia jako punkt.
	- Dwa punkty, wyliczyć różnicę, zaczepić w pierwszym punkcie.

2. Dozwolone operacje.

	- Dodawanie (dowolny wektor).
	- Odejmowanie (dowolny wektor).
	- Translacja (zmiana punktu zaczepienia względem początkowego o wskazany wektor).
	- Mnożenie wektora przez skalar - skalowanie współrzędnych wektora przez wskazaną liczbę.
	- Mnożenie skalarne wektorów.
	- Mnożenie wektorowe z użyciem kąta między wektorami.
	- Mnożenie wektorowe ze wzoru Sarrusa (wektor z 3 składnikami).
	- Wektor przeciwny - odwrócenie znaków współrzędnych wektora.
	- Norma
	- Długość wektora - pierwiastek normy.

3. Metody.

	- operator + - dodawanie wektorów.
	Parametry: (wektor)
	Return: wektor

	- operator - - odejmowanie wektorów.
	Parametry: (wektor)
	Return: wektor

	- operator * - mnożenie wektora przez skalar.
	Parametry: (liczba)
	Return: wektor

	- operator = - przepisanie cech wektora.
	Parametry: (wektor)
	Return: wektor

	- dot_product() - mnożenie skalarne z innym wektorem.
	Parametry: (wektor)
	Return: liczba

	- cross_product_theta() - mnożenie wektorowe dwóch wektorów o podany kąt.
	Parametry: (wektor, kąt)
	Return: liczba

	- cross_product() - mnożenie dwóch wektorów ze wzoru Sarrusa.
	Parametry: (wektor)
	Return: wektor

	- translate() - translacja wektora o wektor.
	Parametry: (wektor)
	Return: wektor

	- opposite() - wektor przeciwny.
	Parametry: ()
	Return: wektor

	- norm() - kwadrat długości wektora.
	Parametry: ()
	Return: liczba

	- abs() - długośc wektora.
	Parametry: ()
	Return: liczba