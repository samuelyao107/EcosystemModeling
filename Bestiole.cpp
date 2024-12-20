#include <chrono>
#include <functional>
#include "Bestiole.h"



#include "Milieu.h"


#include "Kamikaze.h"
#include "Prevoyant.h"
#include "Peureuse.h"
#include "Gregaire.h"

#include <thread>
#include <cstdlib>
#include <cmath>



const double     Bestiole::AFF_SIZE = 8.;
const double     Bestiole::MAX_VITESSE = 10.;
const double     Bestiole::LIMITE_VUE = 30.;
const double     Bestiole::CHAMP_ANGULAIRE_MAX = 0.90;
const double     Bestiole::CHAMP_ANGULAIRE_MIN = 0;
const double     Bestiole::DISTANCE_YEUX_MAX = 270;
const double     Bestiole::DISTANCE_YEUX_MIN = 0;
const double     Bestiole::CAPACITE_DETECTION_YEUX_MAX = 1.;
const double     Bestiole::CAPACITE_DETECTION_YEUX_MIN = 0.;
const double     Bestiole::PLAGE_OREILLES_MAX= 75.;
const double     Bestiole::PLAGE_OREILLES_MIN= 0.;
const double     Bestiole::CAPACITE_DETECTION_OREILLE_MAX = 1.;
const double     Bestiole::CAPACITE_DETECTION_OREILLE_MIN = 0.;
const double     Bestiole::MULTIPLICATEUR_NAGEOIRE_MAX= 20.;
const double     Bestiole::REDUCTEUR_CARAPACE_MAX= 20.;
const double     Bestiole::REDUCTEUR_CARAPACE_MORT_MAX= 5.;
const double     Bestiole::CAMOUFLAGE_MAX= 10.;
const double     Bestiole::CAMOUFLAGE_MIN= 0.;


int               Bestiole::next = 0;


Bestiole::Bestiole(std::unique_ptr<IComportementStrategy> &&strategy): strategy_(std::move(strategy))
{
  

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;

   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
   hasEye= rand() % 2; 
   hasEar= rand() % 2; 
   hasCamouflage= 0;//rand() % 2; 
   hasNageoire= rand() % 2; 
   hasCarapace= rand() % 2; 
   hasMultipleBehavior = 0;
   behaviorNb =0;
   cible = nullptr;
   death = aleatoireEntre(0, 1) ;
   champ_angulaire = aleatoireEntre(CHAMP_ANGULAIRE_MIN, CHAMP_ANGULAIRE_MAX) ;
   distance_yeux= aleatoireEntre(DISTANCE_YEUX_MIN, DISTANCE_YEUX_MAX) ;
   capacite_detection_yeux= aleatoireEntre(CAPACITE_DETECTION_YEUX_MIN, CAPACITE_DETECTION_YEUX_MAX) ; 
   plage_oreilles= aleatoireEntre(PLAGE_OREILLES_MIN, PLAGE_OREILLES_MAX) ;
   capacite_detection_oreille= aleatoireEntre(CAPACITE_DETECTION_OREILLE_MIN, CAPACITE_DETECTION_OREILLE_MAX) ;
   multiplicateur_nageoire= aleatoireEntre(1.0, MULTIPLICATEUR_NAGEOIRE_MAX) ;
   reducteur_carapace= aleatoireEntre(1.0, REDUCTEUR_CARAPACE_MAX) ;
   reducteur_carapace_mort= aleatoireEntre(1.0, REDUCTEUR_CARAPACE_MORT_MAX) ;
   camouflage= aleatoireEntre(CAMOUFLAGE_MIN, CAMOUFLAGE_MAX) ;
   couleur = new T[ 3 ];
   setColorByBehavior();

}


Bestiole::Bestiole(const Bestiole & b)
{
    identite = ++next;

  //  cout << "const Bestiole (" << identite << ") par copie" << endl;

    
    x = b.x;
    y = b.y;
    cumulX = 0.;
    cumulY = 0.;
    orientation = b.orientation;
    vitesse = b.vitesse;
    
    hasEye = b.hasEye;               
    hasEar = b.hasEar;               
    hasCamouflage = b.hasCamouflage; 
    hasNageoire = b.hasNageoire;     
    hasCarapace = b.hasCarapace;     
    hasMultipleBehavior = b. hasMultipleBehavior;
    behaviorNb = b.behaviorNb;
    
    
    
    champ_angulaire = b.champ_angulaire;           
    distance_yeux = b.distance_yeux;                
    capacite_detection_yeux = b.capacite_detection_yeux;
    plage_oreilles = b.plage_oreilles;              
    capacite_detection_oreille = b.capacite_detection_oreille; 
    multiplicateur_nageoire = b.multiplicateur_nageoire; 
    reducteur_carapace = b.reducteur_carapace;     
    reducteur_carapace_mort = b.reducteur_carapace_mort;  
    camouflage = b.camouflage; 

   
    couleur = new T[3];
    memcpy(couleur, b.couleur, 3 * sizeof(T));
}




