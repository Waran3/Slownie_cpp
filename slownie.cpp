// S³ownie ver 1.0 C++ by Waran3
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string zero[1] = { "zero" };
string jednosci[9] = { "jeden", "dwa", "trzy","cztery", "piêæ", "szeœæ", "siedem","osiem", "dziewiêæ" };
string nascie[9] = { "jedenaœcie","dwanaœcie","trzynaœcie","czternaœcie","piêtnaœcie","szesnaœcie","siedemnaœcie","osiemnaœcie", "dziewiêtnaœcie" };
string dziesiatki[9] = { "dziesiêæ", "dwadzieœcia", "trzydzieœci", "czterdzieœci", "piêædziesi¹t", "szeœædziesi¹t","siedemdziesi¹t","osiemdziesi¹t", "dziewiêædziesi¹t" };
string setki[9] = { "sto","dzwieœcie","trzysta","czterysta","piêæset","szeœæset","siedemset","osiemset","dziewiêæset" };
string tysiace[3] = { "tysi¹c", "tysi¹ce","tysiêcy" };
string miliony[3] = { "milion","miliony","milionów" };
string miliardy[3] = { "miliard","miliardy","miliardów" };
string zlote[3] = { "z³oty","z³ote","z³otych" };
string grosze[3] = { "grosz","grosze","groszy" };

int ilosc_cyfr;
//int ilosc_cyfr = 15;
//int* tablica_cyfr = new int[ilosc_cyfr]; // deklaracja tablicy o wielkoœci zale¿nej od iloœci obliczonych cyfr;
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
	setlocale(LC_ALL, "polish"); // w³aczenie polskich znaków
	cout << "WprowadŸ kwotê =";
	setlocale(LC_ALL, "en-US"); // w³aczenie znaków USA ( w³aczenie kropki  dziesiêtnej) 
	cin >> kwota_char;
	double kwota = atof_plus(kwota_char);
	setlocale(LC_ALL, "polish"); // w³aczenie polskich znaków
	//cout << "Wprowadzona kwota ="<<fixed<<kwota <<"\n";

	int licznik_cyfr = 0;

	wskaznik_ulamka = kwota - (__int64)kwota != 0;
	if (wskaznik_ulamka != 0)	// czyli kwota jest z czesci¹ u³amkow¹
		kwota_wszystkie_cyfry = kwota *1000 /10 ; // zamiana kwoty z u³amkiem na liczbe ca³kowit¹ ( pierwsze dwie cyfry to grosze)
												// wystarczy pomno¿yc przez 100 ale wychodz¹ czasem dziwne zaokraglenia st¹d taka kombinacja
		else
			kwota_wszystkie_cyfry = kwota; // kwota jest bez czêœci u³amkowej ( bez groszy)
	
	//int ilosc_cyfr;
	kwota_w_c = kwota_wszystkie_cyfry;
	for ( ilosc_cyfr = 0; kwota_w_c > 0; ilosc_cyfr++) // obliczanie iloœci cyfr
		kwota_w_c = kwota_w_c / 10;

	int* tablica_cyfr = new int[ilosc_cyfr];
	

	int ilosc_c = ilosc_cyfr;
	licznik_cyfr_w_funkcji = ilosc_cyfr;
	//cout << "Iloœæ cyfr = "<< ilosc_cyfr<<"\n";
	

	for (ilosc_c; ilosc_c > 0; ilosc_c--) // pêtla generuj¹ca  poszczególne cyfry
	{
		
		cyfra = kwota_wszystkie_cyfry % 10; //wydzielanie poszczególnych  cyfr ( modulo)
		kwota_wszystkie_cyfry /= 10; //przesuwanie przecinka 

		tablica_cyfr[licznik_cyfr] = cyfra;
		//cout << "Poszczególne cyfry to ="<<"["<<licznik_cyfr<<"]" << cyfra << endl;

		licznik_cyfr++;
	}
	
			if (wskaznik_ulamka != 0) // kwota ma czêœæ u³amkow¹ (grosze)
			{
				grosze_jednosci_nascie_diesiatki_setki(tablica_cyfr); // grosze
				grosze_display = display;
				odmiana_groszy();
			}

			grosze_jednosci_nascie_diesiatki_setki(tablica_cyfr); // setki / dziesi¹tki / jednoœci 
			setki_display = display; 
			odmiana_zlotych();

			if (ilosc_cyfr > 3)
			{
				grosze_jednosci_nascie_diesiatki_setki(tablica_cyfr); // tysi¹ce 
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
	

	cout << "Kwota s³ownie to: " <<miliardy_display<<miliardy_odmiana<<miliony_display<<miliony_odmiana<< tysiace_display<< tysiace_odmiana<< setki_display <<zlotowki_odmiana<< grosze_display<<grosze_odmiana<< endl;

	delete[] tablica_cyfr;
	return 0;
	
}

