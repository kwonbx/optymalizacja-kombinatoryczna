#include <iostream>
#include "additionalFunctions.cpp"

using namespace std;

static vector<Item> knapsackProblemGreedy(vector<Item> items, double const maxWeight, double const maxVolume) {
    sort(items.begin(), items.end(), compareItems);

    double currWeight = 0;
    double currVolume = 0;
    vector<Item> chosenItems;

    for (int i = 0; i < items.size(); i++) {
        if (canAddItem(items[i], chosenItems, maxWeight, maxVolume, currWeight, currVolume) == true) {
            chosenItems.push_back(items[i]);
            currWeight += items[i].weight;
            currVolume += items[i].volume;
        }
    }

    return chosenItems;
}

static vector<Item> knapsackProblemRandomGreedy(vector<Item> items, double const maxWeight, double const maxVolume) {
    shuffle(items.begin(), items.end(), random_device());

    double currWeight = 0;
    double currVolume = 0;
    vector<Item> chosenItems;

    for (int i = 0; i < items.size(); i++) {
        if (canAddItem(items[i], chosenItems, maxWeight, maxVolume, currWeight, currVolume) == true) {
            chosenItems.push_back(items[i]);
            currWeight += items[i].weight;
            currVolume += items[i].volume;
        }
    }

    return chosenItems;
}

static vector<string> knapsackProblemAllSolutions(vector<Item> items, double const maxWeight, double const maxVolume) {
    string currOption = "";
    string lastOption = "";
    for (int i = 0; i < items.size(); i++) {
        currOption += "0";
        lastOption += "1";
    }

    double currWeight = 0;
    double currVolume = 0;
    int flag = 0;
    vector<string> possibleSolutions;
    vector<Item> chosenItems;


    while (currOption != lastOption) {
        for (int i = 0; i < items.size(); i++) {
            if (currOption[i] == '1') {
                chosenItems.push_back(items[i]);
            }
        }

        for (int i = 0; i < chosenItems.size(); i++) {
            if (canAddItem(chosenItems[i], chosenItems, maxWeight, maxVolume, currWeight, currVolume) == false) {
                flag = 1;
                break;
            }
            currWeight += chosenItems[i].weight;
            currVolume += chosenItems[i].volume;
        }

        if (flag == 0) {
            possibleSolutions.push_back(currOption);
        }

        flag = 0;
        currWeight = 0;
        currVolume = 0;
        chosenItems.clear();
        currOption = binaryAddOne(currOption);
    }

    for (int i = 0; i < items.size(); i++) {
        chosenItems.push_back(items[i]);
    }

    for (int i = 0; i < chosenItems.size(); i++) {
        if (canAddItem(chosenItems[i], chosenItems, maxWeight, maxVolume, currWeight, currVolume) == false) {
            flag = 1;
            break;
        }
        currWeight += chosenItems[i].weight;
        currVolume += chosenItems[i].volume;
    }

    if (flag == 0) {
        possibleSolutions.push_back(currOption);
    }

    return possibleSolutions;
}