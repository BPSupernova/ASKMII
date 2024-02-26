#include "TitleManager.h"

std::string TitleManager::getTitle(const int scores[], int size) {
    if (size < 2) {
        return "Invalid scores";
    }

    // Find the highest and second-highest scores
    int highest = 0, secondHighest = 0;
    for (int i = 0; i < size; ++i) {
        if (scores[i] > highest) {
            secondHighest = highest;
            highest = scores[i];
        }
        else if (scores[i] > secondHighest && scores[i] != highest) {
            secondHighest = scores[i];
        }
    }

    // Assign titles based on highest and second-highest scores
    if (highest == 0) {
        if (secondHighest == 1)
            return "The Ruthless Tyrant";
        else if (secondHighest == 2)
            return "The Serene Diplomat";
        else if (secondHighest == 3)
            return "The Brutal Conqueror";
    }
    else if (highest == 1) {
        if (secondHighest == 0)
            return "The Benevolent Leader";
        else if (secondHighest == 2)
            return "The Tranquil Mediator";
        else if (secondHighest == 3)
            return "The Savage Despot";
    }
    else if (highest == 2) {
        if (secondHighest == 0)
            return "The Compassionate Guide";
        else if (secondHighest == 1)
            return "The Malevolent Overlord";
        else if (secondHighest == 3)
            return "The Warmongering General";
    }
    else if (highest == 3) {
        if (secondHighest == 0)
            return "The Gentle Guardian";
        else if (secondHighest == 1)
            return "The Vicious Warlord";
        else if (secondHighest == 2)
            return "The Pacifist Guardian";
    }

    return "Unknown Title";
}