double atof_plus(char kwota[])
{
	int ilosc_znakow = strlen(kwota); //d³ugoœæ ³añcucha ( kwota)

	for (int a = 0; a < ilosc_znakow; a++) // pêtla wyszukuj¹ca znak inny ni¿ cyfra (ASCII)
	{
		int znak = kwota[a];

		if (znak < 48 || znak > 57)
		{
			kwota[a] = '.'; // podmiana znaku dziesiêtnego na kropkê
		}
	}

	double kwota_po_zamianie = atof(kwota); //wartoœæ wynikowa
	return kwota_po_zamianie;
}


void grosze_jednosci_nascie_diesiatki_setki(int * tablica_cyfr)
{
	display = ""; //zerowanie zmiennej - string display.
		//cout << "Iloœæ cyfr w  funkcji =" << licznik_cyfr_w_funkcji << "\n";

		if (wskaznik_ulamka != 0) // kwota ma czêœæ u³amkow¹ (grosze)
		{
			++wskaznik_wejscia_w_grosze;
						wskaznik_ulamka = 0;// zamkniêcie ponownego wejœcia w grosze
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


						if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy >1 || cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy ==0) // jednoœci <---------------------

							{
								jednosci_liczba = jednosci[cyfra_zero_grupy - 1];
								display = display + jednosci_liczba + " ";
							}
				
						ilosc_cyfr -= 2;
						licznik_cyfr_w_funkcji -= 2;
						//cout << "Koniec groszy *** iloœæ cyfr = "<<ilosc_cyfr<<" licznik_cyfr_w_funkcji = "<< licznik_cyfr_w_funkcji << "\n";
						
		}

		else
		{
			if (licznik_cyfr_w_funkcji >= 3 && licznik_wejsc_w_grosze < 1)
			{
				//cout << "wejœcie - iloœæ cyfr >3" << "\n";
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


				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy != 1) // jednoœci <---------------------

				{
					jednosci_liczba = jednosci[cyfra_zero_grupy - 1];
					display = display + jednosci_liczba + " ";
				}
				
			}

			if (licznik_cyfr_w_funkcji == 2 && licznik_wejsc_w_grosze < 1)
			{
				
				//cout << "wejœcie - iloœæ cyfr ==2" << "\n";
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


				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy != 1) // jednoœci <---------------------

				{
					
					jednosci_liczba = jednosci[cyfra_zero_grupy - 1];
					display = display + jednosci_liczba + " ";
				}
			}

			if (licznik_cyfr_w_funkcji == 1 && licznik_wejsc_w_grosze < 1)
			{
				
				//cout << "wejœcie - iloœæ cyfr == 1" << "\n";
				//cout << "a =" << a << " b= " << b << " c= " << c << "\n";
				
				cyfra_zero_grupy = tablica_cyfr[a];
				cyfra_pierwsza_grupy = 0;
				cyfra_druga_grupy = 0;
				/*cout << "tysi¹ce ### cyfra zero = " << cyfra_zero_grupy << "\n";
				cout << "tysi¹ce ### cyfra jeden = " << cyfra_pierwsza_grupy << "\n";
				cout << "tysi¹ce ### cyfra dwa = " << cyfra_druga_grupy << "\n";*/

				if (cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy != 1) // jednoœci <---------------------

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
			zlotowki_odmiana = zlote[0] + ", "; //z³oty
			else
			zlotowki_odmiana = zlote[0] + " ";
		}
		
			if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy > 1)
			{
				//cout << "wwwg= " << wskaznik_wejscia_w_grosze<<"\n";
				if (wskaznik_wejscia_w_grosze > 0)
					zlotowki_odmiana = zlote[1] + ", "; 
				else                                      // z³ote
					zlotowki_odmiana = zlote[1] + " ";
			}
			if (cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy == 0 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1)
			{
				if (wskaznik_wejscia_w_grosze > 0)
					zlotowki_odmiana = zlote[2] + ", "; //z³otych
				else
					zlotowki_odmiana = zlote[2] + " ";
			}
}
void odmiana_tysiace()
{
	if (cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy == 0 )
		tysiace_odmiana = tysiace[0] + ", "; //tysi¹c
	if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy >= 0)
		tysiace_odmiana = tysiace[1] + ", "; // tysi¹ce
	if (cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy >0 && cyfra_pierwsza_grupy == 1)
		tysiace_odmiana = tysiace[2] + ", "; //tysiêcy

}
void odmiana_miliony()
{
	if (cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy == 0)
		miliony_odmiana = miliony[0] + ", "; //milion
	if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy >= 0)
		miliony_odmiana = miliony[1] + ", "; // miliony
	if(cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1)
		miliony_odmiana = miliony[2] + ", "; //milionów

}
void odmiana_miliardy()
{
	if (cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy == 0)
		miliardy_odmiana = miliardy[0] + ", "; //miliard
	if (cyfra_zero_grupy > 1 && cyfra_zero_grupy < 5 && cyfra_pierwsza_grupy >= 0)
		miliardy_odmiana = miliardy[1] + ", "; // miliardy
	if (cyfra_zero_grupy >= 5 || cyfra_zero_grupy == 1 && cyfra_pierwsza_grupy > 0 || cyfra_zero_grupy > 0 && cyfra_pierwsza_grupy == 1)
		miliardy_odmiana = miliardy[2] + ", "; //miliardów
}
