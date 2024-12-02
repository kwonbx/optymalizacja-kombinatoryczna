#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "item.h"

using namespace std;

static bool compareItems(Item const itemLeft, Item const itemRight) {
    if (itemLeft.profit != itemRight.profit) {
        return itemLeft.profit > itemRight.profit;
    }

    return itemLeft.groupID < itemRight.groupID;
}

static bool isIDChosen(int id, vector<Item> chosenItems) {
    for (int i = 0; i < chosenItems.size(); i++) {
        if (id == chosenItems[i].groupID) {
            return true;
        }
    }

    return false;
}

static bool canAddItem(Item const itemToAdd, vector<Item> chosenItems, double maxWeight, double maxVolume, double currWeight, double currVolume) {
    if (itemToAdd.groupID != 0 && isIDChosen(itemToAdd.groupID - 1, chosenItems) == false) {
        return false;
    }

    if (itemToAdd.weight + currWeight > maxWeight || itemToAdd.volume + currVolume > maxVolume) {
        return false;
    }

    return true;
}

static string binaryAddOne(string currOption) {
    for (int i = currOption.length() - 1; i >= 0; i--) {
        if (currOption[i] == '0') {
            currOption[i] = '1';
            return currOption;
        }
        currOption[i] = '0';
    }
}

static string neighbor(string currOption, int n) {
    string newOption = currOption;
    int index = rand() % n;
    if (newOption[index] == '0') {
        newOption[index] = '1';
    }
    else {
        newOption[index] = '0';
    }

    return newOption;
}

static double checkOption(string currOption, vector<Item> items, double maxWeight, double maxVolume) {
    double currWeight = 0;
    double currVolume = 0;
    double totalValue = 0;
    int flag = 0;
    vector<Item> chosenItems;

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
        totalValue += chosenItems[i].value;
    }

    if (flag == 0) {
        return totalValue;
    }

    return -1;
}