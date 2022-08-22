#include <iostream>
#include <vector>
#include "reis.hpp"
#include "basisprogramma.hpp"



int main(){



/*
Voorbeeld 1
*/
Basisprogramma bas('A','E');                //er wordt een casus aangemaakt met beginpunt A en eindpunt E

bas.setVluchten(Vlucht('A','B',34));
bas.setVluchten(Vlucht('B','A',34));
bas.setTreinritten(Treinrit('A','C',120));          //alle stappen worden toegevoegd
bas.setTreinritten(Treinrit('C','A',120));
bas.setAutoritten(Autorit('C','D',500));
bas.setAutoritten(Autorit('D','C',500));
bas.setAutoritten(Autorit('B','D',2000));
bas.setAutoritten(Autorit('D','B',2000));
bas.setTreinritten(Treinrit('B','E',120));
bas.setTreinritten(Treinrit('E','B',120));
bas.setVluchten(Vlucht('C','E',34));
bas.setVluchten(Vlucht('E','C',34));

std::vector<char> beste = bas.besteRoute();               // de snelste route
for (char locatie : beste){std::cout << locatie << "\n";}
std::cout << "\n";


/*
Voorbeeld 2
*/

Basisprogramma twee('A','E');

twee.setTreinritten(Treinrit('A','B',60));
twee.setTreinritten(Treinrit('B','A',60));
twee.setTreinritten(Treinrit('C','E',230));
twee.setTreinritten(Treinrit('E','C',230));
twee.setTreinritten(Treinrit('D','E',250));
twee.setTreinritten(Treinrit('E','D',250));
twee.setAutoritten(Autorit('A','D',120));
twee.setAutoritten(Autorit('D','A',120));
twee.setAutoritten(Autorit('D','B',150));
twee.setAutoritten(Autorit('B','D',150));
twee.setAutoritten(Autorit('B','C',200));
twee.setAutoritten(Autorit('C','B',200));
twee.setVluchten(Vlucht('A','E',50));
twee.setVluchten(Vlucht('E','A',50));

std::vector<char> besteTwee = twee.besteRoute();
for (char locatie : besteTwee){std::cout << locatie << "\n";}














}