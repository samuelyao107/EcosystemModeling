#ifndef _PEUREUSE
#define _PEUREUSE

#include "IComportementStrategy.h"

class Peureuse: public IComportementStrategy{
    public:
       void behavior(Bestiole & b, Milieu & milieu) override;
       void estimerTrajectoire(Bestiole& autre, double &futureX, double &futureY, double delay = 1.0) const;
};

#endif