#ifndef YEUX_H
#define YEUX_H

#include "capteur.h"
#include <iostream>

class Yeux : public Capteur {
public:
    // Constructeur : appelle le constructeur de Capteur
    Yeux(iBestiole* bestiole) : Capteur(bestiole) {}

    // Destructeur
    ~Yeux() override = default;

    // Redéfinition de la méthode execute
    void execute() override;
};

#endif // YEUX_H
