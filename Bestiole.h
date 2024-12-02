#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>


using namespace std;


class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static const double CHAMP_ANGULAIRE_MAX;
   static const double CHAMP_ANGULAIRE_MIN;
   static const double DISTANCE_YEUX_MAX;
   static const double DISTANCE_YEUX_MIN;
   static const double CAPACITE_DETECTION_YEUX_MAX;
   static const double CAPACITE_DETECTION_YEUX_MIN;
   static const double PLAGE_OREILLES_MAX;
   static const double PLAGE_OREILLES_MIN;
   static const double CAPACITE_DETECTION_OREILLE_MAX;
   static const double CAPACITE_DETECTION_OREILLE_MIN;
   static const double MULTIPLICATEUR_NAGEOIRE_MAX;
   static const double REDUCTEUR_CARAPACE_MAX;
   static const double REDUCTEUR_CARAPACE_MORT_MAX;
   static const double CAMOUFLAGE_MAX;
   static const double CAMOUFLAGE_MIN;
  

   static int              next;

private :
   int               identite;
   int               x, y;
   int               age; //en nombre de tours

   bool hasEye;
   bool hasEar;
   bool hasCamouflage;
   bool hasNageoire;
   bool hasCarapace;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   double            champ_angulaire;
   double            distance_yeux;
   double            capacite_detection_yeux; 
   double            plage_oreilles; 
   double            capacite_detection_oreille; 
   double            multiplicateur_nageoire;
   double            reducteur_carapace;
   double            reducteur_carapace_mort;
   double            camouflage;
   

   T                 * couleur;

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

   double aleatoireEntre(double min, double max);

  

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
