#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>

#include "IBestiole.h"

using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;

   static int              next;

private :
   int               identite;
   int               x, y;
   int               age; //en nombre de tours
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   double            death = 0;                      //probabilité de mourir
   double            omega;                         //coefficient Carapace
   double            nu;                           //coefficient Nageoire
   double            deltaO;                        //coefficient Oreille
   double            psi;                          //coefficient Camouflage
   double            alpha;                        //Champ angulaire
   double            deltaY;                      //Distance Yeux
   double            detectionY                  //Capacite de detection des yeux
   double            detectionO                  //Capacite de detection Oreille 

   T               * couleur;

private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;
   bool jeTEntends( const Bestiole & b ) const;
   void actionCarapace();
   void actionNageoire();

   void initCoords( int xLim, int yLim );

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
