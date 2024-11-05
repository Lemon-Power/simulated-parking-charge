#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Vehicle {
    string plateNumber;
    int tollFee;
    string vehicleType;
};

int main() {
    // Define toll rates
    const int LIGHT_VEHICLE_TOLL = 50;
    const int HEAVY_VEHICLE_TOLL = 85;
    const int MOTORCYCLE_TOLL = 35;

    vector<Vehicle> vehicleRecords;  // Stores the vehicle entries
    int vehicleType;
    string plateNumber;
    char anotherCar;

    cout << "Welcome to the Parking Garage System\n";

    do {
        cout << "\nSelect Vehicle Type:\n";
        cout << "1. Light Vehicle (50 PHP)\n";
        cout << "2. Heavy Vehicle (85 PHP)\n";
        cout << "3. Motorcycle (35 PHP)\n";
        cout << "Enter your choice (1-3): ";
        cin >> vehicleType;

        // Check if the vehicle type is valid
        int tollFee = 0;
        string vehicleTypeName;
        switch (vehicleType) {
            case 1:
                tollFee = LIGHT_VEHICLE_TOLL;
                vehicleTypeName = "Light Vehicle";
                break;
            case 2:
                tollFee = HEAVY_VEHICLE_TOLL;
                vehicleTypeName = "Heavy Vehicle";
                break;
            case 3:
                tollFee = MOTORCYCLE_TOLL;
                vehicleTypeName = "Motorcycle";
                break;
            default:
                cout << "Invalid vehicle type selected.\n";
                continue;  // Ends the loop so that it won't run into errors.
        }

        // Ask for the plate number and validate it
        cout << "Enter Plate Number (6 characters, letters and digits): ";
        cin >> plateNumber;

        if (plateNumber.length() != 6) {
            cout << "Invalid plate number format. Must be 6 characters.\n";
            continue;  // Restart the loop if the input is invalid
        }

        // Save vehicle entry
        Vehicle newVehicle = {plateNumber, tollFee, vehicleTypeName};
        if (vehicleRecords.size() >= 5) {
            vehicleRecords.erase(vehicleRecords.begin());  // Remove the oldest entry
        }
        vehicleRecords.push_back(newVehicle);

        // Show confirmation from current entries.
        cout << "\nVehicle added successfully:\n";
        cout << "Type: " << newVehicle.vehicleType << ", Plate Number: " << newVehicle.plateNumber << ", Toll Fee: " << newVehicle.tollFee << " PHP\n";

        cout << "\nCurrent Vehicles in System:\n";
        for (int i = 0; i < vehicleRecords.size(); ++i) {
            cout << i + 1 << ". " << vehicleRecords[i].vehicleType
                 << " - Plate: " << vehicleRecords[i].plateNumber
                 << " - Toll Fee: " << vehicleRecords[i].tollFee << " PHP\n";
        }

        // Loop, asks the user if there's another car.
        cout << "\nIs there another car? (Y/N): ";
        cin >> anotherCar;

    } while (anotherCar == 'Y' || anotherCar == 'y');

    cout << "\nThank you for using the parking garage system.\n";

    return 0;
}
