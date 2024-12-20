#include "Milieu.h"
#include <cmath> 
#include <cstdlib>
#include <ctime>
#include <atomic>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };

int Milieu::stepNumber=0;
Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}






void Milieu::step(void)
{
    const double seuilCollision = 10.0; // Distance minimale pour considérer une collision

    // Nettoyer l'écran avant d'afficher les bestioles
    cimg_forXY(*this, x, y) fillC(x, y, 0, white[0], white[1], white[2]);
      //std::vector<Bestiole>::iterator
  
    for ( auto it = listeBestioles.begin(); it != listeBestioles.end();it++){

        if(it->get()->hasMultipleBehavior && stepNumber%100==0){
        if (it->get()->behaviorNb ==1) {
            it->get()->set_strategy(std::make_unique<Gregaire>());
            it->get()->behaviorNb =3;
        } else if (it->get()->behaviorNb ==2) {
            it->get()->set_strategy(std::make_unique<Kamikaze>());
            it->get()->behaviorNb =1;
        } else if (it->get()->behaviorNb ==3) {
            it->get()->set_strategy(std::make_unique<Prevoyant>());
            it->get()->behaviorNb =2;
        } else if(it->get()->behaviorNb ==4) {
            it->get()->set_strategy(std::make_unique<Peureuse>());
            it->get()->behaviorNb =3;
        }else{
          
        }
        }
        it->get()->applyStrategy(**it, *this);
    }
    for ( auto it = listeBestioles.begin(); it != listeBestioles.end();)
    {
        bool dead = false;

        // Vérifier la distance avec les autres bestioles
        //
        for (auto other = listeBestioles.begin(); other != listeBestioles.end(); ++other)
        {
            if (it != other) // Ne pas comparer avec elle-même
            {
                double distance = std::sqrt(
                    std::pow(it->get()->getX() - other->get()->getX(), 2) +
                    std::pow(it->get()->getY() - other->get()->getY(), 2)
                );

                if (distance < seuilCollision)
                {

                   if(!it->get()->gethasCarapace() && other->get()->gethasCarapace()){
                        dead = true;
                        break;
                   }else if(it->get()->gethasCarapace() && other->get()->gethasCarapace()){
                         if((it->get()->getDeath() - it->get()->getReducteurCarapaceMort())>(other->get()->getDeath() - other->get()->getReducteurCarapaceMort())){
                           dead =true;
                           break;
                         }
                    
                   }
                    
                }
            }
        }

        // Agir et dessiner uniquement si aucune collision détectée
        if (!dead)
        {
            it->get()->action(*this);
            it->get()->draw(*this);
            ++it;
        }else{
            it = listeBestioles.erase(it);
        }
    }
    stepNumber++;
}



int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( auto it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *(*it)) && b.jeTeVois(*(*it)) )
         ++nb;

   return nb;

}
