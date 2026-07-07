#include <iostream>
#include <vector>
#include <string>

using namespace std;
// 1. Klasa reprezentująca Grafik Wydawnictwa (OOP + Enkapsulacja)
class Harmonogram {
private:
    int siatka_godzin[3][5];
public:
    Harmonogram() {
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 5; ++y) {
                siatka_godzin[x][y] = 8; 
            }
        }
    }

    // Metoda analizująca macierz po współrzędnych X i Y
    void szukajNadgodzin() const {
        cout << "Szukanie nadgodzin (Wspolrzedne X = Pracownik, Y = Dzien):" << endl;
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 5; ++y) {
                if (siatka_godzin[x][y] > 8) {
                    cout << "-> Pracownik X=[" << x << "] w dniu Y=[" << y << "] ma nadgodziny: " << siatka_godzin[x][y] << "h" << endl;
                }
            }
        }
    }

    // 2. Metoda dodawania godzin konkretnemu pracownikowi
    void dodajGodziny(int id_pracownika, int dzien, int godziny) {
        if (id_pracownika >= 0 && id_pracownika < 3 && dzien >= 0 && dzien < 5) {
            siatka_godzin[id_pracownika][dzien] += godziny;
        }
    }

    // 3. operator == Porównywanie dwóch grafików
    bool operator==(const Harmonogram& inny) const {
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 5; ++y) {
                if (this->siatka_godzin[x][y] != inny.siatka_godzin[x][y]) {
                    return false; // Jeśli choć jeden dzień się różni
                }
            }
        }
        return true;
    }
};

int main() {
    // 4. Wykorzystanie kontenera dynamicznego 
    vector<Harmonogram> archiwum_grafikow;
    Harmonogram grafik_lipiec;
    Harmonogram grafik_sierpien;
    // Symulacja zmian w grafiku lipcowym przy użyciu metod i logiki biznesowej
    grafik_lipiec.dodajGodziny(0, 2, 4); // Pracownik 0 w środę (dzień 2) dostaje +4h nadgodzin
    grafik_lipiec.dodajGodziny(2, 4, 2); // Pracownik 2 w piątek (dzień 4) dostaje +2h nadgodzin
    archiwum_grafikow.push_back(grafik_lipiec);
    archiwum_grafikow.push_back(grafik_sierpien);

    cout << "=== ANALIZA GRAFIKU Z WYKORZYSTANIEM MACIERZY ===" << endl;
    archiwum_grafikow[0].szukajNadgodzin(); 
    cout << endl;

    cout << "=== TEST PRZELADOWANIA OPERATOROW ===" << endl;
    if (grafik_lipiec == grafik_sierpien) {
        cout << "Grafiki sa identyczne." << endl;
    } else {
        cout << "Grafiki sie roznia (Operator == dziala poprawnie)." << endl;
    }

    return 0;
}
