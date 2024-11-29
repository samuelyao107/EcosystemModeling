#ifndef _CARAPACE_H_
#define _CARAPACE_H_

#include "Accessoires.h"

class Carapace : public Accessoires {
private:
    double resistance;    // Facteur de résistance ajouté
    double ralentissement; // Ralentissement de la vitesse

public:
    Carapace(IBestiole* bestiole, double resistanceFactor, double speedReduction);
    virtual ~Carapace() {}

    void execute() override;
};

#endif
