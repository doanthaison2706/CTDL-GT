#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

class PublicTransportVehicle {
private:
    // Các thuộc tính của phương tiện
    string vehicleType;
    string routeNumber;
    int capacity;
    double distance;
    double ticketPrice;
    string routeDescription;
public:
    // Construction
    PublicTransportVehicle(string vType, string rNumber, int cap, double dist, double price, string rDesc) : vehicleType(vType), routeNumber(rNumber), capacity(cap), distance(dist), ticketPrice(price), routeDescription(rDesc) {}
    // Toán tử nhập >>
    friend istream &operator>>(istream &in, PublicTransportVehicle &vehicle) {
        cout << "Enter vehicle Type: ";
        in >> vehicle.vehicleType;
        cout << "Enter route number: ";
        in >> vehicle.routeNumber;
        cout << "Enter capacity: ";
        in >> vehicle.capacity;
        if (vehicle.capacity <= 0) {
            cout << "Invalid capacity!" << endl;
            return in;
        }
        cout << "Enter distance: ";
        in >> vehicle.distance;
        if (vehicle.distance <= 0) {
            cout << "Invalid distance!" << endl;
            return in;
        }
        cout << "Enter ticket price: ";
        in >> vehicle.ticketPrice;
        cout << "Enter route description: ";
        in.ignore();
        getline(in, vehicle.routeDescription);
        return in;
    }
    // Toán tử << 
    friend ostream &operator<<(ostream &out, PublicTransportVehicle &vehicle) {
        out << "Vehicle Type: " << vehicle.vehicleType << endl;
        out << "Route Number: " << vehicle.routeNumber << endl;
        out << "Capacity: " << vehicle.capacity << endl;
        out << "Distance: " << vehicle.distance << " km" << endl;
        out << "Ticket Price: " << vehicle.ticketPrice << " VND"<< endl;
        out << "Route Description: " << vehicle.routeDescription << endl;
        return out;
    }
    // toán tử so sánh <
    bool operator<(const PublicTransportVehicle &other) const {
        return this->distance < other.distance;
    }
    // Phương thức đọc từ file
    bool loadFromFile(ifstream &file) {
        file >> vehicleType >> routeNumber >> capacity >> distance >> ticketPrice;
        if (file.fail()) {
            return false;
        }
        file.ignore();
        getline(file, routeDescription);
        if (capacity <= 0 || distance <= 0) {
            return false;
        }
        return true; 
    }
    // Phương thức lấy các thuộc tính của đối tượng
    string getVehicleType() {
        return vehicleType;
    }
    string getRouteNumber() {
        return routeNumber;
    }
    int getCapacity() {
        return capacity;
    }
    double getDistance() {
        return distance;
    }
    double getTicketPrice() {
        return ticketPrice;
    }
    string getRouteDescription() {
        return routeDescription;
    }
};

