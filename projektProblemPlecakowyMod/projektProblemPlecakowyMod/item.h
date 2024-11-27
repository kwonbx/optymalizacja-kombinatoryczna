#pragma once
struct Item
{
    int id;
    double weight;
    double volume;
    double value;
    int groupID;
    double profit = value / (weight + volume);
};