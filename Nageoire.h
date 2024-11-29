#ifndef _NAGEOIRE_H_
#define _NAGEOIRE_H_

#include "Accessoires.h"

class Nageoire : public Accessoires {
private:
    double boostVitesse; // Facteur de vitesse ajouté (par exemple, 1.2 pour +20%)

public:
    Nageoire(IBestiole* bestiole, double speedBoost);
    virtual ~Nageoire() {}

    void execute() override;
};

#endif
