#ifndef _PREVOYANT_H_
#define _PREVOYANT_H_

#include "IComportementStrategy.h"
#include "Bestiole.h"  
#include <vector>
#include <memory>


class Prevoyant: public IComportementStrategy{
    public:
       
       void behavior(Bestiole & b, Milieu & milieu) override;
       bool collisionImminente( Bestiole& autre,const Bestiole& b, double delay = 1.0);
       void estimerTrajectoire(Bestiole& autre, double &futureX, double &futureY, double delay = 1.0) ;
       
      
};

#endif