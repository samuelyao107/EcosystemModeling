#ifndef CAPTEUR_H
#define CAPTEUR_H

#include "bestioleDecorator.h"
#include <iostream>

class Capteur : public BestioleDecorator {
public:
    // Constructeur : appelle le constructeur de BestioleDecorator
    Capteur(iBestiole* bestiole) : BestioleDecorator(bestiole) {}

    // Destructeur
    ~Capteur() override = default;

    // Redéfinition de la méthode execute
    void execute() override;
};

#endif // CAPTEUR_H
