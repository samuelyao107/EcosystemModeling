#include "Camouflage.h"

Camouflage::Camouflage(IBestiole* bestiole, double invisibilityFactor)
    : Accessoires(bestiole), invisibilite(invisibilityFactor) {}

void Camouflage::execute() {
    Accessoires::execute();
    std::cout << "Camouflage activé : Invisibilité augmentée à " << invisibilite << std::endl;
}
