#include<bits/stdc++.h>

using namespace std;

// Project: Smart Disaster Alert System
// Created by: SUSMITA DAS KRISHNA 

class Disaster {
protected:
    string location;
    float waterLevel;
    float rainIntensity;
public:
    void setData(string loc, float wl, float ri) {
        location = loc;
        waterLevel = wl;
        rainIntensity = ri;
    }
    
};

class AlertSystem : public Disaster {
public:
    void generateReport() {
        cout << "\n==========================================" << endl;
        cout << "   DISASTER RISK ANALYSIS REPORT" << endl;
        cout << "==========================================" << endl;
        cout << "Location   : " << location << endl;
        cout << "Water Level: " << waterLevel << " meters" << endl;
        cout << "Rainfall   : " << rainIntensity << " mm/hr" << endl;
        cout << "------------------------------------------" << endl;

       
        if (waterLevel >= 12.0 && rainIntensity >= 150.0) {
            cout << "STATUS: RED ALERT (Extreme Danger)" << endl;
            cout << "ACTION: Evacuate the entire zone immediately!" << endl;
        } 
        else if (waterLevel >= 7.0 || rainIntensity >= 80.0) {
            cout << "STATUS: ORANGE ALERT (High Risk)" << endl;
            cout << "ACTION: Move to high-ground shelters." << endl;
        } 
        else if (waterLevel >= 4.0 || rainIntensity >= 40.0) {
            cout << "STATUS: YELLOW ALERT (Caution)" << endl;
            cout << "ACTION: Monitor local news and stock supplies." << endl;
        } 
        else {
            cout << "STATUS: GREEN (Safe)" << endl;
            cout << "ACTION: No immediate threat. Stay vigilant." << endl;
        }
        cout << "==========================================\n" << endl;
    }

    
    void saveLog() {
        ofstream logFile;
        logFile.open("disaster_logs.txt", ios::app);
        if(logFile.is_open()){
            logFile << "Location: " << location << " | Water: " << waterLevel << "m | Rain: " << rainIntensity << "mm | Status Saved.\n";
            logFile.close();
            cout << ">> Log successfully saved to 'disaster_logs.txt'." << endl;
        } else {
            cout << ">> Error: Could not save log file." << endl;
        }
    }
};

int main() {
    AlertSystem mySystem;
    string loc;
    float wl, ri;
    int choice;

    cout << "------------------------------------------" << endl;
    cout << "      SMART DISASTER ALERT SYSTEM        " << endl;
    cout << "         Created by: SUSMITA DAS KRISHNA          " << endl;
    cout << "------------------------------------------" << endl;
    
    while(true) {
        cout << "1. Input Sensor Data\n2. Generate Report\n3. Save to Log File\n4. Exit\nChoose Option: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter Area Name: ";
            cin.ignore();
            getline(cin, loc);
            cout << "Enter Current Water Level (meters): ";
            cin >> wl;
            cout << "Enter Current Rainfall (mm/hr): ";
            cin >> ri;
            mySystem.setData(loc, wl, ri);
            cout << ">> Data Updated Successfully!\n" << endl;
        } 
        else if(choice == 2) {
            mySystem.generateReport();
        } 
        else if(choice == 3) {
            mySystem.saveLog();
        } 
        else if(choice == 4) {
            cout << "Exiting System. Stay Safe!" << endl;
            break;
        } 
        else {
            cout << "Invalid Option! Try again." << endl;
        }
    }

    return 0;
}