Bestiole::~Bestiole( void )
{

   

   delete[] couleur;

  // cout << "dest Bestiole" << endl;

}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{
   
   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}

void Bestiole::setVitesse(double _vitesse){
   vitesse = _vitesse;
}
void Bestiole::action( Milieu & monMilieu )
{

   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}


void Bestiole::draw(UImg& support) {
    drawBody(support);         // Corps de la bestiole
    drawTail(support);         // Queue
    drawFins(support);         // Nageoires
    drawEars(support);         // Cercle d'audition
    drawCamouflage(support);   // Effet de camouflage
    drawConeVision(support);   // Cône de vision
}




void Bestiole::drawBody(UImg& support) {
    if (hasCarapace) {
        // Avec carapace : carré et ellipse
        double tailleCarapace = AFF_SIZE + 3;
        support.draw_rectangle(
            x - tailleCarapace / 2, y - tailleCarapace / 2,
            x + tailleCarapace / 2, y + tailleCarapace / 2,
            couleur
        );

        double xEllipse = x - cos(orientation) * tailleCarapace / 2;
        double yEllipse = y + sin(orientation) * tailleCarapace / 2;
        support.draw_ellipse(xEllipse, yEllipse, AFF_SIZE / 1.5, AFF_SIZE / 3., -orientation / M_PI * 180., couleur);
    } else {
        // Sans carapace : cercle et ellipse
        support.draw_circle(x, y, AFF_SIZE / 1.5, couleur);
        double xEllipse = x - cos(orientation) * AFF_SIZE / 2;
        double yEllipse = y + sin(orientation) * AFF_SIZE / 2;
        support.draw_ellipse(xEllipse, yEllipse, AFF_SIZE / 1.5, AFF_SIZE / 3., -orientation / M_PI * 180., couleur);
    }
}

void Bestiole::drawTail(UImg& support) {
    double xt = x + cos(orientation) * AFF_SIZE / 2.1;
    double yt = y - sin(orientation) * AFF_SIZE / 2.1;
    support.draw_circle(xt, yt, AFF_SIZE / 3, couleur);
}


void Bestiole::drawFins(UImg& support) {
    if (hasNageoire) {
        T couleurContour[3] = {0, 0, 0};  // Noir pour le contour
        T couleurNageoire[3] = {0, 0, 255};  // Bleu pour les nageoires

        double longueurNageoire = AFF_SIZE * 0.8; // Longueur des nageoires
        double largeurNageoire = AFF_SIZE * 2.0;  // Largeur des nageoires

        // Calcul des sommets des triangles pour les nageoires
        double xLeftBase = x + cos(orientation + M_PI / 2) * largeurNageoire;
        double yLeftBase = y - sin(orientation + M_PI / 2) * largeurNageoire;

        double xRightBase = x + cos(orientation - M_PI / 2) * largeurNageoire;
        double yRightBase = y - sin(orientation - M_PI / 2) * largeurNageoire;

        double xLeftTip = xLeftBase + cos(orientation) * longueurNageoire;
        double yLeftTip = yLeftBase - sin(orientation) * longueurNageoire;

        double xRightTip = xRightBase + cos(orientation) * longueurNageoire;
        double yRightTip = yRightBase - sin(orientation) * longueurNageoire;

        // Dessiner la nageoire gauche
        support.draw_triangle(xLeftBase, yLeftBase, xLeftTip, yLeftTip, x, y, couleurNageoire);
        support.draw_triangle(xLeftBase, yLeftBase, xLeftTip, yLeftTip, x, y, couleurContour, 1, 'c'); // Contour

        // Dessiner la nageoire droite
        support.draw_triangle(xRightBase, yRightBase, xRightTip, yRightTip, x, y, couleurNageoire);
        support.draw_triangle(xRightBase, yRightBase, xRightTip, yRightTip, x, y, couleurContour, 1, 'c'); // Contour
    }
}




void Bestiole::drawEars(UImg& support) {
    if (hasEar) {
        T couleurOreilles[3] = {0, 255, 0};
        double rayonAudition = plage_oreilles * 1.5;
        float transparence = 0.15f;
        support.draw_circle(x, y, rayonAudition, couleurOreilles, transparence);
    }
}


