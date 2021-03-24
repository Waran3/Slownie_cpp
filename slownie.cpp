// S�ownie ver 1.0 C++ by Waran3
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string zero[1] = { "zero" };
string jednosci[9] = { "jeden", "dwa", "trzy","cztery", "pi��", "sze��", "siedem","osiem", "dziewi��" };
string nascie[9] = { "jedena�cie","dwana�cie","trzyna�cie","czterna�cie","pi�tna�cie","szesna�cie","siedemna�cie","osiemna�cie", "dziewi�tna�cie" };
string dziesiatki[9] = { "dziesi��", "dwadzie�cia", "trzydzie�ci", "czterdzie�ci", "pi��dziesi�t", "sze��dziesi�t","siedemdziesi�t","osiemdziesi�t", "dziewi��dziesi�t" };
string setki[9] = { "sto","dzwie�cie","trzysta","czterysta","pi��set","sze��set","siedemset","osiemset","dziewi��set" };
string tysiace[3] = { "tysi�c", "tysi�ce","tysi�cy" };
string miliony[3] = { "milion","miliony","milion�w" };
string miliardy[3] = { "miliard","miliardy","miliard�w" };
string zlote[3] = { "z�oty","z�ote","z�otych" };
string grosze[3] = { "grosz","grosze","groszy" };

int ilosc_cyfr;
//int ilosc_cyfr = 15;
//int* tablica_cyfr = new int[ilosc_cyfr]; // deklaracja tablicy o wielko�ci zale�nej od ilo�ci obliczonych cyfr;
int licznik_cyfr_w_funkcji;
float wskaznik_ulamka;
int a = 0, b = 1, c = 2; 
int licznik_wejsc_w_grosze = 0;
int pamiec_licznika_grosze;
int wskaznik_wejscia_w_grosze = 0;

char kwota_char[15];
int cyfra;
__int64 kwota_wszystkie_cyfry;
__int64 kwota_w_c;

string grosze_liczba;
string display;
string grosze_display;
string setki_display;
string tysiace_display;
string miliony_display;

int cyfra_zero_grupy = 0;
int cyfra_pierwsza_grupy = 0;
int cyfra_druga_grupy = 0;

string jednosci_liczba;
string nascie_liczba;
string dziesiatki_liczba;
string setki_liczba;

string grosze_odmiana;
string zlotowki_odmiana;
string tysiace_odmiana;
string miliony_odmiana;
string miliardy_odmiana;
string miliardy_display;

double atof_plus(char kwota[]);
void grosze_jednosci_nascie_diesiatki_setki(int* tablica_cyfr);
void odmiana_groszy(void);
void odmiana_zlotych(void);
void odmiana_tysiace(void);
void odmiana_miliony(void);
void odmiana_miliardy(void);

