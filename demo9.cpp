#include<bits/stdc++.h>
using namespace std;

class Hero{
    private:
    int health;

    public:
    int *kills;
    static int instances;
    void getHealth(){
        cout<<health<<endl;
    }
    void setHealth(int health){
        this->health = health;
    }
    void getKills(){
        cout<<*kills<<endl;
    }
    void setKills(int k){
        *kills = k;
    }


    Hero(){
        instances++;
        cout<<"default empty constructor"<<endl;
    }

    Hero(int health){
        setHealth(health);
        kills = new int;
        instances++;
    }
    Hero(Hero &b){
        this->health = b.health;
        this->kills = new int;
        *kills = *b.kills;
        cout<<"Copy constructor called"<<endl;
    }
    ~Hero(){
        cout<<"Destructor called"<<endl;
        delete(kills);
    }
};

int Hero::instances = 0;

int main(){
    Hero Hero(5);
    Hero.getHealth();
    cout<<Hero::instances<<endl;
}