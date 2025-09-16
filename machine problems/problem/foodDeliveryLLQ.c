#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int orderID;
    char customerName[50];
    char foodItem[50];
    float price;
    int preparationTime; // in minutes
} FoodOrder;

typedef struct OrderNode {
    FoodOrder order;
    struct OrderNode* next;
} OrderNode;

typedef struct {
    OrderNode* front;
    OrderNode* rear;
    int totalOrders;
    float totalRevenue;
} DeliveryQueue;

// Function prototypes
DeliveryQueue initializeQueue();
void placeOrder(DeliveryQueue *dq, FoodOrder newOrder);
void processOrder(DeliveryQueue *dq);
int isEmpty(DeliveryQueue *dq);
FoodOrder viewNextOrder(DeliveryQueue *dq);
void displayQueue(DeliveryQueue dq);
void displayQueueStats(DeliveryQueue dq);
void clearBuffer();

// Main function for testing
int main() {
    DeliveryQueue foodQueue;
    FoodOrder nextOrder;
    
    printf("=== FOOD DELIVERY QUEUE SYSTEM ===\n\n");
    
    // PROBLEM 1: Initialize queue and place initial orders
    printf("=== PROBLEM 1: Queue Initialization ===\n");
    // Initialize the delivery queue
    // Place 5 initial food orders
    // Display the current queue
    // Display queue statistics

    // Sample orders for testing
FoodOrder initialOrders[] = {
    {101, "John Doe", "Burger Meal", 12.99, 15},
    {102, "Jane Smith", "Pizza Large", 18.50, 20},
    {103, "Bob Johnson", "Chicken Wings", 14.75, 12},
    {104, "Alice Brown", "Salad Bowl", 9.99, 8},
    {105, "Charlie Wilson", "Pasta", 11.25, 10}
};
    
    // PROBLEM 2: Process some orders
    printf("\n=== PROBLEM 2: Order Processing ===\n");
    // Process 2 orders from the queue
    // Display the updated queue after each processing
    // Display updated statistics
    
    // PROBLEM 3: Place new orders while processing
    // Sample new orders for PROBLEM 3
FoodOrder newOrders[] = {
    {106, "David Lee", "Sushi Platter", 22.99, 18},
    {107, "Emma Davis", "Steak Dinner", 24.50, 25},
    {108, "Frank Miller", "Ice Cream", 5.99, 5}
};

    printf("\n=== PROBLEM 3: Mixed Operations ===\n");
    // Place 2 new orders
    // Process 1 order
    // Place 1 more order
    // Display the final queue
    // Display final statistics
    
    // PROBLEM 4: Edge cases
    printf("\n=== PROBLEM 4: Edge Cases ===\n");
    // Try to process from empty queue
    // View next order from empty queue
    
    printf("\nPress Enter to exit...");
    clearBuffer();
    getchar();
    
    return 0;
}

// Initialize the delivery queue
DeliveryQueue initializeQueue() {
    DeliveryQueue newQueue;
    // Implement initialization logic here
    return newQueue;
}

// Add a new food order to the rear of the queue
void placeOrder(DeliveryQueue *dq, FoodOrder newOrder) {
    // Implement order placement logic here
    printf("Order #%d placed for %s: %s ($%.2f)\n", 
           newOrder.orderID, newOrder.customerName, newOrder.foodItem, newOrder.price);
}

// Process the next order (remove from front of queue)
void processOrder(DeliveryQueue *dq) {
    // Implement order processing logic here
}

// Check if the queue is empty
int isEmpty(DeliveryQueue *dq) {
    // Implement isEmpty logic here
    return 1; // placeholder
}

// View the next order without removing it
FoodOrder viewNextOrder(DeliveryQueue *dq) {
    FoodOrder dummy = {0, "N/A", "N/A", 0.0, 0};
    // Implement view logic here
    return dummy;
}

// Display all orders in the queue
void displayQueue(DeliveryQueue dq) {
    // Implement display logic here
}

// Display queue statistics
void displayQueueStats(DeliveryQueue dq) {
    // Implement statistics display logic here
}

// Clear input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

