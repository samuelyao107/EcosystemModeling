
#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyant.h"
#include <iostream>
#include <string>



int main()
{
    // Get aquarium dimensions and frame rate
    Aquarium ecosysteme(1280, 720, 30);

    // Total number of Bestiole
     int totalBestioles = 50;

    // User input for percentages
    int kamikazePercent, prevoyantPercent, peureusePercent, gregairePercent, multiPercent;
    std::cout << "Enter the number of Bestioles: "<<std::endl;
    std::cin >> totalBestioles;
    std::cout << "Enter the percentage of Kamikaze Bestioles: "<<std::endl;
    std::cin >> kamikazePercent;

    std::cout << "Enter the percentage of Prevoyant Bestioles: "<<std::endl;
    std::cin >> prevoyantPercent;

    std::cout << "Enter the percentage of Peureuse Bestioles: "<<std::endl;
    std::cin >> peureusePercent;

    std::cout << "Enter the percentage of Gregaire Bestioles: "<<std::endl;
    std::cin >> gregairePercent;

    std::cout << "Enter the percentage of Multi Bestioles: "<<std::endl;
    std::cin >> multiPercent;

    // Check if percentages sum to 100
    while (kamikazePercent + prevoyantPercent + peureusePercent + gregairePercent + multiPercent != 100) {
        std::cout << "Percentages do not add up to 100. Please enter again.\n"<<std::endl;
        std::cout << "Kamikaze: "<<std::endl;
        std::cin >> kamikazePercent;
        std::cout << "Prevoyant: "<<std::endl;
        std::cin >> prevoyantPercent;
        std::cout << "Peureuse: "<<std::endl;
        cin >> peureusePercent;
        std::cout << "Gregarie: "<<std::endl;
        cin >> gregairePercent;
        std::cout << "Multi: "<<std::endl;
        std::cin >> multiPercent;
    }

    // Calculate number of each type
    int kamikazeCount = totalBestioles * kamikazePercent / 100;
    int prevoyantCount = totalBestioles * prevoyantPercent / 100;
    int peureuseCount = totalBestioles * peureusePercent / 100;
    int gregaireCount = totalBestioles * peureusePercent / 100;
    int multiCount = totalBestioles - kamikazeCount - prevoyantCount - peureuseCount - gregaireCount;

    // Create and add Bestiole instances
    for (int i = 0; i < kamikazeCount; ++i) {
        Bestiole b;
        b.set_strategy(std::make_unique<Kamikaze>());
        b.behaviorNb =1;
        ecosysteme.getMilieu().addMember(b);
    }

    for (int i = 0; i < prevoyantCount; ++i) {
        Bestiole b;
        b.set_strategy(std::make_unique<Prevoyant>());
         b.behaviorNb =2;
        ecosysteme.getMilieu().addMember(b);
    }

    for (int i = 0; i < peureuseCount; ++i) {
        Bestiole b;
        b.set_strategy(std::make_unique<Peureuse>());
         b.behaviorNb =3;
        ecosysteme.getMilieu().addMember(b);
    }

    for (int i = 0; i < gregaireCount; ++i) {
        Bestiole b;
        b.set_strategy(std::make_unique<Gregaire>());
        b.behaviorNb =4;
        ecosysteme.getMilieu().addMember(b);
    }

    for (int i = 0; i < multiCount; ++i) {
        Bestiole b;
        b.set_strategy(std::make_unique<Gregaire>());
        b.hasMultipleBehavior= 1;
        ecosysteme.getMilieu().addMember(b);
    }


    // Run the simulation
    ecosysteme.run();

    return 0;
}


























































/*#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include "Gregaire.h"
#include "Peureuse.h"
#include "Kamikaze.h"
#include "Prevoyant.h"
#include "Multi.h"
#include <iostream>
#include <string>



int main()
{
    // Get aquarium dimensions and frame rate
    Aquarium ecosysteme(1280, 720, 30);

    // Total number of Bestiole
    const int totalBestioles = 50;

    // User input for percentages
    int kamikazePercent, prevoyantPercent, peureusePercent, gregairePercent, multiPercent;

    std::cout << "Enter the percentage of Kamikaze Bestioles: "<<std::endl;
    std::cin >> kamikazePercent;

    std::cout << "Enter the percentage of Prevoyant Bestioles: "<<std::endl;
    std::cin >> prevoyantPercent;

    std::cout << "Enter the percentage of Peureuse Bestioles: "<<std::endl;
    std::cin >> peureusePercent;

    std::cout << "Enter the percentage of Gregaire Bestioles: "<<std::endl;
    std::cin >> gregairePercent;
   

    std::cout << "Enter the percentage of Multi Bestioles: "<<std::endl;
    std::cin >> multiPercent;

    // Check if percentages sum to 100
    while (kamikazePercent + prevoyantPercent + peureusePercent + gregairePercent+ multiPercent!= 100) {
        std::cout << "Percentages do not add up to 100. Please enter again.\n"<<std::endl;
        std::cout << "Kamikaze: "<<std::endl;
        std::cin >> kamikazePercent;
        std::cout << "Prevoyant: "<<std::endl;
        std::cin >> prevoyantPercent;
        std::cout << "Peureuse: "<<std::endl;
        cin >> peureusePercent;
        std::cout << "Gregarie: "<<std::endl;
        cin >> gregairePercent;

    }

    // Calculate number of each type
    int kamikazeCount = totalBestioles * kamikazePercent / 100;
    int prevoyantCount = totalBestioles * prevoyantPercent / 100;
    int peureuseCount = totalBestioles * peureusePercent / 100;
    int gregaireCount = totalBestioles * gregairePercent / 100;
    int multiCount = totalBestioles - kamikazeCount - prevoyantCount - peureuseCount - gregaireCount;


    // Create and add Bestiole instances
    for (int i = 0; i < kamikazeCount; ++i) {
        Bestiole b;
       // b.set_strategy(std::make_unique<Kamikaze>());
        ecosysteme.getMilieu().addMember(b,2);
    }

    for (int i = 0; i < prevoyantCount; ++i) {
        Bestiole b;
       // b.set_strategy(std::make_unique<Prevoyant>());
        ecosysteme.getMilieu().addMember(b,4);
    }

    for (int i = 0; i < peureuseCount; ++i) {
        Bestiole b;
        //b.set_strategy(std::make_unique<Peureuse>());
        ecosysteme.getMilieu().addMember(b,3);
    }

    for (int i = 0; i < gregaireCount; ++i) {
        Bestiole b;
        //b.set_strategy(std::make_unique<Gregaire>());
        ecosysteme.getMilieu().addMember(b,1);

    for (int i = 0; i < multiCount; ++i) {
        Bestiole b;
        //b.set_strategy(std::make_unique<Multi>());
        ecosysteme.getMilieu().addMember(b,5);
    }

    }

 

    // Run the simulation
    ecosysteme.run();

    return 0;
}

*/















/*#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 1280, 720, 30 );

   for ( int i = 1; i <= 50; ++i )
      ecosysteme.getMilieu().addMember( Bestiole() );
   ecosysteme.run();


   return 0;

}
*/ 
