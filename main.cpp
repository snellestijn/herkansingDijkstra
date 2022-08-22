#include <iostream>
#include <vector>
#include "reis.hpp"
#include "basisprogramma.hpp"



int main(){




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




std::vector<char> beste = bas.besteRoute();         // de snelste route

for (char locatie : beste){std::cout << locatie << "\n";}





}