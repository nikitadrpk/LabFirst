#pragma once
#include "../BaseHero/BaseHero.h"

class AssasinHero : public BaseHero {
private:
    int stealthLevel;
    bool hasPoison;

public:
    AssasinHero();
    AssasinHero(const AssasinHero& other);
    AssasinHero(const char* name,
                const char* itemInHand,
                int stealthLevel,
                bool hasPoison);
    ~AssasinHero() override;

    int getStealthLevel() const;
    bool getHasPoison() const;

    void setStealthLevel(int stealthLevel);
    void setHasPoison(bool hasPoison);

    AssasinHero& operator=(const AssasinHero& other);

    void print(std::ostream& os) const override;
    BaseHero* clone() const override;
};
