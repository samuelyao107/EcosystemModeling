#include "Nageoire.h"

Nageoire::Nageoire(IBestiole* bestiole, double speedBoost)
    : Accessoires(bestiole), boostVitesse(speedBoost) {}

void Nageoire::execute() {
    Accessoires::execute();
    std::cout << "Nageoire ajoutée : Vitesse augmentée de " << boostVitesse << std::endl;
}
