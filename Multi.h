#ifndef _MULTI
#define _MULTI

#include "IComportementStrategy.h"

class Multi: public IComportementStrategy{
    public:
       void behavior(Bestiole & b, Milieu & milieu) override;
       //double calculerOrientation(const Bestiole& b1, const Bestiole& b2);
};

#endif