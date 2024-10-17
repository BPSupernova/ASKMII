#include "TitleManager.h"

std::string TitleManager::getTitle(const int scores[], int size) {
    if (size < 2) {
        return "Invalid scores";
    }

    // Find the highest and second-highest scores
    int highest = scores[0], secondHighest = scores[0];
    for (int i = 1; i < size; ++i) {
        if (scores[i] > highest) {
            secondHighest = highest;
            highest = scores[i];
        }
        else if (scores[i] > secondHighest && scores[i] != highest) {
            secondHighest = scores[i];
        }
    }

    if (highest == scores[0]) {
        if (secondHighest == scores[1])
            return "The Ruthless Tyrant";
        else if (secondHighest == scores[2])
            return "The Serene Diplomat";
        else if (secondHighest == scores[3])
            return "The Brutal Conqueror";
    }
    else if (highest == scores[1]) {
        if (secondHighest == scores[0])
            return "The Benevolent Leader";
        else if (secondHighest == scores[2])
            return "The Tranquil Mediator";
        else if (secondHighest == scores[3])
            return "The Savage Despot";
    }
    else if (highest == scores[2]) {
        if (secondHighest == scores[0])
            return "The Compassionate Guide";
        else if (secondHighest == scores[1])
            return "The Malevolent Overlord";
        else if (secondHighest == scores[3])
            return "The Warmongering General";
    }
    else if (highest == scores[3]) {
        if (secondHighest == scores[0])
            return "The Gentle Guardian";
        else if (secondHighest == scores[1])
            return "The Vicious Warlord";
        else if (secondHighest == scores[2])
            return "The Pacifist Guardian";
    }

    return "Unknown Title";
}