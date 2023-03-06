#include <iostream>
#include <string>
#include <cstdlib>
#include <locale>

// WYBRANY TEMAT: WYPOZYCZALNIA SAMOCHODOW, STRUKTURA KLIENTOW I SAMOCHODOW UDOSTEPNIANYCH PRZEZ WYPOZYCZALNIE


/*tresc zadania
program zwiazany z zarzadzniem przedszkola
dziennik ucznia
zarzadznie uczelnia/bankiem
ogolnie zarzadzanie

jak?

1.cos co rewizuje mechanizm przeladowania funkcji
2. new, delete, np Osoba**; podwojny wskaznik, sterta, , tablica obiektow (Osoba*;
3.usuniecie z pamieci wszystkich samolotow, much

co minimalnie?
1)menu tekstowe uzytkownika, petla switch case,itp
-stworz tablice much, potrzebuje rozmiar<-wylosowac rozmiar tablicy
2)stworz tablice samolotow<-tak samo wylosowac srandem, rand numery
wszystkie atrybuty struktur maja byc randomowe
3. ini (Mucha** );
4. ini(Samolot*);
5. dodaj(Mucha**);
6. dodaj(Samolot*);
dynamicznie mozna zwiekszac zmniejszac ilosc z poziomu menu
WYSWIETL POKAZ TABELE!!!
7.Usun (Mucha**); trzeba usunac konkretna muche z tej tablicy, losujac numer indeksu
8.Usun (Samolot*); tak samo konktetna losujac nr indeksu
9.
przetwarzanie danych, sortowanie, cokolwiek takiego zeby pokazac ze ogarniam, daj znizke jakiejs tam osobie wg kryteriow i tego typu rzeczy
10.Wyjscie z programu - wyczyszczenie pamieci ktora zostala uzyta podczas korzystania z programu
*/


struct Klient {
    int wiek = 0;
    std::string imie;
    std::string nazwisko;
};

struct Samochod {
    std::string marka;
    std::string model;
    int rocznik = 0;
    int moc = 0;
};


void dodajKlienta(Klient**& klienci, int& liczbaKlientow) {
    // losowanie wartości dla pól struktury Klient
    int wiek = rand() % 50 + 18;
    std::string imie = "Imie" + std::to_string(rand() % 100);
    std::string nazwisko = "Nazwisko" + std::to_string(rand() % 100);

    // tworzenie nowego klienta i dodawanie go do tablicy
    Klient* nowyKlient = new Klient{ wiek, imie, nazwisko };
    Klient** nowaTablica = new Klient * [liczbaKlientow + 1];
    for (int i = 0; i < liczbaKlientow; i++) {
        nowaTablica[i] = klienci[i];
    }
    nowaTablica[liczbaKlientow] = nowyKlient;
    liczbaKlientow++;

    // zwalnianie pamięci
    delete[] klienci;
    klienci = nowaTablica;
};
void dodajSamochod(Samochod**& samochody, int& liczbaSamochodow) {
    // Zwiększenie rozmiaru tablicy samochodów
    Samochod** temp = new Samochod * [liczbaSamochodow + 1];
    for (int i = 0; i < liczbaSamochodow; i++) {
        temp[i] = samochody[i];
    }

    // Dodanie nowego samochodu
    Samochod* nowySamochod = new Samochod;
    nowySamochod->marka = "BMW";
    nowySamochod->model = "X5";
    nowySamochod->rocznik = 2022;
    nowySamochod->moc = 300;
    temp[liczbaSamochodow] = nowySamochod;

    // Usunięcie starej tablicy samochodów i przypisanie nowej
    delete[] samochody;
    samochody = temp;
    liczbaSamochodow++;
};
void usunKlienta(Klient**& klienci, int& liczbaKlientow) {
    if (liczbaKlientow == 0) {
        std::cout << "Brak klientow do usuniecia!" << std::endl;
        return;
    }

    // Wylosowanie indeksu klienta do usunięcia
    int index = rand() % liczbaKlientow;

    // Usunięcie klienta z pamięci i przesunięcie pozostałych elementów tablicy
    delete klienci[index];
    for (int i = index; i < liczbaKlientow - 1; i++) {
        klienci[i] = klienci[i + 1];
    }

    // Zmniejszenie liczby klientów o 1
    liczbaKlientow--;
};
void usunSamochod(Samochod**& samochody, int& liczbaSamochodow) {
    if (liczbaSamochodow == 0) {
        std::cout << "Brak samochodow do usuniecia\n";
        return;
    }

    // wylosuj indeks samochodu do usuniecia
    int indeks = rand() % liczbaSamochodow;

    // zwolnij pamiec zajmowana przez samochod
    delete samochody[indeks];

    // przesun tablice w lewo, zastepujac usuniety samochod
    for (int i = indeks; i < liczbaSamochodow - 1; i++) {
        samochody[i] = samochody[i + 1];
    }

    // zmniejsz liczbe samochodow i zwolnij pamiec dla ostatniego elementu
    liczbaSamochodow--;
    Samochod** temp = new Samochod * [liczbaSamochodow];
    for (int i = 0; i < liczbaSamochodow; i++) {
        temp[i] = samochody[i];
    }
    delete samochody;
    samochody = temp;

    std::cout << "Usunieto losowy samochod z tablicy\n";
};
void wyswietlKlientow(Klient** klienci, int liczbaKlientow) {
    std::cout << "Klienci:\n";
    for (int i = 0; i < liczbaKlientow; i++) {
        std::cout << "Klient #" << i + 1 << ": " << klienci[i]->imie << " " << klienci[i]->nazwisko << ", " << klienci[i]->wiek << " lat\n";
    }
}
void wyswietlSamochody(Samochod** samochody, int liczbaSamochodow) {
    std::cout << "Lista samochodow:\n";
    for (int i = 0; i < liczbaSamochodow; i++) {
        std::cout << "Samochod " << i + 1 << ":\n";
        std::cout << "Marka: " << samochody[i]->marka << "\n";
        std::cout << "Model: " << samochody[i]->model << "\n";
        std::cout << "Rocznik: " << samochody[i]->rocznik << "\n";
        std::cout << "Moc: " << samochody[i]->moc << "\n";
        std::cout << "\n";
    }
}
void zwolnijPamiec(Klient**& klienci, Samochod**& samochody, int& liczbaKlientow, int& liczbaSamochodow) {
    for (int i = 0; i < liczbaKlientow; i++) {
        delete klienci[i];
    }
    delete[] klienci;
    liczbaKlientow = 0;

    for (int i = 0; i < liczbaSamochodow; i++) {
        delete samochody[i];
    }
    delete[] samochody;
    liczbaSamochodow = 0;
};

