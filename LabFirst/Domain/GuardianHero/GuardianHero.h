#pragma once
#include "../BaseHero/BaseHero.h"

class GuardianHero : public BaseHero {
private:
    int armorLevel;           
    std::string shieldType;   

public:
    GuardianHero();
    GuardianHero(const GuardianHero& other);
    GuardianHero(const std::string& name,
                 const std::string& itemInHand,
                 int armorLevel,
                 const std::string& shieldType);

    ~GuardianHero() override;
    
    int getArmorLevel() const;
    std::string getShieldType() const;
    
    void setArmorLevel(int armorLevel);
    void setShieldType(const std::string& shieldType);

    GuardianHero& operator=(const GuardianHero& other);

    BaseHero* clone() const override;
        
    friend std::ostream& operator<<(std::ostream& os,
                                    const GuardianHero& hero);
};
