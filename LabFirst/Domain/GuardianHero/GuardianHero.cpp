#include "GuardianHero.h"

GuardianHero::GuardianHero()
    : BaseHero("Unknown", "Guardian", "Shield"),
      armorLevel(0),
      shieldType("None") {}

GuardianHero::GuardianHero(const GuardianHero& other)
    : BaseHero(other),
      armorLevel(other.armorLevel),
      shieldType(other.shieldType) {}

GuardianHero::GuardianHero(const char* name,
                           const char* itemInHand,
                           int armorLevel,
                           const char* shieldType)
    : BaseHero(name, "Guardian", itemInHand),
      armorLevel(armorLevel),
      shieldType(shieldType) {}

GuardianHero::~GuardianHero() = default;

int GuardianHero::getArmorLevel() const { return armorLevel; }
const char* GuardianHero::getShieldType() const { return shieldType.c_str(); }

void GuardianHero::setArmorLevel(int armorLevel) { this->armorLevel = armorLevel; }
void GuardianHero::setShieldType(const char* shieldType) { this->shieldType.set(shieldType); }

GuardianHero& GuardianHero::operator=(const GuardianHero& other) {
    if (this != &other) {
        BaseHero::operator=(other);
        armorLevel = other.armorLevel;
        shieldType = other.shieldType;
    }
    return *this;
}

void GuardianHero::print(std::ostream& os) const {
    BaseHero::print(os);
    os << " | Armor: " << armorLevel
       << " | Shield: " << shieldType;
}

BaseHero* GuardianHero::clone() const {
    return new GuardianHero(*this);
}
