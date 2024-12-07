#ifndef _GREGAIRE
#define _GREGAIRE

#include "IComportementStrategy.h"

class Gregaire: public IComportementStrategy{
    public:
       void behavior(Bestiole & b, Milieu & milieu) override;
};

#endif