#include "reis.hpp"
#include <iostream>

/*
Interface klasse voor de vergelijkingsfunctie.
De functie heeft 3 versies (overloads). Voor elke vorm van een Stap is er eentje.
De functie is nodig om soorten van stappen met elkaar te vergelijken.
60 minuten == 100km == 10 euro.
Op basis van deze vergelijking spelen de functies een rol. Waardes van de stappen worden naar
een alternatieve eenheid gestuurd en opgeslagen in een Stap object.
*/
class IComparable
{
    //vergelijk functie voor de Vlucht klasse (x 100)
    virtual int compareTo(Vlucht vlucht) = 0;
    //vergelijk functie voor de Autorit klasse (x 10)
    virtual int compareTo(Autorit autorit) = 0;
    //vergelijk functie voor de Treinrit klasse (x 17)
    virtual int compareTo(Treinrit treinrit) = 0;
};

/*
Basisprogramma klasse maakt een object voor het Dijkstra algoritme met een begin en eind punt.
De klasse is een inheritance van de Icomparable interface.
Aan dit programma worden vervolgens stappen toegevoegd en als er een weg te vinden is naar het eindpunt, wordt er op slimme wijze
de snelste route bepaald.
Atributen:
vluchten : lijst van alle vluchten.
treinritten : lijst van alle treinritten.
autoritten : lijst van alle autoritten.
bereiktePunten : lijst van alle punten die al ees bereikt zijn.
reizen : lijst van alle reizen die afgelegd zijn, naar elk bereikte punt is er een apparte reis.
*/
class Basisprogramma : public IComparable
{
private:
    std::vector<Vlucht> vluchten;
    std::vector<Treinrit> treinritten;
    std::vector<Autorit> autoritten;

    std::vector<char> bereiktePunten;
    std::vector<Reis> reizen;

    char eindPunt;
public:
    /*
    Constructor methode van de Basisprogramma klasse.
    parameters:
    begin (char): het begin punt van een veld.
    eind (char): het eindpunt van een veld, hier wordt in het programma de kortste weg naar gezocht.
    */
    Basisprogramma(char begin, char eind);

    /*
    inLijst methode kijkt of een character voorkomt in een gegeven lijst van characters.
    Parameters:
    target (char): het gezochte character.
    lijst (vector van char): de lijst waar doorheen gezocht wordt.
    Return waarde (bool): character in de lijst = true, anders false.
    */
    bool inLijst(char target, std::vector<char> lijst);
    
    //methode die een vector terug geeft van alle stappen in de Stap klasse, met de relatieve eenheid als duur.
    std::vector<Stap> alleStappen();
    //methode die alle stappen doorloopt en returnt een lijst van stappen die mogelijk gezet kunnen worden volgends het dijkstra algoritme.
    std::vector<Stap> mogelijkHeden();
    //methode die uit de mogelijke stappen, de kortste route bepaald volgends het dijkstra algoritme.
    Stap kortstePad();
    //methode die de beste stap toevoegt aan de reizen.
    Reis nieuweReis();

    /*
    besteRoute methode is het programma die afspeelt en zoekt naar de best mogelijke route naar het eindpunt.
    Deze methode herhaalt de nieuweReis methode totdat het eindpunt bereikt is (dijkstra algoritme).
    */
    std::vector<char> besteRoute();

    // return (int) relatieve waarde voor vluchten
    int compareTo(Vlucht vlucht) override;
    //return (int) relatieve waarde voor autoritten
    int compareTo(Autorit autorit) override;
    //return (int) relatieve waaarde voor treinritten
    int compareTo(Treinrit treinrit) override;

    //getter voot vluchten
    std::vector<Vlucht> getVluchten();
    //getter voot treinritten
    std::vector<Treinrit> getTreinritten();
    //getter voor autoritten
    std::vector<Autorit> getAutoritten();
    //getter voor bereikte punten
    std::vector<char> getBereiktePunten();
    //getter voor reizen
    std::vector<Reis> getReizen();
    
    //setter voor vluchten
    void setVluchten(Vlucht vlucht);
    //setter voor treinritten
    void setTreinritten(Treinrit treinrit);
    //setter voor autoritten
    void setAutoritten(Autorit autorit);
    //setter voot bereikte punten
    void setBereiktePunten(char bereiktePunt);
    //setter voot reizen
    void setReizen(Reis reis);
};