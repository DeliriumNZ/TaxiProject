# TaxiProject
#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib> 
#include <ctime> 

using namespace std;


class Trip {
private:
    int tripID;
    int driverID;
    int customerID;
    int vehicleID;
    double cost;
public:
    Trip() {
        tripID = rand() % 1000 + 1;
    }
    void setDriverID(int dID) {
        driverID = dID;
    }
    void setCustomerID(int cID) {
        customerID = cID;
    }
    void setVehicleID(int vID) {
        vehicleID = vID;
    }
    void setCost(double c) {
        cost = c;
    }
    int getTripID() {
        return tripID;
    }
    int getDriverID() {
        return driverID;
    }
    int getCustomerID() {
        return customerID;
    }
    int getVehicleID() {
        return vehicleID;
    }
    double getCost() {
        return cost;
    }
};

class Complaint {
private:
    int complaintID;
    int customerID;
    string complaint;
public:
    Complaint() {
        complaintID = rand() % 1000 + 1;
    }
    void setCustomerID(int cID) {
        customerID = cID;
    }
    void setComplaint(string c) {
        complaint = c;
    }
    int getComplaintID() {
        return complaintID;
    }
    int getCustomerID() {
        return customerID;
    }
    string getComplaint() {
        return complaint;
    }
};

class LostAndFound {
private:
    int lostAndFoundID;
    string lostItem;
    string foundItem;
public:
    LostAndFound() {
        lostAndFoundID = rand() % 1000 + 1;
    }
    void setLostItem(string l) {
        lostItem = l;
    }
    void setFoundItem(string f) {
        foundItem = f;
    }
    int getLostAndFoundID() {
        return lostAndFoundID;
    }
    string getLostItem() {
        return lostItem;
    }
    string getFoundItem() {
        return foundItem;
    }
};
