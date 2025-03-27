#include "hw3functions.h"
#include <iostream>
#include <iomanip>
// Maximum number of profiles to store
const int MAX_PROFILES = 20;

int main() {
    // Array to store Griffin family profiles
    GriffinProfile profiles[MAX_PROFILES];
    int profileCount = 0;
    
    std::cout << "===== Save Quahog: The Griffin Data Recovery Mission =====" << std::endl;
    std::cout << "Starting recovery process..." << std::endl;
    
    try {
        // Step 1: Load profiles from file
        if (!loadProfiles(profiles, profileCount)) {
            throw std::runtime_error("Failed to load profiles. Mission aborted.");
        }
        
        // Step 2: Display the loaded profiles
        std::cout << "\nDisplaying initial profiles:" << std::endl;
        displayProfiles(profiles, profileCount);
        
        // Step 3: Sort profiles by intelligence
        std::cout << "\nSorting profiles by intelligence (descending)..." << std::endl;
        sortProfilesByIntelligence(profiles, profileCount);
        std::cout << "Sorting complete." << std::endl;
        
        // Step 4: Display the sorted profiles
        std::cout << "\nDisplaying sorted profiles:" << std::endl;
        displayProfiles(profiles, profileCount);
        
        // Step 5: Calculate and display average sarcasm
        float avgSarcasm = calculateAverageSarcasm(profiles, profileCount);
        std::cout << "\nAverage sarcasm level (excluding corrupted profiles): " 
                  << std::fixed << std::setprecision(2) << avgSarcasm << std::endl;
        
        // Step 6: Recover corrupted profiles
        std::cout << "\nRecovering corrupted profiles..." << std::endl;
        recoverCorruptedProfiles(profiles, profileCount);
        
        // Step 7: Display the recovered profiles
        std::cout << "\nDisplaying profiles after recovery:" << std::endl;
        displayProfiles(profiles, profileCount);
        
        // Step 8: Export recovery report
        std::cout << "\nExporting recovery report..." << std::endl;
        if (!exportReport(profiles, profileCount)) {
            throw std::runtime_error("Failed to export recovery report.");
        }
        
        std::cout << "\n===== Recovery mission completed successfully! =====" << std::endl;
        std::cout << "Stewie says: \"Victory is mine!\"" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        std::cerr << "Mission failed. Better luck next time!" << std::endl;
        return 1;
    }
    
    return 0;
}
