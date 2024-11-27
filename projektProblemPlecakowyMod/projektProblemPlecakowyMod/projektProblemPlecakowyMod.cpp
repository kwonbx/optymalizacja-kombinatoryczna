#include <iostream>
#include "knapsack.cpp"
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

void static generateData(int numItems, int numGroups, double maxWeightofItem, double maxVolumeofItem, const string& filename) {
    json j;

}

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

    vector<Item> chosenItems = knapsackProblemRandomGreedy(items, maxWeight, maxVolume);

    double totalWeight = 0;
    double totalVolume = 0;
    double totalValue = 0;

    cout << "Wybrane przedmioty:\n\n";

    for (int i = 0; i < chosenItems.size(); i++) {
        totalWeight += chosenItems[i].weight;
        totalVolume += chosenItems[i].volume;
        totalValue += chosenItems[i].value;

        cout << "ID: " << chosenItems[i].id << ", ID grupy: " << chosenItems[i].groupID << ", waga: " << chosenItems[i].weight << ", objetosc: " << chosenItems[i].volume << ", wartosc: " << chosenItems[i].value << endl;
    }

    cout << "\nSumaryczna waga: " << totalWeight << ", sumaryczna objetosc: " << totalVolume << ", sumaryczna wartosc: " << totalValue << endl << endl;

    vector<string> solutions = knapsackProblemAllSolutions(items, maxWeight, maxVolume);

    cout << "Mozliwe rozwiazania:\n\n";

    double weight = 0;
    double volume = 0;
    double value = 0;
    string currSolution = "";

    for (int i = 0; i < solutions.size(); i++) {
        cout << "ID przedmiotow: ";
        currSolution = solutions[i];
        for (int j = 0; j < currSolution.length(); j++) {
            if (currSolution[j] == '1') {
                weight += items[j].weight;
                volume += items[j].volume;
                value += items[j].value;
                cout << items[j].id << "; ";
            }
        }
        cout << ", sumaryczna waga: " << weight << ", sumaryczna objetosc: " << volume << ", sumaryczna wartosc: " << value << endl << endl;
        weight = 0;
        volume = 0;
        value = 0;
    }
}