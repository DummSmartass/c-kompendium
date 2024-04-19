// linijke komentuje się zapomocą zapisania znaków // na jej początku
/*
jeżeli chce
się zakomentować
wiele linijek
należy zaznaczyć podany tekst i kliknąć ctrl shift /
*/
// elementy zakomentowane nie kompilują się

// #include <nazwabiblioteki> - pozwala połączyć się z bibliotekami c++ jak i zplikami autorstwa urzytkownika
#include <iostream> // - zawiera podstawowe komendy
#include <string> // umożliwa tworzenia zmiennych typu string  używanie
#include <cmath> // zapewniadostęp do różnych metod matematycznych
#include <random> // - zapewnia dostęp do metod randomowych
#include <ctime> // - zapewnia dostęp do różnych metod związanych z czasem
#include <algorithm> // - zapewnia dostęp do różnych przydatnych alorytmów
#include <vector> // -zapewni dostęp do wektorów i ich funkcji
#include <cstring> // - jest wymagane do operacji na char*
#include <utility> // - zapewnia dostęp do funbkcji std::swap
#include <fstream> // - pozwala operować naplikach zewnętrznych
#include <cstdarg>// nażedzie niezbędne do tworzenia funkcji o zmiennej ilosci arumentów
#include <cassert> // pozwala używać funkcji assert
#include <functional> // pozwala używać std::functional<typ1<typ2> - jako typ
#include <cstdlib> // załącza funkcje do obsługi pamięći
#include <iomanip> // jest nażędziem roszerzającymzastosowanie manippulatorów
#include <strstream> // pozwala traktowąć strini jakplikidoodczytu
#include <memory> // pozwala używać shared
#include <map> // pozwala mapować
#include <typeinfo> // pozwal urzywaćtypeid
//#include "file" - pozwala załączyć plik

// instrukcje preprocesora - wykonywane przed kompilacją
#define varP2  // - definowanie zmiennych
#define varP1  7 // - definownaie z podaniem wartości
#define varP3  "bbb" // - w instrukcjachprocesorowych nie istnieją typy danych, kążdazmiennamoże trzymaćkażdy typ
#define varP4  \
"bbb" //tak też możnadefinować

#undef varP1 // - oddefiniowanie zmiennej

#if (defined(varP2)) // - if, działa jak if
#define varP0 3
int main2()
{
    std::cout<<"varP2"<<std::endl; // funkcja jest zdefinowana jezeli warunek jest spełniony
}
#define varP1 1  //- nie trzebaurzywaćznakówkońcalinjianinawiasów
#elif (defined(varP3)) && (defined(varP2)) // elif - działa tak, i spójniki && i || (PODWÓJNE) też działają
#define varP1 2;
#else // else - działa jak else
    #define varP1 3;
#endif // - zakończenie ifa, tu kończą się instrukcje związane z if , endif jestniezbędnydokompilacji

#ifdef varP1 // - skrót od if defined()
#define varP4 varP1+varP2
#endif

#ifndef varP2 // - zaprezeczenie ifdef
#ERROR przykladowy error
#endif

#define define float double// zastępuje wszystkie typy float w funkcji na typy double w zakresie istnienia

#include "Triangle.h" // załączenie pliku .h pozwala odwoływać sie do zmiennych i funkcji w nim zapisanych
#include "MyStack.h"
#include "Resistor.h"
#include "Testfield.h"
#include "Segment.h"
#include "Vechicle.h"
#include "Car.h"

#undef float // tutaj kończy się działanie zmiennej float


// funkcje /////////////////////////////////////////////////////////////////////////////////////
void fun1(int a, int b , std::string c) // -  void - typ zwracany -nic    fun1 - nazwa funkcji    (...) - elementy zwracane
{ // funkcjezawsze należy zawierać się wewnątrz klamerek
    std::cout<<c<<std::endl;// wewnątrz funkcji można odwóływać się do podanych zmiennych
    std::cout<<a+b<<std::endl;
}

int fun2(int a, int b , std::string c) // funkcjamoże zwracać watości różnych typów np int
{
    std::cout<<c<<std::endl;
    if(a>b)
        return a-b; // - retun - okreslamiejscew kodziezktórego ma byćzwacanawartosć
    else if(b<a)
        return b-a; //-może itnieć więcejniżjeden return
    std::cout<<c<<std::endl;
    return NULL;//wartościązwracanąmoże być pusta wartość
}

void funt( int *tab,size_t size) // w funkcji można czytać tablice, ale trzeba zapewnić długość  arraya jako odrębnązmienn,bobeztego nie zadziała, tablice podaje się przez wskaźnik, wskaźnikami wewnątrz funkcji posługujemy się tak samo jak wszędzie
{
    for (int i = 0; i < size; ++i)
    {
        std::cout<<tab[i]<<std::endl;
    }
}

void funref(double (&t)[6])// mozna podawać tablice  poprzez referencje, pozwala to zadeklarować ilośc jej elmentów(można ją przesyłać np, poprzezmanipulowaną zmienną globalną) do wielkości tablicy wewnątrz funkcji
{
    cout << "Wymiar t w funref: " << sizeof(t) << endl;
}

void funv( std::vector<int> vec) // w funkcji można czytać wektor, bo wektor wszędzie znaswoją długość
{
    for (int a:vec)
    {
        std::cout<<a<<std::endl;
    }
}

void fun3(std::string s)
{
    std::cout<<s<<std::endl;
}

int fun4(int a)//funkcje rekurencyjne
{
    fun3("dispaly"); // funkcaj może odwoływać się do innych funkcji
    std::cout<<a<<std::endl;
    if (a>=0)
        a=fun4(a-1);// w tym smaej siebie i to się nazywa rekurencją
    return a;
}

void fun5()
{
    static int a; // zmienna statyczna a zachowuje wartość pomiędzy wewnątrzklamerek nawet jeżeli program z nich będzie, czyli np. pkolejne wywołanie tej funkcji będzie pamiętać artość a z popzedniego wywołania;
    a++;
    std::cout<<a<<std::endl;
}

void fun6(int a=0,std::string s="aaa")//można funkcją przypisywać watości domyślne które uruchamiają się w przypadku braku argumentu
{
    std::cout<<a<<std::endl;
    std::cout<<s<<std::endl;
}

void fun7(int);//  możnazadeklarować funkcję przed jej napisaniem, co umożliwia odwoływaniesię do niej przed jej zapisaniem, deklarująć funkcje nie trzeba okreslaćnazw zmiennych do niej podawanych , tylko typy
void fun8()
{
    fun7(4);
    std::cout<<"ef"<<std::endl;
}

void fun7(int a)
{
    std::cout<<"cd"<<a<<std::endl;
}

template<typename T,typename K> // template zapewniadostęp do elementów dowolnego typu poprzezstwozenie sztucznych typów typename T i typname k, pod które możnapodstawić dowolne współpracującezzamysłemfunkcji typy
T fun9(K k,T t) // tworząc funkcje można można odwoływać się do typów ztemplata
{
    std::cout<<t<<std::endl;
    t=(T)k;
    return t;
}

template<typename T,typename P>
T fun10(P p,T t)
{
    int a=(p(t)); // lamdy mogą być dostarczane jako typy z template
    return a;
}

template <typename T>
T larger(T k1, T k2)
{
    cout << "T=" << typeid(T).name() << " ";
    return k1 < k2 ? k2 : k1;
}

double larger(double k1, double k2) // funkcje z template możnaprzeciążyć funkcją
{
    cout << "Spec. double ";
    return k1 < k2 ? k2 : k1;
}

// można jąteż przeciążyćalternatywnym templatem
template<>// pusty template przy pzeciążeniach bezelementów z nieo
short larger<short>(short k1, short k2)//funkcje z template larger można przeciążyć dla  konkretnego typu zmiennej
{
    cout << "Spec. short ";
    return k1 < k2 ? k2 : k1;
}

template<>
long larger<long>(long k1, long k2) = delete;// =delete oznacz, że ten proram ma się nie kompilować
template<typename T, typename U>
decltype(auto) mul(T x, U y) // tylko spostrzerzenie, typ zwracany typenamea możnaustawić na decltype(auto) i czego nie zwrócisz program zadziała
{
    return x*y;
}

double fun11(double& u, double* v)
{
    double x = u;
    u *= u;
    *v = sqrt(x);
    return u*x;
}

int* fun12(int* p)
{
    *p *= *p;
    return p;
}

int& fun13(int* tab, int ile)
{
    int i, ind = 0;
    for ( i = 1; i < ile; i++ )
        if ( tab[i] > tab[ind] ) ind = i;
    return tab[ind];
}

inline int fun14(int m) // modyfikator inline powoduje,że kompilator zastępuje każdee wystąpienie tej funkcji framentem kodu w niej zawartej,pomagato czasem z wydajnością, samo wywoąłnie takiej funkcji powoduje zmianny i zwracawatości analogiczne  do analoicznej funkcji bez modyfikatora
{
    return 2*m;
}

typedef double (*fun15)(double);// tak defińjuje się wskaźnik do funkcji przyjmujacej double i zwracającej double - teraz ten wskaźnik może być podawany jako argument do innych funkcji, w miejsce takiego agumentu będzie można wstawić każdą funkcje spełniającą wymaania
void fun16(fun15 f,double a)// wskanik do funkcji moze być używany jak typ zmiennej
{
    std::cout<<f(a)<<std::endl;
}

typedef double (*TABFUN[])(double);// od teraz TABFUN stanowi typ tablicy wskaźników do funkcji przyjmujących i zwracających wartości double
using TABNAP = const char* [];// TABNAP od teraz jest typem obiektów zawierających niemodyfikowalne tablice charów
void fun17(TABFUN f, TABNAP t, double x)// funkcja naturalnie może przyjmować elementy powyższego wskaźnika i typów
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "funkjca: " << t[i] <<" od "<<x<< " wynosi: "<< f[i](x) << endl;
    }
}

void fun18(std::function<double(double)> f, double a)// std::function<typ1(typ2)> - to typ zmiennej będąćą funkcją przyjmującą typ1 i zwracającą typ2
{
    std::cout<<f(a)<<std::endl;
}

int &razdwa(int& m) //do funkcji można rownież dostarczać argumenty referencyjne, pozwala to modyfikować daną wartość mimo, że funkcja nie jest w jeje zasięu
{
    m *= 2;
}

int konwert(char* nap) // w konwersjach,służydo konwertowania tablic charów na inty
{
    int w = 0, i = 0, c;
    while (c = nap[i++], c >= '0' && c <= '9')
        w = 10*w + c - '0';
    return w;
}

auto krotko(int a, double b) -> decltype(a * b)// funkcje nieznanego typuzwracanego deklauje się ustawiająć auto z przodu i -> decltype( element zwracany ) aby funkcja sama zorientpwałasię jaki typ musi zwracać
{
    return a*b;
}

// ta fukcja wymaa wiedzy ażdo etykiet, jeżeli się z nimi nie zapoznałeś/aś wruć tu później
void typy(const char typ[], ...)// jeżeli funkcja ma mieć prtzewidzianą zmienną ilość agumentów, po wszystkich standardowych argumentach(takich które pojawiąsię zawsze) należy napisać ...
{
    // zapowiada , że używasz elementów std, od teraz nie trzeba pisać np. tsd::cout..., a można pisać cout... i to działa dla wielu tego typu przedrostków
    using namespace std;

    int i = 0, integ;
    char c, *strin;
    double doubl;

    va_list ap;//argume_pointer typu va_list - varaible_list // wewnątrz tej listy są podane wszystkie zmienne

    va_start(ap,typ);// va_stat - wywoływany jest tylko raz z wywoływaną listą ap jako pierwszym argumentem i ostatnim parametem obowiązkowym, w tym przypadku typ

    while ( (c = typ[i++]) != '\0')//iterujemy po tablicy charów zawierającej informacje dotyczące podanych w ap zmiennych
    {
        switch (c)//rozpoznanie elementów tablicy charów, ppozwala się zorientować o typie kolejnych zmiennych zawartych w ap
        {
            case 'i':
                case 'I':
                    integ = va_arg(ap,int);// wydobycie argumentu z ap, oczekiwany typ int - każde wywołanie podaje kolejny argument z listyzmiennych i interpretuje ją jako zmienną typu podanego jako drugi argument
                    cout << "Liczba int : " << integ << endl;
                    break;
            case 'd':
                case 'D':
                    doubl = va_arg(ap,double);
                    cout << "Liczba double: " << doubl << endl;
                    break;
                    case 's':
            case 'S':
                strin = va_arg(ap,char*);
                cout << "Napis : " << strin << endl;
                break;
            default:
                cout << "Nielegalny kod typu!!!!!" << endl;
                goto KONIEC;
        }
    }
    KONIEC:
    cout << endl;
    va_end(ap);// kończy uzywanie listy argumentów, nie można tego pominąć
}

double** allocMatrix2D(size_t dim1, size_t dim2)// twozenie tablity doubli zapomocą wskąźników
{
    double** matrix2d = new double*[dim1];// wskaźnik do wskaźnika do doubla = dim1 elementowa tablica wskaników do doubli
    double* dumm = new double[dim1*dim2];// wskaźnik do doubla = dim1*dim2-tablica doubli

    for (size_t i = 0; i < dim1; ++i)
        matrix2d[i] = dumm + i*dim2; // przypisywanie do kolejnych elementów tablicy wskaźników do doubli tablice doubli
    return matrix2d;// zwracanie lokacji w pamięci do pierwszeo elementu, pierwszej tablicy doublowej
}

void deleteMatrix2D(double**& matrix2d)// podawnae jest miejsce w pamięci pierwszego elementu tabeli
{
    delete [] matrix2d[0];// usunięcie z pamięci lokalizacji wskaźnika do wszystkich doubli zawartych w tablicy
    delete [] matrix2d;// uzunięcie z pamięci miejesce zajmoane przez liste wskaźników do wskaźników
    matrix2d = 0;
}

inline char returnletter(char a) // inline, zapisanie inline poprawia wydajność progamu gdy zastosowane na
{
    return a;
}

void pr1 (const int *a) // podając argument jako const nie czyni zmiennej const globalnie, aleuniemożliwiajej edycje wewnątrzwspomnianejfunkcji
{
    std::cout<<a<<std::endl;
}
// koniec funkcji /////////////////////////////////////////////////////////////////////////////////////


// początek struktór
// stróktóry - nowe customowe typy danych mogące zawierać wiele zmiennych i funkcje do ich kolektywnej obróbki i odczytu
struct str1
{
    int v1;
    std::string v2;
    char v3[25]; // struktura może zawierać zmienne wielu typów wewnbątz
    void print()
    {
        std::cout<<v1<<" "<<v2<<std::endl;
    }
    int returnv1()
    {
        return v1;
    }
    int static biggerv1(str1 s1, str1 s2)
    {
        return s1.v1>s1.v1;
    }
} str1E,str_1,str_2,str_3; //- pod tymi nazwami tworzone są zmienne z domyślnymi wartościąkażdej zmiennej

template<typename T, typename K, typename L>
struct Tstruct// stróktóry moą używać template
{
    T v1;
    K v2;
    L V3;
};

struct Osoby // struktóry i klasy mogą być bazą do tablicobiektów (więcej w stróktórach nadole)
{
    char imie[4]; // czteoelementowa tablica charów
    int wiek;
};
// koniec struktór


// początek Przeciążeń operatorów
struct str2
{
    int a;
    int b;
};
str2 operator+(str2 s1, str2 s2)
{
    int a=s1.a+s2.a;
    int b=s1.b+s2.b;
    return str2{a,b};
}
int operator+(int s1, str2 s2)
{
    int a=s1+s2.a;
    int b=s1+s2.b;
    return a+b;
}
str2 operator+(str2 s1, int s2)
{
    int a=s1.a+s2;
    int b=s1.b+s2;
    return str2{a,b};
}
// operatory jednoelementowe
bool operator!(const str2& c)
{
    return c.a>c.b;
}



// koniec przeciążenia stróktór


//początek stosów
struct Node // stosty tworzy się za pomocą struktór zawierających zmienną wskaźnikwą do kolejnegoel ementu tego samego rodzaju
{
    int   data;
    Node* next;
};
bool add(Node*& head, int data)//dodawanie unikalnego elemntu do listy
{
    Node *act = head;// zmienna pomocnicza pozwala poruszać się po stosie bez naruszania odnośnika do pierwszego elementu
    while(act != NULL) // zmienna pomocnicza pzechodzi po elementach stosu asz nie napotka końca
    {
        if(act->data == data)// jeżeli zmienna się jużpjawiła zwracany jest false
            return false;
        act = act->next;// zmienna pomocnicza przechodzi do kolejneo elementustosu
    }
    Node *tmp = new Node {data,head};// zmienna pomocnicza zostajenadpisana podaną daną i wskaźnikiem do początku stosu
    head = tmp; // nadpisanie głowy zmiennąpomocniczą

}
size_t size(const Node* head) // znajdowanie długoścu tablicy
{
    size_t size = 0;
    auto act = head;
    while(act != NULL)
    {
        size++;
        act = act->next;
    }
    return size;
}

void clear(Node*& head) // czyszczenie stosu
{
    while(head != nullptr)
    {
        std::cout<<"DEL: "<<head->data<<" ";
        Node *tmp = head->next;
        delete head; // usówanie elementów stosu
        head = tmp;
    }
}

void printList(const Node* head) // wypisywanie elementów stosu
{
    Node tmp = *head;
    std::cout<<tmp.data<<" ";
    while(tmp.next != nullptr)
    {
        tmp = *tmp.next;
        std::cout<<tmp.data<<" ";
    }
    std::cout<<std::endl;
}
// koniec stosów/////////////////////////////////////////////////////////////////////////////////////

// początek unii
union Bag// unia to typ złożony mogący przechowywać wiele różnych zmiennych, ale tylko jednąna raz
{
     float liczbaF; //  Bag przechowuje wartość typu float pod nazwą LiczbaF
     long double liczbaLD; // Ba przechowuje wartość typu long double pod nazwą liczbaD
} bag ;

void wstaw(Bag *w, float f)// umieszcza w  zmiennej w elementu f w polu liczbaF
{
    w->liczbaF = f;
}

void wstaw(Bag *w, long double ld) //umieszcza w  zmiennej w elementu f w polu liczbaF
{
    w->liczbaLD = ld;
}

void infor(const Bag *w)// wypisanie obu elementów
{
    cout << "\nliczbaF : " << w->liczbaF << endl;
    cout << "liczbaLD: " << w->liczbaLD << endl;
}
// koniec unii

// początek klas
using namespace std;

class Zakres;

class Punkt
{
    int liczba;
    friend void isInside(const Punkt*, const Zakres*);

public:
    Punkt(int liczba = 0) : liczba(liczba){ }
};

class Zakres
{
    int lewy, prawy;
    friend void isInside(const Punkt*, const Zakres*);//friends przed funkcją zadeklarowaną wewnątzfunkcji tworzy funkcje nienależącądotej funkcji, ale posiadającą w dostęp do wszystkich komponętów funkcji jaby były publiczne

    public:
    Zakres(int lewy = 0, int prawy = 0): lewy(lewy), prawy(prawy){ }
};

void isInside(const Punkt *p, const Zakres *z)
{
    if ((p->liczba >= z->lewy) && (p->liczba <= z->prawy))
         cout << "Punkt " << p->liczba << " lezy w "
         "zakresie [" << z->lewy << ","
         << z->prawy << "]\n";
    else
        cout << "Punkt " << p->liczba << " lezy poza "
             "zakresem [" << z->lewy << ","
             << z->prawy << "]\n";
}

class A
{
public:
    void show() { cout << "A::show()" << endl; }
};

void termin()
{
    cout << "termin: exit(7)" << endl;

    //exit(7); wychodzi z błędem
    exit(7);
}

double Sqrt(double x)
{
    if (x < 0) throw "x < 0";
    return sqrt(x);
}

class Base
{
    virtual void member() {}
};

class Derived : Base {};

class Ka
{
public:
    virtual ~Ka();
};

//klasy abstrakcyjne
// próbowałem to robić w odzielnym pilu i nie dizała i nie wiem czemu
// fugura hest klasąbazową
class Figura
{
    protected:
    static const double PI;

    public:
    // to są funkcje virtualne które są oznaczone jako puste( = 0)
    virtual double getPole() const = 0;
    virtual double getObwod() const = 0;
    virtual void info(ostream&) const = 0;

    // w klasie abstrakcyjnej mogą być nievirtualne funkcje
    static double totalPole(Figura* tab[], int size)
    {
        double suma = 0;
        for (int i = 0; i < size; ++i)
            //można się tu odwołać do funckcji get pole bo istnieje ona(nawet jeżeli jest pusta) w klasie figóra, ale w momęcie wywołania funkcje faktycznie urzyte to funkcje klas pochodnych
            suma += tab[i]->getPole();
        return suma;
    }

    static Figura* maxObwod(Figura* tab[], int size)
    {
        int ind = 0;
        for (int i = 0; i < size; ++i)
            if (tab[i]->getObwod() >
                tab[ind]->getObwod())
        ind = i;
        return tab[ind];
    }
};

// 4*atan(1.)  tak można precyzyjnie wygenerować pi
const double Figura::PI = 4*atan(1.);
void Figura::info(ostream& str) const
{
    str << "Figura: ";
}

// tak się pisze dziedziczenie
class Kolo : public Figura
{
    double promien;
    public:
    Kolo(double r) : promien(r){ }

    //tu są funkcje virtualne z figury
    double getPole() const { return PI*promien*promien; }
    double getObwod() const { return 2*PI*promien; }

