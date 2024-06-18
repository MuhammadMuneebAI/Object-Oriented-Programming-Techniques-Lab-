#include<iostream>
#include<string>
using namespace std;

class Animal 
{
public:
    string name;
    int age;    
};

class Elephant : public Animal 
{
public:
    int weight;
    float height;
    string food;
};

int main() 
{
    Elephant e;
    e.name = "jojo";   
    e.age = 10;       
    e.weight = 71;     
    e.height = 8.9;    
    e.food = "apple";  

    cout << "Elephant Name: " << e.name << endl;
    cout << "Age: " << e.age << " years" << endl;
    cout << "Weight: " << e.weight << " kg" << endl;
    cout << "Height: " << e.height << " meters" << endl;
    cout << "Favorite Food: " << e.food << endl;

    return 0;
}

