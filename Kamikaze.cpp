#include "Kamikaze.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cmath>
#include <limits>

void Kamikaze::behavior(Bestiole& b, Milieu& milieu) {
    
    if(isCibleInListe(b.cible, milieu.getListeBestioles())){
    double distance_min = std::numeric_limits<double>::infinity();
  

    for (const auto& autre_bestiole : milieu.getListeBestioles()) {
        if (*autre_bestiole == b) continue;  

        double distance = calculerDistance(b, *autre_bestiole);

        if (distance < distance_min) {
            distance_min = distance;
            b.cible = autre_bestiole.get();  
        }
    }

    if (b.cible) {
        double orientation_cible = calculerOrientation(b, *(b.cible)) + M_PI;;
        b.setOrientation(orientation_cible);  // Adjust the orientation of 'b'
    }

    }
}

double Kamikaze::calculerDistance(const Bestiole& b1, const Bestiole& b2) {
    double dx = b1.getX() - b2.getX();
    double dy = b1.getY() - b2.getY();
    return std::sqrt(dx * dx + dy * dy);
}

double Kamikaze::calculerOrientation(const Bestiole& b1, const Bestiole& b2) {
    double dx = b2.getX() - b1.getX();
    double dy = b2.getY() - b1.getY();
    return std::atan2(dy, dx);
}

bool Kamikaze::isCibleInListe(const Bestiole* cible, std::vector<std::unique_ptr<Bestiole>>& listeBestioles) {
    // Use std::find_if to search for a match
    auto it = std::find_if(
        listeBestioles.begin(), 
        listeBestioles.end(),
        [cible](const std::unique_ptr<Bestiole>& bestiole) {
            return bestiole.get() == cible;  // Compare raw pointers
        });

    // Return true if found, false otherwise
    return it != listeBestioles.end();
}