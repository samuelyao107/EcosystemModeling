#ifndef _KAMIKAZE
#define _KAMIKAZE

#include "IComportementStrategy.h"
#include <vector>
#include <memory>

class Kamikaze: public IComportementStrategy{
    public:
       void behavior(Bestiole & b, Milieu & milieu) override;
       double calculerDistance(const Bestiole& b1, const Bestiole& b2);
       double calculerOrientation(const Bestiole& b1, const Bestiole& b2);
       bool isCibleInListe(const Bestiole* cible, std::vector<std::unique_ptr<Bestiole>>& listeBestioles);
};

#endif