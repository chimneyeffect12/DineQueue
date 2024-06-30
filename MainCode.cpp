#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Struct to store order details
struct Order {
    int orderId;
    string customerName;
    string orderDetails;

    // Constructor
    Order(int id, string name, string details) {
        orderId = id;
        customerName = name;
        orderDetails = details;
    }
};

// Class for Restaurant Order Management System
class RestaurantOrderManagementSystem {
private:
    queue<Order> orderQueue;
    int currentOrderId;

public:
    // Constructor
    RestaurantOrderManagementSystem() {
        currentOrderId = 1;
    }

    // Add new order
    void addOrder(string customerName, string orderDetails) {
        Order newOrder(currentOrderId++, customerName, orderDetails);
        orderQueue.push(newOrder);
        cout << "Order added successfully! Order ID: " << newOrder.orderId << endl;
    }

    // View all orders
    void viewOrders() {
        if (orderQueue.empty()) {
            cout << "No orders to display." << endl;
            return;
        }

        queue<Order> tempQueue = orderQueue; // OrderQueue for Display.
        while (!tempQueue.empty()) {
            Order order = tempQueue.front();
            tempQueue.pop();
            cout << "Order ID: " << order.orderId << ", Customer Name: " << order.customerName << ", Order Details: " << order.orderDetails << endl;
        }
    }

    // Process the next order
    void processOrder() {
        if (orderQueue.empty()) {
            cout << "No orders to process." << endl;
            return;
        }

        Order order = orderQueue.front();
        orderQueue.pop();
        cout << "Processing Order ID: " << order.orderId << ", Customer Name: " << order.customerName << ", Order Details: " << order.orderDetails << endl;
    }
};

int main() {
    RestaurantOrderManagementSystem system;
    int choice;
    string customerName, orderDetails;

    do {
        cout << "\nRestaurant Order Management System\n";
        cout << "1. Add Order\n";
        cout << "2. View Orders\n";
        cout << "3. Process Order\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter Customer Name: ";
            getline(cin, customerName);
            cout << "Enter Order Details: ";
            getline(cin, orderDetails);
            system.addOrder(customerName, orderDetails);
            break;
        case 2:
            system.viewOrders();
            break;
        case 3:
            system.processOrder();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
