#include "hw3functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// Function to load profiles from file
bool loadProfiles(GriffinProfile profiles[], int &count) {
    std::ifstream inputFile("griffin_logs.txt");
    count = 0;
    
    // Check if file opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open griffin_logs.txt!" << std::endl;
        return false;
    }
    
    std::string line;
    // Process each line in the file
    while (std::getline(inputFile, line) && count < 20) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }
        
        try {
            // Use a stream to parse the line
            std::istringstream iss(line);
            
            // Parse each field individually with comma delimiter
            std::string name, ageStr, genderStr, sarcasmStr, intellStr, corruptedStr;
            
            std::getline(iss, name, ',');
            std::getline(iss, ageStr, ',');
            std::getline(iss, genderStr, ',');
            std::getline(iss, sarcasmStr, ',');
            std::getline(iss, intellStr, ',');
            std::getline(iss, corruptedStr, ',');
            
            // Convert the strings to the appropriate types
            int age = std::stoi(ageStr);
            char gender = genderStr[0];
            float sarcasmLevel = std::stof(sarcasmStr);
            int intelligence = std::stoi(intellStr);
            
            // Set boolean for corruption status
            bool isCorrupted;
            if (corruptedStr == "true") {
                isCorrupted = true;
            } else if (corruptedStr == "false") {
                isCorrupted = false;
            } else {
                throw std::runtime_error("Invalid corruption status: '" + corruptedStr + "'");
            }
            
            // Parse loyalty markers
            int markers[5];
            for (int i = 0; i < 5; i++) {
                if (!(iss >> markers[i])) {
                    throw std::runtime_error("Error parsing loyalty markers");
                }
            }
            
            // Populate the profile
            profiles[count].name = name;
            profiles[count].age = age;
            profiles[count].gender = gender;
            profiles[count].sarcasmLevel = sarcasmLevel;
            profiles[count].intelligence = intelligence;
            profiles[count].isCorrupted = isCorrupted;
            
            // Copy loyalty markers
            for (int i = 0; i < 5; i++) {
                profiles[count].loyaltyMarker[i] = markers[i];
            }
            
            // Increment count
            count++;
            
        } catch (const std::exception& e) {
            std::cerr << "Error processing line: " << line << std::endl;
            std::cerr << "Reason: " << e.what() << std::endl;
            // Continue to next line
        }
    }
    
    inputFile.close();
    
    if (count == 0) {
        std::cerr << "Warning: No valid profiles were loaded." << std::endl;
        return false;
    }
    
    std::cout << "Successfully loaded " << count << " profile(s)." << std::endl;
    return true;
}

// Function to display profiles to console
void displayProfiles(const GriffinProfile profiles[], int count) {
    std::cout << "----- Griffin Family Profiles -----" << std::endl;
    std::cout << std::setw(15) << "Name" << " | "
              << std::setw(5) << "Age" << " | "
              << "G | "
              << std::setw(8) << "Sarcasm" << " | "
              << std::setw(5) << "IQ" << " | "
              << "Corrupted | "
              << "Loyalty Markers" << std::endl;
    std::cout << std::string(80, '-') << std::endl;
    
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(15) << profiles[i].name << " | "
                  << std::setw(5) << profiles[i].age << " | "
                  << profiles[i].gender << " | "
                  << std::setw(8) << std::fixed << std::setprecision(1) << profiles[i].sarcasmLevel << " | "
                  << std::setw(5) << profiles[i].intelligence << " | "
                  << std::setw(9) << (profiles[i].isCorrupted ? "Yes" : "No") << " | ";
        
        // Display loyalty markers
        for (int j = 0; j < 5; j++) {
            std::cout << profiles[i].loyaltyMarker[j];
            if (j < 4) std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::string(80, '-') << std::endl;
}

// Function to sort profiles by intelligence
void sortProfilesByIntelligence(GriffinProfile profiles[], int count) {
    // Bubble sort algorithm for descending order of intelligence
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (profiles[j].intelligence < profiles[j + 1].intelligence) {
                // Swap profiles
                GriffinProfile temp = profiles[j];
                profiles[j] = profiles[j + 1];
                profiles[j + 1] = temp;
            }
        }
    }
}

// Function to calculate average sarcasm
float calculateAverageSarcasm(const GriffinProfile profiles[], int count) {
    float totalSarcasm = 0.0f;
    int validProfiles = 0;
    
    for (int i = 0; i < count; i++) {
        if (!profiles[i].isCorrupted) {
            totalSarcasm += profiles[i].sarcasmLevel;
            validProfiles++;
        }
    }
    
    if (validProfiles == 0) {
        return 0.0f; // Handle case where all profiles are corrupted
    }
    
    return totalSarcasm / validProfiles;
}

// Function to recover corrupted profiles
void recoverCorruptedProfiles(GriffinProfile profiles[], int count) {
    float avgSarcasm = calculateAverageSarcasm(profiles, count);
    
    std::cout << "Attempting to recover corrupted profiles..." << std::endl;
    int recoveredCount = 0;
    
    for (int i = 0; i < count; i++) {
        if (profiles[i].isCorrupted) {
            profiles[i].sarcasmLevel = avgSarcasm;
            profiles[i].intelligence = 100; // Default recovery level
            profiles[i].isCorrupted = false;
            recoveredCount++;
        }
    }
    
    std::cout << "Recovery complete. " << recoveredCount << " profile(s) recovered." << std::endl;
}

// Function to decode loyalty marker
int decodeLoyaltyMarker(const int marker[5]) {
    // Use the provided decoding algorithm
    return marker[0] * marker[1] + marker[2] * marker[3] + marker[4];
}

// Function to export report to a file
bool exportReport(const GriffinProfile profiles[], int count) {
    std::ofstream reportFile("griffin_report.txt");
    
    if (!reportFile.is_open()) {
        std::cerr << "Error: Could not create griffin_report.txt!" << std::endl;
        return false;
    }
    
    reportFile << "=== GRIFFIN FAMILY MATRIX RECOVERY REPORT ===" << std::endl;
    reportFile << std::string(45, '=') << std::endl << std::endl;
    
    // Export each profile
    for (int i = 0; i < count; i++) {
        int loyaltyScore = decodeLoyaltyMarker(profiles[i].loyaltyMarker);
        
        reportFile << "Name: " << profiles[i].name << std::endl;
        reportFile << "Age: " << profiles[i].age << std::endl;
        reportFile << "Intelligence: " << profiles[i].intelligence << std::endl;
        reportFile << "Loyalty Score: " << loyaltyScore << std::endl;
        
        // Add message for recovered profiles
        if (profiles[i].intelligence == 100 && profiles[i].sarcasmLevel == calculateAverageSarcasm(profiles, count)) {
            reportFile << "Status: RECOVERED" << std::endl;
        } else {
            reportFile << "Status: ORIGINAL" << std::endl;
        }
        
        reportFile << std::string(30, '-') << std::endl;
    }
    
    // Add average sarcasm level at the end
    reportFile << std::endl;
    reportFile << "Average Sarcasm Level: " << std::fixed << std::setprecision(2) 
               << calculateAverageSarcasm(profiles, count) << std::endl;
    
    reportFile.close();
    std::cout << "Recovery report exported to griffin_report.txt" << std::endl;
    return true;
}