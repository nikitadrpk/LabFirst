#include "ConsoleApp.h"

#include <iostream>
#include "../Domain/AssasinHero/AssasinHero.h"
#include "../Domain/GuardianHero/GuardianHero.h"
#include "../Controller/HeroController/HeroController.h"

void ConsoleApp::run() {
    AssasinHero aDefault;
    GuardianHero gDefault;
    
    AssasinHero aFull("Ezio", "Hidden Blade", 80, true);
    GuardianHero gFull("Brienne", "Sword", 90, "Tower Shield");
    
    AssasinHero aCopy(aFull);
    GuardianHero gCopy(gFull);
    
    aDefault = aCopy;
    gDefault = gCopy;

    aDefault.setStealthLevel(99);
    aDefault.setHasPoison(false);

    int stealth = aDefault.getStealthLevel();
    bool poison = aDefault.getHasPoison();

    gDefault.setArmorLevel(77);
    gDefault.setShieldType("Kite Shield");

    int armor = gDefault.getArmorLevel();
    std::string shield = gDefault.getShieldType();

    aDefault.setName("Altair");
    aDefault.setHeroClass("Assasin"); 
    aDefault.setItemInHand("Dagger");

    std::cout << "Base getters: "
              << aDefault.getName() << ", "
              << aDefault.getHeroClass() << ", "
              << aDefault.getItemInHand() << "\n";
    
    std::cout << "Assasin getters: stealth=" << stealth
              << ", poison=" << (poison ? "Yes" : "No") << "\n";
    std::cout << "Guardian getters: armor=" << armor
              << ", shield=" << shield << "\n";
    
    std::cout << "Assasin: " << aDefault << "\n";
    std::cout << "Guardian: " << gDefault << "\n";
    
    BaseHero* pCloneA = aFull.clone();
    BaseHero* pCloneG = gFull.clone();
    std::cout << "CloneA: " << *pCloneA << "\n";
    std::cout << "CloneG: " << *pCloneG << "\n";
    delete pCloneA;
    delete pCloneG;

    controller.addHero(aFull);
    controller.addHero(gFull);

    std::cout << controller.getTable() << "\n";

    AssasinHero aNew("Kassandra", "Spear", 70, true);
    controller.updateHero(0, aNew);
    controller.removeHero(1);

    std::cout << "After update/remove:\n";
    std::cout << controller.getTable() << "\n";

    const auto& tConst = controller.getTable();
    if (tConst.getCount() > 0) {               
        std::cout << "Const operator[] [0]: " << tConst[0] << "\n";
    }
}
