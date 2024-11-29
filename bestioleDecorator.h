#ifndef BESTIOLEDECORATOR_H
#define BESTIOLEDECORATOR_H

#include "iBestiole.h"

// Classe BestioleDecorator qui hérite de iBestiole
class BestioleDecorator : public iBestiole {
protected:
    iBestiole* bestiole; // Pointeur vers une bestiole décorée

public:
    // Constructeur avec un paramètre pour initialiser la bestiole
    explicit BestioleDecorator(iBestiole* bestiole) : bestiole(bestiole) {}

    // Destructeur virtuel
    virtual ~BestioleDecorator() = default;

    // Méthode execute redéfinie
    void execute() override;
};

#endif // BESTIOLEDECORATOR_H
