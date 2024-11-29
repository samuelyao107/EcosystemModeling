#ifndef _ACCESSOIRES_H_
#define _ACCESSOIRES_H_

#include "BestioleDecorator.h"
#include <iostream>

class Accessoires : public BestioleDecorator {
public:
    Accessoires(IBestiole* bestiole) : BestioleDecorator(bestiole) {}
    virtual ~Accessoires() {}

    virtual void execute() override {
        BestioleDecorator::execute();
    }
};

#endif
