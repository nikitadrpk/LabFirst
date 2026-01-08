#include "ConsoleApp.h"

#include <iostream>
#include "../Domain/AssasinHero/AssasinHero.h"
#include "../Domain/GuardianHero/GuardianHero.h"
#include "../Controller/HeroController/HeroController.h"

void ConsoleApp::run() {
    AssasinHero a0;                 
    GuardianHero g0;
    
    AssasinHero a1("Ezio", "Blade", 80, true);                 
    GuardianHero g1("Brienne", "Sword", 90, "Tower Shield");   

    AssasinHero a2(a1);             
    GuardianHero g2(g1);            
    
    a0 = a2;
    g0 = g2;
    
    a0.setName("Altair");
    a0.setItemInHand("Dagger");
    a0.setStealthLevel(99);
    a0.setHasPoison(false);

    std::cout << "Assasin getters: "
              << a0.getName() << ", "
              << a0.getItemInHand() << ", stealth="
              << a0.getStealthLevel() << ", poison="
              << (a0.getHasPoison() ? "Yes" : "No") << "\n";

    g0.setName("GuardianName");
    g0.setItemInHand("Hammer");
    g0.setArmorLevel(77);
    g0.setShieldType("Kite Shield");

    std::cout << "Guardian getters: "
              << g0.getName() << ", "
              << g0.getItemInHand() << ", armor="
              << g0.getArmorLevel() << ", shield="
              << g0.getShieldType() << "\n";
    
    BaseHero& br1 = a1;
    BaseHero& br2 = g1;
    std::cout << "Polymorphic print 1: " << br1 << "\n";
    std::cout << "Polymorphic print 2: " << br2 << "\n";
    
    controller.addHero(a1);
    controller.addHero(g1);

    std::cout << "\n" << controller.getTable() << "\n";
    std::cout << "Count: " << controller.count() << "\n";
    
    AssasinHero a3("Kassandra", "Spear", 70, true);
    controller.updateHero(0, a3);
    controller.removeHero(1);

    std::cout << "After update/remove:\n";
    std::cout << controller.getTable() << "\n";
    
    if (controller.count() > 0) {
        const HeroTable& tConst = controller.getTable();
        std::cout << "Const operator[] [0]: " << tConst[0] << "\n";

        HeroTable& tMut = controller.getTableMutable();
        std::cout << "Non-const operator[] [0]: " << tMut[0] << "\n";
    }
    
    BaseHero* c1 = a1.clone();
    BaseHero* c2 = g1.clone();
    std::cout << "Clone A: " << *c1 << "\n";
    std::cout << "Clone G: " << *c2 << "\n";
    delete c1;
    delete c2;
}
