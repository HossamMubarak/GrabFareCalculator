#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int pickupChoice, dropoffChoice, pickupTime, vehicleChoice;
    double distance = 0.0;
    int duration = 0;
    bool isPeakHour = false;

    string pickupName, dropoffName, vehicleName, promoCode;

    double baseFare = 0.0;
    double ratePerKm = 0.0;
    double ratePerMin = 0.0;

    cout << "=========================================\n";
    cout << "      GRAB RIDE FARE CALCULATOR\n";
    cout << "=========================================\n";

    cout << "\nAvailable Locations:\n";
    cout << "1. MMU Cyberjaya Campus\n";
    cout << "2. Dpulze Shopping Centre\n";
    cout << "3. Shaftsbury Square\n";
    cout << "4. KLIA Airport\n";

    cout << "\nSelect pickup location (1-4): ";
    cin >> pickupChoice;

    cout << "Select drop-off location (1-4): ";
    cin >> dropoffChoice;

    if (pickupChoice < 1 || pickupChoice > 4 || dropoffChoice < 1 || dropoffChoice > 4) {
        cout << "\nError: Invalid location choice.\n";
        return 0;
    }

    if (pickupChoice == dropoffChoice) {
        cout << "\nError: Pickup and drop-off cannot be the same.\n";
        return 0;
    }

    if ((pickupChoice == 1 && dropoffChoice == 2) || (pickupChoice == 2 && dropoffChoice == 1)) {
        pickupName = (pickupChoice == 1) ? "MMU Cyberjaya" : "Dpulze";
        dropoffName = (dropoffChoice == 2) ? "Dpulze" : "MMU Cyberjaya";
        distance = 3.5;
        duration = 8;
    }
    else if ((pickupChoice == 1 && dropoffChoice == 3) || (pickupChoice == 3 && dropoffChoice == 1)) {
        pickupName = (pickupChoice == 1) ? "MMU Cyberjaya" : "Shaftsbury";
        dropoffName = (dropoffChoice == 3) ? "Shaftsbury" : "MMU Cyberjaya";
        distance = 2.8;
        duration = 6;
    }
    else if ((pickupChoice == 1 && dropoffChoice == 4) || (pickupChoice == 4 && dropoffChoice == 1)) {
        pickupName = (pickupChoice == 1) ? "MMU Cyberjaya" : "KLIA Airport";
        dropoffName = (dropoffChoice == 4) ? "KLIA Airport" : "MMU Cyberjaya";
        distance = 28.5;
        duration = 30;
    }
    else if ((pickupChoice == 2 && dropoffChoice == 3) || (pickupChoice == 3 && dropoffChoice == 2)) {
        pickupName = (pickupChoice == 2) ? "Dpulze" : "Shaftsbury";
        dropoffName = (dropoffChoice == 3) ? "Shaftsbury" : "Dpulze";
        distance = 1.9;
        duration = 5;
    }
    else if ((pickupChoice == 2 && dropoffChoice == 4) || (pickupChoice == 4 && dropoffChoice == 2)) {
        pickupName = (pickupChoice == 2) ? "Dpulze" : "KLIA Airport";
        dropoffName = (dropoffChoice == 4) ? "KLIA Airport" : "Dpulze";
        distance = 29.0;
        duration = 32;
    }
    else {
        pickupName = (pickupChoice == 3) ? "Shaftsbury" : "KLIA Airport";
        dropoffName = (dropoffChoice == 4) ? "KLIA Airport" : "Shaftsbury";
        distance = 27.2;
        duration = 28;
    }

    cout << "\nEnter pickup time in 24-hour format, example 0830 or 1745: ";
    cin >> pickupTime;

    if (pickupTime < 0 || pickupTime > 2359 || pickupTime % 100 >= 60) {
        cout << "\nError: Invalid time format.\n";
        return 0;
    }

    if ((pickupTime >= 700 && pickupTime <= 930) || (pickupTime >= 1700 && pickupTime <= 2000)) {
        isPeakHour = true;
    }

    cout << "\nSelect Grab service type:\n";
    cout << "1. JustGrab\n";
    cout << "2. GrabCar Premium\n";
    cout << "3. GrabCar 6-Seater\n";
    cout << "4. GrabBike\n";
    cout << "Enter choice (1-4): ";
    cin >> vehicleChoice;

    switch (vehicleChoice) {
        case 1:
            vehicleName = "JustGrab";
            baseFare = 2.00;
            ratePerKm = 0.25;
            ratePerMin = 0.43;
            break;

        case 2:
            vehicleName = "GrabCar Premium";
            baseFare = 5.00;
            ratePerKm = 0.60;
            ratePerMin = 0.70;
            break;

        case 3:
            vehicleName = "GrabCar 6-Seater";
            baseFare = 4.00;
            ratePerKm = 0.45;
            ratePerMin = 0.55;
            break;

        case 4:
            vehicleName = "GrabBike";
            baseFare = 1.50;
            ratePerKm = 0.15;
            ratePerMin = 0.25;
            break;

        default:
            cout << "\nError: Invalid Grab service choice.\n";
            return 0;
    }

    cin.ignore();
    cout << "\nEnter promo code, or press Enter to skip: ";
    getline(cin, promoCode);

    double normalFare = baseFare + (distance * ratePerKm) + (duration * ratePerMin);
    double surgeCharge = 0.0;
    double discount = 0.0;
    double finalFare = normalFare;

    if (isPeakHour) {
        surgeCharge = normalFare * 0.50;
        finalFare = finalFare + surgeCharge;
    }

    if (promoCode == "GRABFINALS") {
        discount = 5.00;
        finalFare = finalFare - discount;
    }

    if (finalFare < 5.00) {
        finalFare = 5.00;
    }

    cout << fixed << setprecision(2);

    cout << "\n=========================================\n";
    cout << "             BOOKING RECEIPT\n";
    cout << "=========================================\n";
    cout << "Route          : " << pickupName << " -> " << dropoffName << endl;
    cout << "Service Type   : " << vehicleName << endl;
    cout << "Distance       : " << distance << " km" << endl;
    cout << "Duration       : " << duration << " minutes" << endl;
    cout << "Pickup Time    : " << pickupTime << endl;
    cout << "Normal Fare    : RM " << normalFare << endl;

    if (isPeakHour) {
        cout << "Peak Surge     : RM " << surgeCharge << endl;
    } else {
        cout << "Peak Surge     : RM 0.00" << endl;
    }

    if (discount > 0) {
        cout << "Promo Discount : -RM " << discount << endl;
    }

    cout << "-----------------------------------------\n";
    cout << "Final Fare     : RM " << finalFare << endl;
    cout << "=========================================\n";
    cout << "Thank you for using Grab Fare Calculator!\n";

    return 0;
}