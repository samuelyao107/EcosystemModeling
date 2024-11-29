#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

#include "Accessoires.h"

class Camouflage : public Accessoires {
private:
    double invisibilite; // Facteur de camouflage (0 à 1)

public:
    Camouflage(IBestiole* bestiole, double invisibilityFactor);
    virtual ~Camouflage() {}

    void execute() override;
};

#endif
