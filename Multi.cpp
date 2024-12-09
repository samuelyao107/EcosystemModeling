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


    // 获取当前时间戳
    static double elapsedTime = 0.0;       // 用于累积时间
    const double deltaTime = 0.1;          // 每次调用时间步长
    elapsedTime += deltaTime;

    // 切换行为的时间间隔（以秒为单位）
    const double behaviorSwitchInterval = 0.2;

    // 计算当前行为索引
    int behaviorIndex = static_cast<int>(elapsedTime / behaviorSwitchInterval) % 4;

    // 根据行为索引调用不同的行为
    switch (behaviorIndex) {
        case 0:
            peureuseBehavior.behavior(b, milieu);
            
        case 1:
            kamikazeBehavior.behavior(b, milieu);
            
        case 2:
            prevoyantBehavior.behavior(b, milieu);
            
        case 3:
            gregaireBehavior.behavior(b, milieu);
            
        
            
    }





}