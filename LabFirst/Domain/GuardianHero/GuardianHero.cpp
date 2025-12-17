#include "GuardianHero.h"

GuardianHero::GuardianHero()
    : BaseHero("Unknown", "Guardian", "Shield"),
      armorLevel(0),
      shieldType("None")
{
}

GuardianHero::GuardianHero(const GuardianHero& other)
    : BaseHero(other),
      armorLevel(other.armorLevel),
      shieldType(other.shieldType)
{
}

GuardianHero::GuardianHero(const std::string& name,
                           const std::string& itemInHand,
                           int armorLevel,
                           const std::string& shieldType)
    : BaseHero(name, "Guardian", itemInHand),
      armorLevel(armorLevel),
      shieldType(shieldType)
{
}

GuardianHero::~GuardianHero() {}


int GuardianHero::getArmorLevel() const {
    return armorLevel;
}

std::string GuardianHero::getShieldType() const {
    return shieldType;
}

void GuardianHero::setArmorLevel(int armorLevel) {
    this->armorLevel = armorLevel;
}

void GuardianHero::setShieldType(const std::string& shieldType) {
    this->shieldType = shieldType;
}

GuardianHero& GuardianHero::operator=(const GuardianHero& other) {
    if (this != &other) {
        BaseHero::operator=(other);
        armorLevel = other.armorLevel;
        shieldType = other.shieldType;
    }
    return *this;
}

BaseHero* GuardianHero::clone() const {
    return new GuardianHero(*this);
}

std::ostream& operator<<(std::ostream& os, const GuardianHero& hero) {
    os << static_cast<const BaseHero&>(hero)
       << " | Armor: " << hero.armorLevel
       << " | Shield: " << hero.shieldType;
    return os;
}