int main()
{
	setlocale(LC_ALL, "polish"); // w�aczenie polskich znak�w
	cout << "Wprowad� kwot� =";
	setlocale(LC_ALL, "en-US"); // w�aczenie znak�w USA ( w�aczenie kropki  dziesi�tnej) 
	cin >> kwota_char;
	double kwota = atof_plus(kwota_char);
	setlocale(LC_ALL, "polish"); // w�aczenie polskich znak�w
	//cout << "Wprowadzona kwota ="<<fixed<<kwota <<"\n";

	int licznik_cyfr = 0;

	wskaznik_ulamka = kwota - (__int64)kwota != 0;
	if (wskaznik_ulamka != 0)	// czyli kwota jest z czesci� u�amkow�
		kwota_wszystkie_cyfry = kwota *1000 /10 ; // zamiana kwoty z u�amkiem na liczbe ca�kowit� ( pierwsze dwie cyfry to grosze)
												// wystarczy pomno�yc przez 100 ale wychodz� czasem dziwne zaokraglenia st�d taka kombinacja
		else
			kwota_wszystkie_cyfry = kwota; // kwota jest bez cz�ci u�amkowej ( bez groszy)
	
	//int ilosc_cyfr;
	kwota_w_c = kwota_wszystkie_cyfry;
	for ( ilosc_cyfr = 0; kwota_w_c > 0; ilosc_cyfr++) // obliczanie ilo�ci cyfr
		kwota_w_c = kwota_w_c / 10;

	int* tablica_cyfr = new int[ilosc_cyfr];
	

	int ilosc_c = ilosc_cyfr;
	licznik_cyfr_w_funkcji = ilosc_cyfr;
	//cout << "Ilo�� cyfr = "<< ilosc_cyfr<<"\n";
	

	for (ilosc_c; ilosc_c > 0; ilosc_c--) // p�tla generuj�ca  poszczeg�lne cyfry
	{
		
		cyfra = kwota_wszystkie_cyfry % 10; //wydzielanie poszczeg�lnych  cyfr ( modulo)
		kwota_wszystkie_cyfry /= 10; //przesuwanie przecinka 

		tablica_cyfr[licznik_cyfr] = cyfra;
		//cout << "Poszczeg�lne cyfry to ="<<"["<<licznik_cyfr<<"]" << cyfra << endl;

		licznik_cyfr++;
	}
	
			if (wskaznik_ulamka != 0) // kwota ma cz�� u�amkow� (grosze)
			{
				grosze_jednosci_nascie_diesiatki_setki(tablica_cyfr); // grosze
				grosze_display = display;
				odmiana_groszy();
			}

			grosze_jednosci_nascie_diesiatki_setki(tablica_cyfr); // setki / dziesi�tki / jedno�ci 
			setki_display = display; 
			odmiana_zlotych();

			if (ilosc_cyfr > 3)
			{
				grosze_jednosci_nascie_diesiatki_setki(tablica_cyfr); // tysi�ce 
				tysiace_display = display;
				odmiana_tysiace();
			}
			if (ilosc_cyfr > 6)
			{
				grosze_jednosci_nascie_diesiatki_setki(tablica_cyfr);// miliony 
				miliony_display = display;
				odmiana_miliony();
			}
			if (ilosc_cyfr > 9)
			{
				grosze_jednosci_nascie_diesiatki_setki(tablica_cyfr);// miliardy  
				miliardy_display = display;
				odmiana_miliardy();
			}
	

	cout << "Kwota s�ownie to: " <<miliardy_display<<miliardy_odmiana<<miliony_display<<miliony_odmiana<< tysiace_display<< tysiace_odmiana<< setki_display <<zlotowki_odmiana<< grosze_display<<grosze_odmiana<< endl;

	delete[] tablica_cyfr;
	return 0;
	
}

double atof_plus(char kwota[])
{
	int ilosc_znakow = strlen(kwota); //d�ugo�� �a�cucha ( kwota)

	for (int a = 0; a < ilosc_znakow; a++) // p�tla wyszukuj�ca znak inny ni� cyfra (ASCII)
	{
		int znak = kwota[a];

		if (znak < 48 || znak > 57)
		{
			kwota[a] = '.'; // podmiana znaku dziesi�tnego na kropk�
		}
	}

	double kwota_po_zamianie = atof(kwota); //warto�� wynikowa
	return kwota_po_zamianie;
}


