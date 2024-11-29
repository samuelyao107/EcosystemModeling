#include "Carapace.h"

Carapace::Carapace(IBestiole* bestiole, double resistanceFactor, double speedReduction)
    : Accessoires(bestiole), resistance(resistanceFactor), ralentissement(speedReduction) {}

void Carapace::execute() {
    Accessoires::execute();
    std::cout << "Carapace ajoutée : Résistance augmentée de " << resistance
              << ", Vitesse réduite de " << ralentissement << std::endl;
}