int main()
{

    srand(time(nullptr)); // inicjalizacja generatora liczb losowych

    int liczbaKlientow = rand() % 10 + 1; // losowa liczba klientów z przedziału [1, 10]
    Klient** klienci = new Klient * [liczbaKlientow];

    for (int i = 0; i < liczbaKlientow; i++) {
        klienci[i] = new Klient;
        dodajKlienta(klienci, liczbaKlientow); // wypełnienie struktury Klient losowymi danymi
    }

    int liczbaSamochodow = rand() % 10 + 1; // losowa liczba samochodów z przedziału [1, 10]
    Samochod** samochody = new Samochod * [liczbaSamochodow];

    for (int i = 0; i < liczbaSamochodow; i++) {
        samochody[i] = new Samochod;
        dodajSamochod(samochody, liczbaSamochodow); // wypełnienie struktury Samochod losowymi danymi
    }



    //  Klient** klienci = nullptr; // deklaracja i inicjalizacja wskaźnika na tablicę klientów
    // int liczbaKlientow = 0; // deklaracja i inicjalizacja liczby klientów
    // dodajKlienta(klienci, liczbaKlientow);

    char wybor = ' ';
    while (wybor != 'q') {
        std::cout << "Menu główne:" << std::endl;
        std::cout << "1. Dodaj klienta" << std::endl;
        std::cout << "2. Dodaj samochód" << std::endl;
        std::cout << "3. Usuń klienta" << std::endl;
        std::cout << "4. Usuń samochód" << std::endl;
        std::cout << "5. Wyświetl tablicę" << std::endl;
        std::cout << "6. Wyczyść pamięć" << std::endl;
        std::cout << "q. Wyjście" << std::endl;

        std::cin >> wybor;

        switch (wybor) {
        case '1':
            dodajKlienta(klienci, liczbaKlientow);
            break;
        case '2':
            dodajSamochod(samochody, liczbaSamochodow);
            break;
        case '3':
            usunKlienta(klienci, liczbaKlientow);
            break;
            /* case '4':
                 usunSamochod();
                 break;
             case '5':
                 wyswietlTablice();
                 break;
             case '6':
                 wyczyscPamiec();
                 break;
             case 'q':
                 break;*/
        default:
            std::cout << "Nieznana opcja" << std::endl;
            break;
        }
    }
     return 0;
};