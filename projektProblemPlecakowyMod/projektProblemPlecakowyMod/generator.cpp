#include <iostream>
#include <nlohmann/json.hpp>
#include <random>
#include <fstream>
#include "item.h"

using namespace std;
using json = nlohmann::json;

static void generateData(int numItems, int numGroups, double minWeight, double maxWeight, double minVolume, double maxVolume, double minValue, double maxValue, string file) {
	random_device dev;
	mt19937 engine(dev());
	uniform_real_distribution<double> weightDist(minWeight, maxWeight);
	uniform_real_distribution<double> volumeDist(minVolume, maxVolume);
	uniform_real_distribution<double> valueDist(minValue, maxValue);
	uniform_int_distribution<int> groupDist(0, numGroups-1);

	json items;
	for (int i = 0; i < numItems; i++) {
		json item;
		item["id"] = i + 1;
		item["weight"] = weightDist(engine);
		item["volume"] = volumeDist(engine);
		item["value"] = valueDist(engine);
		item["groupID"] = groupDist(engine);

		items.push_back(item);
	}

	ofstream f(file);
	if (!f.is_open()) {
		cout << "Error\n";
		return;
	}
	f << items.dump(2);
}