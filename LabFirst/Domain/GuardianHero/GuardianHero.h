#pragma once
#include "../BaseHero/BaseHero.h"

class GuardianHero : public BaseHero {
private:
    int armorLevel;
    MyString shieldType;

public:
    GuardianHero();
    GuardianHero(const GuardianHero& other);
    GuardianHero(const char* name,
                 const char* itemInHand,
                 int armorLevel,
                 const char* shieldType);
    ~GuardianHero() override;

    int getArmorLevel() const;
    const char* getShieldType() const;

    void setArmorLevel(int armorLevel);
    void setShieldType(const char* shieldType);

    GuardianHero& operator=(const GuardianHero& other);

    void print(std::ostream& os) const override;
    BaseHero* clone() const override;
};