    //dodawanie elementu do ostreama
    void info(ostream& str) const
    {
        Figura::info(str);
        str << "kolo o promieniu " << promien;
    }
};

//wiele klas może dziedziczyć po klasie
class Kwadrat : public Figura
{
    double bok;

    public:
    Kwadrat(double s) : bok(s) { }
    double getPole() const { return bok*bok; }
    double getObwod() const { return 4*bok; }
    void info(ostream& str) const
    {
        Figura::info(str);
        str << "kwadrat o boku " << bok;
    }
};


// PS. KLASA MOZE DZIEDICZY PO KILKU KLASACH
//nie chce mi się dawać przykładów, ale można używać zmiennych i funkcji (a także można nadpisywać funkcje) wszystkich klas po których klasa dziedziczy

//jedyna różnica w zapisie to deklaracaja klasy
//tak się robi klase dziedziczącą z klasy1 i klasy2
//class klsa dziedziczonca : public klasa1, public klsa2

// koniec klas


//początek namespaców
// tak tworzy się namespacy, zawierają one zmienne funkcje i można się do nich szybko i estetycznie odwoływać
namespace nA
{
    const int two = 2;
    const int six = 6;
    void write() { cout << "ns-A" << endl; }
}

namespace nB
{
    void write() { cout << "ns-B" << endl; }
}

namespace nC
{
    const int two = 22;
    const int six = 66;
}
// koniec namespaców


// zmienne globalne, zmienne zadeklarowane poza jakąkolwiek funkcją dostępne wszędzie
int glob=4;
extern int supglob=6; // jeżeli zmienna istnieje w innym pliku zlinkowanym ztym plikiem można umieścić ją w obecnie używanym pliku poprzez zadeklarowanie jej jako extern, program będzie miał dostęp do jej wartości zapisanej w innnym pliku    funkcje extern definjuje się ZAWSZE poza jakąkolwiek funkcją

