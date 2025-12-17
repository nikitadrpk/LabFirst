#pragma once
#include "../BaseHero/BaseHero.h"

class AssasinHero : public BaseHero {
private:
    int stealthLevel;
    bool hasPoison; 

public:
    AssasinHero();
    AssasinHero(const AssasinHero& other);
    AssasinHero(const std::string& name,
                const std::string& itemInHand,
                int stealthLevel,
                bool hasPoison);
    ~AssasinHero() override;

    int getStealthLevel() const;
    bool getHasPoison() const;  

    void setStealthLevel(int stealthLevel);
    void setHasPoison(bool hasPoison); 

    AssasinHero& operator=(const AssasinHero& other);

    BaseHero* clone() const override;

    friend std::ostream& operator<<(std::ostream& os,
                                    const AssasinHero& hero);
};