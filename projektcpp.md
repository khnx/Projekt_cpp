# Operacje na wektorach

## Zalożenia

1. szablon klas punkt, wektor

2. każda klasa ma obsłużyć twór 1, 2 lub 3 argumentowy

	```
	u(1,2,3), v(4,2), w
	```

3. Operacje, które zwracają zawsze nowy twór:

	- utworzenie wektora
	- translacja o wektor
	- dodawanie wektorów
	- odejmowanie
	- oba iloczyny wektorowe
	- wektor przeciwny
	- mnożenie liczby przez wektor
	- długość wektora

## Pytania ogólne

1. Jakie typy powinny być wspierane przez szablony?

## Punkt

1. Podobny do klasy liczby zespolone.

	- Czy obsługuje liczby zespolone?
	- Czy potrzebna klasa "liczby zespolone", czy użyć biblioteki complex?

2. Zawiera 3 opcjonalne współrzędne.

	- Czy współrzędne powinny być przekazywane "na sztywno", tj. 3 argumenty, z wartościami domyślnymi.
	- II opcja: przekazanie wartości współrzędnych przez obiekt klasy vector lub listę inicjalizacyjną; zmienna ilość parametrów bez obciążenia pustymi wartościami.

3. Pozycja domyślna to początek układu współrzednych.

	- Użyć domyślnego początku?
	- Początek dla układu lini prostej, płaszczyzny, przestrzeni?

4. Dozwolone operacje.

	- Dodawanie.
	- Odejmowanie.

## Wektor

1. Zachowanie pozycji.

	- Czy wektor powinien być zawieszony w punkcie początkowym i kończyć się w punkcje końcowym?
	- Czy wektor powinien być standaryzowany do początku układu współrzędnych.
	- Czy trzymać współrzędne punktu zaczepienia wektora?

2. Sposoby tworzenia wektorów:

	- Współrzędne wektora.
	- Współrzędne wektora, punkt zaczepienia.
	- Dwa punkty, wyliczyć różnicę, zaczepić w pierwszym punkcie.

3. Dozwolone operacje.

	- Dodawanie (dowolny wektor).
	- Odejmowanie (dowolny wektor).
	- Translacja (zmiana punktu zaczepienia względem początkowego o wskazany wektor).
	- Mnożenie wektora przez skalar - skalowanie współrzędnych wektora przez wskazaną liczbę.
	- Mnożenie skalarne wektorów.
	- Mnożenie wektorowe z użyciem kąta między wektorami (wektor z 3 składnikami).
	- Mnożenie wektorowe ze wzoru Sarrusa (wektor z 3 składnikami).
	- Wektor przeciwny - odwrócenie znaków współrzędnych wektora.
	- Długość wektora - norma.

4. Metody.

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