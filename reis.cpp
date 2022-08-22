#include "reis.hpp"



Reis::Reis(std::vector<char> plekken, char nieuwePlek, int totaleDuur){
    plekken.push_back(nieuwePlek);
    this->plekken = plekken;
    this->totaleDuur = totaleDuur;
    }

Reis::Reis(char nieuwePlek){
    this->plekken.push_back(nieuwePlek);
    this->totaleDuur = 0;
    }

std::vector<char> Reis::getPlekken(){
    return this->plekken;
}

int Reis::getTotaleDuur(){
    return this->totaleDuur;
}

char Stap::getBegin(){return this->begin;}
char Stap::getEind(){return this->eind;}
int Stap::getDuur(){return this->duur;}

void Stap::setBegin(char begin){this->begin = begin;}
void Stap::setEind(char eind){this->eind = eind;}
void Stap::setDuur(int duur){this->duur = duur;}




Vlucht::Vlucht(char begin, char eind, int kosten){
    this->kosten = kosten;
    setBegin(begin);
    setEind(eind);
}
int Vlucht::getKosten(){return this->kosten;}


Autorit::Autorit(char begin, char eind, int kilometers){
    this->kilometers = kilometers;
    setBegin(begin);
    setEind(eind);
}
int Autorit::getKilometers(){return this->kilometers;}


Treinrit::Treinrit(char begin, char eind, int minuten){
    this->minuten = minuten;
    setBegin(begin);
    setEind(eind);
}
int Treinrit::getMinuten(){return this->minuten;}