void Bestiole::drawCamouflage(UImg& support) {
    if (hasCamouflage) {
        T couleurNuage[3] = {100, 100, 100};
        float transparence = 0.3f;
        int nombreCercles = 25;
        double rayonBase = AFF_SIZE + camouflage * 2;

        for (int i = 0; i < nombreCercles; ++i) {
            double angle = static_cast<double>(rand()) / RAND_MAX * 2 * M_PI;
            double distance = rayonBase * (0.2 + static_cast<double>(rand()) / RAND_MAX * 0.5);
            double xNuage = x + cos(angle) * distance;
            double yNuage = y + sin(angle) * distance;

            double rayonPetitCercle = rayonBase * (0.1 + static_cast<double>(rand()) / RAND_MAX * 0.15);
            support.draw_circle(xNuage, yNuage, rayonPetitCercle, couleurNuage, transparence);
        }
    }
}


void Bestiole::drawConeVision(UImg& support) {
    if (hasEye) {
        T couleurCone[3] = {255, 0, 0};
        float transparenceCone = 0.15f;

        double orientationNormalized = fmod(orientation, 2 * M_PI);
        if (orientationNormalized < 0) {
            orientationNormalized += 2 * M_PI;
        }

        double angleStart = orientationNormalized - champ_angulaire / 2;
        double angleEnd = orientationNormalized + champ_angulaire / 2;

        double x1 = x + cos(angleStart) * distance_yeux;
        double y1 = y - sin(angleStart) * distance_yeux;
        double x2 = x + cos(angleEnd) * distance_yeux;
        double y2 = y - sin(angleEnd) * distance_yeux;

        support.draw_triangle(x, y, x1, y1, x2, y2, couleurCone, transparenceCone);
    }
}

void Bestiole::setColorByBehavior() {
    if (dynamic_cast<Kamikaze*>(strategy_.get())) {
        couleur[0] = 255; // Rouge
        couleur[1] = 0;
        couleur[2] = 0;
    } else if (dynamic_cast<Prevoyant*>(strategy_.get())) {
        couleur[0] = 0;   // Bleu
        couleur[1] = 0;
        couleur[2] = 255;
    } else if (dynamic_cast<Peureuse*>(strategy_.get())) {
        couleur[0] = 0;   // Vert
        couleur[1] = 255;
        couleur[2] = 0;
    } else if (dynamic_cast<Gregaire*>(strategy_.get())) {
        couleur[0] = 255; // Jaune
        couleur[1] = 255;
        couleur[2] = 0;
    } else {
        couleur[0] = 128; // Gris par défaut
        couleur[1] = 128;
        couleur[2] = 128;
    }
}


 std::unique_ptr<IComportementStrategy>& Bestiole::get_strategy() {
    return strategy_;
}
double Bestiole::getX() const{
   return x;
}

double Bestiole::getY() const{
   return y;
}

bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}

double Bestiole::getDeath(){
   return death;
}

void Bestiole::setDeath(double _death){
   death = _death;
}

bool Bestiole::gethasCarapace(){
   return hasCarapace;
}

double Bestiole::getReducteurCarapaceMort(){
   return reducteur_carapace_mort;
}


bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;
   double         angle;

   angle = atan2(b.y - y, b.x-x) - orientation;
   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   if(b.hasCamouflage && b.camouflage > capacite_detection_yeux){
      return false;
   }else {
      return ((angle > -champ_angulaire/2)&&(angle < champ_angulaire/2)&& dist < distance_yeux);
   }
   
  

}

bool Bestiole::jeTEntends(const Bestiole & b ) const{
      double         dist;

      dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );

      if(b.hasEar && b.camouflage > capacite_detection_oreille){
          return false;
      }else {
           return ( dist < plage_oreilles);
   }
}

double Bestiole::aleatoireEntre(double min, double max) {
    return min + (static_cast<double>(rand()) / RAND_MAX) * (max - min);
}

void Bestiole::actionCarapace() {
    if(reducteur_carapace  !=0 ){
       vitesse *= (1 / reducteur_carapace );
    }
    
}

void Bestiole::actionNageoire() {
   if(multiplicateur_nageoire!=0){
      vitesse *= multiplicateur_nageoire ;
   }
}

void Bestiole::init(){
   if(this->hasCarapace){
      this->actionCarapace();
   }
   if (this->hasNageoire){
      this ->actionNageoire();
   }   
}

void Bestiole::set_strategy(std::unique_ptr<IComportementStrategy> &&strategy)
    {
        strategy_ = std::move(strategy);
        setColorByBehavior();
    }


void Bestiole::applyStrategy(Bestiole & b, Milieu & m){
   //if(strategy_){
      strategy_->behavior(b, m);
   //}
}  


  IComportementStrategy* Bestiole::get_strategyX(){
        return strategy_.get();
    }

double Bestiole::getOrientation(){
   return orientation;
}

void Bestiole::setOrientation(double _orientation){
   orientation = _orientation;
}

 double Bestiole::getVitesse(){
   return vitesse;
 }


