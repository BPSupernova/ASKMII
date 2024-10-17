#ifndef POINTSMANAGER_H
#define POINTSMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>



class PointsManager {
private:
    int kindness;
    int cruelty;
    int peacefulness;
    int violence;
    const std::string filename = "choice_values.txt";

    PointsManager();

public:
    static PointsManager& getInstance();

    void setKindness(int val);
    void setCruelty(int val);
    void setPeacefulness(int val);
    void setViolence(int val);

    int getKindness() const;
    int getCruelty() const;
    int getPeacefulness() const;
    int getViolence() const;

    void setAllValues(int kindnessVal, int crueltyVal, int peacefulnessVal, int violenceVal);
    std::string getHighestValueString() const;

    void increaseValues(int lineNumber, int k, int c, int p, int v);
    void readValuesFromFile(int lineNumber);

    std::string getFinalResult();
};

#endif