//int main() // - oznaczenie podstawowej funkcji która wykonuje się po uruchomieniu programu
int main(int argc, char *argv[]) // tak umieszcza się w funkcji mainargumenty wywołania   int argc - licza okreslająca iloścpodanych zmiennych    *argv[] - lista zawierające zmienne wybranego typu
{// - funkcje mainzawiera się pomiędzy klamerkami


    // zmienne wywołania
    {
        for (int i = 0; i < argc; ++i)
        {
            std::cout << "Argumentem nr " << i << " jest "<< argv[i] << std::endl;
        }
    }


    // operacje procesorowe
    {
        std::cout << __LINE__ << std::endl; // __LINE__- podaje ljnjie kou w której się znajduje
        std::cout << __FILE__ << std::endl; //__LINE__- podaje ljnjie kou w której się znajduje
        std::cout << __DATE__ << std::endl; //__LINE__- podaje ljnjie kou w której się znajduje
        std::cout << __TIME__ << std::endl; //__LINE__- podaje ljnjie kou w której się znajduje
        std::cout << __FUNCTION__ << std::endl; //__LINE__- podaje ljnjie kou w której się znajduje
        std::cout << varP1 <<std::endl;
    }


    // zmienne
    {
        std::cout<<"początek zmienne"<<std::endl;
        // - zmienne definowanie
        bool v1; // bool - watości loiczne   v1 - nazwa zmiennej bool
        std::byte v2; // std:: - pozwala    byte - wartości typu byte   v2 - nazwa zmiennej byte
        short v3; // short - watości typu short   v3 - nazwa zmiennej short
        int short v3_1; //może być też zapisane jako short int
        int v4; // int - watości typu int   v4 - nazwa zmiennej int
        long v5; // long - watości typu long   v5 - nazwa zmiennej long
        int long v5_1; //może być też zapisane jako long int
        char v6; // char - watości typu znakowego   v6 - nazwa zmiennej char
        char v6_1;// może byćteż zapisane jako char int - nie wiem czemu nie działa
        float v7; // float - watości typu float   v7 - nazwa zmiennej float
        double v8; // double - watości typu double   v8 - nazwa zmiennej double
        char *v9; // char* - watości typu tablicy charów niezmiennej długości   v9 - nazwa zmiennej char*
        std::string v10; // string - watości stringowe   v10 - nazwa zmiennej string
        long long v18; // long long - watości long long   v18 - nazwa zmiennej long long    może byćteż zapisane jako long long int
        long double v25; //  long double - watości long double   v18 - nazwa zmiennej long double
        int v26=26;// deklaracja z zainicjowaniem wartości DZIAłA DO NADPISYWANIA
        int v27(27);// deklaracja z zainicjowaniem wartości NIE DZIAłA DO NADPISYWANIA
        int v28{28};// deklaracja z zainicjowaniem wartości NIE DZIAłA DO NADPISYWANIA


        // -zmienne przypisowanie wartości, po lewej stronie zmiennaktórej pzypisujemy wartość, po prawej stronie dowolne wyazenie zwracającepożądanytyp;
        v1 = true;
        v1 = false;// zmiennąmożna nadpisać w ten sposób
        v2 = static_cast<std::byte>(5);// zmienne niekompatybilnych wartosćni należy zamieniać na wymagany typ, tak to się robio
        v3 =67;
        v4 =6785;
        v4=v4+v3+2;// można wewnątrz nadawaniawatości odwoływać się do jużistniejacych zmiennych
        v5 =6809998;
        v6 ='a';
        v6 =(char)(6);// wartość niektorych zmiennych mogą zostać efektem zmiany typu zmiennejpodanej,jak naprzykładzie
        v6 ='\101'; // odwołanie do 101 charu
        v7 =4.3;// wartości zmiennnowprzecinkowe wyrarza się z użyciem .
        v8 =7.8796;
        v9 ="kala";
        v10="hugugyg";
        v18=5467757;

        std::string v11 = "ioyuhi";//możnapołączyć deklaracje znaaniem wartości jakpokazane

        // zmienna auto
        auto v12 = "haha"; //dopasowuje swój typ w trakcie nadawanajej warośći

        decltype (1*0.5) v13=17.5; // - decltype (x) - decltype - przypisuje zmiennej konkretny   (x) - defniuje typ zmiennej najbardziej pasujący do zawartościnawiasów

        int v14;
        v14=NULL; // zmienne mogąmiećnadanybrakwartości ergo NULL

        int v15,v16=3,v17; // można w jednej lini deklarować wiele zmiennych jednoliteo typu odzielają je przecinkami

        // zmienne lokalne istnieją tylko między klamerkami w których zostałyzadeklarowane, większośćzmiennych jakie są przeznasużywane są lokalne
        {
            int valloc=1;
            std::cout<<valloc<<std::endl;
        }
        {
            {
                int valloc=2;
                std::cout<<valloc<<std::endl;
            }
            int valloc=3;
            std::cout<<valloc<<std::endl;
        }
        int valloc=4;
        std::cout<<valloc<<std::endl;

        // zmienne globalne, zmienne zadeklarowane poza jakąkolwiek funkcją dostępne wszędzie
        std::cout<<glob<<std::endl; // do zmiennych globalnych można odwołać się wszędzie
        int glob=3;// zmiennalobalna może być nadpisana lokalnie, nie wpływato na wartość zmiennej globalnej
        std::cout<<glob<<std::endl;
        std::cout<<::glob<<std::endl; // zmienna:: - pozwala się odwołąć do zmiennej lobalnej,nawet jakjest ona nadpisana lokalnie

        const int cons1=3; // zmienne const - constant są niemożliwe do późniejszej modyfikacji    fun fakt wskaźniki do zmiennych cons tnie mogą mieć formy  --> typ* nazwa <--, muszą mieć formę  -->  const typ* nazwa <--
        constexpr int conex1=5; // constexpr jest "śilniejszą" wersją const, poza niemożliwością jej zmiany, wartość tego typu zmiennej jest dostępnajużna etapie kompilacji.

        // zmienne statyczne istnieją są szerzej opisane w funkcjach

        //zmienne można tworzyć signed albo unsigned, unsigned są zawsze dodatnie, a signed mogą miećznak minus
        unsigned int v19=4;
        v19=-4; // - ten element nie będzie się wyświetlał jako -4
        std::cout<<v19<<std::endl;
        signed int v20=4;
        v20=-4;
        std::cout<<v19<<std::endl; // a ten już tak

        // typy charów zawsze unsigned
        wchar_t v21;// podstawowe znaki
        char16_t v22;// unicode 16
        char32_t v23;// unicde 32

        std::int16_t v24;// tak możnasię odwoływaćdo wariantów typów o różnym rozmiaże   inne opcje to    int8_t, int16_t, int32_t, int64_t
        // uint8_t, uint16_t, uint32_t, uint64_t  - urzywająć tych aliasów można tworzyć tego typu zmienne unsigned

        //tą metodą można również ustalać ograniczenia wielkości zmiennych preprocesorowych
        std::cout<<INT32_MIN<<std::endl;
        std::cout<<INT32_MAX<<std::endl;
        std::cout<<UINT32_MAX<<std::endl;

        /*  specjalne znaki,zapis charowy
        \n nowa linia (LF)
        \t tabulator poz. (HT)
        \v tabulator pion. (VT)
        \b cofnięcie (BS)
        \r powrót karetki (CR)
        \f nowa strona (FF)
        \a sygnał dźwiękowy (BEL)
        \\ ukośnik
        \? pytajnik
        \’ apostrof
        \" cudzysłów
        */

        typedef int t1; // tak deklaruje się nowe typy zmiennych
        typedef char t2[3]; // tworzenie nowych typu działa na tej samej zasadzie jak ich odczytywanie - ten typ to trzyelementowa tablica charów
        typedef t2 t3[3]; // to jest tablica trzy elementowa z elementami typu t2
        typedef int *t4[][2][2]; // to wskaźnik do tablicy trójwymiarowa zawierająca dowolną ilość elementów, z któych każdy zawiera tablice dwuwymiarową 2X2

        // warte zapamiętania
        // zmienne przypisuje się od wnętra na zewnątrz iod prawej do lewej np (x=y)=(z=k-2)=4 znaczy tyle samo co x=4
        volatile int k=9; // zmienna która może być zmieniona bez wiedzy programu , po co to istnieje.... nikt nie wie

        // istnieje wiele więcej typów danych, to reszta zn ich, nie wszystkie treba naten moment znać
        /*
        alignas
        const_cast
        module
        static_cast
        alignof
        continue
        mutable
        struct
        and
        decltype
        namespace
        switch
        and_eq
        default
        new
        synchronized
        asm
        delete
        noexcept
        template
        atomic_cancel
        do
        not
        this
        atomic_commit
        double not_eq
        thread_local
        atomic_noexcept
        dynamic_cast
        nullptr
        trrow
        auto
        else
        operator
        true
        bitand
        enum
        or
        try
        bitor
        explicit
        or_eq
        typedef
        bool
        export
        private
        typeid
        break
        extern
        protected
        typename
        case
        false
        public
        union
        catch
        float
        register
        unsigned
        char
        for
        reinterpret_cast
        using
        char16_t
        friend
        requires
        virtual
        char32_t
        goto
        return
        void
        class
        if
        short
        volatile
        compl
        import
        signed
        wchar_t
        concept
        inline
        sizeof
        while
        const
        int
        static
        xor
        constexpr
        long
        static_assert
        xor_eq
        */

        std::cout<<"koniec zmienne"<<std::endl;
    }


    //in/out
    {
        int a = 0;
        // std::cin>>a; // - tak się wpisuje wartości podane przez urzytkownika

        std::cout << "aaa" << a << 45 << std::endl;// std::cout - służy do wypisywania elementów   kolejne elementy dostarcza się strzałkami <<   std::endl -przenosi do kolejnej lini, bez tegokolejny cout zacznie pisaćw tej samejlinji

        printf("OK?"); // tak też mozna, nie wiem po co ale można
        std::cout<<endl;

        //zapis do pliku
        std::fstream fileOut; // zmienna typu fstream
        fileOut.open("plik.txt",std::ios::out); //metoda .open zastowsowana na zmiennej typu fstream z argumentami (ścieżka do pliku, std::ios:: out - tryb wypisująca z programu do pliku)
        if(fileOut.is_open())
        { //sprawdzam czy plik zostal poprawnie otwarty
            fileOut<<"Hello\n";// wpisyuje elementy strumieniem danych
            fileOut<<"World\n";
            fileOut.close();//Należy pamięać o zamknięciu strumienia pliku, inaczej zmiannysię nie zapisza
        }

        fileOut.open("plik.txt",std::ios::out);//ponowne otwarcie pliku do zapis powoduje wyczyszczenie jego dotychczasowej zawartosci
        if(fileOut.is_open())
        {
            fileOut<<"Hello2\n";
            fileOut.close();
        }

        fileOut.open("plik.txt",std::ios::app);// tryb std::ios::app nie nadpisuje obecnejzawartościpliku tylko dopisuje elementy na koniec
        if(fileOut.is_open())
        {
            fileOut<<"World2\n";
            fileOut.close();
        }

        //czytanie zpliku
        std::fstream fileIn;// fstream służy do odczytu zplików
        fileIn.open("plik.txt",std::ios::in);// tryb std::ios::in pozwala odczytywać zawate w pliku wartości
        if(fileIn.is_open())
        {
            std::string line;
            while (std::getline(fileIn,line))// metoda getline z argumentami (fstream, line) - zapisuje kolejne linie z pliku do którego kieruje fsrtream na zmienną line, nadpisująć jąprzykażdym obrocie  kiedy linie się skończą funkjcja zwraca wartość false, co przerywa petle while
            {
                std::cout<<line<<std::endl;
            }
            fileIn.close();// jak zawsze nalezy zasobą zamykać plik
        }




        std::fstream strum("plik.txt", std::ios::in | std::ios::out);// można używać wielu trybów jednocześnie poprzez podanie w argumencie 2 ichalternatywy
        strum.close();

        //Występuje więcej rodzajów trybów
        /*
         ios::in — zezwala na odczyt ze strumienia;
         ios::out — zezwala na zapis do strumienia;
         ios::trunc — (truncate) po utworzeniu usuń dotychczasową zawartoś";
         ios::ate — po otwarciu ustaw na końcu pliku (at end);
         ios::app — (append) przechodź na koniec strumienia dla każdej operacji wstawiania (pisania);
         ios::binary — nie interpretuj w żaden sposób znaków końca linii i powrotu karetki (w Linuksie ta opcja jest zbędna, ale przydaje się w Windows, gdzie koniec linii oznaczany jest za pomocą dwóch znaków);
         */

        //.tellg - tell get, zwraca zmiennątypu streampos stanowiącą aktualną pozycje lokazlizatora odczytu(działatylko w trybie ios::in)
        //.tellp - tell put, zwraca zmiennątypu streampos stanowiącą aktualną pozycje lokazlizatora zapisu(działatylko w trybie ios::out)
        //.seekg(poz) //przyjmuje zmienną typu streampos i przenosi lokazlizator odczytu na podaną pozycje zwracając i zwraca do niej referencje
        //.seekp(poz) //przyjmuje zmienną typu streampos i przenosi lokazlizator zapisu na podaną pozycje zwracając i zwraca do niej referencje
        //.seekg(offset,poz) //(ostream& seekg(streamoff offset, ios::seek_dir poz) — robi to samo co swój odpowiednik z mniejszą ilością arumentów
            //, ale danąpozycje przesówa o odpowiedni offset // steamoff i ios::seek_dir to aliasy typów całkowitych
        //.seekp(offset,poz) //(ostream& seekp(streamoff offset, ios::seek_dir poz) — robi to samo co swój odpowiednik z mniejszą ilością arumentów
        //, ale danąpozycje przesówa o odpowiedni offset


        //odczyt nieformatowalny
/* // odkomentu aby użyć
        char c;
        while ( cin.get(c) ) // get bierze wartość i pomyła odniesienie do kolejnego elementu
        {
            if ( c == '/' )// kiedy strumień wczytujący znajduje  // traktuje jako znak końca
                if ( cin.peek() == '/')// peek zwraca wartość kolejnego element nie przechodząc do dalej
                {
                    cin.ignore(1024,'\n');
                    cout << endl;
                    continue;
                }
            cout << c;
        }
*/

        // występują też inne funkcje jak naprzykład:
        //.get()// zwracające integer, znaku ale nie zwracającewskanika do kolejnego elementu
        //.get(buf,  length, termin = ’\n’)//przepisuje kolejne elementy to tablicy charów buf,ustala długość odczytywanychargumentów na lenght
            //(w tym przypadku 1 bajt, bo buf mieści tylko 1 bajt), char termin = '\n' - pomija znaki końcalińji, to wszystko jest customizowalne
        //.getline(buf, length, termin = ’\n’) //działa jak poprzednia funkcja (niezałębiajmysię w to)
        //.getline(c)// - dla c bęącego typustring wczytuje kolejne lińje
        //.read(buf, length)// wczytuje lenht buytów do buf
        //.ignore(length = 1, termin = EOF)// wczytuje określoną ilość znaków, nie zwracajać ich jeżelinapotkapo drodze znak końca
        //.gcount( ) - //zawraca int zawierający ilość wczytanyych zestrumieniabajtów
        //.peek //zwraca kolejny znak nie poruszająć się jednocześnie po strumeniu
        //.putback(znak)// wstawia na obecną lokalizacje w odczycie podany znak znak,od niego potemzaczynasię czytanie
        //.unget()// wstawia ostanio pobrany znak spowrotem do strumienia(po prostu się cofa)

        //zapis nieformalny
        //.put(char c) - zapisuje do strumienia char i zwracareferencje do strumienia
        //.write(buf, length) //write(const char* buf, streamsize length) - zapisuje podaną ilość(length) znaków z byf do streama naktórym funkcjajest wykonywana

        //obsługa błędów strumieni
        // informacje o błlędach zawarte sąw
        //ios::badbit // - ogień i zniszczenie nie manadzieji strumeień jest nieodwracalnie zniszczony
        //ios::eofbit // - proram próbował odwołać się do elementu poza strumieniem (dalej niż koniec przestrzeni naktórej miał operować)
        //ios::failbit // - następna operacja nie powiedzie się, ale strumieńnei jestzniszczony
        //ios::goodbit // - strumień jest zdrowy kiedy wartość goodbit jest 0

        // strumień można sprawdzać zpomocą tych funkcji bool
        /*
        .bad( );
        .eof( );
        .fail( );
        .good( );
        */

        //.rdstate(); zwracasłowo stanutypu iostate
        //clear(stan = ios::goodbit)// ustawia słowostanu typu iostate nagoodbit
        //.setstate(stan)// pozwalaustwawićstan

        //role odczytywanych plików moąpełnićrównieżobiekty klasystin

        // wersja "gumowa"
        ostrstream napis1;
        napis1 << "Poczatek, " << "dalszy ciag, "
            << "koniec." << ends;
        char* n = napis1.str();// przypisuje się zmiennej typu strinowej tablicy charów wartosć zmiennej ostream przerobionąna typ tablicy charów
        cout << "Napis jest: " << n << endl;
        free(n);// zwalnia pamięć

        // wersja tablicowa
        char tab[30];
        ostrstream napis2(tab,sizeof(tab));// do ostreama załaćzamy tablice i jej długość, i od tej poy ostream będzie wypełniał te tablice
        napis2 << "Magda " << "Kasia " << "Marta" << ends;
        cout << tab << endl;

        ostrstream strum1(tab, sizeof(tab));// teo typustrimień będzie wsobie zawieral odniesienia od t do końcapodanej długośći
        istrstream istr1(tab);//ten z kolei aż do napotkania znaku końca

        // zmienne typustream sąbardzoprzydatne, możnadonichłatwododawaćkolejne eleementy
        //strumień<< "To be" << " or not to be" << ", etc.";


    }


    //operatory logiczne
    {
        std::cout<<"początek operacji logicznych"<<std::endl;
        std::cout<<! true<<std::endl; // ! - zapzeczenie
        std::cout<<(true && false)<<std::endl; // && - koniunkcja
        std::cout<<(true && true)<<std::endl;
        std::cout<<(true || false)<<std::endl; // || - alternatywa
        std::cout<<(true || true)<<std::endl;
        std::cout<<(2>1)<<std::endl;// -większe/mniejsze
        std::cout<<(2==2)<<std::endl;// -równe
        std::cout<<(3>=3)<<std::endl;// -większości/mniejszości lub równości
        std::cout<<"koniec operacji logicznych"<<std::endl;
    }


    // operatory bitowe
    {
        std::cout<<"początek operacji bitowych"<<std::endl;
        int a=5;
        std::cout<<sizeof(a)<<std::endl; // size of zwraca długość reprezentacji bitowej

        int a1=22;
        int b1=44;
        int c1=129;
        int d1=255;

        std::cout<<~a1<<std::endl; // negacja bitowa a
        std::cout<<(a1|b1)<<std::endl; // alternatywa bitowa a oraz b
        std::cout<<(a1&b1)<<std::endl; // koniunkcja bitowa a oraz b
        std::cout<<(a1^b1)<<std::endl; // część niewspólna XOR bitowa a oraz b

        std::uint32_t n1=0;// zmienna teo typu ma dość miejscaaby zapisać w niej 4 warości od 0 do 255
        n1=a1;// przypisujemy wartość na koniec zmiennej
        n1=(n1<<8)+b1; // (n1<<8) - przesuwamy bitowo wartośćo 8 miejsc aby zrobić miejsce i dodajemy na zwolnionej pozycji kolejną watość ( proram zadziałarównież, jeżeli + zostanie zastąpiony |, bo każdydodatni bit inta zostanie wstawiony na każdy zerowy bit piewotnejwartośći )
        n1=(n1<<8)+c1;
        n1=(n1<<8)+d1;

        std::cout<<(n1 & 0xFF)<<std::endl; // 0xFF - oznacza tyle co 8 wypełniponych jedynkami bitów
        n1>>=8; // skrócona metoda przypisania wartości przesuniętej tym razem w prawo nie lewo
        std::cout<<(n1 & 0xFF)<<std::endl;
        n1>>=8;
        std::cout<<(n1 & 0xFF)<<std::endl;
        n1>>=8;
        std::cout<<(n1 & 0xFF)<<std::endl;

        // i forma w funkcji iteracyjnej
        long k=0;
        int byty[]={245,0,35,99};
        k=byty[0];
        for (int i = 1; i < (sizeof(long)/sizeof(byte)); ++i) // (sizeof(long)/sizeof(std::byte)) - określa ile wartośći bytowych może byćpomieszczonych w longu
        {
            k=(a<<8)+byty[i]; // przesunięcie o osiem bajt
        }
        std::cout<<"bałagan zapisu w longu"<<k<<std::endl;
        std::cout<<(k & 0xFF)<<std::endl;//wypisanie zmiennej w koninkcji z wielkością byta
        for (int i = 1; i < (sizeof(long)/sizeof(byte)); ++i) // (sizeof(long)/sizeof(std::byte)) - określa ile wartośći bytowych może byćpomieszczonych w longu
        {
            k>>=8;
            std::cout<<(k & 0xFF)<<std::endl;
        }




        std::cout<<"koniec operacji bitowych"<<std::endl;
    }


    //instrukcje warunkowe
    {
        std::cout<<"początek funkcji warunkowych"<<std::endl;

        int x=3;
        // instrrukcja warunkowa
        int var1= (x>1)?3:4; // warunek w nawiasach prezed ? alternatywa jeżeli tak : alternatywa jeżeli nie - wartość zdeterminowana przez warunek jest traktowana jak watość wnawiasie do dalszegoużycia
        std::cout<<var1<<std::endl;

        std::cout<<"początekifów"<<std::endl;
        if(x>2) // if() - w nawiasach zawarty jestwarunek wykoniania
        {//zawartość instrukcji warunkowejpowinnabyć zawaraw klamekach
            std::cout<<"if1"<<std::endl;
            std::cout<<"if1"<<std::endl;
        }
        else // elese uruchamia się gdy warunek if nie jest spełniony, else jest opcjonalny
        {
            std::cout<<"if2"<<std::endl;
            std::cout<<"if2"<<std::endl;
        }

        if(x>2) // jeżeli do wykoniania jest tylko jedna linia kodu, nie trzeba urzywać klamerek
            std::cout<<"if1"<<std::endl;
        else
            std::cout<<"if2"<<std::endl;
        if(x>3) // można łączyć wiele ifów zapomocą elsów, co pozwalaprzetestować więcej alternatyw
            std::cout<<"if1"<<std::endl;
        else if(x>2)
            std::cout<<"if2"<<std::endl;
        else
            std::cout<<"if3"<<std::endl;

        int a=3;
        double b=1.5678;
        char c ='a';
        if (auto delta = b*b-4*a*c; delta > 0) // wewnątrz ida można zawrzeć kilka lińji kodu, w tym deklaracje które przestająistnieć po opuszczniu ifa
            std::cout<<delta<<std::endl;// typof - zwraca typ zmiennej

        int k=0;
        if ( 2>k ) std::cout<<"a"<<std::endl; // minimalistyczne ify też działąją
        else if ( k>2 ) std::cout<<"a"<<std::endl;
        else std::cout<<"a"<<std::endl;


        std::cout<<"koniec ifów"<<std::endl;

        std::cout<<"początek switcha"<<std::endl;
        switch (x-1) // switch wykonuje różne akcje w zależności od watości dostarczonej  (x-1) - wartość dostarczona   ( ) - w nawiasac hmoże znajdować się dowolne równanie, nie tylko pojedyńczawartość
        {
            case 2:// case 2 - kiedy podana zmienna ma wartość 2
            { // wykonaj zawartość nawiasów
                std::cout<<"a2"<<std::endl;
                break; // break trzeba umieszczać na końcu wariantu switcha, beztego wykonają się również wszystkie wariaty po nim
            }
            case 3:
                break; // jak instrukcja jest jednolinijkowa można nie używać nawiasów
            case 1:
            {
                std::cout<<"a1"<<std::endl;
                // to siędzieje jaknie mabreaka
            }
            case 0: case 5: case 7: // tak zawiera się warunek z wielomaswitchami w jednym miejscu
            {
                std::cout<<"a1"<<std::endl;
            }
            default: // w default: umieszcza się instrukcje która na zostacwykonanajeżeli wszystkieinnewarianty pozostaly niespełnione
            {
                std::cout<<"a1"<<std::endl;
            }
        }
        std::cout<<"koniec switcha"<<std::endl;

        //assert
        assert(1>0);// jeżeli assert jest spełniony proram kontynuuje działanie,jeżeli nie proram jest przerywany i wipisany zostaje błąd

        std::cout<<"koniec funkcji warunkowych"<<std::endl;
    }


    //opeacje matematyczne
    {
        int a=7;
        int pi=M_PI;// zwracawartość pi
        std::cout<<"początek operacji matematycznych"<<std::endl;
        std::cout<<a++<<std::endl;//dodoawanie 1
        std::cout<<a++<<std::endl;//dodoawanie 1  // podczas przypisania ++ może się powtarzać wielokrotnie
        std::cout<<a--<<std::endl;//odejmowanie 1
        std::cout<<2+1<<std::endl;//dodoawanie
        std::cout<<3-2<<std::endl;//odejmowanie
        std::cout<<4*4<<std::endl;//mnożenie
        std::cout<<8/2<<std::endl;//dzielenie
        std::cout<<pow(3,3)<<std::endl;//potgowanie, wymaga biblioteki cmath
        std::cout<<sqrt(25)<<std::endl;//potgowanie, wymaga biblioteki cmath
        std::cout<<7%3<<std::endl;//resztazdzieleniea
        std::cout<<!6<<std::endl;//zwraca logicznezapzeczenie dla0 1, dla każdej innej liczby 0
        std::cout<<sin(3)<<std::endl;// zwraca sin
        std::cout<<cos(4)<<std::endl;// zwraca cos
        std::cout<<tan(5)<<std::endl;// zwraca tangens
        std::cout<<asin(1.)<<std::endl;// zwraca arcsin
        std::cout<<acos(-1.)<<std::endl;// zwraca arccos
        std::cout<<atan(1.)<<std::endl;// zwraca arctangens
        cout.precision(15);// pozwal dostosowąć prezycje liczb wyświetlanych prze funkcje cout
        std::cout<<"koniec operacji matematycznych"<<std::endl;

    }


    // pętle
    {
        std::cout<<"początek funkcji iteracyjnych"<<std::endl;
        std::cout<<"początek funkcji for"<<std::endl;
        for (int i = 0; i < 3; ++i) // - funkcja for wykonuje się tak długo jak i jest mniejszeod 3 zwiększająci zkarzdym obrotem
        {
            std::cout<<i<<std::endl;
        }

        for (int a:{1,2,3}) // - for( int a : {}) - iteruje zawartość klamerek przypisując pokolei elementy dozmiennej int a
        {
            std::cout<<a<<std::endl;
        }
        std::cout<<"koniec funkcji for"<<std::endl;


        int i=0;
        std::cout<<"początek funkcji while"<<std::endl;
        while(i<3) //- funkcja while wykonuje się takdługo jak spełnione są warunki wewnątrz ()
        {
            std::cout<<i<<std::endl;
            i++;
        }
        int tab[]={1,2,3,0,7,8};
        int k=-1;
        while (tab[k++]);// pętla z pustą instrukcją będzie kręcić się i zwiększać k o 1 z każdym obrotem aż nie znajdzie tab[k]=0  bo zero jest równoznaczne z falszem, każdy warunek może być zawat wewnątrz
        std::cout<<k<<std::endl;
        std::cout<<"koniec funkcji while"<<std::endl;


        std::cout<<"początek funkcji do while"<<std::endl;
        i=0;
        do // do while działa jak while, ale najjpier wykonuje instrukcje a potem sprawdzawarunek dla potencjalnej powtórki
        {
            std::cout<<i<<std::endl;
            i++;
        }
        while(i<3); //- funkcja while wykonuje się takdługo jak spełnione są warunki wewnątrz ()
            std::cout<<"koniec funkcji do while"<<std::endl;

        std::cout<<" początek inbstrukcji zaniechania"<<std::endl;
        // instrukcje zaniechania
        int suma=0;
        for (int i = 0; i < sizeof(tab); i++)
        {
            if ( tab[i] <= 0 ) continue; // continue inoruje reszte obecnej iteracji ale nie przerywa iterowania
            std::cout<<i<<std::endl;
            suma += tab[i];
        }
        std::cout<<suma<<std::endl;

        suma=0;
        for (int i = 0; i < sizeof(tab); i++)
        {
            if ( tab[i] <= 0 ) break; // continue inoruje reszte obecnej iteracji ale nie przerywa iterowania
            std::cout<<i<<std::endl;
            suma += tab[i];
        }
        std::cout<<suma<<std::endl;
        std::cout<<" koniec inbstrukcji zaniechania"<<std::endl;


        std::cout<<"koniec funkcji iteracyjnych"<<std::endl;
    }


    // randomowość
    {
        std::cout<<"początek funkcji randomowych"<<std::endl;

        // pseudorandomowość wymaga załączenia <random>
        std::cout<<RAND_MAX<<std::endl; // - RAND_MAX - podaje maksymalną warość jaką można utrzymaćenerując liczby losowe

        std::cout<<std::rand()<<std::endl; // - std:rand() - generuje randomową liczbę pomiędzy 0 i randMAX
        std::cout<<std::rand()<<std::endl; // samo std::rand przykażdejkompilacjizwraca te same watości
        std::cout<<std::rand()<<std::endl;
        std::cout<<std::rand()<<std::endl;


        // mniejpseudorandomowość wymaga załączenia <ctime>
        srand(time(NULL)); // - załączenie czasu do funkcji rand

        std::cout<<std::rand()<<std::endl; // - st::rand po załączeniu funkcji czasu watości faktycznie są zakażdymrazeminne
        std::cout<<std::rand()<<std::endl;
        std::cout<<std::rand()<<std::endl;
        std::cout<<std::rand()<<std::endl;

        std::cout<<"koniec funkcji randomowych"<<std::endl;
    }


    // wskaźniki i referencje
    {
        std::cout<<"początek wskaźników i referencji"<<std::endl;
        int a = 5;
        int *pa; // - * przed nazwą zmiennej czyni ją zmienna typu wskaźnikoweo
        pa=&a; // - pa odnosi się do lokalizacji zmiennej do której *pa się odwołuje   & - służy do odwoływnaia się do miejsca w pamięci to znacz,żę &a - zwraca miejsce danego elementu

        int b1;
        int* b=&b1;

        void *pv; // istnieją również wskańniki generyczne mogące trzymać odnośnik do dowolnego typudanych   z voida nie można wyciągnąć wartości bez zmieniania jeo typu
        b=(int*)pv;// z wskaźnika generyczne nie można wyciągnąć wartości więc trzeba zmienić go na inny typ danych, tak to się robi
        b=static_cast<int*>(pv); // albo tak

        std::cout<<&a<<std::endl; // - miejsce w pamięci w którym zapisana jest a
        std::cout<<pa<<std::endl; // - miejsce w pamięci doktórego prowadzi zmienna odnośnikowa do a... to samo

        std::cout<<a<<std::endl;// wartość a
        std::cout<<*pa<<std::endl; // wartość elementu znajdującego się w miejscu pamięci doktórego prowadziodnośnik

        int &refa = a;// referencja &refa a stanowi alternatywną nazwe zmiennej a
        std::cout<<a<<" "<<refa<<std::endl; // tak odwołuje się do wartosci referencji
        a=7;
        std::cout<<a<<" "<<refa<<std::endl; // zmianna wartości zmiennej na której bazuje referencja zmienia wartość referencji
        refa=8;
        std::cout<<a<<" "<<refa<<std::endl; // zmiana wartości referencji zmienia wartość zmiennej

        short sh= 'b'+256*'a';// zmienne typu short przechowująca dwa chary w dwóch kolejnych byteach
        void *v = static_cast<void*>(&sh); // tworzymy odnośnik typu void
        char *c = static_cast<char*>(v); // potem zmieniamy na odnośnik danego typu char
        std::cout<<c[0]<<c[1]<<std::endl;// i liczby są zapisane tam jak w tabeli

        int* v26 = (int*) malloc(sizeof(int));// do zmiennej wskaźnika do inta przypisywany jest zakres pamięci typu void o wielkości sizeof(int) zcastowany do typu *int
        *v26 = 5;

        int size=4;
        int* m = (int*) malloc(size*sizeof(int));// malockmoże zarezerwować dowolną ilość miejsca, funkcja rezerwuje tyle wolnej pamięci ile ma w arumęcie a (int*) pozwala zamienić element na porządany typ
        for (int i = 0; i < size; ++i)
            m[i] = 2*i;
        int dim=6;
        int* tab = (int*) calloc(dim,sizeof(int));// calloc alokuje pamięć o wielkości dim elementów wielkośći sizeof(int) każdy i wypełnia te elementy wartościami domyślnymi dla inta to 0. ps jako miare wielkości ta funkcja z jakieoś powodu przyjmuje tylko zmiennej size_T
        tab=(int*) realloc(tab,size);// relloc podaje wskaźmniik ze zmienionym rozmiarem, biorąc jako arumenty element na któreo wskaźnikach ma operować i nową ilość elementów

        free(tab);// freee, zwalnia pamięć elementów tworzonych z użyciem trzech poprzednich funkcji

        int* t = new int[size];
        memcpy(t,tab,size*sizeof(int));// memory copy kopiuje do tablicy podanej jako piewwszy argument, fragment tablice podaną jako drugi agument o wielkości podanej w trzecim arumęcie
        memmove(t,tab,size*sizeof(int));// to samo co memcp, ale obszar docelowy może pokrywać się z obszarem pierwotnym
        char ptr[] = "This is a random string";
        char ch = 'r';
        int count = 15;
        char* ch1 = (char *)(memchr(ptr, ch, count));// memerch zwraca wskaźnik do bajtu zawartego w tablicy podanym w pierwszym agumęcie, będącego równym watości podanej w druim argumęcie sprawdzając podaną w trzecim arumęcie ilość pozycji
        std::cout<<*ch1<<ptr<<std::endl;

        std::unique_ptr<int> ptr1 (new int(3));// unikalny wskaźnik do elementu typu int o watości 3, bezkoniecności deklarowania tego inta,działa tak samo, ale sam się usówa kiedy musi
        std::cout<<ptr1<<" "<<ptr1.get()<<" "<<*ptr1<<std::endl;

        std::shared_ptr<int> ptr2 = std::shared_ptr<int>( new int );// shared ptr, to wksąxnik który można kopiowaći wysyłać
        std::cout<<ptr2<<" "<<ptr2.get()<<" "<<*ptr2<<std::endl;// te zmienną po prosyu mozna sobie wysyłać do funkcji

        //rvalue reference
        int v27 = 5 ;// to lvalue
        int & r1 = v27;// zwykła refencja to referencja do lvalue elementu

        //będe to KIEDYŚ muszęogarnąć
        int && rr1 = 5;// r referencja rr1 przechowuje wartość, nie lokalizaje(z tego co rozmumiem mogęsię mylić)
        //nie wiem do czego to służy, nie pytajcie mnie, z tego co czytałem to może służyć jako argument funkcji, ale nie wiem jak i po co
        cout<<rr1<<endl;
        cout<<&rr1<<endl;
        /*
        Arr(const Arr& other)

        : size(other.size),
        arr(static_cast<int*>(
        std::memcpy(new int[size],other.arr,
        size*sizeof(int))))

        Arr(Arr&& other) noexcept
        : size(other.size), arr(other.arr)

         to chyba pokazuje zastosowanie w przypadku manipulacji na listach
        */

        //inteligentne wskaźniki


        //auto_ptr to typ wskaźniku który usówa obiek z którym jest powiązany w momęcie w którym wskaźnik przestaje obowiązywać,
        // może również istnieć tylko jeden tegotypu wskaźnik do obiektu danego typu(jest to często używane do klas nieprzechowujących )
        // p1 is jest automatycznym wskaźnikiem klasy A(nie obiektu tulko całej klasy(może istnieć 1 na cąłą klase(można traktować go jako wygodny skrót)))
        auto_ptr<A> pa1(new A);
        pa1->show();//funkcja działa

        // zwraca miejsce w pamięci
        cout << pa1.get() << endl;

        // stworzenie nowego wskaźnika opróżnia poprzedni
        auto_ptr<A> pa2(pa1);
        pa2->show();//funkcja działa

        // p1 jest pusty(czyli 0)
        cout << pa1.get() << endl;
        // p2 ma to samo miejsce co miał p1
        cout << pa2.get() << endl;

        //unikalny wskaźnik jest jak automatycny wskaźnik ale
        //nie da się tworzyć kopi rzadną metodą
        //działa na arrayach
        //ma automatyczne usówanie(nie musiz przejmować się niczym kiedy usówasz wszystko się usówa)
        //tworzenie unikalnego wskaźnika dla klasy A
        unique_ptr<A> pu1(new A);
        pu1->show();

        cout << pu1.get() << endl;

        unique_ptr<A> pu2 = move(pu1);
        pu2->show();
        cout << pu1.get() << endl;
        cout << pu2.get() << endl;

        unique_ptr<A> pu3 = move(pu2);
        pu3->show();
        cout << pu1.get() << endl;
        cout << pu2.get() << endl;
        cout << pu3.get() << endl;


        //dzielone wskaźniki, może być wiele wskaźników, trzymana jest informacja ile wskaźników istnieje, dana nie zostanie usónięta puki cout istniejących wskaźników jest dodatni
        //tworzenie dzielonego wskaźnika obiektu klasy A
        shared_ptr<A> p1(new A);

        //pobranie jego lokalizacji
        cout << p1.get() << endl;

        //Użycie funkcji z p1, po czym stworzeniu p2 i użycie funkcji w obu(to działa)
        p1->show();
        shared_ptr<A> p2(p1);
        p2->show();
        p1->show();

        //oba wskaźniki prowadzą do tej samej lokalizacji w pamięci, mogąsłużyć za backupy tej drogi
        cout << p1.get() << endl;
        cout << p2.get() << endl;

        // Oba wskaźniki do obiektu zawierają informacje ile istnieje dzielonych wskaźników do tego obiektu i tak sięte infromacje pozyskuje
        cout << p1.use_count() << endl;
        cout << p2.use_count() << endl;

        //tak resetuje(pozbawia miania wskaźnika) się wskaźnik, który staje si e nullowy(0)
        p1.reset();
        //jak widać lokalizacja wróviała na pustą domyślną(0)
        cout << p1.get() << endl;

        //jak widać p2 wciąż itnieje, ale ilość zmieniła siędo jednego wskaźnika, ale obiekt istnieje bo wciąż istnieją wskaźniki do niego
        cout << p2.use_count() << endl;
        cout << p2.get() << endl;

        //istnieje jezcze coś takiego jak weak pointer(słaby wskaźnik), jest to kopia shared pointera i nie jest ona uwzględniona w coutnie
        // (możę ona istnieć, a wartość obiektu i tak jest tracona kiedy wszystkie shared poimtery przestają istnieć)


        std::cout<<"koniec wskaźników i referencji"<<std::endl;
    }


    // tablice
    {
        //tablice
        int tab1[30]; // - int -typ zmiennych przechowywanych w tablicy    tab1 - nazwa tablicy    [30] - ilośćel ementów listy = 30
        const int a=5;// zmienne używane do definowania tablicpowinny być typu const albo constxpr, ale nie jest to niezbędne
        constexpr int b=31; // nie wiem nawet czym sięone różnią
        int tab2[a]; // - długość może być przypisana zp omocą zmiennych (zmiana wartośći a nie zmienia długości tablicy po zadeklarowaniu)
        int tab3[b];
        std::string tab31[20]; // - można tworzyć tablice typów wywoływanychz std::
        int tab4[] = {1,3,5,7,9,11}; // - tablice można wypełniać umieszczająć wszystkie elementy w  {} porozdzielane , długość tablicy nie musibyćtu deklarowana, dopasuje się ona do ilości podanych elementów
        int tab5[6] = {3,2,1};// - podczas deklarowania elementów listymożna uwzlędnić możliośćpojawieniasię kilku więcej poprzezzadeklarowaniedługośćilisty nawięcejniżistnieje elementów
        int tab7[7]{3,4,5}; // - tak też można deklarować liste

        int tab10[2][3];// wartościami tabeli mogą być inne tabele jednolitego typu, ta tabela zawiera dwie tabele po trzy elementami

        const int ca=2;
        const int cb=3;
        int tab11[ca][cb];// wartościami tabeli mogą być inne tabele jednolitego typu, ta tabela zawiera dwie tabele po trzy elementami
        std::cout<<*(tab11+1*256+2)<<std::endl;// tak można odwołać się do elementu tab[1][2]
        // jakby się ktośzastanawiał typ odnośnika do pierwszego elementu pierwszej tablicy to int**
        // ciekawostka tablice stringów sąw rzeczywistości macierzami charów ergo... ich typ to std::string*==char**

        size_t sizetab1 = std::size(tab1); // - size_t - typ służący do przechowywania długości tablic    std::size(tab1) - zwraca długość tablicy tab1
        std::cout<<sizetab1<<std::endl;
        std::cout<<std::begin(tab4)<<std::endl;//zwraca odnośnik do piewszeo elementu tablicy
        std::cout<<std::end(tab4)<<std::endl;//zwraca odnośnik do ostatniego elementu tablicy

        std::cout<<tab4[3]<<std::endl; // -  tab4[4] - tak się odwołuje do 5 elementu tablicy tab4   elementy liczonesąod zerowego

        std::cout<<tab4<<"=="<<&tab4[0]<<std::endl;
        std::cout<<tab4[2]<<"=="<<*(tab4+2)<<std::endl;
        // zmienna kryjąca się za nazwą tablicy jest w rzeczywistości wskaźnikiem do pierwszego elementu ero :  tab4==&tab4[0] i co z tego wynika tab4[i]==*(tab4+i)


        for (int i = 0; i < std::size(tab4); ++i) // - iteracja po tablice
        {
            std::cout<<tab4[i]<<std::endl;
        }

        std::sort(std::begin(tab4),std::end(tab4)); // - std::sort - służy do sortowania (begin,end)//to począteki koniec fagmentu do posortowania
        for (int i = 0; i < std::size(tab4); ++i) // - iteracja po tablice
        {
            std::cout<<tab4[i]<<std::endl;
        }

        //std::swap wymaga #include <utility>
        std::swap(tab4[2],tab4[4]); // swap zaminenia miejscami dwa podane zmienne będące elementem tablicy
        for (int i = 0; i < std::size(tab4); ++i) // - iteracja po tablice
        {
            std::cout<<tab4[i]<<std::endl;
        }


        char* s1 = "ala"; // - string możnazapisać w formie odniesienia do pierwszego charu
        char s2[] = {'a','l','a','\0'};// - strin może być zapisany za pomocą  tablicy charów    '\0' ostatni element tablicy stanowiznak końcastringu,jest on niezbędy i stanowipowóddla którego wielkość syrinówjestzawszezawyrzona
        char s3[] = "ala"; //- string może być zapisany w tablicy charów bezpośrednio z tekstu

        int tab8[]={4,6,8,10,12} , *p;
        p=&tab8[0]+2;// -  p - odwołanie do trzeciego elementu tablicy miejsce w pamięci przemieszcza się o 2*ilość miejsca jaką zajmuje typ zmiennej
        std::cout<<*p<<std::endl;// - *p -element danej pozycji listy
        p=p+1; // można odwoływąć się do kolejnych elementów tab8
        std::cout<<*p<<std::endl;

        p=tab8;
        std::cout<<*(p+2)<<std::endl; // -  owoływanie się do elementu listy nakonkretnej pozycji
        std::cout<<p[2]<<std::endl;
        std::cout<<2[p]<<std::endl; // - alternatywnametod do odwołania się do danego elementu listy


        //vektory
        // wymaga zawarcia #include <vector>
        std::vector<int> vec1; // std::vector deklaracja    <int> - typ zawarty w wektorze    vec1l nazwawektora
        std::vector<int> vec2{8,7,6,5,4}; // deklaracaja wektora z jego elementami
        for (int a:vec2) // iterowanie wektora, możnatakiterować wektor w przeciweństwie do tablic
        {
            std::cout<<a<<std::endl;
        }
        std::cout<<vec2.size()<<std::endl;// - .size - zwracawielkość wektora
        std::cout<<vec2.at(2)<<std::endl;// -tak uzyskuje sie element wektora nadanej pozycji
        vec2.pop_back(); // - pop_back() - usówa ostni element wektora
        vec2.push_back(89); // wstawia nakoniec wektora nowy element
        for (int a:vec2); // iterowanie wektora, możnatakiterować wektor w przeciweństwie do tablic
        {
            std::cout<<a<<std::endl;
        }

        cout<<vec2.capacity()<<endl;//wyświetla ilość miejsca zajmowanego przez wektor
        vec2.shrink_to_fit();//zminiejsza wektor aby pasował do ilości elementów

        std::cout<<vec2.front()<<std::endl;// - .front - zwraca pierwszy element wektora
        std::cout<<vec2.back()<<std::endl;// - .back - zwraca ostatni element wektora
        vec2.erase(vec2.begin()+1,vec2.begin()+3); // - erase - usówa elementy wektora   (a,b) - zakres usówanych elementów
        vec2.insert(vec2.begin()+1,67); // - vec2.insert umieszcza w wektorze vec2 (na pozycji, podaną wartość)
        std::cout<<vec2.data()<<std::endl; // - zwraca miejsce zapisu wektora w pamięci
        sort(vec2.begin(),vec2.end());// a tak ałtomatycznie sortuje się wektor
        for (int a:vec2); // iterowanie wektora, możnatakiterować wektor w przeciweństwie do tablic
        {
            std::cout<<a<<std::endl;
        }

        //std::arrays    arraye znająswoją długość niezależnie gdzie się donichodwołujemy, ale wciąż maają sałą dlugość, są onekompromisem pomiędzytablicami i wektorami
        // zarówno metodyodwóływaniasię do wektorów jak i tabllicdziałają na arrayach
        std::array<int,7> arr1;// std::array - tworzy arraye   <int,7> - wyznacza typ i długość arraya
        std::array<double,5> arr2{2.2,3.3,4.4};
        std::cout<<"koniec tablic,kolekcji, wektorów etc"<<std::endl;
    }


    // lambdy
    {
        std::cout<<"poczatek lambd"<<std::endl;

        std::cout<<[](int a,int b, int c){return a+b*c;}(1,2,4)<<std::endl; // [](zmienne){ciało}(wartości dla któych lambda mabyć wykonana) - tak tworzy się lambde zwracającą wyniki
        auto f1 = [] (auto e1, auto e2)// implementacja funkcji lokalnych za pomocą lambd, taprzyjmuje dwie dowolne zminene, porównuje je izwraca typ wybranej
        {
            return e1 < e2 ? e1 : e2;
        };
        auto f2 = [](auto a1){return typeid(a1)==typeid(double);};// lamde najlepiej zawsze przypisywać dotypu auto
        auto f3 = [](double a1){std::cout<<a1<<std::endl;};// lamnda nie musi nic zwracać i moze mieć predefiniowany typ argumentów'
        auto f4 = [](std::string a1){std::cout<<a1<<std::endl;};
        int a=5;
        auto f5 = [a]()mutable{a=a+1; std::cout<<a<<std::endl;};// mutable po argumentach i przed ciałem lambdy pozwala jej zmieniać wartośći zmiennych jej podanych

        auto v1=f1(3,7.89);// prezentacja działania
        if(f2(v1))
            f3(v1);
        f4("bbb"s);// s po napisie oznacza,że jest to string
        f5();
        f5();
        f5();

        // [=] = wpisane w nawiasy kwadratowe lambdy zapewnia jej dostęp do kopi wszystkich zmiennych
        // [&] & wpisane w nawiasy kwadratowe lambdyzapewnia jej dostęp do wskańników do wszystkich zmiennych wszystkich zmiennych
        // [v1,v2]  wpisując konkretne zmienne zapewnia do nich dostęp wewnatrz lambdy
        // [&v3,&v4] wpisując konkretne wskaźniki do zmiennych zapewnia do nichd ostęp wewnatrz lambdy
        //[v1,&v3] można jednocześnie zapewniać dostęp do kopi częsci zmiennuych i wskaźników do innych zmiennych
        // więcej w funkcjach
        std::cout<<"koniec lambd"<<std::endl;
    }


    // funkcje
    {
        //zawartość funkcji jest przed zadeklarowaniem funkcji main
        std::cout<<"początek funkcji"<<std::endl;
        int v1=8;
        fun1(2,v1,"hah");// funkcje wywołuje się poprzez zapisanie jej nazwyipodanie potrzebnych zmiennych w nawiasach
        int a = fun2(2,v1,"hah");
        int t[]{2,3,4,5};
        funt(t, std::size(t));
        std::vector<int>v{6,7,8,9};
        funv(v);
        fun4(7);
        fun5(); // - wartość staticjest zachowywana wewnątrz funkcji w kolejnych wywołaniach
        fun5();
        fun5();
        fun5();
        fun6(1,"b");// przeciążenie funkcji
        fun6(1);
        //fun6( "b"); - nie wiem czmu nie działa
        fun6();
        fun8();
        char f91 = (fun9(6,'a'));
        char f92 = (fun9(7.0,5));
        char f93 = (fun9('y',5.0));
        fun10([](auto a){return (int)a;},'a');// lambda dostarczonajako zmiennadofunkcjinie musi mieć podanych wartości dla których ma się wykonywać
        int a1=5;
        std::cout<<larger(1,a1)<<std::endl;// funkcja larger template dla intów
        std::cout<<larger('a','b')<<std::endl;// funkcja larger template dla charów
        short a2=5;
        std::cout<<larger(3,a2)<<std::endl;// funkcja larger template dla shortów, załąćza się przecuiążona funkcja
        double a3=5;
        std::cout<<larger(3,a3)<<std::endl;// funkcja larger template dla shortów, załąćza się przecuiążona funkcja
        double a4=5;
        std::cout<<larger(3,a4)<<std::endl;// zgodnie z zapisem nie kompiluje się, jest po prostu ominięte
        double u11=4,v11;
        double fun11va=fun11(u11,&v11);// jeżeli zmienna wymagana to odniesienie, jako argument wstawiamy  zmienną(po prostu u11), jeżeli zmienna musi być wskaźnikiem wstawiamy miejsce w pamięci gdzie się ona zjanjude (czyli &v11) - jak przy przypisywaniu
        int i12=4;
        int v12=*(fun12(&i12));//przykład funkcji przyjmującej wskaźnik do zmiennej i zwracającej jego zedytowanąwartość
        int tab13[] = {1,4,6,2};
        cout << "Tablica przed : ";
        for (int i = 0; i < 4; i++ ) cout << tab13[i] << " ";
        cout << endl;
        fun13(tab13,4)=0;// ze względuna to, że znaleziony element jest odnośnikiem do innej zmiennej w pamięci możemy nie tylko jąodczytać ale i do niej przyisać wartość
        cout << "Tablica po : ";
        for (int i = 0; i < 4; i++ ) cout << tab13[i] << " ";
        cout << endl;
        fun16(sin,4);// można w miejsce fun15 umieścić dowolnąfunkcje podanej właściwości
        fun16(cos,3);//jest takich kilka
        fun16([](double a){return a*2+3;},7);// może byćonanawet zastąpionalambdą
        TABFUN tabfun = { sin, cos, tan };// możnaTABFUN i TABNAP używać jako typów zmiennych jak widać
        TABNAP tabnap = {"sin","cos","tan"};
        fun17(tabfun,tabnap,5.3);// funkcja zapisana w funkcjach
        fun18([](double x){return 2*x;},3.4);// fun18 uzupełniamy lambdą, lub dowolną inną funkcją
        auto f94=krotko(1,3.3);
        std::cout<<a<<std::endl;
        typy("SxS", "Jan", 0, "Maria");// wyjaśnienei funkcji w funkcjach, tu tylko widać,zę działa
        typy("issD", 17, "Jan", "Maria", 1.);
        typy("iDdsiI", 17, 19.5, 1.5, "OK", -1, 8);
        {
            size_t dim1 = 2, dim2 = 3; //wymiary tablic
            double** matrix2d = allocMatrix2D(dim1,dim2);// tworzenie i pzypisanie do wkaźnika do wskaźnika do doubla tablicy dwuwymiarowej wyenerowanej prez allocMatrix2D(dim1,dim2)(więcej w funkcjach)

            for (size_t i = 0; i < dim1; ++i)
                for (size_t j = 0; j < dim2; ++j)
                    matrix2d[i][j] = 3*i+j+1.5;// wypełnianie watościami, to po przykład

            for (size_t i = 0; i < dim1; ++i)
            {
                for (size_t j = 0; j < dim2; ++j)
                    cout << matrix2d[i][j] << " ";//wypisywanie zawartości listy
                cout << endl;
            }

            // usuwanie
            deleteMatrix2D(matrix2d);
        }
        std::cout<<returnletter('a')<<std::endl;
        int v2=4;
        pr1(&v2);

        std::cout<<"koniec funkcji"<<std::endl;

        /* funkcje wciąż mogą sięwywoływać jeżeli podane poniżej konwersje nastąpią T- oznaczadowolny typ
        T → T&
        T& → T
        T[] → T*
        fun() → (*fun)()
        T → const T
        T → volatile T
        T* → const T*
        T* → volatile T*
        */
    }


    // operacje na zmiennych różnych typów
    {
        std::cout<<"początek operacji"<<std::endl;
        // na intach lub charach
        std::cout<<isalpha(24) <<std::endl;// sprawdza czy charowy odpowiedznik int aj jest literą
        std::cout<<isdigit('6') <<std::endl;// sprawdz cz ycharowy odpowiedznik int aj jest cyfrą
        std::cout<<isalpha(68) <<std::endl;// sprawdzac zy charowy odpowiedznik int aj jest mała literą
        std::cout<<isalpha('A') <<std::endl;// sprawdza czy charowy odpowiedznik int aj jest wielką literą
        std::cout<<toupper('a')<<std::endl;// zwraca wielką wersje podanej litey
        std::cout<<tolower('A')<<std::endl;// zwraca małą wersje podanej litey
        char *ch = "hahaha";
        std::cout<<strlen(ch)<<std::endl;// zwraca długość char*
        std::cout<<"koniec operacji"<<std::endl;
    }


    // struktóry
    {
        std::cout<<"początek stróktur"<<std::endl;
        // więcej informacji w strukturach na początku funkcji
        str1 s1=str1{1,"aaa",{'k','a','h'}}; // - tak tworzy się elementy struct, zmienne podaje się w klamerkach
        std::cout<<s1.v1<<std::endl; // poprzez nazwa_elementu_typu_twoejej_struct.nazwa_zmiennej_wewnątrz_structury można uzyskaćdo niej dostęp
        s1.v1=12; // tak można modyfikować watośći elementów structór
        std::cout<<s1.v1<<std::endl;// tako odwołuje siędo elemntów
        std::cout<<(&s1)->v1<<std::endl;//tak owołuje się do do elementu przez wskaźnik
        std::cout<<str1E.v1<<std::endl; // można również odwołać się do zadeklarowanego modelu domyślnego struktóry
        str1 s3=str1{2, "aba", {'l', 'o', 'l'}};
        str1 *s2=&s3;
        std::cout<<s2->v1<<std::endl;
        std::cout<<(*s2).v1<<std::endl;
        s1.print(); // tak odwołujemy się do funkcji w struktórach
        int v1 = s1.returnv1(); // funkcje zwnętrza struktóry moązwracaćwartości pozastruktóre
        s1.biggerv1(s1,str1E); // odwoływanie się do funkcji statycznej
        long v2=6;
        bool v3=true;
        std::string v4="aaa";
        Tstruct<long,bool,std::string> a{v2,v3,v4};// struktóry oparte o template
        std::cout<<"koniec stróktur"<<std::endl;
        Osoby ktab[5] = {{"Ala",17},{"Ola",32}, {"Ula",26},{"Iza",29}};//używanie stróktóry/klasy jako bazydo listy elementów
    }


    // using
    {
        std::cout<<"początek using"<<std::endl;
        {
            using namespace std; // - using namespace wraz z nazwą elementu konstrukcyjnego popzedzającego funkcje pozwala pisać te funkcje bez niego co poprawia czytelność kodu
            cout << "bez std::" << endl;
        }
        std::cout<<"z std::"<<std::endl;// - using działatylko wewnątrz nawiasów wktórych jestzadeklarowany
        std::cout<<"koniec using"<<std::endl;
    }


    // enumy
    {
        std::cout<<"początek enumy"<<std::endl;
        enum en1{A,B=0,C='a',D,E= false,F,G}; // - tak tworzy się Enumu -   enum - typ enumowy   en1 - nazwa enuma     {...} - elementy beztypowe enuma   enum może przechowywać wartościzmiennych typów prostych
        std::cout<<en1::A<<std::endl; // tak się odwołuje do elenebtow enuma
        en1 e1 = B;// tak przypisuje sie zmiennej wartość enuma
        enum en2 : unsigned {H,I,J}; // enumy mogą być unsigned, co daje im większy zasięg
        std::cout<<"koniec enumy"<<std::endl;
    }


    // new i delete
    {
        std::cout<<"początek new i delete"<<std::endl;
        str1* s1 = new str1{3,"cda",{'h'}}; // tworząćzmienną z urzyciem new rezerwujeszdla niej pamięć manualnie i możeszuzyskać do jejwartości dostęp w różnych częściachprogramu bezkopiowania jej
        delete s1; // niestety tego typu zmienne trzeba usówać instrukcją delete, inaczej pamięć nie zostanie zwolniona
        int* s2= new int [20];//można twozyć w tensposóbtablice
        delete[] s2;// i je należy usówaćw tensposób
        int a1=4;
        int *s3=&a1;
        std::cout<<"aaaa"<<std::endl;
        //delete s3;// zmienne nie inijowane za pomocą new też można usówać,aby zwolnićpamięć    nie wiem czemu ta linijka sprawia czasem problemy, normalnie dizłąnormalnie chyba,że jejesie niechce
        std::cout<<"koniec new i delete"<<std::endl;
    }


    // klasy
    {
        std::cout<<"początek klasy"<<std::endl;
        Triangle t1 = Triangle();// tak odwołuje się do pustego konstruktora Triange
        Triangle t2 = Triangle(4,5,6);// tak odwołuje się do konstruktora z trzema  Triange
        Triangle t3(4,5,6);// alternatywna metoda twozenia zmiennych klasy

        int a1=t1.getA(); // tak odwołuje się do elementu a zmiennej t1
        std::cout <<a1<< std::endl;
        t2.setA(a1);
        a1=t2.getA();
        std::cout <<a1<< std::endl;

        //wywołanie metody statycznej
        Triangle::into(t2);

        int Triangle::*wi[3];// lista wskaźników do elemnetów klasy
        wi[0]=&Triangle::a;// deklaracja stanowiąca,że pierwszy element tablicy wi będzie zawierał wskaźnik do a
        //resztazmiennych jest niedostępna, bo śą niepubliczne

        std::cout<<t1.*wi[0]<<std::endl;// itak można odwołąć się do elementu danej klasy tym wskaźnikiem.... komu i na co to potzebne

        Testfield a2(3,4);

        Testfield::testfield1 a3(1,2);// zmienna typu klasy zadeklarowanej w innnejklasie

        Punkt p(7);
        Zakres z1(0,10), z2(8,20);
        isInside(&p,&z1);
        isInside(&p,&z2);

        // KlasaSegment pomoźe lepiejzrozumieć przeciążenia operatrów
        using std::cout; using std::endl;
        Segment seg{2,3}, s = 1 + 2*((seg-2)/2+seg)/3;
        cout << s << endl << std::boolalpha;
        for (double x = 0.5; x < 4; x += 1)
            cout << "x=" << x << ": " << s(x) << endl;

        std::cout<<sqrt(t2);// element trainge zastępuje double sprawdź w jego pliku.h dlaczeo

        //Car dziedziczy po Vechicle więcej szczegułów w klasach
        Vechicle plane("plane");
        plane.describe();
        plane.nameOfClass();

        Car bus("autobus",6);
        bus.nameOfClass();
        bus.describe();
        bus.elements();


        //pokazanie zastosowań rozszeroznych klas
        Figura* tab[] =
        {
                //1. to to samo co 1.0
                new Kolo(1.), new Kwadrat(1.),
                new Kolo(2.), new Kwadrat(3.)
        };

        int size = sizeof(tab)/sizeof(tab[0]);

        for (int i = 0; i < size; ++i)
        {
             tab[i]->info(cout);
             cout << endl;
        }

        Figura* maxobw = Figura::maxObwod(tab,size);
        cout << "Suma pol: " << Figura::totalPole(tab,size)
        << "\nFigura o najwiekszym obwodzie: ";

        maxobw->info(cout);
        cout << "\n ma obwod "<< maxobw->getObwod() << endl;

        for (size_t i=0; i < std::size(tab); ++i)
            delete tab[i];

        std::cout<<"koniec klas"<<std::endl;
    }


    // stosy
    {
        // więcej o strosach w struktórach
        std::cout<<"początek stosy"<<std::endl;

        using std::cout; using std::endl;
        int tab[] = {1,4,1,3,5};

        Node* head = 0; // tworzenie stosu
        for (size_t i = 0, e = std::size(tab); i != e; ++i)  // dla każdeo elementu z tabeli
        {
            bool b = add(head,tab[i]); // dodawanie elementu
            cout << tab[i] << (b ? "     " : " NOT ")
                 << "added" << endl;
        }
        cout << "Size of the list: " << size(head) << endl;
        printList(head);// wypisanie stosu
        clear(head); // wyczyszczenie listy

        std::cout<<"koniec stosy"<<std::endl;
    }


    // stos w klasie
    {
        // głępszy opis w MyStak.h
        std::cout<<"początek stosy w klasie"<<std::endl;
        using std::cout; using std::endl; using std::string;
        MyStack<string> stS;// tworzenie elementu klasy MyStack typu string
        MyStack<double> stD;// tworzenie elementu klasy MyStack typu string - jak widać klasa pzyjmuje wszystkie typy danych
        for (int i = 5; i > 0; --i)
        {
            stS.push(std::to_string(double(i)));
            stD.push(double(i));
        }
        while (!stS.empty())// jeżeli stos nie jest pusty
            cout << "string: " << stS.pop() << " "<< "double: " << stD.pop() << endl;
        std::cout<<"koniec stosy w klasie"<<std::endl;
    }


    // L i P czyli zmienne zlożone
    {
        std::cout<<"początek zmiennych złożonych"<<std::endl;

        // L watość - wyrażenie identyfikujące daną o określonym typie, która ma określony, dostępny w programie adres w pamięci.
        // P wartość - wyrażenie, które ma określoną wartość.

        /* - kilka przydatnychrad dotyczących czytania zmiennych złożonych
        1. zaczynamy od nazwy deklarowanej zmiennej,
        2. patrzymy w prawo: jeśli jest tam nawias otwierający okrągły, to będzie to funkcja (odczytujemy liczbę i typ parametrów); jeśli będzie tam nawias otwierający kwadratowy, to będzie to tablica (odczytujemy rozmiar),
        3. jeśli po prawej stronie nic nie ma lub jest nawias okrągły zamykający, to przechodzimy na lewo i czytamy następne elementy kolejno od prawej do lewej aż do końca lub do napotkania nawiasu otwierającego
        4. jeśli napotkaliśmy nawias okrągły otwierający, to wychodzimy z całego tego nawiasu i kontynuujemy znów od jego prawej strony,
        5. gwiazdkę (’*’) czytamy jest wskaźnikiem do,
        6. ampersand (’&’) czytamy jest referencją do,
        7. po odczytaniu liczby i typu parametrów funkcji dalszy ciąg procedury określa typ zwracany tej funkcji,
        8. po odczytaniu wymiaru tablicy dalszy ciąg procedury określa typ elementów tablic
        */
        // przykłady
        int i=1,j=2,k=3;
        (i=j) = k; // i=3, j=2, k=3

        int tab[] = {1,2,3,4}, *p = tab;
        *++++++p = 8; // tab[] = {1,2,3,8} - policzyć++    p*=8

        int m = 7;
        razdwa( (int&)m=8 )++; //razdwa to funkcja podwaja podany element poprzez odwołanie do wskaźnika  m=17

        razdwa(m)++; // m=35

        int n = razdwa(m) = 10; // m=10

        k = (i=1, j=2) + 1; //k=3

        (k > 2 ? i : j) = 5; // i=5

        (k < 2 ? i : j) = 5; //  j=5

        std::cout<<"koniec zmiennych złożonych"<<std::endl;
    }


    //etykiety
    {
        std::cout<<"początek etykiet"<<std::endl;

        int tab[2][2][2]{{{1,2},{3,4}},{{5,6},{7,8}}};
        bool jest = false;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                {
                    std::cout << ">" << tab[i][j][k] << "<" << std::endl; // po znalezieniu etykiety kod nie wraca do funkcji
                    if (tab[i][j][k] == 5) {
                        jest = true;
                        goto LAB; // goto automatycznie przenosi kompilacje do miejsca kodu z etykietą
                    }
                }
        LAB:if(jest) //LAB-nazwa etykiety,   : -indykator,ze to etykieta    reszta kodu,wykonywana normalnie
            cout << "5 jest w tablicy" << endl;
            else
            cout << "5 nie wystepuje w w tablicy" << endl;

        int a=0;
        LAB2: // puste zadeklarowanie etykiet, sama etykieta
        std::cout<<a<<std::endl;
        a++;
        if(a<5)
            goto LAB2;// jak widać etykieta pozwala również cofać się w kodzie

        std::cout<<"koniec etykiet"<<std::endl;
    }


    // operatory
    {
        //priorytety
        /*
        Priorytety wywoływanesą od najwyrzszych do najnizszych
         L - oznacza, że element na którym jest coś wywoływane jest od lewej stronu
            np. tab[1] - 1 element tabeli - bierze najpier tabele(z lewej) a potem szuka jej pierwszego elemntu(z prawej)
         R - oznacza, że element na którym jest coś wywoływane jest od prawej strony
            np. sizeof(a) - najpierw znajduje element a (z prawej) po tem umieszcza go w funkcji szieof()(z lewej)

        Priorytet 16
            L operator zasięgu klasa::sklad,pnaz::sklad,::naz
        Priorytet 15
            L dostęp do składowej ob.sklad,wsk->sklad
            L indeksowanie wyr[wyr]
            L wywołanie funkcji wyr(lista_wyr)
            L konstruowanie wartości typ(lista_wyr),typ{lista_wyr}
            L postdekrementacja,postinkr. lwar−−,lwar++
        Priorytet 14
            R rozmiar obiektu sizeof wyr
            R rozmiar typu sizeof(typ)
            R rozmiar pakietu sizeof...(naz)
            R predekrementacja,preinkr. −−lwart,++lwart
            R negacja bitowa,logiczn ∼wyr,!wyr
            R minus, plus jednoargumentowy −wyr,+wyr
            R wyłuskanie adresu &lwart
            R dereferencja *wsk
            R przydział pamięci na obiekt new typ
            R przydział pamięci na tablicę new typ[wyr]
            R zwolnienie obiektu delete wyr
            R zwolnienie tablicy delete [ ] wyr
            R rzutowanie w stylu C (typ)wyr
        Priorytet 13
            L wskaźnik do składowej wsk->*sklad_wsk,ob.*sklad_wsk
        Priorytet 12
            L mnożenie,dzielenie wyr*wyr,wyr/wyr
            L reszta z dzielenia wyr % wyr
        Priorytet 11
            L dodawanie,odejmmowanie wyr+wyr,wyr−wyr
        Priorytet 10
            L przesunięcie w lewo, prawo wyr<<wyr,wyr>>wyr
        Priorytet 9
            L mniejsze od wyr < wyr
            L mniejsze lub równe od wyr <= wyr
            L większe od wyr > wyr
            L większe lub równe od wyr >= wyr
        Priorytet 8
            L równe wyr == wyr
            L nierówne wyr != wyr
        Priorytet 7
            L koniunkcja bitowa wyr&wyr
        Priorytet 6
            L bitowa różnica symetryczna wyr^wyr
        Priorytet 5
            L alternatywa bitowa wyr|wyr
        Priorytet 4
            L koniunkcja logiczna wyr && wyr
        Priorytet 3
            L alternatywa (suma) logiczna wyr || wyr
        Priorytet 2
            R operator warunkowy wyr ? wyr : wyr
            R przypisanie lwar = wyr
            R dodawanie z przypisaniem lwar += wyr
            R odejmowanie z przypisaniem lwar −= wyr
            R mnożenie z przypisaniem lwar ∗= wyr
            R dzielenie z przypisaniem lwar /= wyr
            R reszta z przypisaniem lwar %= wyr
            R przesunięcie w lewo z przypisaniem lwar <<= wyr
            R przesunięcie w prawo z przypisaniem lwar >>= wyr
            R iloczyn bitowy z przypisaniem lwar&= wyr
            R alternatywa bitowa z przypisaniem lwar |= wyr
            R różnica bitowa z przypisaniem lwar ^= wyr
            R zgłoszenie wyjątku throw wyr
        Priorytet 1
            L operator przecinkowy wyr,wy

         albo można wszędzie używać nawiasów i sie tym nie martwić( nawiasy mają wyższy pryjorytet niż wszystkie wyminione akcje)
        tekstowa symboliczna tekstowa symboliczna
        and &&
        and_eq &=
        bitand &
        bitor |
        compl ∼
        not !
        not_eq !=
        or ||
        or_eq |=
        xor ^
        xor_eq ^=
        */
    }


    //Przeciążenie  Operatorów
    {
        // operatory mogą być przeciążane dla formatu typ1 operatorA(Typ1,Typ2); - z tym, że co najmniej jeden z podanych typów musi być typu ustalonego przezużytjkownika
        // operatory które mogą byc przeciążone
        std::cout<<"poczatek przeciążeń operatorów"<<std::endl;
        // operator przeciążony dla stróktury str2 - możnaznaleźć w struktórach
        str2 s1{2,3};
        str2 s2{7,9};

        str2 s3=s1+s2;// wykorzystanie przeciążonego operatora dodawania dla dwóch elementw typu str2 zwracający str2
        std::cout<<"a: "<<s3.a<<", "<<"b: "<<s3.b<<std::endl;

        int s4 =4+s1;// wykorzystanie przeciążonego operatora dodawania dla elementu int i str2 zwracający int
        std::cout<<s4<<std::endl;

        str2 s5=s1+3;// wykorzystanie przeciążonego operatora dodawania dla elementu typu str2 i int zwracający str2
        std::cout<<"a: "<<s5.a<<", "<<"b: "<<s5.b<<std::endl;

        // więcej informacji w Resistor.h i w Resistor.cpp
        Resistor r1, r2{6};
        r1.r(3);
        std::cout << (r1 + r2) << " " << (r1 * r2) << std::endl;// operatory są przeciążone w klasie Resistor

        std::cout<<"koniec przeciążeń operatorów"<<std::endl;
    }


    //casty - pojawiły się z raz bez konteksu... oto kontekst
    {
        std::cout<<"początek castów"<<std::endl;
        //const_cast
        {
            const int a=5;
            const int *ptr = &a;
            int *ptr1 = const_cast<int*>(ptr);// pozwala zamienić zmienną const na zmienną bez const
            cout<<a<<" "<<*ptr1<<endl;
            *ptr1=4;// da się zmienić
            cout<<a<<" "<<*ptr1<<endl;
        }
        //static_cast
        {
            int* p = new int(65);
            char* ch = reinterpret_cast<char*>(p);// reinterpreter cast może przeprowadzać bezpieczne konwesje nie wymagające zmiana w zapisie, takie jak int->char - konwersja jest bezpieczna bo elementy zajmują taką sam zakres pamięci i są tak samo zbudowane
            // to działa tak samo jak np.
            /*
            int p=65;
            char ch=(char)p;
            tylko to jest metoda dla zmiennych a reinterpret_cast działatak dla wskaźników
            */
            cout << *p << endl;//różne watośći
            cout << *ch << endl;
        }
        //dynamic cast
        {
            //dziala jak static cast, ale
            /*
                sprawdza czy konwersja którą próbujesz zrobić będzie zwracać porządany typ jeżeli nie zwraca 0
                static cast generalnie jest chyba przydatniejszy, ale dynamic cast pozwala się czasem zabezpieczuć przed nieporządaną, błędna konwersą - ma zastosowanie w instrukcjach warunkowych do sprawdzania czy np. element customowej klasy może być zamieniony na element innej klasy
            */
        }
        {// reinterpreter_cast
            int* p = new int(65);
            double* d = reinterpret_cast<double*>(p);// reinterpreter cast może przeprowadzać niebezpieczne konwesje wymagające zmiana w zapisie, takich jak int->double - konwersje niebezpieczne to konwersje niespełniajace definicji konwersjibezpiecznej
            // pozwalato próbować przekształcaćwszystkie niebezpieczne konwersje
            // to działa tak samo jak np.
            /*
            int p=65;
            double  d=(double)p;
            tylko to jest metoda dla zmiennych a reinterpret_cast działatak dla wskaźników
            */
            cout << *p << endl;//różne watośći
            cout << *d << endl;
        }
        std::cout<<"koniec castów"<<std::endl;
    }


    // konwesje
    {
        std::cout<<"początek konwersji"<<std::endl;

        int a1 = 3;
        double a2=(double)a1; // to jest konwersja z int na doubla, jest to konwersja niestratna, bo każdy int zawiera się w doublach co można określić jako double będący szerszym niż int
        a1=(int)a2; //to jest konwersja z double na int, jest to konwersja stratna, bo nie każdy double zawiera się w intach co można określić jako int będący węrzszym niż double

        // niektóre konwersje są cięższe do wykoania,częśćtrzeba implementować manualnie
        //przykład konwetera tablic charowych nainty, zpominięciem niepotrzebnych znaków znajduje się w funkcjach
        char tab1[] = "123a";
        char tab2[] = "456 1";
        char tab3[] = " 56";
        cout << "tab1 -> " << konwert(tab1) << endl;
        cout << "tab2 -> " << konwert(tab2) << endl;
        cout << "tab3 -> " << konwert(tab3) << endl;

        std::cout<<"koniec konwersji"<<std::endl;

    }


    // funkcje czasu
    {
        std::cout<<"początek funkcji czasu"<<std::endl;


        timeb start, teraz;// deklaracja zmiennnych start i teraz

        ftime(&start);// przypisanie zmiennej w pamięci &start obecnego czsu
        for (int i = 0; i <= 900000000; ++i)
        {
            if (i%100000000 == 0)
            {
                ftime(&teraz);
                time_t sec = teraz.time - start.time;// tak pobiera się czas w sekundach, watość wyrażenia to różnica pomiędzy obecnym czasem a czasem startowym
                int msec = teraz.millitm - start.millitm;//taksię pobieraczas w milisekundach, wartość obu wyrażęń może być przechowywana w dowolnej zmiennej typu liczboweo, ale preferowana są zmienne typu time_t
                if(msec<0)
                    msec+=1000;// korekta błędu
                cout << "Po " << i << " iteracjach: "
                     << sec << "s and " << msec << "ms\n";

                std::cout<<"koniec fujkcji czasu"<<std::endl;

            }
        }
    }


    //Unie
    {
        std::cout<<"pocżatek unjii"<<std::endl;

        cout << " sizeof(float)=" << sizeof(float) << endl;
        cout << "sizeof(long double)="
            << sizeof(long double) << endl;
        cout << " sizeof(Bag)=" << sizeof(Bag) << endl;

        // więcej w funkcjach
        wstaw(&bag, 3.14F);
        infor(&bag);// wypisuje sie umieszczony element właściwie i błędnie przypisuje drugą zmienną
        wstaw(&bag, 3.14L);
        infor(&bag);// wypisuje się ostatni umieszczony element wlaściwie i drui z nich nieprawidłowo

        std::cout<<"koniec unjii"<<std::endl;
    }


    // flagi
    {
        std::cout<<"poczatek flag"<<std::endl;

        //flagi zdefiniowane są w ios_base i klasie pochodnej ios_base, czyli ios,służą one do ustalania zasad na jakich pewne fragmenty programu są wykonywane
        //typ flag stanowi ios_base::fmtflags

        //ios::skipws - przy wczytywaniu ignoruje wiodące białe znaki defaut:TAK
        //ios::leff,ios::internal,ios::right - te flagi razem tworzą pole wyrównania ios:::adjustfield, tylko jedna z tych flag może być ustawiona na raz, domyślnie jest to prawa
        //os::dec, ios::hex, ios::oct - te flagi tworzą razem pole podstawy ios::basefield, tylko jedna z nich może być udtawiona na raz, domyślnie dziesiętna
        //ios::scientific, ios::fixed razem tworząpole formatu ios::floatfield, ustawienie ios::scientific wypisuje liczby zmiennoprzecinkowe w notacji naukowej, ios::fixed wypisuje ułamki normalnie po kropce, tylko jedna z tych flag może być ustawiona na raz i domyślnie jest to ios::fixed
        //ios::boolalpha - defińjuje czy wypisywane zmienne typu boolean mają być reprezentowane przez 1 i 0 ( domyślniee), czy przez true i false
        //ios::showbase - ustawia czy 0 i 0x przed typem usemkowym i szesnastkowym mają być pokazane
        //ios::showpoint - zawsze rozwija ułamek do jego pełnej długości ergo 1.2 wypisuje jako 1.20000000000000000000000  default: NIE
        //ios::showpos - pokazuje + pzed licznbami dodatnimi default: NIE
        //ios::uppercase — litery ’e’ w zapisie naukowym i ’x’ w szesnastkowym pisz jako duże’E’ i ’X’ default: NIE
        //ios::unitbuf — opróżnij bufor po każdej operacji zapisu default: NIE

        //ios::fmtflags flags( ) - zwracaobecną flafę stanu strumienia
        //ios::fmtflags flags(ios::fmtflags flg) — zwraca aktualną flagę stanu formatowania,i ustawia jej nową wartość na flg.

        std::cout << "początek funkcji dodatkowych" << std::endl;

        ios::fmtflags fn1 = ios::hex | ios::showbase | ios::uppercase;// oróując ustawiane są flagi
        ios::fmtflags fs1 = cout.flags(fn1);// tak się robi jednoczesne zapamiętanie starej flagi i ustawienie nowej
        cout.flags(fs1);// przywrtócenie starej flagii

        ios::fmtflags fs2 = cout.flags();// za pomocą cout.flags moznauzyskać dostęp dozmiennych zawartch wewnątrzflagi, takzapisuje się starą flaę dopóźniejszego użycia
        ios::fmtflags fn2 = fs2 | ios::showpos;// dddanie flagi do obecnego ustawienia flag i zapisanie jako nowaflaga
        cout.flags(fn2); //ustawienie nowejej flagii
        cout.flags(fs2);//ustawienie spowrotem starej flagi


        typedef ios_base::fmtflags FFLAG;// tworzy typ  ios_base::fmtflags pod nazwą  FFLAG

        int m = 49;
        double x = 21.73;

        cout << "1. m = " << m << ", x = " << x << endl;

        FFLAG newf = ios::hex | ios::showbase | ios::showpoint;// flaga o nazwie newf zzałączonymi wymienonymi flagami
        FFLAG oldf = cout.flags(newf);// załączenie nowej kalsy i stworzenie backapu klasy

        cout.setf(ios::showpos);// załączanie flai
        cout.unsetf(ios::showpos);// odłączanie flagi

        cout << "2. m = " << m << ", x = " << x << endl;// wypisane zmienne zachowują się zodnie z obecnymi flagami

        cout.setf(ios::scientific, ios::floatfield);//zalaczenie danej flai wewnątrz danego pola, pomaa uniknąć błędów kiedy flaisię wykluczają
        cout.unsetf(ios::showbase);// odłącza(sprawi, że przestaje obowiązywaćdanaflaa)
        cout << "3. m = " << m << ", x = " << x << endl;// wypisane zmienne zachowują się zodnie z obecnymi flagami

        cout.setf(ios::fixed, ios::floatfield);// kolejna zmianna w fieldzie, wszystko w celu unikania błędów
        cout.setf(ios::showbase | ios::uppercase);// odłąćzenie kilku fla jednocześnie
        cout << "4. m = " << m << ", x = " << x << endl;// wypisane zmienne zachowują się zodnie z obecnymi flagami

        cout.flags(oldf);
        cout << "5. m = " << m << ", x = " << x << endl;

        cout.flags(oldf); // przywracamy stara

        cout<<(cin.width())<<endl;// cin.with() -zwracaile elementów przygotowane jest przyjąć cin (0 oznaczaniezdefiniowanąilośc,przyjmie ilebędzie musiało)
        char napis[10];
        cin.width(sizeof(napis));// możnaustalić ile znaków cin maprzyjmowac
        cout<<(cin.width())<<endl;// i faktycznie zmienia to odczyt szerokości cin
        //cin >> napis;// jak i zachowanie cin, które nie przyjmie więcej znaków niż ma podane(w przypdaku tablicycharów pobierze tylko 9, bo ostatni znak to znak konńca)

        //w analogiczny sposób działają innne metody zdefiniowane dlaios
        // działają one dla wszystkich wszystkich klas zawartych w iostream więć mogą byćzastosowane na cin, cout,ifstream i nie tylko
        //do funkcji nalężą:
        cout<<(cin.precision())<<endl;//.precision()//zwraca obenie ustawioną precyzje
        (cout.precision(5));//.precision(streamsize prec)//zamienia precyzje na ustalonąi loścmiejscpo przecinku
        cout<<4.868667068<<endl;// wypisuje określoną ilość miejscpop rezcinku-1 - bo miejsce 0
        cout<<(cin.fill())<<endl;//.fill()// zwraca znak używany do wypełniania pustych pzestrzeni podczas wypisyawnia znaku ( domyślnie znak odstępu dlatego nic nie widać)
        (cout.fill('_'));//.fill(char znak)// pozwalago ustalić
        /*string a1;
        cin>>a1;
        cout<<a1<<endl;*/
        // nie wiem czemu nie działa

        std::cout<<"koniec flag"<<std::endl;
    }


    // manipulatory bezarumentowe
    {
        std::cout<<"poczatek manipulatorów"<<std::endl;

        // zmiany wprowadzone do streamów przezmanipulatory obowiążują ąz nie zostaną odczunione innym manipulatorem albo wywołać odpowiednią flaę na rzecz strumienia - TLDR, manipulatory to narzędzia dołatwiejszego idynamiczniejszego ustawiania flag w streamach

        /*
        hex, oct, dec — ustawiają podstawę wyprowadzanych liczb całkowitych, podobnie jak robią to funkcje setf(ios::hex,ios::basefield)
            itd. Zmiana jest trwała: aby przywrócić poprzednie ustawienia, trzeba do strumienia wstawić odpowiedni manipulator
        lub na rzecz strumienia wywołać jedną z metod zmieniających flagę stanu formatownia.
            left, right, internal — ustawiają sposób wyrównywania (justowania) wyprowadzanych
        danych, podobnie jak robią to poznane już przez nas wcześniej funkcje setf(ios::left,ios::adjustfield) itd.
        fixed, scientific — ustawiają formatowanie wyprowadzanych liczb zmiennopozycyjnych, podobnie jak robią to funkcje setf(ios::fixed,ios::floatfield) itd.
        showbase, noshowbase — podobne do wywołania setf(ios::showbase) lub setf(ios::noshowbase).
        showpoint, noshowpoint — podobne do wywołania setf(ios::showpoint) lub setf(ios::noshowpoint).
         */

        /*
        flush — powoduje opróżnienie strumienia wyjściowego.
        endl  — powoduje wysłanie do strumienia wyjściowego znaku końca linii i opróżnienie bufora związanego z tym strumieniem, czyli natychmiastowe wyprowadzenie
            znaków z bufora do miejsca przeznaczenia (na ekran, do pliku itd).
        ends — — powoduje wysłanie do strumienia wyjściowego znaku końca napisu, czyli znaku ’\0’.
        */

        int a = 0xdf, b = 0771, c = 123;

        cout << "dec (default): "
            << dec << a << " " << b << " " << c << endl;// ustawianie flagi cout na dec

        cout << "hex bez showbase: "
            << hex << a << " " << b << " " << c << endl;// ustawianie flagi cout na hex

        cout.setf(ios::showbase);// ustawienie showbasedo couta

        cout << "hex z showbase: "
            << a << " " << b << " " << c << endl;

        cout << "oct z showbase: "
            << oct << a << " " << b << " " << c << endl;// ustawianie flagi cout na oct

        cout.unsetf(ios::showbase);//zdjęcie flai showbase

        cout << "oct bez showbase: "
            << a << " " << b << " " << c << endl;

        // jest możliwe ustawianie w manipulatorach argumentów wływających tylko na najbliższe operacje

        string name;
        //cin>>setw(5)>>name;//przepuszczam pierwsze pięćznaków lokalinie ustawiaąjąc szerokość na 5, przestaje to obowiążycwać po pierwszym użyciu
        //cin>>setw(5)>>setfill('_')>>setprecision(9)>>name;//ustawione elementy obowiązują w do puki nie napotkają zmiennej naktórej sąrealizowane
        ios_base::fmtflags newf = ios::hex | ios::showbase | ios::showpoint;// flaga o nazwie newf zzałączonymi wymienonymi flagami
        //cin>>setiosflags(newf)>>resetiosflags(newf)>>name;
        //cin>>setbase(8)>>name;// ustawia system liczowy

        std::cout<<"koniec manipulatrów"<<std::endl;
    };

    // c - napisydaldsze rozwinięcie
    {
        std::cout<<"początek rozwinięciac napisów"<<std::endl;

        char s1[] = "Ulalalala";
        std::cout<<s1<<std::endl;// wypisanie tablicy chaów jako string
        std::cout<<strlen(s1)<<std::endl;//strlen(s) -  zwraca ilość elementów

        char s2[20] = "Ula";
        strcat(s2, s1);// strlcat dodaje do s2 s1 i zwraca zmienione s2
        //char s3[] = "Ulala";
        //strncat(s1, s3, 2);// dodaje do s1 pierwsze 2 chary ;
        //char s4=strcpy(s1, s1+7);

        strncpy(s2, s2, 5);// dodaje do s pierwsze 5 charów z s2

        if( strcmp(s1,s2))// zwracawynik porównainai leksykograficznego elementu s1 do s2
            std::cout<<"s1 jest leksykograficznie przed s2"<<std::endl;
        //strcoll(const char* s1, const char* s2) //- działa identycznie do strcmp tylko uzwględnia znaki nieangielskie ąęó...
        //strncmp(const char* s1, const char* s2, size_t n) //- działa identycznie do strcmp tylko sprawdzatylko określoną ilość znakó
        char *s3 = strchr(s2, 'a');//zwraca wskaźnik do pierwszego wystąpienia a w stringu
        char *s4 = strrchr(s2, 'a');//zwraca wskaźnik do ostatnieo wystąpienia a w stringu
        int i1 = strspn(s2,s1 );// zwraca dłuość najdłuższego fragmentu s2 skałdającego się wyłącznie ze znaków należących do s1
        int i2 = strcspn(s2,s1 );// zwraca dłuość najdłuższego fragmentu s2 skałdającego się wyłącznie ze znaków nienależących do s1
        char *s5 = strpbrk(s2, s1);//zwraca wskaźnik do pierwszego wystąpienia znkau zawateo w s1 wewnątrz s2
        char *s6 = strstr(s2, s2);//zwraca wskaźnik do ostatnieo wystąpienia znkau nie zawateo w s1 wewnątrz s2
        strtok(s2, s1);// ustawia s1 jako separator po którym funkcja rozkłada napis s2 na słowa

        std::cout<<"koniec rozwinięcia cnapisów"<<std::endl;
    }


    // operacje na znakach
    {
        char a1 ='a';
        //funkcje boolen
        std::cout<<(isalnum(a1)?"yes":"no")<<std::endl;// czy litera lub cyfra
        std::cout<<(isalpha(a1)?"yes":"no")<<std::endl;// czy litera
        std::cout<<(isdigit(a1)?"yes":"no")<<std::endl;// czy cyfra
        std::cout<<(isxdigit(a1)?"yes":"no")<<std::endl;// czy cyfrawsystemie szestastkowym
        std::cout<<(iscntrl(a1)?"yes":"no")<<std::endl;// czy znak kontrolny
        std::cout<<(isprint(a1)?"yes":"no")<<std::endl;// czy znak drukowany
        std::cout<<(isgraph(a1)?"yes":"no")<<std::endl;// czy znak widoczny
        std::cout<<(ispunct(a1)?"yes":"no")<<std::endl;// czy znak interpunkcyjny
        std::cout<<(isspace(a1)?"yes":"no")<<std::endl;// czy znak biały
        std::cout<<(isupper(a1)?"yes":"no")<<std::endl;// czy wielka litera
        std::cout<<(islower(a1)?"yes":"no")<<std::endl;// czy mała litera

        a1=toupper(a1); //zamień na wielką
        std::cout<<(isupper(a1)?"yes":"no")<<std::endl;// czy litera lub cyfra
        a1=tolower(a1);//zamineń na małą
        std::cout<<(isupper(a1)?"yes":"no")<<std::endl;// czy litera lub cyfra
    }


    // funkcje konwertujące
    {

        char* ptr;
        char* str ="12345a";

        double a=strtod(str,&ptr);// zwraca do a przekonwertowany na double str, ptr może byćzastąpione nullptr
        // istnieją inne funkcje teo typu
        //strtol(const char* str, char** ptr, int base) - string->long base to system liczbowy
        //strtoul(const char* str, char** ptr) - string-> unsined long
        //strtoul(const char* str, char** ptr, int base) - string-> unsined long
        //atof(const char* str) - string-> double
        //atoi(const char* str) - string(ascii) -> int
        //atol(const char* str) - string(ascii) -> long
    }


    // funkcje na strinach
    {
        std::cout<<"poczatek funkcji nastringach"<<std::endl;

        std::string s1="yfyuhidyu";
        std::cout<<(size(s1))<<std::endl;//zwraca długość
        std::cout<<(empty(s1))<<std::endl;//zwraca czy strin jestpusty
        std::cout<<(s1.at(3))<<std::endl;//4 char stringa
        //resize(size_type n, char c = ’\0’) - resize zmienia wielkość strina i ustawia muwybrany znak nakoońcu
        s1.clear();// czyści s1
        std::cout<<s1<<std::endl;
        s1="yfyuhidyu";
        std::cout<<( s1.substr(2, 5))<<std::endl;// zwraca podany wycinek stringa
        char s2[s1.size()];// tablicacharów
        s1.copy(s2, s1.size(), 0);// kopiuje s1.size znaków z s1 zaczynająć od pierwszeo(0) do s2

        string s3("Arles"), s4("Berlin");
        s3.swap(s4);//zmiana napisów
        cout << s3 << " " << s3 << endl;


        string s5("xxx"), s6("Zuzia");
        s5.assign(s6);// przypisanie s5  wartości s6
        s6.assign("Kasia");
        s5.assign(s1,2,5);// od elementu 2 wpisz 5 elementów
        s6.assign(s1, 5);// wpisz 5 elementó

        // pzypisuje zmiennej s1miejsce w pamięći s2
        /*
        string& assign(const string& wzor)
        string& assign(const char* wzor)
        string& assign(string wzor, size_type start, size_type ile)
        string& assign(const char* wzor, size_type ile)
        string& assign(size_type ile, char c)
        string& assign(const char* start, const char* kon)
         */


        string s7("mama"), s8("plastyka");
        const char* p1 = "temat";
        s7.insert(2,p1,2).insert(6,s2,4);// taki insert wpisuje do s1 2 chary od 2 elementu p1 i 4 chary od 6 elementu s2
        cout << s7 << endl;
        /*
        string& insert(size_type gdzie, const string* wzor)
        string& insert(size_type gdzie, const char* wzor)
        string& insert(size_type gdzie, string wzor, size_type start, size_type ile)
        string& insert(size_type gdzie, const char* wzor, size_type ile)
        string& insert(size_type gdzie, size_type ile, char c)
        */

        // append  dododaje na końcu napisuelement zwarcając do nieo referencje niżej syntax
        /*
        string& append(const char* wzor)
        string& append(const char* wzor, size_type ile)
        string& append(size_type ile, char c)
        string& append(const char* start, const char* kon)
        string& append(const string& wzor)
        string& append(const string& wzor, size_type start, size_type ile)
        */

        // erase  usówa podane framenty tekstu
        string s9("0123456789");
        string::iterator it = s9.erase(s9.begin()+3,s9.end()-3);// uśówa wszystkopoza pierwszymi i ostatnimi trzema wyrazamni
        cout << s9 << " " << *it << endl;
        /*
        string& erase(size_type start = 0, size_type ile = npos)
        iterator erase(iterator start)
        iterator erase(iterator start, iterator kon)
        */

        // usówa wskazane framenty napisu i zastępuje je podanymi
        string s10("0123456789");
        const char* p2("abcdef");
        s10.replace(0,2,p2,2).replace(s10.end()-2,s10.end(),p2+4,p2+6);// wypełnia elementy od 0 do 2 pierwszymi charami z p od 2 charu do skończenia się miejsca
            // p po czym wypełnia ostatnie dwa elementy nawet nie wiem czym i natym etapie nie chce mi się sprawdzać
        cout << s10 << endl;
        /*
        string& replace(size_type start, size_type ile, const string& wzor)
        string& replace(size_type start, size_type ile, const string& wzor, size_type s,size_type i)
        string& replace(size_type start, size_type ile, const char* wzor, size_type i)
        string& replace(size_type start, size_type ile, const char* wzor)
        string& replace(size_type start, size_type ile, size_type i, char c)
        string& replace(iterator start, iterator kon, const string& wzor)
        string& replace(iterator start, iterator kon, const char* wzor)
        string& replace(iterator start, iterator kon, const char* wzor, size_type i)
        string& replace(iterator start, iterator kon, size_type i, char c)
        string& replace(iterator start, iterator kon, const char* st1, const char* kn1)
        */


        // szuka
        string s11("abc345abcAB");
        const char* p3("abcdef");
        string::size_type ii = s11.find(p3,3,2);//zwracają pozycje pierwszeo znaku spełniającego wymagania
        cout << s11.substr(ii-1,5) << endl;
        /*
        ize_type find(const string* s, size_type start = 0)
        size_type find(const char* p, size_type start = 0)
        size_type find(const char* p, size_type start, size_type ile)
        size_type find(char c, size_type start = 0)
        size_type rfind(const string* s, size_type start = npos)
        size_type rfind(const char* p, size_type start = npos)
        size_type rfind(const char* p, size_type start, size_type ile)
        size_type rfind(char c, size_type start = npos)
        */

        // compare pozwal porównywać stringi
        /*
        int compare(const string& wzor)
        int compare(size_type start, size_type ile, const string& wzor)
        int compare(size_type start, size_type ile, const string& wzor,size_type s, size_type ile1)
        int compare(const char* p)
        int compare(size_type start, size_type ile, const char* p, size_type i = npos)
        */

        //push_back(char c) - wstawia c nakoniec napisu
        //char* c_str( ) -zwraca wskaźnik do dostałego c napisu złożonego ze znaków napisu na rzecz którego jest wywołana
        //begin( ) - wskaźnik do pierwszeo charu stinga
        //end( ) - wskąnik do ostatniego charu strina
        //reverse_iterator rbegin( )
        //reverse_iterator rend( ) - zwracają odwrotny iterator, pozwalający odczytać wyraz
        string s12("korab");
        string s13(s1.rbegin(),s1.rend());// zwraca barok

        std::cout<<"koniec funkcji na strinach"<<std::endl;
    }


    // try catch
    {
        std::cout<<"pocczątek try catch"<<std::endl;

        set_terminate(&termin); // set_terminate to ustawienie ostatniej deski ratunku przed błędem wygenerowanym przez którąś funkcji który nie jest obsługiwany przez nic
        //set_terminate wksazuje na funkcje ktora ma być wywołana jeżeli nastąpi błą który nie jest obsługiwany przez jakąkolwiek innączęść programu

        double z, x;

        x = 16;
        z = Sqrt(x);
        cout << "Sqrt(" << x << ")=" << z << endl;

        //jeżęli odblokujesz to nastąpi nieobsługiwany błąd i zadziała funkca ustawiona w set_terminate termin
        //x = -16;
        z = Sqrt(x);
        cout << "Sqrt(" << x << ")=" << z << endl;

        // nic się nie wyświetli jezęli błąd nastąpi
        cout<<"koniec"<<endl;

        // w try { } zawiera sie fragment kodu który próbujesz wykonać, ale w którym może nastąpić błąd
        try
        {
            //jeżeli zmienisz age na coś powyżej 15 wszystko zadzaiła
            int age = 15;
            if (age >= 18)
            {
                cout << "Access granted - you are old enough.";
            } else
            {
                //rzyca wyjątek(w formie int)
                throw (age);
            }
        }

            //łapie wyjątki które są initegereami
            // typ błędu może być dowlny w tym customowy(może być na przykład klasy Osoba)
            //catch obsługuje wyjątki bez kończenia programu
            //catch() { } zawiera kod który ma być wykonany w przypadku przechwycenia błędu
        catch (int myNum)
        {
            cout << "Access denied - You must be at least 18 years old.\n";
            cout << "Age is: " << myNum;
        }

        try {
            int age = 15;
            if (age >= 18) {
                cout << "Access granted - you are old enough.";
            } else {
                throw 505;
            }
        }
            // catch (...) przechwytuje wszystkie typy błędów
        catch (...)
        {
            cout << "Access denied - You must be at least 18 years old.\n";
        }


        try
        {
            throw 5;
        }
        //można mieć więcej niż jeden catch i wtedy uruchomi się tym pasujący
        catch(double) { cout << "double" << endl; }
        catch(int) { cout << "int" << endl; }


        try
        {
            //możesz odkomentować kolejne fragmenty generujące błędy i zobaczyć który z catchy je obsługuje

            //funkcja do zapychania pamięci
            //bad aloc - zła alokacja, nie wiem gdzie to w cisnąć(ważne przy programach które zapychają się danymi)
            /*while (true)
            {
                new int[100000000ul];
            }*/


            //generowanie błędu nieprawidłowego castu
            //bad_cast - nieprawidłowe urzycie castowania
            /*Base gfg;
            Derived& rd = dynamic_cast<Derived&>(gfg);*/

            //generowanie błędu poprzez próbe pobrania danych ze wskaźnika który prowadzi do nikąd
            //bad_typeid -nie może znaleźć id
            /*Ka* k = NULL;
            cout << typeid(*k).name() << endl; */

            //nie chce mi się tego robić(tego nawet nie ma w 600 stronicowym pdfie)
            //generalna koncepcja jeżeli stworzysz funkcje i zapowiesz w niej throw(bad_exeption)
            //to każdy errror w tej funkcji jest wyrzucany jako bad exeption
            /*void fun() throw(bad_exception)
            {
                throw runtime_error("test");
            }
             **wyrzuca bad exption przy wywołaniu zamiast runtime_error**
             */


            //nie umiałem niczego znaleźć na ios::failure i mi się coraz mniej chce


            throw runtime_error("shit don't work");

        }
        catch(bad_alloc){cout<<"bad_alloc"<<endl;}
        catch(bad_cast){cout<<"bad_cast"<<endl;}
        catch(bad_typeid){cout<<"bad_typeid"<<endl;}
        catch(bad_exception){cout<<"bad_exception"<<endl;}
        catch(ios::failure){cout<<"ios::failure"<<endl;}
        catch (runtime_error& e)
        //trzeba pamiętać rze każy typ błędu można wyraźić w zmiennej patrz przykład
        {cout << "Exception occurred" << endl << e.what();}

        std::cout<<"koniec try catch"<<std::endl;
    }


    // customowe namespacy
    {
        std::cout<<"początek namespaców"<<std::endl;

        //więcej o namesacach w miejscu gdzie są zadeklarowane
        // usigng nazwanamespaca::funkcja powduje, że wywołanie tej funkcji bez namespaca spowoduje wywoałanie funkcjiz tego namespaca
        using nA::write;

        // using namespace nC powoduje, że zmienne w nC są dostępne bez odwoływania siębezpośrednio do tego namespace
        using namespace nC;

        //write z nA
        write();

        //write z nB
        nB::write();

        //six z nC
        cout << six << endl;

        std::cout<<"koniec namespaców"<<std::endl;
    }


    // iteratory(podobne do pętli)
    {
        std::cout<<"początek iteratorów"<<std::endl;

        vector<string> vs{"Ola", "Ula", "Ela","Ala"};

        for
        (
            vector<string>::iterator // vector<string>::iterator wywołanie iteratora dla elementów o bazie stringa
            ite = vs.begin(); // pierwszy element ustawiony na pierwszy element vectora
            ite!= vs.end(); // warunek iteracji
            ++ite // zmiany
        )
            //wypisanie wartości elementów vektora
            cout << *ite << " ";
        cout << endl;


        //lepsza wersja
        vector<string>::iterator it, kon = vs.end();
        // ustawienie zmiennej elemntu iteratora jako zmiennej faktycznie zminianej

        // ustawienie it wartości wykonywane aż osiągnie wartość kon
        for ( it = vs.begin(); it != kon; ++it )
            cout << *it << " ";
        cout << endl;


        //jeszcze lepsza wersja
        using SIT=vector<string>::iterator;

        SIT iter, koniec = vs.end();
        // ustawienie zmiennych iteratora i końca elementu iterowanego

        for ( iter = vs.begin(); iter != koniec; ++iter )
            cout << *iter << " ";
        cout << endl;


        //najlepsza wersja, bardziej elastyczna
        for ( auto i = vs.begin(); i != vs.end(); ++i )
            cout << *i << " ";
        cout << endl;

        std::cout<<"koniec iteratorów"<<std::endl;
    }


    // dodatkowe przydatne funkcje i reszt arzeczy które nie wiem gdzie wrzucić
    {
        std::cout<<"początek lokalizacja systemu operacyjnego"<<std::endl;

        // można używać operacji preprocesorówych wewnątrz maina i to dizała
        //tak się rozpoznaje system operacyjny
        #if defined(__WIN32)
            cout << "Windows:\n";
        #elif defined(__linux)
            cout << "Linux:\n";
        #else
            #error Nieznany system
        #endif

        std::cout<<"koniec lokalizacji systemu operacyjnego"<<std::endl;
    }


    // Mapy pozwalają trzymać zmienne pod customowymi, liczbami, kodami itp
    {
        std::cout<<"początek map"<<std::endl;

        // tworzenie pustej mapy przechowującej inty ropoznawanej intami
        //warto pamięctać, że int może byćzastąpiony czymkoliwek innym
        map<int, int> gquiz1;

        // wstawienie par elementó do mapy para dwóch intów<int,int> (_,_)
        gquiz1.insert(pair<int, int>(1, 40));
        gquiz1.insert(pair<int, int>(2, 30));
        gquiz1.insert(pair<int, int>(3, 60));
        gquiz1.insert(pair<int, int>(4, 20));
        gquiz1.insert(pair<int, int>(5, 50));
        gquiz1.insert(pair<int, int>(6, 50));

        // można też wstawiać tak
        gquiz1[7]=10;


        // tworzenia iteratora mapy
        map<int, int>::iterator itr;

        cout << "\nThe map gquiz1 is : \n";
        cout << "\tKEY\tELEMENT\n";

        //iterowanie po mapie
        for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
        {
            cout << '\t'
                 << itr->first // pobieranie klucza
                 << '\t'
                 << itr->second // pobieranie wartości
                 << '\n';
        }
        cout << endl;

        // kopiowanie wartości z mapy do innej mapy poprzez podanie pierwszego i ostaniego elementu(można to smao zrobićjedynie z wycinkiem)
        map<int, int> gquiz2 ( gquiz1.begin(), gquiz1.end());

        // wypisanie elementów dugiej mapy
        cout << "\nThe map gquiz2 after"
             << " assign from gquiz1 is : \n";
        cout << "\tKEY\tELEMENT\n";

        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
        {
            cout << '\t'
                 << itr->first
                 << '\t'
                 << itr->second
                 << '\n';
        }
        cout << endl;
        // to samo co w pierwszej mapie

        // pozbycie się elementów do klucza = 3
        cout << "\ngquiz2 after removal of"
                " elements less than key=3 : \n";
        cout << "\tKEY\tELEMENT\n";
        //.erase pozbywa się elementów z podanego zakresu
        gquiz2.erase(gquiz2.begin(), gquiz2.find(3));

        //wuypisywanie
        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
        {
            cout << '\t' << itr->first << '\t' << itr->second
                 << '\n';
        }

        // remove all elements with key = 4
        int num;
        num = gquiz2.erase(4);
        cout << "\ngquiz2.erase(4) : ";
        cout << num << " removed \n";
        cout << "\tKEY\tELEMENT\n";
        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
            cout << '\t' << itr->first << '\t' << itr->second
                 << '\n';
        }

        cout << endl;

        // lower bound and upper bound for map gquiz1 key = 5
        cout << "gquiz1.lower_bound(5) : "
             << "\tKEY = ";
        cout << gquiz1.lower_bound(5)->first << '\t';
        cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second
             << endl;
        cout << "gquiz1.upper_bound(5) : "
             << "\tKEY = ";
        cout << gquiz1.upper_bound(5)->first << '\t';
        cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second
             << endl;

        std::cout<<"koniec map"<<std::endl;
    }

    //Algorytmy , jest ich za dużo aby robić przykłady i można to doczytać
    //tu jest lista wszytskich
    {
        std::cout<<"początek algorytmów"<<std::endl;

        /*
        all_of, any_of, none_of (C++11) checks if a predicate is true for all, any or none
        of the elements in a range
        for_each applies a function to a range of elements
        for_each_n (C++17) applies a function object to the first n elements of a sequence
        countcount_if returns the number of elements satisfying specific criteria
        mismatch finds the first position where two ranges differ
        find, find_if, find_if_not (C++11) finds the first element satisfying specific criteria
        find_end finds the last sequence of elements in a certain range
        find_first_of searches for any one of a set of elements
        adjacent_find finds the first two adjacent items that are equal (or satisfy a given
        predicate)
        search searches for a range of elements
        search_n searches a range for a number of consecutive copies of an element
        *** Modifying sequence operations — header algorithm
        copy, copy_if (C++11) copies a range of elements to a new location
        copy_n (C++11) copies a number of elements to a new location
        copy_backward copies a range of elements in backwards order
        move (C++11) moves a range of elements to a new location
        move_backward (C++11) moves a range of elements to a new location in backwards
        order
        fill copy-assigns the given value to every element in a range
        fill_n copy-assigns the given value to N elements in a range
        transform applies a function to a range of elements
        generate assigns the results of successive function calls to every element in a range
        generate_n assigns the results of successive function calls to N elements in a range
        remove, remove_if removes elements satisfying specific criteria
        remove_copy, remove_copy_if copies a range of elements omitting those that satisfy specific criteria
        replace, replace_if replaces all values satisfying specific criteria with another value
        replace_copy, replace_copy_if copies a range, replacing elements satisfying specific
        criteria with another value
        swap swaps the values of two objects
        swap_ranges swaps two ranges of elements
        iter_swap swaps the elements pointed to by two iterators
        reverse reverses the order of elements in a range
        reverse_copy creates a copy of a range that is reversed
        rotate rotates the order of elements in a range
        rotate_copy copies and rotate a range of elements
        shift_left, shift_right (C++20) shifts elements in a range
        shuffle (C++11) randomly re-orders elements in a range
        sample (C++17) selects n random elements from a sequence
        unique removes consecutive duplicate elements in a range
        unique_copy creates a copy of some range of elements that contains no consecutive
        duplicates
        *** Partitioning operations — header algorithm
        is_partitioned (C++11) determines if the range is partitioned by the given predicate
        partition divides a range of elements into two groups
        partition_copy (C++11) copies a range dividing the elements into two groups
        stable_partition divides elements into two groups while preserving their relative order
        partition_point (C++11) locates the partition point of a partitioned range
        *** Sorting operations — header algorithm
        is_sorted (C++11) checks whether a range is sorted into ascending order
        is_sorted_until (C++11) finds the largest sorted subrange
        sort sorts a range into ascending order
        partial_sort sorts the first N elements of a range
        partial_sort_copy copies and partially sorts a range of elements
        stable_sort sorts a range of elements while preserving order between equal elements
        nth_element partially sorts the given range making sure that it is partitioned by the
        given element
        *** Binary search operations on sorted ranges — header algorithm
        lower_bound returns an iterator to the first element not less than the given value
        upper_bound returns an iterator to the first element greater than a certain value
        binary_search determines if an element exists in a certain range
        equal_range returns range of elements matching a specific key
        *** Other operations on sorted ranges — header algorithm
        merge merges two sorted ranges
        inplace_merge merges two ordered ranges in-place
        *** Set operations on sorted ranges — header algorithm
        includes returns true if one set is a subset of another
        set_difference computes the difference between two sets
        set_intersection computes the intersection of two sets
        set_symmetric_difference computes the symmetric difference between two sets
        set_union computes the union of two sets
        *** Heap operations — header algorithm
        is_heap (C++11) checks if the given range is a max heap
        is_heap_until (C++11) finds the largest subrange that is a max heap
        make_heap creates a max heap out of a range of elements
        push_heap adds an element to a max heap
        pop_heap removes the largest element from a max heap
        sort_heap turns a max heap into a range of elements sorted in ascending order
        *** Minimum/maximum operations — header algorithm
        max returns the greater of the given values
        max_element returns the largest element in a range
        min returns the smaller of the given values
        min_element returns the smallest element in a range
        minmax (C++11) returns the smaller and larger of two elements
        minmax_element (C++11) returns the smallest and the largest elements in a range
        clamp (C++17) clamps a value between a pair of boundary values
        *** Comparison operations — header algorithm
        equal determines if two sets of elements are the same
        lexicographical_compare returns true if one range is lexicographically less than another
        compare_3way (C++20) compares two values using three-way comparison
        lexicographical_compare_3way (C++20) compares two ranges using three-way comparison
        *** Permutation operations — header algorithm
        is_permutation (C++11) determines if a sequence is a permutation of another sequence
        next_permutation generates the next greater lexicographic permutation of a range
        of elements
        prev_permutation generates the next smaller lexicographic permutation of a range
        of elements
        *** Numeric operations — header numeric
        iota (C++11) fills a range with successive increments of the starting value
        accumulate sums up a range of elements
        inner_product computes the inner product of two ranges of elements
        adjacent_difference computes the differences between adjacent elements in a range
        partial_sum computes the partial sum of a range of elements
        reduce (C++17) similar to std::accumulate, except out of order
        exclusive_scan (C++17) similar to std::partial_sum, excludes the ith input element
        from the ith sum
        inclusive_scan (C++17) similar to std::partial_sum, includes the ith input element
        in the ith sum
        transform_reduce (C++17) applies a functor, then reduces out of order
        transform_exclusive_scan (C++17) applies a functor, then calculates exclusive scan
        transform_inclusive_scan (C++17) applies a functor, then calculates inclusive scan
        *** Operations on uninitialized memory — header memory
        uninitialized_copy copies a range of objects to an uninitialized area of memory
        uninitialized_copy_n (C++11) copies a number of objects to an uninitialized area
        of memory
        uninitialized_fill copies an object to an uninitialized area of memory, defined by a
        range
        uninitialized_fill_n copies an object to an uninitialized area of memory, defined by
        a start and a count
        uninitialized_move (C++17) moves a range of objects to an uninitialized area of
        memory
        uninitialized_move_n (C++17) moves a number of objects to an uninitialized area
        of memory
        uninitialized_default_construct (C++17) constructs objects by default-initialization
        in an uninitialized area of memory, defined by a range
        uninitialized_default_construct_n (C++17) constructs objects by default-initialization
        in an uninitialized area of memory, defined by a start and a count
        uninitialized_value_construct (C++17) constructs objects by value-initialization in
        an uninitialized area of memory, defined by a range
        uninitialized_value_construct_n (C++17) constructs objects by value-initialization
        in an uninitialized area of memory, defined by a start and a count
        destroy_at (C++17) destroys an object at a given address
        destroy (C++17) destroys a range of objects
        destroy_n (C++17) destroys a number of objects in a range
        */
        int arr[] = {1,2,3};
        cout<<max_element(arr,arr+2)<<endl; // jak widać wybiera największy element z podanego zbioru
        // tak samo działa każdy z tych algorytmów, a mnie nie chce się każdego z nich rozpisywać, masz je powyżej skopiój je sobie i teórz własne przyjkłady

        std::cout<<"koniec algorytmów"<<std::endl;
    }


    //Operator typeid
    {
        // ...
        double x = 1.5;
        // ...
        //tak pozyskuje sięi sprawdza typeid
        if (typeid(x) == typeid(double)) cout<<"1 true"<<endl; // true
        if (typeid(x) == typeid(36.0)) cout<<"2 true"<<endl; // true
        if (typeid(x) == typeid(3)) cout<<"3 true"<<endl; // false
        if (typeid(x) != typeid(3)) cout<<"4 true"<<endl; // true
        if (typeid(x) != typeid(int)) cout<<"5 true"<<endl; // true

        cout<<endl<<typeid(x).name()<<endl;// at tak można uzyskać nazwe typuid w tym przypadku d nie wiem dlaczego
    }


    //exity
    {
        int x = 1;
        if (x < 1)
            exit(1); // exit (!=0) to kod błędu, i możnago zwróćicć manualnie
        exit(0);// exit(0) - kończy program wynikiem pozytywnym
    }


}// - koniec funkcji main