void grosze_jednosci_nascie_diesiatki_setki(int * tablica_cyfr)
{
	display = ""; //zerowanie zmiennej - string display.
		//cout << "Ilo�� cyfr w  funkcji =" << licznik_cyfr_w_funkcji << "\n";

		if (wskaznik_ulamka != 0) // kwota ma cz�� u�amkow� (grosze)
		{
			++wskaznik_wejscia_w_grosze;
						wskaznik_ulamka = 0;// zamkni�cie ponownego wej�cia w grosze
						cyfra_zero_grupy = tablica_cyfr[a];
							if (ilosc_cyfr == 1)
								cyfra_pierwsza_grupy = 0;
							else
								cyfra_pierwsza_grupy = tablica_cyfr[b];
							a += 2;
							b += 2;
							c += 2;

						/*cout << "grosze *** cyfra zero = " << cyfra_zero_grupy << "\n";
						cout << "grosze *** cyfra jeden = " << cyfra_pierwsza_grupy << "\n";*/

						if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy > 1 || cyfra_zero_grupy == 0 && cyfra_pierwsza_grupy > 0)   // dziesiatki <---------------------
							{
								dziesiatki_liczba = dziesiatki[cyfra_pierwsza_grupy - 1];
								display = display + dziesiatki_liczba + " ";
							}

						if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1) // nascie <---------------------
							{
								nascie_liczba = nascie[cyfra_zero_grupy - 1];
								display = display + nascie_liczba + " ";
							}


						if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy >1 || cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy ==0) // jedno�ci <---------------------

							{
								jednosci_liczba = jednosci[cyfra_zero_grupy - 1];
								display = display + jednosci_liczba + " ";
							}
				
						ilosc_cyfr -= 2;
						licznik_cyfr_w_funkcji -= 2;
						//cout << "Koniec groszy *** ilo�� cyfr = "<<ilosc_cyfr<<" licznik_cyfr_w_funkcji = "<< licznik_cyfr_w_funkcji << "\n";
						
		}

		else
		{
			if (licznik_cyfr_w_funkcji >= 3 && licznik_wejsc_w_grosze < 1)
			{
				//cout << "wej�cie - ilo�� cyfr >3" << "\n";
				//cout << "a =" << a << " b= " << b << " c= " << c << "\n";
				cyfra_zero_grupy = tablica_cyfr[a];
				cyfra_pierwsza_grupy = tablica_cyfr[b];
				cyfra_druga_grupy = tablica_cyfr[c];
				a = a + 3;
				b = b + 3;
				c = c + 3;
				/*cout << "setki ### cyfra zero = " << cyfra_zero_grupy << "\n";
				cout << "setki ### cyfra jeden = " << cyfra_pierwsza_grupy << "\n";
				cout << "setki ### cyfra dwa = " << cyfra_druga_grupy << "\n";*/

				if (cyfra_druga_grupy > 0) //setki <--------------------
				{
					setki_liczba = setki[cyfra_druga_grupy - 1];
					display = setki_liczba + " ";
				}

				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy > 1)   // dziesiatki <---------------------
				{
					dziesiatki_liczba = dziesiatki[cyfra_pierwsza_grupy - 1];
					display = display + dziesiatki_liczba + " ";
				}

				if (cyfra_zero_grupy == 0 && cyfra_pierwsza_grupy > 0)   // dziesiatki <---------------------
				{
					dziesiatki_liczba = dziesiatki[cyfra_pierwsza_grupy - 1];
					display = display + dziesiatki_liczba + " ";
				}

				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1) // nascie <---------------------
				{
					nascie_liczba = nascie[cyfra_zero_grupy - 1];
					display = display + nascie_liczba + " ";
				}


				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy != 1) // jedno�ci <---------------------

				{
					jednosci_liczba = jednosci[cyfra_zero_grupy - 1];
					display = display + jednosci_liczba + " ";
				}
				
			}

			if (licznik_cyfr_w_funkcji == 2 && licznik_wejsc_w_grosze < 1)
			{
				
				//cout << "wej�cie - ilo�� cyfr ==2" << "\n";
				cyfra_zero_grupy = tablica_cyfr[a];
				cyfra_pierwsza_grupy = tablica_cyfr[b];
				cyfra_druga_grupy = 0;

				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy > 1)   // dziesiatki <---------------------
				{
					dziesiatki_liczba = dziesiatki[cyfra_pierwsza_grupy - 1];
					display = display + dziesiatki_liczba + " ";
				}

				if (cyfra_zero_grupy == 0 && cyfra_pierwsza_grupy > 0)   // dziesiatki <---------------------
				{
					dziesiatki_liczba = dziesiatki[cyfra_pierwsza_grupy - 1];
					display = display + dziesiatki_liczba + " ";
				}

				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1) // nascie <---------------------
				{
					nascie_liczba = nascie[cyfra_zero_grupy - 1];
					display = display + nascie_liczba + " ";
				}


				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy != 1) // jedno�ci <---------------------

				{
					
					jednosci_liczba = jednosci[cyfra_zero_grupy - 1];
					display = display + jednosci_liczba + " ";
				}
			}

			if (licznik_cyfr_w_funkcji == 1 && licznik_wejsc_w_grosze < 1)
			{
				
				//cout << "wej�cie - ilo�� cyfr == 1" << "\n";
				//cout << "a =" << a << " b= " << b << " c= " << c << "\n";
				
				cyfra_zero_grupy = tablica_cyfr[a];
				cyfra_pierwsza_grupy = 0;
				cyfra_druga_grupy = 0;
				/*cout << "tysi�ce ### cyfra zero = " << cyfra_zero_grupy << "\n";
				cout << "tysi�ce ### cyfra jeden = " << cyfra_pierwsza_grupy << "\n";
				cout << "tysi�ce ### cyfra dwa = " << cyfra_druga_grupy << "\n";*/

				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy != 1) // jedno�ci <---------------------

				{
					jednosci_liczba = jednosci[cyfra_zero_grupy - 1];
					display = display + jednosci_liczba + " ";
					cout << "dispaly =" << display<<"\n";
				}
				
			}
			licznik_cyfr_w_funkcji = licznik_cyfr_w_funkcji - 3;
		}
}

