#include "basisprogramma.hpp"

Basisprogramma::Basisprogramma(char begin, char eind){
    this->eindPunt = eind;
    setBereiktePunten(begin);
    setReizen(Reis(begin));
}


int Basisprogramma::compareTo(Vlucht vlucht){
    return vlucht.getKosten() * 100 ;
}
int Basisprogramma::compareTo(Autorit autorit){
    return autorit.getKilometers() * 10;
}
int Basisprogramma::compareTo(Treinrit treinrit){
    return treinrit.getMinuten() * 17;
}



bool Basisprogramma::inLijst(char target, std::vector<char> lijst){
    for (char element : lijst){
        if (element == target){return true;}
    }
    return false;
}

std::vector<Stap> Basisprogramma::alleStappen(){
    std::vector<Stap> alleStappen;
    for (Vlucht vlucht : vluchten){
        Stap vluchtstap = vlucht; vluchtstap.setDuur(compareTo(vlucht));
        alleStappen.push_back(vluchtstap);
    }
    for (Autorit autorit : autoritten){
        Stap autostap = autorit; autostap.setDuur(compareTo(autorit));
        alleStappen.push_back(autostap);
    }
    for (Treinrit treinrit : treinritten){
        Stap treinstap = treinrit; treinstap.setDuur(compareTo(treinrit));
        alleStappen.push_back(treinstap);
    }
    return alleStappen;
}

std::vector<Stap> Basisprogramma::mogelijkHeden(){
    std::vector<Stap> mogelijkeStappen;
    std::vector<Stap> stappen = alleStappen();
    for (Stap stap : stappen){
        for (Reis reis : reizen){
            if (stap.getBegin() == reis.getPlekken().back()){
                if (inLijst(stap.getBegin(),bereiktePunten) && !inLijst(stap.getEind(),bereiktePunten)){
                    stap.setDuur(stap.getDuur()+reis.getTotaleDuur());
                    mogelijkeStappen.push_back(stap);
                }
            }
        }
    }
    return mogelijkeStappen;
}

 Stap Basisprogramma::kortstePad(){
    std::vector<Stap> mogelijkheden = mogelijkHeden();
    Stap kortste = mogelijkheden[0];
    for (Stap stap : mogelijkheden){
            if (stap.getDuur() < kortste.getDuur()){
                kortste = stap;
            }
        }
    return kortste;
}

Reis Basisprogramma::nieuweReis(){
    Stap stap = kortstePad();
    for (Reis reis : reizen){
        if (reis.getPlekken().back() == stap.getBegin()){
            return Reis(reis.getPlekken(),stap.getEind(),stap.getDuur());
        }
    }
    return NULL;
}


std::vector<char> Basisprogramma::besteRoute(){
    while (!inLijst(this->eindPunt,bereiktePunten)){
        Reis een = nieuweReis();
        reizen.push_back(een);
        bereiktePunten.push_back(een.getPlekken().back());
    }
    return reizen.back().getPlekken();
}



std::vector<Vlucht>  Basisprogramma::getVluchten(){return this->vluchten;}
std::vector<Treinrit> Basisprogramma::getTreinritten(){return this->treinritten;}
std::vector<Autorit> Basisprogramma::getAutoritten(){return this->autoritten;}
std::vector<char> Basisprogramma::getBereiktePunten(){return this->bereiktePunten;}
std::vector<Reis> Basisprogramma::getReizen(){return this->reizen;}

void Basisprogramma::setVluchten(Vlucht vlucht){this->vluchten.push_back(vlucht);}
void Basisprogramma::setTreinritten(Treinrit treinrit){this->treinritten.push_back(treinrit);}
void Basisprogramma::setAutoritten(Autorit autorit){this->autoritten.push_back(autorit);}
void Basisprogramma::setBereiktePunten(char bereiktePunt){this->bereiktePunten.push_back(bereiktePunt);}
void Basisprogramma::setReizen(Reis reis){this->reizen.push_back(reis);}