class PublicTransportList {
private:
    vector<PublicTransportVehicle> vehicleList;
public:
    // Phương thức thêm phương tiện mới
    void addVehicle(PublicTransportVehicle &vehicle) {
        vehicleList.push_back(vehicle);
    }
    // Phương thức thêm 1 danh sách từ file
    void readFile(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Couldn't open file!" << endl;
            return;
        }
        PublicTransportVehicle vehicle("", "", 0, 0.0, 0, "");
        while (vehicle.loadFromFile(file)) {
            addVehicle(vehicle);
        }
        file.close();
    }
    // Phương thức hiển thị ra màn hình
    void displayList() {
        if (vehicleList.empty()) {
            cout << "The list is empty!" << endl;
            return;
        }
        // Sử dụng chỉ số để duyệt qua danh sách
        cout << "\nList of vehicle: \n" << endl;
        for (int i = 0; i < vehicleList.size(); ++i) {
            cout << vehicleList[i] << endl;  
        }
    }
    // Phương thức xuất danh sách ra file
    void saveFile(string &fileName) {
        if (vehicleList.empty()) {
            cout << "The list is empty!" << endl;
            return;
        } 
        ofstream file(fileName);
        if (!file) {
            cout << "Couldn't open file!" << endl;
            return;
        }
        for (auto &vehicle : vehicleList) {
            file << vehicle; 
        }
        file.close();
    }
    void sortVehicle() {
        if (vehicleList.empty()) {
            cout << "The list is empty!" << endl;
            return;
        }
        sort(vehicleList.begin(), vehicleList.end());
    }
    // Phương thức tìm kiếm thông tin
    PublicTransportVehicle *searchVehicle(string &routeNumber) {
        if (vehicleList.empty()) {
        cout << "The list is empty!" << endl;
        return nullptr;
    }
    for (auto &vehicle : vehicleList) {
        if (vehicle.getRouteNumber() == routeNumber) {
            cout << "Vehicle found:" << endl;
            cout << vehicle;  
            return &vehicle;  
        }
    }
    // Nếu không tìm thấy sau khi duyệt hết, in ra thông báo
    cout << "Not found!" << endl;
    return nullptr;
    }
    // Phương thức xoá 
    void deleteVehicle(const string &routeNumber) {
        if (vehicleList.empty()) {
            cout << "The list is empty. No vehicles to delete." << endl;
            return;
        }
        bool found = false;                         
        vector<PublicTransportVehicle> updatedList; 
        for (auto &vehicle : vehicleList) {
            if (vehicle.getRouteNumber() != routeNumber) {
                updatedList.push_back(vehicle); 
            } else {
                found = true;
            }
        }
        vehicleList = updatedList;
        if (found) {
            cout << "Vehicle with route number " << routeNumber << " deleted successfully." << endl;
        } else {
            cout << "Vehicle with route number " << routeNumber << " not found." << endl;
        }
    }
};

class TransportApp {
private:
    PublicTransportList transportList;
public:
    void displayMenu() {
        cout << "===== Transport Management System =====" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. Add List of Vehicles" << endl;
        cout << "3. Display Vehicle List" << endl;
        cout << "4. Sort Vehicles by Distance" << endl;
        cout << "5. Search Vehicle by Route Number" << endl;
        cout << "6. Delete Vehicle by Route Number" << endl;
        cout << "7. Export Vehicle List to File" << endl; 
        cout << "0. Exit" << endl;
        cout << "=======================================" << endl;
        cout << "Enter your choice: ";
    }
    void handleUserChoice(int choice) {
        switch (choice) {
        case 1: { 
            PublicTransportVehicle vehicle("", "", 0, 0.0, 0.0, "");
            cin >> vehicle; 
            transportList.addVehicle(vehicle);
            cout << "Vehicle added successfully!" << endl;
            break;
        }
        case 2: { 
            string filename;
            cout << "Enter filename to read vehicles from: ";
            cin >> filename;
            transportList.readFile(filename); 
            cout << "List of vehicles added successfully!" << endl;
            break;
        }
        case 3: {
            transportList.displayList();
            break;
        }
        case 4: {
            transportList.sortVehicle();
            cout << "Vehicles sorted successfully!" << endl;
            break;
        }
        case 5: { 
            string routeNumber;
            cout << "Enter route number to search: ";
            cin >> routeNumber;
            transportList.searchVehicle(routeNumber);
            break;
        }
        case 6: {
            string routeNumber;
            cout << "Enter route number to delete: ";
            cin >> routeNumber;
            transportList.deleteVehicle(routeNumber);
            break;
        }
        case 7: { 
            string filename;
            cout << "Enter filename to export: ";
            cin >> filename;
            transportList.saveFile(filename); 
            cout << "Vehicle list exported successfully!" << endl;
            break;
        }
        case 0: {
            cout << "Exiting the application." << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }  
        }
    }
    // Phương thức chạy app
    void run() {
        int choice;
        do {
            displayMenu();
            cin >> choice;
            handleUserChoice(choice);
        } while (choice != 0);
    }
};

int main() {
    TransportApp app;
    app.run();
    return 0;
}