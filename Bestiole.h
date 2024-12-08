#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>

#include <memory>

#include "IComportementStrategy.h"

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
 

   double            death;
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

   std::unique_ptr<IComportementStrategy> strategy_;





private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole( std::unique_ptr<IComportementStrategy> &&strategy = {} );                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   bool jeTEntends( const Bestiole & b ) const;

   void actionCarapace();
   
   void actionNageoire();
   void init();
   void initCoords( int xLim, int yLim );

   double aleatoireEntre(double min, double max);

   double getX() const;

   double getY() const;

   double getDeath();

   double getReducteurCarapaceMort();

   void setDeath(double _death);

   bool gethasCarapace();

   void drawConeVision(UImg& support) ;

   void drawBody(UImg& support);

   void drawTail(UImg& support);

   void drawFins(UImg& support);

   void drawEars(UImg& support) ;

   void drawCamouflage(UImg& support);
   
   void set_strategy(std::unique_ptr<IComportementStrategy> &&strategy);

   
   void applyStrategy(Bestiole & b, Milieu & m);

   double getOrientation();

   void setOrientation(double _orientation);

   double getVitesse();
   void setVitesse(double _vitesse);

   Bestiole* cible  ;

   void setColorByBehavior();




   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
