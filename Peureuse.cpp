#include "Peureuse.h"
#include "Bestiole.h"  
#include "Milieu.h"



void Peureuse::behavior(Bestiole & b, Milieu & milieu) {
    int nb=0;
    for(auto it = milieu.getListeBestioles().begin(); it != milieu.getListeBestioles().end();it++){
        if(!(**it ==b)){
            if (b.jeTEntends(**it) || b.jeTeVois(**it)){
                nb++;
            }
        }
       
    }
    if(nb>5){
        double orientation = -b.getOrientation();
        b.setOrientation(orientation);
    }
   
}