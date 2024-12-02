#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "item.h"

using namespace std;
using json = nlohmann::json;

static vector<Item> readJsonF(string file) {
	ifstream f(file);

	if (!f.is_open()) {
		cout << "Error\n";
		return {};
	}

	json items;
	f >> items;

	vector<Item> readItems;
	
	for (int i = 0; i < items.size(); i++) {
		json item = items[i];
		Item currItem;
		currItem.id = item["id"];
		currItem.weight = item["weight"];
		currItem.volume = item["volume"];
		currItem.value = item["value"];
		currItem.groupID = item["groupID"];

		readItems.push_back(currItem);
	}

	return readItems;
}