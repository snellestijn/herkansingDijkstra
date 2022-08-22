#define CATCH_CONFIG_MAIN

#include "reis.hpp"
#include "basisprogramma.hpp"
#include "catch.hpp"

TEST_CASE("BasisProgramma testen"){ //testcases runnen om te zien of alles uit het basisprogramma werkt
    
    Basisprogramma bas('A','D');

    bas.setVluchten(Vlucht('A','B',5));
    bas.setVluchten(Vlucht('B','A',5));
    bas.setVluchten(Vlucht('A','C',8));
    bas.setVluchten(Vlucht('C','A',8));
    bas.setVluchten(Vlucht('B','D',10));
    bas.setAutoritten(Autorit('D','B',10)); 
    bas.setVluchten(Vlucht('C','D',2));
    bas.setVluchten(Vlucht('D','C',2));

        // test of alle stappen correct zijn ingevuld
        REQUIRE(bas.getVluchten().size() == 7);
        REQUIRE(bas.alleStappen().size() == 8);
        REQUIRE(bas.getAutoritten().size() == 1);
        REQUIRE(bas.getTreinritten().size() == 0);

        //testen of de inLijst functie werkt
        REQUIRE(bas.inLijst(('A'),bas.getBereiktePunten()) == true);

        //testen van vergelijkingsfunctie
        REQUIRE(bas.compareTo(bas.getVluchten()[0]) == 500);
        //testen van het kiezen voor het kortste pad op actuele locatie
        REQUIRE(bas.kortstePad().getEind() == 'B');

        //testen of het complete programma werkt
        REQUIRE(bas.besteRoute()[0] == 'A');
        REQUIRE(bas.besteRoute()[1] == 'C');
        REQUIRE(bas.besteRoute()[2] == 'D');
}


TEST_CASE("Reis testen"){ //testcases die kijken of de klasse Reis goed werkt
    
    //een nieuwe Reis aanmaken
    Reis reis = Reis('A');

        //kijken of de reis correct is aangemaakt
        REQUIRE(reis.getPlekken().size() == 1);
        REQUIRE(reis.getPlekken()[0] == 'A');
        REQUIRE(reis.getTotaleDuur() == 0);

    //een lijst met plekken en een aantal totale duur
    std::vector<char> plekken = {'A','B','C'};
    int duur = 10;

    // een nieuwe reis maken
    Reis nieuweReis = Reis(plekken,'D',duur);

        //kijken of de nieuwe reis goed is ingevoerd
        REQUIRE(nieuweReis.getPlekken().size() == 4);
        REQUIRE(nieuweReis.getPlekken()[2] == 'C');
        REQUIRE(nieuweReis.getTotaleDuur() == 10);
}

TEST_CASE("Stappen testen"){ //testcases die kijken of alle soorten stappen goed werken

    //een normale stap maken
    Stap stap;

    //waardes toevoegen aan de stap
    stap.setBegin('A'); stap.setEind('B'); stap.setDuur(10);

        //kijk of de waardes goed ingevuld zijn
        REQUIRE(stap.getBegin() == 'A');
        REQUIRE(stap.getEind() == 'B');
        REQUIRE(stap.getDuur() == 10);

    //vlucht testen
    Vlucht vlucht = Vlucht('A','B',10);
    REQUIRE(vlucht.getBegin() == 'A');
    REQUIRE(vlucht.getKosten() == 10);

    //autorit testen
    Autorit autoRit = Autorit('C','D',20);
    REQUIRE(autoRit.getEind() == 'D');

    //treinrit testen
    Treinrit trein = Treinrit('E','F',100);
    trein.setBegin('Z');
    REQUIRE(trein.getBegin() == 'Z');



}