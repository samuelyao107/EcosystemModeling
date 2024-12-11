#include "Aquarium.h"

#include "Milieu.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {
         int gregaire =0;
         int peureuse =0;
         int prevoyant=0;
         int kamikaze=0;
         int multi=0;
      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
      }

      for ( auto it = flotte->getListeBestioles().begin(); it != flotte->getListeBestioles().end();it++)
      {
        
       // auto strategy = it->get()->get_strategyX();
       
       
        if (it->get()->behaviorNb ==4 && !it->get()->hasMultipleBehavior) {
            gregaire++;
        } else if (it->get()->behaviorNb ==3 && !it->get()->hasMultipleBehavior) {
            peureuse++;
        } else if (it->get()->behaviorNb ==1 && !it->get()->hasMultipleBehavior) {
            kamikaze++;
        } else if(it->get()->behaviorNb ==2 && !it->get()->hasMultipleBehavior) {
            prevoyant++;
        } else if (it->get()->hasMultipleBehavior){
          multi++;
        }
        else{

        }

       }

      std::cout<<"Bestioles Kamikazes: "<<kamikaze<<std::endl;
      std::cout<<"Bestioles Peureuses: "<<peureuse<<std::endl;
      std::cout<<"Bestioles Prevoyantes: "<<prevoyant<<std::endl;
      std::cout<<"Bestioles Gregaires: "<<gregaire<<std::endl;
      std::cout<<"Bestioles avec comportement multiple: "<<multi<<std::endl;
    
      flotte->step();
      display( *flotte );

      wait( delay );

   } // while

}
