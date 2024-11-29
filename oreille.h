#ifndef OREILLE_H
#define OREILLE_H

#include "capteur.h"
#include <iostream>

class Oreille : public Capteur {
public:
    // Constructeur : appelle le constructeur de Capteur
    Oreille(iBestiole* bestiole) : Capteur(bestiole) {}

    // Destructeur
    ~Oreille() override = default;

    // Redéfinition de la méthode execute
    void execute() override;
};

#endif // OREILLE_H
