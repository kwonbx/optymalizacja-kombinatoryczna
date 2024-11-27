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