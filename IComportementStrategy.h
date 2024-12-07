#ifndef _ICOMPORTEMENTSTRATEGY_H_
#define _ICOMPORTEMENTSTRATEGY_H_

//#include "Bestiole.h"
//#include "Milieu.h"

class Bestiole; 
class Milieu;

class IComportementStrategy {
public:
    
    virtual void behavior(Bestiole & b,  Milieu & milieu) = 0;               // Pure virtual function for defining behavior
    virtual ~IComportementStrategy() = default; // Virtual destructor to ensure proper cleanup
};

#endif
