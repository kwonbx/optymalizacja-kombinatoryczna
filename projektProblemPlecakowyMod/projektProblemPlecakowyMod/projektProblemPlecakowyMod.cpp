#include <iostream>
#include "knapsack.cpp"
#include "generator.cpp"
#include "readJsonFile.cpp"

using namespace std;

int main()  
{
    vector<Item> items{
        {1, 20, 30, 50, 2},
        {2, 10, 10, 20, 0},
        {3, 10, 10, 20, 2},
        {4, 40, 10, 40, 1},
        {5, 15, 20, 30, 1},
        {6, 10, 15, 40, 0}
    };

    double maxWeight = 60;
    double maxVolume = 50;

    vector<Item> solution = knapsackProblemBruteForce(items, maxWeight, maxVolume);
    double weight = 0;
    double volume = 0;
    double value = 0;

    cout << "ID przedmiotow: ";

    for (int i = 0; i < solution.size(); i++) {
        cout << solution[i].id << ", ";
        weight += solution[i].weight;
        volume += solution[i].volume;
        value += solution[i].value;
    }
    cout << "\nSumaryczna waga: " << weight << "\nSumaryczna objetosc: " << volume << "\nSumaryczna wartosc: " << value;
}