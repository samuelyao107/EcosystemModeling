#include "Milieu.h"
#include "Bestiole.h"
#include "Multi.h"
#include "Kamikaze.h"
#include "Peureuse.h"
#include "Prevoyant.h"
#include "Gregaire.h"

void Multi::behavior(Bestiole & b, Milieu & milieu) {
    Peureuse peureuseBehavior;
    Kamikaze kamikazeBehavior;
    Prevoyant prevoyantBehavior;
    Gregaire gregaireBehavior;

    // Get current timestamp
    static double elapsedTime = 0.0;       // For accumulating time
    const double deltaTime = 0.1;          // Time step per call
    elapsedTime += deltaTime;

    // Time interval for switching behavior (in seconds)
    const double behaviorSwitchInterval = 15.0;

    // Calculate the current behavior index
    int behaviorIndex = static_cast<int>(elapsedTime / behaviorSwitchInterval) % 4;

    // Calling different behaviors based on the behavior index
    switch (behaviorIndex) {
        case 0:
            peureuseBehavior.behavior(b, milieu);
            break;
        case 1:
            kamikazeBehavior.behavior(b, milieu);
            break;
        case 2:
            prevoyantBehavior.behavior(b, milieu);
            break;
        case 3:
            gregaireBehavior.behavior(b, milieu);
            break;
    }
}