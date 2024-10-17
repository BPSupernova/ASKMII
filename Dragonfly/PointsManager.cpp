#include "PointsManager.h"
#include "TitleManager.h"
#include "LogManager.h"


PointsManager::PointsManager() : kindness(0), cruelty(0), peacefulness(0), violence(0) {}

PointsManager& PointsManager::getInstance() {
    static PointsManager instance;
    return instance;
}

void PointsManager::setKindness(int val) { kindness = val; }
void PointsManager::setCruelty(int val) { cruelty = val; }
void PointsManager::setPeacefulness(int val) { peacefulness = val; }
void PointsManager::setViolence(int val) { violence = val; }

int PointsManager::getKindness() const { return kindness; }
int PointsManager::getCruelty() const { return cruelty; }
int PointsManager::getPeacefulness() const { return peacefulness; }
int PointsManager::getViolence() const { return violence; }

void PointsManager::setAllValues(int kindnessVal, int crueltyVal, int peacefulnessVal, int violenceVal) {
    kindness = kindnessVal;
    cruelty = crueltyVal;
    peacefulness = peacefulnessVal;
    violence = violenceVal;
}

std::string PointsManager::getFinalResult() {
    int values[4] = { getKindness(), getCruelty(), getPeacefulness(), getViolence() };
    LM.getInstance().writeLog("\n\tFinal results: %d %d %d %d", values[0], values[1], values[2], values[3]);
    return TitleManager::getTitle(values, 4);
}


std::string PointsManager::getHighestValueString() const {
    int maxVal = std::max({ kindness, cruelty, peacefulness, violence });
    if (maxVal == kindness)
        return "Kindness is the highest.";
    else if (maxVal == cruelty)
        return "Cruelty is the highest.";
    else if (maxVal == peacefulness)
        return "Peacefulness is the highest.";
    else
        return "Violence is the highest.";
}

void PointsManager::increaseValues(int lineNumber, int k, int c, int p, int v) {
    kindness += k;
    cruelty += c;
    peacefulness += p;
    violence += v;
}

void PointsManager::readValuesFromFile(int lineNumber) {
    std::ifstream file(filename);
    std::string line;

    // LM.getInstance().writeLog("PointsManager: Reading values from line number %d\n",lineNumber);

     // Skipping lines until we reach the desired line number
    for (int i = 1; i < lineNumber; ++i) {
        if (!std::getline(file, line)) {
            return;
        }
    }

    // Read the values from the desired line
    if (std::getline(file, line)) {

        std::stringstream ss(line);
        std::string token;
        std::vector<int> values;
        //LM.getInstance().writeLog("PointsManager: Caught getline with line: %s\n", line);

        while (std::getline(ss, token, ',')) {
            LM.getInstance().writeLog("\t\tPointsManager: Token Added: %d\n", std::stoi(token));
            values.push_back(std::stoi(token));
        }
        //
               // LM.getInstance().writeLog("PointsManager: Read a set of values of size %d", values.size());

                //LM.getInstance().writeLog("PointsManager: PUSHING THE FOLLOWING CHANGES: %d,%d,%d,%d", values[0], values[1], values[2], values[3]);
        increaseValues(lineNumber, values[0], values[1], values[2], values[3]);

        // Assuming there are exactly 4 values in the line
        if (values.size() == 4) {

        }
    }
}