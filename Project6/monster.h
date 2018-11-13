#include <iostream>

class Monster{
    private:
        std::string name;
        int health;
        int strength;
        int defense;
        int speed;

        static const int MAX_HEALTH = 100;
        static const int MAX_STRENGTH = 50;
        static const int MAX_DEFENSE = 100;
        static const int MAX_SPEED = 20;
    public:
        //Constructors
        Monster();
        Monster(std::string name, int health, int strength, int defense, int speed);
        Monster(Monster& monster);
        ~Monster();

        void attack(Monster& monster);
        void print();

        //Getter Methods
        std::string getName();
        int getHealth();
        int getStrength();
        int getDefense();
        int getSpeed();

        //Setter Methods
        void setName(std::string name);
        void setHealth(int health);
        void setStrength(int strength);
        void setDefense(int defense);
        void setSpeed(int speed);
};