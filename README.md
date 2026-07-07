### Opis projektu
Zaawansowany projekt akademicki implementujący konsolowy system zarządzania zasobami ludzkimi, czasem pracy oraz analizy wydajności w strukturze przedsiębiorstwa (grafik roboczy wydawnictwa). Projekt w pełni wykorzystuje paradygmat programowania obiektowego (OOP), zaawansowane struktury dwuwymiarowe (macierze) do mapowania procesów biznesowych, kontenerowanie dynamiczne oraz własne przeciążanie operatorów językowych w celu optymalizacji kodu.

Głównym celem aplikacji jest symulacja działania modułu analitycznego, który przetwarza i weryfikuje dane strukturalne w pamięci operacyjnej komputera (RAM), odzwierciedlając logikę biznesową powiązaną z relacyjnymi bazami danych.

---

### Zakres zrealizowanych zadań:

#### 1. Architektura obiektowa i Hermetyzacja (OOP & Encapsulation)
* **Projektowanie klas bazowych:** Implementacja kompleksowej klasy `Harmonogram`, stanowiącej logiczny model całego komponentu zarządzania czasem pracy.
* **Ochrona i integralność danych (Hermetyzacja):** Ukrycie kluczowych struktur danych (macierz godzin) w sekcji prywatnej (`private`). Uniemożliwia to niekontrolowaną, zewnętrzną modyfikację stanów obiektu, wymuszając komunikację wyłącznie przez bezpieczny interfejs publiczny (`public API`).
* **Zarządzanie stanem początkowym:** Implementacja konstruktora domyślnego, który automatycznie inicjalizuje struktury danych w pamięci bazowymi wartościami normatywnymi (8-godzinny dzień pracy) dla całego zespołu.

#### 2. Logika macierzowa i przetwarzanie współrzędnych (Tablice 2D)
* **Modelowanie strukturalne:** Wykorzystanie dwuwymiarowej tablicy (macierzy) o stałym rozmiarze `[3][5]`, gdzie osie reprezentują dwuosiowy układ danych: współrzędna X (identyfikator pracownika) oraz współrzędna Y (dni tygodnia roboczego).
* **Algorytmy wyszukiwania i analizy:** Zastosowanie optymalnych, zagnieżdżonych pętli iteracyjnych do przeszukiwania siatki współrzędnych. Algorytm dynamicznie sprawdza warunki graniczne (wartości > 8h) w celu natychmiastowej lokalizacji nadgodzin w konkretnych punktach danych.

#### 3. Bezpieczna manipulacja danymi i logika biznesowa
* **Metoda `dodajGodziny`:** Implementacja funkcji operacyjnej pozwalającej na dynamiczne wprowadzanie modyfikacji w grafiku.
* **Walidacja i odporność kodu:** Wprowadzenie mechanizmu weryfikacji zakresu indeksów (zarówno dla identyfikatora pracownika, jak i indeksu dnia). Zapobiega to krytycznym błędom naruszenia pamięci (out-of-bounds) i gwarantuje stabilność działania aplikacji konsolowej.

#### 4. Przeciążanie operatorów (Operator Overloading)
* **Abstrakcja językowa:** Implementacja własnej logiki dla operatora porównania (`operator==`), co pozwala na traktowanie obiektów klasy `Harmonogram` jak wbudowanych typów danych.
* **Głębokie porównywanie struktur (Deep Comparison):** Operator wykonuje pełną analizę komórka po komórce między dwoma niezależnymi obiektami w pamięci, sprawdzając tożsamość całych harmonogramów i zwracając precyzyjny wynik logiczny (`true`/`false`).

#### 5. Konteneryzacja i dynamiczne struktury danych
* **Zastosowanie `std::vector`:** Wykorzystanie standardowego kontenera dynamicznego do zbudowania elastycznej struktury archiwum (`vector<Harmonogram>`).
* **Zarządzanie kolekcjami obiektów:** Dynamiczne alokowanie i przechowywanie całych instancji klasowych w pamięci RAM, co umożliwia płynne symulowanie wielomiesięcznej historii operacji przedsiębiorstwa bez konieczności stałego definiowania rozmiaru struktur na etapie kompilacji.

---

### 💻 Technologiczny Stack:
* **Środowisko programistyczne (IDE):** CLion
* **Język programowania:** C++ (Standard C++20)
* **Zarządzanie pamięcią:** Kontenery STL (Standard Template Library)