void odmiana_groszy(void)
{
	if (cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy == 0)
		grosze_odmiana = grosze[0]; //grosz
	if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy == 0 || cyfra_zero_grupy > 1 && cyfra_pierwsza_grupy > 1)
		grosze_odmiana = grosze[1]; //grosze
	if (cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy == 0 && cyfra_pierwsza_grupy > 0)
		grosze_odmiana = grosze[2]; //groszy
	cyfra_zero_grupy = 0;
	cyfra_pierwsza_grupy = 0;
}
void odmiana_zlotych(void)
{
	if (cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy == 0)
		{
			if (wskaznik_wejscia_w_grosze > 0)
			zlotowki_odmiana = zlote[0] + ", "; //z�oty
			else
			zlotowki_odmiana = zlote[0] + " ";
		}
		
			if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy > 1)
			{
				//cout << "wwwg= " << wskaznik_wejscia_w_grosze<<"\n";
				if (wskaznik_wejscia_w_grosze > 0)
					zlotowki_odmiana = zlote[1] + ", "; 
				else                                      // z�ote
					zlotowki_odmiana = zlote[1] + " ";
			}
			if (cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy == 0 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1)
			{
				if (wskaznik_wejscia_w_grosze > 0)
					zlotowki_odmiana = zlote[2] + ", "; //z�otych
				else
					zlotowki_odmiana = zlote[2] + " ";
			}
}
void odmiana_tysiace()
{
	if (cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy == 0 )
		tysiace_odmiana = tysiace[0] + ", "; //tysi�c
	if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy >= 0)
		tysiace_odmiana = tysiace[1] + ", "; // tysi�ce
	if (cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy >0 && cyfra_pierwsza_grupy == 1)
		tysiace_odmiana = tysiace[2] + ", "; //tysi�cy

}
void odmiana_miliony()
{
	if (cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy == 0)
		miliony_odmiana = miliony[0] + ", "; //milion
	if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy >= 0)
		miliony_odmiana = miliony[1] + ", "; // miliony
	if(cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1)
		miliony_odmiana = miliony[2] + ", "; //milion�w

}
void odmiana_miliardy()
{
	if (cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy == 0)
		miliardy_odmiana = miliardy[0] + ", "; //miliard
	if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy >= 0)
		miliardy_odmiana = miliardy[1] + ", "; // miliardy
	if (cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1)
		miliardy_odmiana = miliardy[2] + ", "; //miliard�w
}
