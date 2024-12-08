#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyant.h"
#include <memory>
#include <iostream>
#include <vector>





class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   //std::vector<Bestiole>   listeBestioles;
   std::vector<std::unique_ptr<Bestiole>> listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   std::vector<std::unique_ptr<Bestiole>>& getListeBestioles() {
        return listeBestioles;
    }

   void addMember( const Bestiole & b ) {
      //listeBestioles.push_back(b); listeBestioles.back().initCoords(width, height);

        std::unique_ptr<Bestiole> newBestiole = std::make_unique<Bestiole>(b); 
        newBestiole->initCoords(width, height);
        newBestiole->init();
        newBestiole->set_strategy(std::make_unique<Peureuse>());
        listeBestioles.push_back(std::move(newBestiole));
      
      }
   int nbVoisins( const Bestiole & b );

};


#endif
