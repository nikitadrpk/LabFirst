#pragma once
#include <string>
#include <ostream>


class BaseHero {
protected:
    std::string name;
    std::string heroClass;
    std::string itemInHand;

public:
    BaseHero();
    BaseHero(const BaseHero& other);
    BaseHero(const std::string& name,
             const std::string& heroClass,
             const std::string& itemInHand);

    virtual ~BaseHero();
    
    std::string getName() const;
    std::string getHeroClass() const;
    std::string getItemInHand() const;  

    void setName(const std::string& name);
    void setHeroClass(const std::string& heroClass);
    void setItemInHand(const std::string& itemInHand); 

    BaseHero& operator=(const BaseHero& other);
    
    virtual BaseHero* clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const BaseHero& hero);
};