//warto zaznaczyć na końcu 579 stronicowego dokumentu jest precyzyjniejszy spis treści o szukania bardzo konkretnych rzeczy i jestem sie w stanie założyć, że nikt z to czytających go jescze ni wiedział

//to kompendium NIE ZAWIERA całej wiedzy z 589 stron udostępnionych przez Wernera, to skondensowana wersja pokazująca narzędzia tam przedstawione i pomijające wszytsko inne

/*
*, zob. operator wyłuskania wartości
++, zob. operator zwiększenia
::, zob. operator zasięgu
_WIN32, 21
__linux__, 21
|, zob. operator alternatywy bitowej
||, zob. operator alternatywy logicznej
~, zob. operator negacji bitowej
!, zob. operator negacji logicznej
&, zob. odnośnik
        & (op. binarny), zob. operator koniunkcji bitowej
& (op. unarny), zob. operator wyłuskania adresu
&&, zob. operator koniunkcji logicznej
--, zob. operator zmniejszenia
«, zob. operator wstawiania do strumienia
», zob. operator wstawiania do strumienia
^, zob. operator różnicy symetrycznej
abort, 488
acc.cpp (plik), 265
accout.cpp (plik), 270
Ada, zob. języki programowania
adhocforeach.cpp (plik), 115
adjustfield, 326
ADL, 308
aggreg.cpp (plik), 281
agregat, 280
agrtab.cpp (plik), 283
algorytm, 525
Euklidesa, 174
modyfikujący, 532
niemodyfikujący, 532
sortowania przez wstawianie, 218,
247
sortujący, 526
alignment, zob. wyrównanie
allo.cpp (plik), 214
Anjuta, 4
app (tryb otwarcia), 341
append, 372
argument
domyślny, 161
wywołania, 15
argument funkcji, 159
domyślny, 161, 269, 274
referencyjny, 167
argument wywołania, zob. argument
argumenty.cpp (plik), 16
arr3dim.cpp (plik), 415
array, 114
Arrays.cpp (plik), 67
arytmwsk.cpp (plik), 55
ASCII, 31, 33, 58, 149
assert, 188, 258
assign, 370
at, 369, 516
at.cpp (plik), 516
ate (tryb otwarcia), 341
atof, 364
atoi, 364
atol, 364
atomowa zmienna, 88
auto, zob. zmienna automatyczna, 28
autodecl.cpp (plik), 28
autoret.cpp (plik), 207
back, 518
back_inserter, 527
backins.cpp (plik), 527
bad, 345
bad_alloc, 214, 499
bad_cast, 499
bad_exception, 499
bad_typeid, 499
badbit, 345
basefield, 326
bash, 489
begin, 374, 518
big endian, 57
big-endian, 344
binary (tryb otwarcia), 341
binding, zob. wiązanie
        bitColors.cpp (plik), 134
bits.cpp (plik), 132
blok, 102
bool, 34
boolalpha, 327
brace-init, 26
break, zob. instrukcja zaniechania
byte-code, zob. kod bajtowy
.C, 7, 502
.c, 7, 21
C++11, 26, 36, 50, 93, 157, 167, 189,
193, 237, 306
C++11 standard, 38
C-napis, zob. napis w stylu C
c_str, 374
calloc, 226
CamelCase, 80
cast.cpp (plik), 453
catch, zob. instrukcja obsługi wyjątku,
118, 489
cctype, 359
cerr, 323
cerrno, 361
char, zob. typy danych, 29
char16_t, 29
char32_t, 29
cin, 11, 12, 322, 323
ciąg Fibonacciego, 175, 197
class, 200
classtab.cpp (plik), 284
clear, 345, 369
clog, 323
Code::Blocks, 4
CodeWarrior, 4
compare, 374
compr.cpp (plik), 532
concast.cpp (plik), 443
condes.cpp (plik), 459
confiel.cpp (plik), 311
const, zob. zmienna ustalona, 50, 88
const_cast, 442
const_iterator, 519
const_reverse_iterator, 521
constexpr, 50, 93
constexpr.cpp (plik), 93
constit.cpp (plik), 519
constmet.cpp (plik), 289
continue, zob. instrukcja kontynuowania
convfrom.cpp (plik), 440
convto.cpp (plik), 436
cop.cpp (plik), 456
copy, 369
copy_if, 527
count_if, 529, 543
cout, 11, 322, 323
.cpp, 7, 502
cstdlib, 226, 361
cstring, 227, 354
cstru.cpp (plik), 236
cvscpp.c (plik), 20
.cxx, 502
czas.cpp (plik), 238
czyt.cpp (plik), 13
czytab.cpp (plik), 66
czytnf.cpp (plik), 338
dataczas.cpp (plik), 23
__DATE__, 23
dec, 326
dec (manipulator), 331
decltype, 28
#define, 18
defined, 19
definicja, 79
definicja funkcji, 157
dekl.cpp (plik), 73
dekl1.cpp (plik), 31
deklaracja, 79, 100
deklaracja funkcji, 154
deklaracja użycia, 507
deklaracja zapowiadająca, 247
dekrementacja, zob. operator zmniejszenia
        delegconstr.cpp (plik), 306
delegowanie (konstruktora), 306
delete, 215, 216
deleter, 427
delunique.cpp (plik), 427
deque, 522
dereferencja, zob. operator wyłuskania
        wartości
destruktor, 275
wirtualny, 480
wyjątki w destruktorze, 497
dist.cpp (plik), 523
distance, 523
.dll, 505
do, zob. instrukcja iteracyjna, 110
do-while, 110
dopasowanie
        dokładne, 180
po konwersji niejawnej, 181
po konwersji trywialnej, 180
po konwersji zdefiniowanej przez
użytkownika, 181
po promocji, 181
double, zob. typy danych
dynamic_cast, 444, 499, 552
dyncast.cpp (plik), 445
dyrektywa użycia, 507
dyrektywy preprocesora, 17
#define, 18
defined, 19
#elif, 20
#else, 20
#endif, 20
#error, 22
#if, 20
#ifdef, 20
#ifndef, 20
#include, 8, 18, 502
#undefine, 18
dziedziczenie, 447
dżoker, 4
early binding, zob. wiązanie, wczesne
Eclipse, 4
#elif, 20
else, zob. instrukcja warunkowa
#else, 20
emplace_back, 516
empty, 369
emulstr.cpp (plik), 359
end, 374, 518
#endif, 20
endl, 11
endl (manipulator), 331
ends (manipulator), 331
enum, 35
enumeracja, zob. wyliczenia
enumeration, zob. wyliczenia
enums.cpp (plik), 37
EOF, 336
eof, 345
eofbit, 345
epoka, 237
erase, 372, 524, 540
errno, 361
#error, 22
etykieta, 99
Euklides, 174
exceptions, 499
excpt.cpp (plik), 490
executable, zob. plik wykonywalny
exit, 489
explicit, 436
exter1.cpp (plik), 86
exter2.cpp (plik), 86
extern, zob. zmienna zewnętrzna
fail, 345
failbit, 345
false, 34
fib.cpp (plik), 175
Fibonacci, zob. ciąg Fibonacciego, 197
figur.cpp (plik), 470
__FILE__, 23
fill, 330
find, 373, 530
find_first_not_of, 373
find_first_of, 373
find_if, 530
find_last_not_of, 373
find_last_of, 373
fixed, 326
fixed (manipulator), 331
flaga
adjustfield, 326
basefield, 326
boolalpha, 327
dec, 326
fixed, 326
floatfield, 326
hex, 326
internal, 326
left, 326
noboolalpha, 327
noshowbase, 327
noshowpoint, 327
noshowpos, 327
noskipws, 326
nounitbuf, 327
nouppercace, 327
oct, 326
right, 326
scientific, 326
showbase, 327
showpoint, 327
showpos, 327
skipws, 326
unitbuf, 327
uppercace, 327
flagi formatowania, zob. formatowanie
flags, 327
flags.cpp (plik), 328
float, zob. typy danych
floatfield, 326
flush (manipulator), 331
fmtflags, 326
for, zob. instrukcja iteracyjna, 111
for_each, 532
foreach.cpp (plik), 114
formatowanie, 324, 325
flaga stanu, 326
Fortran, zob. języki programowania
free, 227
front, 518, 525
front_inserter, 528
fstream, 322, 340
ftime, 237
__FUNCTION__, 23
function
merge, 527
remove, 527
reverse, 527
function.cpp (plik), 160
fundefnew.cpp (plik), 158
funk.cpp (plik), 14
funkcja, 14, 153
abort, 488
alternatywna postać deklaracji, 158
append, 372
argument, 159
assert, 188
assign, 370
at, 369, 516
atan, 186
atof, 364
atoi, 364
atol, 364
back, 518
back_inserter, 527
begin, 374, 518
bezrezultatowa, 156
c_str, 374
calloc, 226
clear, 345, 369
compare, 374
copy, 369
copy_if, 527
count_if, 529, 543
definicja, 157
deklaracja, 154
distance, 523
emplace_back, 516
empty, 369
end, 374, 518
erase, 372, 524, 540
exceptions, 499
exit, 489
fill, 330
find, 373, 530
find_first_not_of, 373
find_first_of, 373
find_if, 530
find_last_not_of, 373
find_last_of, 373
flags, 327
for_each, 532
free, 227
front, 518, 525
front_inserter, 528
ftime, 237
gcount, 337
get, 336
getline, 337, 374
globalna, 9, 153
ignore, 337
insert, 371, 525
inserter, 528
isalnum, 360
isalpha, 360
iscntrl, 360
isdigit, 360
isgraph, 360
islower, 360
isprint, 360
ispunct, 360
isspace, 360
isupper, 360
isxdigit, 360
konwertująca, 361
lambda, 193
length, 369
main, 8, 9
make_shared, 433
make_unique, 428
malloc, 226
max_element, 539
memchr, 228
memcmp, 228
memcpy, 227
memmove, 228
memset, 228
metoda, 269
min_element, 539
nagłówek, 156
o zmiennej liczbie argumentów, 164
operująca na C-napisach, 354
otwarta, 177
parametr formalny, 156
peek, 338
pop_back, 518
pop_front, 525
precision, 330
prototyp, 154
przeciążona, 179, 275
push_back, 374, 516
push_front, 525
put, 339
putback, 338
rand, 110
rbegin, 374, 521
rdstate, 345
read, 337
realloc, 227
rekurencyjna, 174
release, 429
remove_if, 540
rend, 374, 521
replace, 372
reset, 430
resize, 369
rezultatowa, 156
rfind, 373
rozwijana, 157, 177, 269
seekg, 341
seekp, 341
set_terminate, 488
setf, 328
setstate, 345
size, 369, 517
sort, 527, 540
srand, 110
statyczna, 177, 273
str, 349
strcat, 354
strchr, 356
strcmp, 355
strcoll, 356
strcpy, 354
strcspn, 357
strlen, 354
strncat, 354
strncmp, 356
strncpy, 355
strpbrk, 357
strrchr, 357
strspn, 357
strstr, 357
strtod, 361
strtok, 357
strtol, 363
strtoul, 364
substr, 369
swap, 370
sygnatura, 157, 179
szablon, 199
tellg, 341
tellp, 341
terminate, 488
tolower, 360
toupper, 360
unget, 338
unsetf, 328
what, 499
width, 329
wklejana, 177
write, 339
wywołanie, 15, 159
z argumentami domyślnymi, 161
zamknięta, 178
zaprzyjaźniona, 307
funkcja otwarta, zob. funkcja rozwijana
funret.cpp (plik), 191
gcd.cpp (plik), 174
gcount, 337
Geany, 4
get, 336
getline, 337, 374
globalna funkcja, 153
good, 345
goodbit, 345
goto, zob. instrukcja skoku, 117
.h, 7, 502
helloWorld.cpp (plik), 7
hex, 326
hex (manipulator), 331
hex.cpp (plik), 108
hier.cpp (plik), 493
hier1.cpp (plik), 494
hierob.cpp (plik), 493
HUGE_VAL, 362
if, zob. instrukcja warunkowa
#if, 20
#ifdef, 20
#ifndef, 20
ifstream, 322, 340
ignore, 337
in (tryb otwarcia), 341
#include, 8, 18, 502
indeksowanie, 123
inf, 362
info, 4
inh.cpp (plik), 463
inhas.cpp (plik), 461
inher.cpp (plik), 450
iniagg.cpp (plik), 282
inicjalizacja, 26
inkrementacja, zob. operator zwiększenia
inline, zob. funkcja rozwijana
input iterator, 522
insert, 371, 525
inserter, 528
instrukcja, 99
catch, 118
do-while, 110
for, 111
goto, 117
grupująca, 101
iteracyjna, 109
kontynuacji, 115
obsługi wyjątku, 118
powrotu, 109, 118
pusta, 101
skoku, 99, 109, 117
throw, 118
try, 118
typedef, 186
warunkowa, 103
while, 109
wyboru, 106
wyrażeniowa, 102
zaniechania, 100, 106, 109
złożona, 10
int, zob. typy danych, 29
int16_t, 33
int32_t, 33
int64_t, 33
int8_t, 33
inteligentny wskaźnik, 426
internal, 326
internal (manipulator), 331
intfilo.cpp (plik), 348
intstr.cpp (plik), 350
ios, 326
ios::failure, 499
ios_base, 326
iostream, 322
isalnum, 360
isalpha, 360
iscntrl, 360
isdigit, 360
isgraph, 360
islower, 360
isprint, 360
ispunct, 360
isspace, 360
istream, 12, 322
istringstream, 322, 349
istrstream, 322, 347
isupper, 360
iswew.cpp (plik), 309
isxdigit, 360
iter.cpp (plik), 518
iterator, 366, 518
dwukierunkowy, 522
jednokierunkowy, 522
o dostępie bezpośrednim, 522
odwrotny, 520
ustalony, 521
ustalony, 519
wejściowy, 522
wyjściowy, 522
jan.cpp (plik), 12
jednolita inicjalizacja, 26
jednostka translacji, 501
języki programowania
Ada, 1, 14
C#, 383, 447
Fortran, 1, 14, 59, 60, 157, 213
Haskell, 383
Java, 1, 7, 8, 25, 29, 43, 45, 51,
100, 103, 104, 116, 123, 129,
131, 132, 151, 153, 171, 209,
210, 214, 233, 261, 262, 279,
283, 314, 367, 383, 385, 442,
447, 448, 451, 468, 470, 473,
485, 487, 515
Lisp, 209
Pascal, 1, 25, 157
PHP, 7
Python, 14, 158, 209, 214, 271,
383, 468, 487
Smalltalk, 209
KDevelop, 4
Kernighan, B., 7
klasa, 261
abstrakcyjna, 473
bazowa, 447
domieszkowa, 485
konkretna, 473
lokalna, 316
otaczająca, 314
pierwotna, 447
pierwszorzędowa, 261
pochodna, 447
pole, 266
statyczne, 266
polimorficzna, 468
sekcje, 262
składowa, 261
szablon, 377
zagnieżdżona, 314
zasięg, 264, 267
klasa pamięci, 83
klawew.cpp (plik), 314
kod bajtowy, 1
kod uzupełnień do dwóch, 30
Koenig lookup, 308
Koenig, A., 308
kolejka dwustronna, 522
kolekcja, 515
komparator, 528
konkatenacja, 354
konkretyzacja, 200
konsolidator, zob. linker
konstruktor, 274
delegujący, 306
domyślny, 274
konwertujący, 435
kopiujący, 294
przenoszący, 421
wyjątki w konstruktorze, 495
kontrola typu, 25
konw.cpp (plik), 149
konwersja, zob. operator konwersji, 45,
124, 435
do typu definiowanego, 435
dynamiczna, 444, 452, 552
elementów wyliczenia, 37
od typu definiowanego, 440
standardowa, 145
statyczna, 443, 452
trywialna, 180
uzmienniająca, 442
wymuszana, 444
kopiow.cpp (plik), 294
kostki.cpp (plik), 111
krol.cpp (plik), 245
krols.cpp (plik), 368
kwalifikacja, 264
l-wartość, 94, 123
labincpp.cpp (plik), 100
lambda, zob. funkcja lambda
lambdagen.cpp (plik), 196
lambdamutable.cpp (plik), 197
lambdas.cpp (plik), 194
late binding, zob. wiązanie, późne
left, 326
left (manipulator), 331
length, 369
lengths.cpp (plik), 27
__LINE__, 23
linker, 2, 3, 501
lista, 242
lista dziedziczenia, 448, 482
lista inicjalizacyjna, 302, 455
lista.cpp (plik), 395
listy.cpp (plik), 250
litera.cpp (plik), 411
literał napisowy, 197
little endian, 57
little-endian, 344
littlebig.cpp (plik), 56
lokalizator, 341
long, zob. typy danych, 29
long double, zob. typy danych
long int, 29
long long, zob. typy danych, 29
long long int, 29
lval.cpp (plik), 95
macierze.cpp (plik), 222
main, zob. funkcja, 8
make_shared, 433
make_unique, 428
makro, 20
malloc, 226
man, 4
manb.cpp (plik), 331
maniparg.cpp (plik), 535
manipulator, 11, 330, 535
argumentowy, 334
bezargumentowy, 331
map, 540
mapy.cpp (plik), 541
match.cpp (plik), 181
matrix2dim.cpp (plik), 220
max_element, 539
mediana.cpp (plik), 217
memchr, 228
memcmp, 228
memcpy, 227
memmove, 228
memset, 228
memstat.cpp (plik), 273
merge, 527
met.cpp (plik), 271
metoda, 269
czysto wirtualna, 474
przesłanianie, 467
stała, 289
ulotna, 293
wirtualna, 468, 469
Microsoft, 4
min_element, 539
minus.cpp (plik), 399
mod.cpp (plik), 128
modcon.cpp (plik), 438
modsev.cpp (plik), 386
modsev1.cpp (plik), 394
Modula-2, zob. języki programowania
moduł, 8, 501
modyfikator, 87, 100
move, 421
multbas.cpp (plik), 483
mutab.cpp (plik), 291
mutable, 291
mySTACK.h (plik), 510
mySTACKS.h (plik), 510
mySTACKSImpl.cpp (plik), 511
nadmiar, 362
napis
C++, 364
w stylu C, 353
nazwa kwalifikowana, 261, 264
NDEBUG, 188
new, 210, 499
new.cpp (plik), 230
niedomiar, 362
nmspc.cpp (plik), 508
no-op, zob. operator identycznościowy
noboolalpha, 327
noexcept, 424, 497
noshowbase, 327
noshowbase (manipulator), 331
noshowpoint, 327
noshowpoint (manipulator), 331
noshowpos, 327
noskipws, 326
notacja naukowa, 34
notacja wielbłądzia, 80
nounitbuf, 327
nouppercase, 327
npos, 364
NUL, 58, 353
NULL, 58
nullptr, 34, 226
.o, 504
obiekt
funkcyjny, 415, 532
wywoływalny, 415, 532
obroty.cpp (plik), 239
oceny.cpp (plik), 117
oct, 326
oct (manipulator), 331
odczyt nieformatowany, 336
odniesienie, zob. odnośnik
ODR, 155
odśmiecacz, 209
ofstream, 322, 340
one definition rule, 155
oneargop.cpp (plik), 392
op.cpp (plik), 409
operacje wejścia/wyjścia, 7
operand, 119
operator, 119
alternatywy bitowej (|), 120, 129
alternatywy logicznej (k), 21, 120,
136
arytmetyczny, 127
dekremantacji, 126
delete, 120, 215, 216
dereferencji, 42
dodawania, 120
dwuargumentowy, 119, 385, 393
dynamic_cast, 499, 552
dzielenia, 120, 127
identycznościowy, 127
identyfikacji typu, 120, 124, 202,
381, 499
indeksowania, 120, 123, 393, 541
przeciążanie, 410
infiksowy, 119
inkrementacji, 126
jednoargumentowy, 119, 391, 398
koniunkcji bitowej (&), 120, 130
koniunkcji logicznej (&&), 21, 120,
136
konstrukcji wartości, 120, 123
konwersji, 120, 124, 127
dynamicznej, 120, 444, 552
statycznej, 120, 443
uzmienniającej, 120, 442
wymuszonej, 120, 444
minus, 120, 127
mnożenia, 120, 127
negacji bitowej (∼), 120, 127, 129
negacji logicznej (!), 21, 120, 127,
136
new, 120, 210, 499
new lokalizujący, 229
odejmowania, 120, 127
plus, 120, 127
porównania, 120, 128
prefiksowy, 119
priorytet, 119, 120
przecinkowy, 120, 142
przeciążanie, 384
funkcją globalną, 385
metodą klasy, 392
przedrostkowy
przeciążanie, 398
przenoszący przypisania, 421
przesunięcia bitowego, 120, 131
przypisania, 120, 138, 393
przeciążanie, 403
złożony, 140
przyrostkowy
przeciążanie, 398
relacyjny, 120, 128
reszty, 120, 127
rzutowania, 120, 124, 127
różnicy symetrycznej (^), 120, 130
selekcji, 141
sizeof, 25, 120, 124
typedef, 126
typeid, 549
warunkowy, 120, 141
wiązanie, 119
wstawiania do strumienia (), 11,
324
wyboru składowej, 120
wyboru składowej przez wskaźnik,
120, 393
przeciążanie, 417
wyjmowania ze strumienia (), 13,
324
wywołania, 120, 123, 393
przeciążanie, 414
wyłuskania adresu (&), 41, 120,
244
wyłuskania wartości (*), 42, 95,
120
zasięgu (::), 81, 261, 264, 273
zgłoszenia wyjątku, 120, 487
zmniejszenia, 120, 123, 126
zwiększenia, 120, 123, 126
opwyj.cpp (plik), 388
osoba1.cpp (plik), 298
osoba2.cpp (plik), 299
osoba3.cpp (plik), 300
ostream, 322
ostream (klasa), 11
ostream_iterator, 527
ostringstream, 322, 349
ostrstream, 322, 347
out (tryb otwarcia), 341
out_of_range, 369, 516
output iterator, 522
overflow, 362
ovrldeq.cpp (plik), 406
ovrlderr.cpp (plik), 404
ovrlskl.cpp (plik), 418
ownunique.cpp (plik), 428
p-wartość, 94
padding, 236
pair, 536
pamięć
przydzielanie, 209
wyciek, 210
zarządzanie, 209
zwalnianie, 215
pamięć wolna, zob. sterta, 209
parametr formalny, 156
parametr funkcji, 156
pary.cpp (plik), 537
pary.dat (plik), 537
Pascal, zob. języki programowania
peek, 338
pierszeństwo, zob. operator, priorytet
pix.cpp (plik), 455
plik
implementacyjny, 502
nagłówkowy, 502
tryb otwarcia, 340
wewnętrzny, 347
wykonywalny, 1
plik nagłówkowy, 8
plik wykonywalny, 3
plikrw.cpp (plik), 342
pminmax.cpp (plik), 44
pointer, zob. wskaźnik
pointers.cpp (plik), 39
polbit.cpp (plik), 286
poldyn.cpp (plik), 212
pole, 233, 266
bitowe, 285
mutable, 291
statyczne, 266
pole bitowe, 285
polimorfizm, 468
polysiz.cpp (plik), 472
pop_back, 518
pop_front, 525
porz.cpp (plik), 151
porządek wartościowania, 151
postdekrementacja, zob. operator zmniejszenia
postinkrementacja, zob. operator zwiększenia
pozdro.cpp (plik), 263
poziom dostępności, 262
pragma once, 21
precision, 330
predekrementacja, zob. operator zmniejszenia
predyk.cpp (plik), 529
predykat, 529
preinkrementacja, zob. operator zwiększenia
preplog.cpp (plik), 22
preprocesor, 2, 8, 9, 17
prgr.cpp (plik), 554
primatr.cpp (plik), 334
priorytet, zob. operator, priorytet
private, 262, 263, 448
program łączący, zob. linker
promocja, 146
protected, 262, 263, 448
prototyp funkcji, 154
przec.cpp (plik), 142
przeciążanie, zob. funkcja przeciążona
przeciążanie funkcji, 179
przenoszący operator przypisania, 421
przesl.cpp (plik), 81
przestrzeń nazw, 506
przesłanianie, 81, 450
przesłanianie metod, 467
przypis.cpp (plik), 139
public, 262, 263, 448
push_back, 374, 516
push_front, 525
put, 339
putback, 338
Python, zob. języki programowania,
158
pętla, zob. instrukcja iteracyjna, 109
do-while, 110
for, 111
foreach, 114
while, 109
quick sort, 101
r-referencja, 420
rand, 110
rbegin, 374, 521
rdstate, 345
read, 337
realloc, 227
ref.cpp (plik), 211
refer.cpp (plik), 46
referencja, zob. odnośnik, 45, 167
do tablicy, 171
jako typ zwracany, 171
register, zob. zmienna rejestrowa
reinterpret_cast, 444
release, 429
remove, 527
remove_if, 540
rend, 374, 521
replace, 372
reset, 430
resetiosflags (manipulator), 334
resize, 369
return, zob. instrukcja powrotu, 118
revers.cpp (plik), 113
reverse, 527
reverse_iterator, 520
revit.cpp (plik), 521
rfind, 373
right, 326
right (manipulator), 331
rmoveassign.cpp (plik), 421
root.cpp (plik), 187
rotate.cpp (plik), 228
rotLR.cpp (plik), 135
rozwijanie funkcji, 177
RrefMet.cpp (plik), 426
RTTI, 124, 549
rtti.cpp (plik), 550
run-time type identification, 549
RWfile.cpp (plik), 350
rzutowanie, zob. operator rzutowania,
124, 442
w dół, 452
w górę, 451
różnica symetryczna, zob. operator różnicy symetrycznej
s-wskaźnik, 432
scientific, 326
scientific (manipulator), 331
scope, zob. zasięg
seek_dir, 342
seekg, 341
seekp, 341
semantyka przenoszenia, 420
set_terminate, 488
setbase (manipulator), 334
setf, 328
setfill (manipulator), 334
setiosflags (manipulator), 334
setprecision (manipulator), 334
setstate, 345
setw (manipulator), 334
shared_ptr, 426, 432
sharedcount.cpp (plik), 432
shareddelete.cpp (plik), 434
short, zob. typy danych, 29
short int, 29
showbase, 327
showbase (manipulator), 331
showpoint, 327
showpoint (manipulator), 331
showpos, 327
signed, zob. typy danych
simplista.cpp (plik), 243
size, 369, 517
size_t, 124, 212, 226, 348, 354
size_type, 364, 517
sizeof, zob. operator sizeof, 124
sizes.cpp (plik), 125
skipws, 326
skok, 99
skrot.cpp (plik), 137
składowa, zob. klasa, składowa, 233
skłądowa, 261
Smalltalk, zob. języki programowania
.so, 505
sorslo.cpp (plik), 355
sort, 527, 540
sort.cpp (plik), 526
sortev.cpp (plik), 528
sortint.h (plik), 503
sortintApp.cpp (plik), 505
sortintImpl.cpp (plik), 503
sortowanie, 218, 247, 526
sorttempl.cpp (plik), 204
srand, 110
sstream, 322, 349
stack.cpp (plik), 476
stacksApp.cpp (plik), 513
StackTmplt.cpp (plik), 252
stale.cpp (plik), 89
stale1.cpp (plik), 89
stale2.cpp (plik), 90
stalstal.cpp (plik), 92
stalwsk.cpp (plik), 91
standard C++11, 38, 157, 167, 193
stat.cpp (plik), 83
statement, zob. instrukcja
static, zob. zmienna statyczna, 177,
266
static.cpp (plik), 84
static_cast, 443
statskl.cpp (plik), 267
status powrotu, 489
stała, zob. zmienna ustalona, 88
stałość metody, 289
std, 508
stdarg, zob. funkcja o nieokreślonej ilości argumentów
stderr, 323
stdexcept, 516
stdin, zob. strumień standardowy wejściowy, 322, 323
stdout, zob. strumień standardowy wyjściowy, 322, 323
sterta, 49, 209
STL, 377, 515
stos, 209, 379
zwijanie, 209, 488
stos.cpp (plik), 379
str, 349
str (funkcja), 348
strcat, 354
strchr, 356
strcmp, 355
strcoll, 356
strcpy, 354
strcspn, 357
streamoff, 342
streamsize, 329, 337
string (klasa), 364, 522
konkatenacja, 367
konstruktory, 365
metody, 369
operatory, 366
string.h, 227
strlen, 354
strncat, 354
strncmp, 356
strncpy, 355
strong typing, zob. kontrola typu
Stroustrup, B., 5, 211
strpbrk, 357
strrchr, 357
strspn, 357
strstr, 357
strstream, 322, 347
strtod, 361
strtod.cpp (plik), 362
strtok, 357
strtol, 363
strtoul, 364
struktura, 233
C-struktura, 233
strumień, 321
błędów
standardowy, 323
standardowy wejściowy, 11, 323
standardowy wyjściowy, 11, 323
wejściowy, 321
wyjściowy, 321
substr, 369
sumaazdo.cpp (plik), 116
sumadod.cpp (plik), 115
surp.cpp (plik), 148
swap, 370
Swift J., 57
switch, zob. instrukcja decyzyjna
switch.cpp (plik), 107
sygnatura, 179
sygnatura funkcji, 157
szablon, 377, 515
funkcji, 199
klasy, 377
struktury, 250
szuk.cpp (plik), 530
słownik, 540
słowo kluczowe, 79
słowo stanu strumienia, 344
tab2dim.cpp (plik), 61
tab2dim2.cpp (plik), 63
tabchar.cpp (plik), 58
tabfunc.cpp (plik), 189
tabfunk.cpp (plik), 53
tabinc.cpp (plik), 401
tablica
dynamiczna, 212
wielowymiarowa, 219
napisów, 64
obiektów, 283
statyczna, 49, 50, 212
wielowymiarowa, 60
półdynamiczna, 212
znaków, 57
tablice.cpp (plik), 52
tabnap.cpp (plik), 64
tabref.cpp (plik), 170
tcsh, 489
Teajtetos, 174
tellg, 341
tellp, 341
template, 200
term.cpp (plik), 488
terminate, 488
testInst.cpp (plik), 2
this, 271
throw, zob. operator zgłoszenia wyjątku, 118, 487
__TIME__, 23
time_t, 237
tmpl.cpp (plik), 201
tmplt.cpp (plik), 199
tok.cpp (plik), 358
tokenizer, 357
tolower, 360
toupper, 360
trian.cpp (plik), 304
true, 34
trunc (tryb otwarcia), 341
try, zob. instrukcja obsługi wyjątku,
118, 490
tryb otwarcia pliku, 340
tworzob.cpp (plik), 277
typ
bool, 34
dynamiczny, 467
int16_t, 33
int32_t, 33
int64_t, 33
int8_t, 33
niekompletny, 247
statyczny, 467
uint16_t, 33
uint32_t, 33
uint64_t, 33
uint8_t, 33
typ funkcji, 156
type
char16_t, 29
char32_t, 29
wchar_t, 29
type_info, 549
typedef, zob. operator typedef, 74, 126,
186
typedef.cpp (plik), 75
typedef1.cpp (plik), 76
typeid, zob. operator identyfikacji typu,
381, 549
typeinfo, 126, 202, 549
typename, 200
typy danych
bez znaku, 29, 30
char, 29, 31
double, 33
float, 33
int, 29
long, 29
long double, 33
long int, 29
long long, 29
long long int, 29
short, 29
short int, 29
size_t, 212
struktura, 233
wyliczenia, 35
ze znakiem, 29, 30
złożone, 71
u-wskaźnik, 426
uint16_t, 33
uint32_t, 33
uint64_t, 33
uint8_t, 33
un.cpp (plik), 254
#undefine, 18
underflow, 362
unget, 338
unia, 253
unie.cpp (plik), 256
unique_ptr, 426
uniquederiv.cpp (plik), 431
uniquereset.cpp (plik), 430
unitbuf, 327
unsetf, 328
unsigned, zob. typy danych
uppercase, 327
upplow.cpp (plik), 361
using, 76, 507
using namespace, 507
va_arg, 165
va_end, 165
va_list, 165
va_start, 165
validan.cpp (plik), 345
vararg, zob. funkcja o nieokreślonej ilości argumentów
vardecl.cpp (plik), 26
varepo.cpp (plik), 172
varg.cpp (plik), 165
vecpoin.cpp (plik), 390
vecsimple.cpp (plik), 69
vector, 68, 516, 522
virtu.cpp (plik), 474
virtual, zob. metoda wirtualna
visibility, zob. widoczność
void, 156
void*, zob. wskaźnik generyczny
volatile, zob. zmienna ulotna, 87
vrp.cpp (plik), 169
wardom.cpp (plik), 162
wardom1.cpp (plik), 163
wardom1h.h (plik), 163
wchar_t, 29
wektor, 68, 516
what, 499
while, zob. instrukcja iteracyjna, 109
wide character, 29
widoczność, 80
width, 329
wielodziedziczenie, 447, 482
wild card, zob. dżoker
wirdes.cpp (plik), 480
wirtualny destruktor, 480
wiązanie, zob. operator, wiązanie
późne, 468
wczesne, 468
wman.cpp (plik), 333
write, 339
wskaźnik, 38, 40
arytmetyka, 54
do składowej, 316
funkcyjny, 153, 182
generyczny (void*), 44, 55
inteligentny, 426
shared, 426, 432
unique, 426
wskfun.cpp (plik), 184
wsklas.cpp (plik), 318
wskref.cpp (plik), 47
wyciek pamięci, 210
wyjątek, 118, 214, 487
bad_alloc, 499
bad_cast, 499
bad_exception, 499
bad_typeid, 499
hierarchia, 492
ios::failure, 499
obsługa, 489
out_of_range, 369, 516
w destruktorze, 497
w konstruktorze, 495
zgłaszanie, 487
wyliczenia, 35
wyrins.cpp (plik), 102
wyrównanie, 254
wywołanie, 123
wywołanie funkcji, 159
wzorzec, zob. szablon, 377
struktury, 250
zakr.cpp (plik), 413
zakres widoczności, 80
zapis nieformatowany, 339
zaprzyjaźnianie funkcji, 307
zasięg, 80
globalny, 120
klasy, 120, 264, 267
przestrzeni nazw, 120
zasob.cpp (plik), 495
zloz.cpp (plik), 140
zmienna, 25, 26
atomowa, 88
eksportowana, 81, 83, 87
globalna, 81, 83
inicjalizacja, 26
lokalna, 81, 83
statyczna, 83
statyczna lokalna, 159
tymczasowa, 93
ulotna, 87
ustalona, 88
wskazywana, 40
zewnętrzna, 81, 85, 502
zmienna liczba argumentów, 164
znak szeroki, 29
zona.cpp (plik), 248
zwalnianie pamięci, 215
zwijanie stosu, 209

*/








