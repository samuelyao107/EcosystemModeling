#include "Gregaire.h"
#include "Bestiole.h"  
#include "Milieu.h"



void Gregaire::behavior(Bestiole & b, Milieu & milieu) {
    int nb=0;
    double orientation = 0;
    for(auto it = milieu.getListeBestioles().begin(); it != milieu.getListeBestioles().end();it++){
        orientation += it->get()->getOrientation();
        nb++;
    }
    orientation = orientation/nb;
    b.setOrientation(orientation);
}