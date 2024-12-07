#include <cmath>
#include "Prevoyant.h"
#include "Milieu.h"
     
void Prevoyant::behavior(Bestiole & b, Milieu & milieu) {
       
        for (const auto& autre : milieu.getListeBestioles()) {
            if (!(b == *autre) && collisionImminente(*autre, b, 1.0)) {
                
                double angleFuite = atan2((*autre).getY() -b.getY(), (*autre).getX() - b.getX()) + M_PI;
                b.setOrientation(angleFuite);
                break;  
            }
        }
    }
 
 
void Prevoyant::estimerTrajectoire(Bestiole& autre, double &futureX, double &futureY, double delay)  {
        futureX = autre.getX() + cos(autre.getOrientation()) * autre.getVitesse() * delay;  
        futureY = autre.getY() + sin(autre.getOrientation()) * autre.getVitesse() * delay;  
    }
    

bool Prevoyant::collisionImminente(Bestiole& autre,const Bestiole& b, double delay) {
        double futureX, futureY;
        estimerTrajectoire(autre, futureX, futureY, delay);  // Estimer la trajectoire de l'autre bestiole

        double distance = sqrt(pow(futureX - b.getX(), 2) + pow(futureY - b.getY(), 2));
        return distance < 5;
    }
    
  
