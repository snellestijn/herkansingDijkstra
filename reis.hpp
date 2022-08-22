#include <vector>
#include <iostream>
#pragma once

/*
Klasse Reis maakt objecten van reizen tussen twee punten.
Atributen =
plekken : een lijst van plekken waar de reis langs gaat, op volgorde. Afgedrukt in Char type.
totaleDuur : geeft aan hoeveel de reis kost. in int type en geeft geen kilomters of prijs aan maar een relatieve eenheid die berekent wordt bij stappen.
*/
class Reis
{
private:
    std::vector<char> plekken;
    int totaleDuur;
public:
    /*
    Constructor methode van de Reis klasse. twee versies door overloaden
    Perameters:
    plekken (vector van char), een lijst van afgelegde plekken toevoegen.
    nieuwePlek (char), een nieuwe plek toevoegen.
    totaleDuur (int), de totale koste om van de eerste naar de laatste plek in de reis te gaan.
    */
    Reis(std::vector<char> plekken, char nieuwePlek, int totaleDuur);
    Reis(char nieuwePlek);

    //getter voor plekken atribuut
    std::vector<char> getPlekken();
    //getter voor totaleDuur atribuut
    int getTotaleDuur();
};


/*
Klasse Stap maakt objecten van stappen die gezet worden in het Dijkstra algoritme.
Atributen =
begin : het begin van de stap die gezet wordt, afgedrukt in Char type.
eind : het eindpunt van de stap die gezet wordt, afgedrukt in Char type.
duur : de koste (zelf verzonnen eenheid) die gemaakt worden in een stap.
*/
class Stap
{
private:
    char begin;
    char eind;
    int duur;
public:
    //getter voor het begin
    char getBegin();
    //getter voor het eind
    char getEind();
    //getter voor de duur
    int getDuur();

    //setter voor het begin
    void setBegin(char begin);
    //setter voor het eind
    void setEind(char eind);
    //setter voor de duur
    void setDuur(int duur);
};

/*
Klasse Vlucht maakt objecten van stappen die gezet worden als een vliegtuig vlucht zijnde.
Deze klasse is een inheritance van de Stap klasse.
Atributen:
alle Stap atributen.
kosten : de kosten in euro's voor de vlucht, afgedrukt in Int type.
*/
class Vlucht : public Stap
{
private:
    int kosten;
public:
    /*
    Constructor methode van de Vlucht klasse.
    Parameters:
    begin (char): het begin punt van de stap.
    eind (char): het eindpunt van de stap.
    kosten (int): de kosten van de stap in euro's.
    */
    Vlucht(char begin, char eind, int kosten);
    //getter van de kosten.
    int getKosten();
};

/*
Klasse Autorit maakt objecten van stappen die gezet worden als een autorit.
Deze klasse is een inheritance van de Stap klasse.
Atributen:
Alle atributen uit Stap klasse.
kilometers: de kilometers die worden afgelegd in de stap.
*/
class Autorit : public Stap
{
private:
    int kilometers;
public:
    /*
    Constructor methode van de Autorit klasse.
    Parameters:
    begin (char): het beginpunt van de stap.
    eind (char) : het eindpunt van de stap.
    kilometers (int): het aantal kilometers van de stap.
    */
    Autorit(char begin, char eind, int kilometers);
    //getter van de kilometers.
    int getKilometers();
};

/*
Klasse Treinrit maakt objecten van de stappen die gezet worden als een treinrit.
Deze klasse is een inheritance van de Stap klasse.
Atributen:
Alle atributen ui Stap klasse.
minuten: de tijd, in aantal minuten, dat het duur om de stap te nemen.
*/
class Treinrit: public Stap
{
private:
    int minuten;
public:
    /*
    Constructor methode van de Treinrit klasse.
    Parameters:
    begin (char): het beginpunt van de stap.
    eind (char): het eindpunt van de stap.
    minnuten (int): het aantal minuten dat de stap duur.
    */
    Treinrit(char begin, char eind, int minuten);
    //getter van het aantal minuten.
    int getMinuten();
};

