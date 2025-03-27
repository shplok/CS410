#ifndef HW3FUNCTIONS_H
#define HW3FUNCTIONS_H

#include <string>

// Define GriffinProfile struct with all required fields
struct GriffinProfile {
    std::string name;
    int age;
    char gender;        // 'M' or 'F'
    float sarcasmLevel; // 0.0 to 10.0
    int intelligence;   // 0 to 200
    bool isCorrupted;   // true if log was damaged
    int loyaltyMarker[5]; // encrypted 5-digit marker array
};

// Function to load profiles from file
bool loadProfiles(GriffinProfile profiles[], int &count);

// Function to display profiles to console
void displayProfiles(const GriffinProfile profiles[], int count);

// Function to sort profiles by intelligence
void sortProfilesByIntelligence(GriffinProfile profiles[], int count);

// Function to calculate average sarcasm
float calculateAverageSarcasm(const GriffinProfile profiles[], int count);

// Function to recover corrupted profiles
void recoverCorruptedProfiles(GriffinProfile profiles[], int count);

// Function to decode loyalty marker
int decodeLoyaltyMarker(const int marker[5]);

// Function to export report to a file
bool exportReport(const GriffinProfile profiles[], int count);

#endif