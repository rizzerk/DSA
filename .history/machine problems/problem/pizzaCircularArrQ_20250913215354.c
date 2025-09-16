#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ORDERS 6  // Pizza oven can handle 6 orders at once
#define MAX_TOPPINGS 10

typedef struct {
    char customerName[30];
    char pizzaType[25];     // "Margherita", "Pepperoni", "Hawaiian", etc.
    char toppings[MAX_TOPPINGS][15]; // Array of toppings
    int numToppings;
    char size[10];          // "Small", "Medium", "Large"
    float price;
    int cookingTime;        // in minutes
} Pizza;

typedef struct {
    int orderID;
    Pizza pizza;
    char status[20];        // "WAITING", "COOKING", "READY", "DELIVERED", "CANCELLED"
    int priority;           // 1=VIP, 2=Regular, 3=Delivery
    char orderTime[10];     // "14:30"
    char specialInstructions[50];
} PizzaOrder;

typedef struct {
    PizzaOrder orders[MAX_ORDERS]; // Circular array - our pizza oven queue!
    int front;              // Next order to start cooking
    int rear;               // Last order added to queue
    int size;               // Current orders in oven queue
    int capacity;           // Max oven capacity
    char ovenName[30];      // "Tony's Wood-Fired Oven #1"
} PizzaOven;

typedef struct {
    int totalOrders;
    int completedOrders;
    int cancelledOrders;
    float totalRevenue;
    float averageCookingTime;
    int happyCustomers;     // Orders completed on time
    char restaurantName[50];
} RestaurantStats;

// Completed Functions
void displayOven(PizzaOven *oven);
void displayStats(RestaurantStats stats);
PizzaOrder createRandomOrder(int orderID);
PizzaOrder createVIPOrder(int orderID);
PizzaOrder createProblemOrder(int orderID);
void runPizzaRestaurantSimulation();

// PROBLEM 0 - Basic Pizza Oven Operations
PizzaOven initOven(char ovenName[]);
int isOvenEmpty(PizzaOven *oven);
int isOvenFull(PizzaOven *oven);
void addOrder(PizzaOven *oven, PizzaOrder newOrder);

// PROBLEM 1 - Kitchen Operations  
PizzaOrder startCooking(PizzaOven *oven);
PizzaOrder checkNextOrder(PizzaOven *oven);
int getCurrentOrders(PizzaOven *oven);

// PROBLEM 2 - Restaurant Management
void cookPizza(PizzaOven *oven, RestaurantStats *stats);
void validateKitchen(PizzaOven *oven);
RestaurantStats calculateDailyStats(PizzaOven *oven);

int main() {
    srand(42); // Fixed seed for consistent results
    
    printf("🍕 ============================================== 🍕\n");
    printf("    WELCOME TO TONY'S PIZZERIA SIMULATOR!\n");
    printf("   Testing Pizza Oven Queue Management System\n");
    printf("🍕 ============================================== 🍕\n\n");
    
    runPizzaRestaurantSimulation();
    
    return 0;
}

void runPizzaRestaurantSimulation() {
    PizzaOven oven;
    RestaurantStats stats;
    PizzaOrder order;
    
    // ==================== TEST 1: EMPTY KITCHEN OPERATIONS ====================
    printf("🔥 TEST 1: Empty Kitchen - Opening Time!\n");
    printf("================================================\n");
    
    // TODO: Test empty oven operations
    // 1. Initialize oven with name "Tony's Wood-Fired Oven #1"
    // 2. Check if oven is empty and not full
    // 3. Try to start cooking (should show "No orders to cook!" message)
    // 4. Try to check next order (should show "No orders waiting!" message)  
    // 5. Try to cook pizza (should show "Kitchen is empty!" message)
    // 6. Display empty oven status
    
    
    
    
    
    printf("\n🍕 Press any key to continue to lunch rush...\n");
    getchar();
    system("clear");
    
    // ==================== TEST 2: SINGLE ORDER OPERATIONS ====================
    printf("🍕 TEST 2: First Customer of the Day!\n"); 
    printf("=======================================\n");
    
    // TODO: Test oven with exactly one order
    // 1. Add one random pizza order to empty oven
    // 2. Check oven size, empty status, full status
    // 3. Check what the next order is (should not remove it)
    // 4. Verify size is still 1 after checking
    // 5. Start cooking the order (should remove it from queue)
    // 6. Verify oven is empty after starting to cook
    
    
    
    
    
    printf("\n🍕 Press any key for the lunch rush...\n");
    getchar(); 
    system("clear");
    
    // ==================== TEST 3: BUSY LUNCH RUSH - FULL OVEN ====================
    printf("🔥 TEST 3: LUNCH RUSH - Oven at Full Capacity!\n");
    printf("==============================================\n");
    
    // TODO: Test completely full oven
    // 1. Fill oven to capacity (MAX_ORDERS = 6) with random orders
    // 2. Display "LUNCH RUSH IN PROGRESS!" message
    // 3. Verify oven is full
    // 4. Try to add another order (should fail - "Oven is full! Please wait!")
    // 5. Display full oven status
    // 6. Start cooking one order (free up space)
    // 7. Verify oven is no longer full
    // 8. Add one more order successfully
    
    
    
    
    
    printf("\n🍕 Press any key for the evening complexity...\n");
    getchar(); 
    system("clear");
    
    // ==================== TEST 4: EVENING RUSH - WRAPAROUND CHAOS ====================
    printf("🌆 TEST 4: Evening Rush - Orders Wrapping Around!\n");
    printf("===============================================\n");
    
    // TODO: Test circular array wraparound with pizza orders
    // 1. Add 3 orders (ID: 101, 102, 103) - customers: "Alice", "Bob", "Charlie"
    // 2. Display oven (front=0, rear=2)
    // 3. Start cooking 2 orders (front moves to 2) 
    // 4. Add 4 more orders (ID: 104, 105, 106, 107) - rear should wraparound
    // 5. Display oven - should show wraparound with rear < front
    // 6. Verify all order IDs and customer names are correct
    
    
    
    
    
    printf("\n🍕 Press any key for the late night cycle...\n"); 
    getchar(); 
    system("clear");
    
    // ==================== TEST 5: LATE NIGHT - OPEN-CLOSE-OPEN CYCLE ====================
    printf("🌙 TEST 5: Late Night - Close and Reopen Cycle\n");
    printf("=============================================\n");
    
    // TODO: Test multiple complete cycles (like closing and reopening)
    // 1. Fill oven completely with late night orders (6 orders)
    // 2. Cook all orders to close for the night (empty completely)
    // 3. Verify oven is empty and pointers reset correctly  
    // 4. Reopen next day - fill oven again with breakfast orders
    // 5. Verify second opening works correctly with new order IDs
    
    
    
    
    
    printf("\n🍕 Press any key for perfect day scenario...\n");
    getchar(); 
    system("clear");
    
    // ==================== TEST 6: PERFECT DAY - ALL ORDERS SUCCESSFUL ====================
    printf("⭐ TEST 6: Perfect Day - All Orders Perfect!\n");
    printf("==========================================\n");
    
    // TODO: Test cooking where all orders succeed perfectly
    // 1. Initialize stats with restaurant name "Tony's Pizzeria"
    // 2. Add 3 regular orders to oven
    // 3. Cook all orders (should all succeed - happy customers!)
    // 4. Calculate and display daily stats (should show 100% success)
    // 5. Validate kitchen operations
    
    
    
    
    
    printf("\n🍕 Press any key for disaster day...\n");
    getchar(); 
    system("clear");
    
    // ==================== TEST 7: DISASTER DAY - ALL ORDERS FAIL ====================
    printf("💥 TEST 7: Disaster Day - Everything Goes Wrong!\n");
    printf("===============================================\n");
    
    // TODO: Test cooking where all orders fail (oven breaks, ingredients spoil)
    // 1. Initialize stats with restaurant name "Tony's Pizzeria (Bad Day)"  
    // 2. Add 3 problem orders using createProblemOrder() (burnt, wrong ingredients, etc.)
    // 3. Try to cook all orders (should all fail dramatically)
    // 4. Calculate stats (should show 0% success, angry customers)
    // 5. Validate kitchen (should detect serious problems)
    
    
    
    
    
    printf("\n🍕 Press any key for realistic busy day...\n");
    getchar(); 
    system("clear");
    
    // ==================== TEST 8: REALISTIC BUSY DAY - MIXED RESULTS ====================
    printf("📊 TEST 8: Realistic Busy Day - Mixed Results\n");
    printf("============================================\n");
    
    // TODO: Test realistic day with mixed success/failure
    // 1. Initialize stats with restaurant name "Tony's Pizzeria (Typical Day)"
    // 2. Add variety: 2 regular orders, 1 VIP order, 1 problem order, 1 regular order
    // 3. Cook all orders (realistic mix of success/problems)
    // 4. Calculate stats (should show partial success, some unhappy customers)
    // 5. Validate kitchen operations
    
    
    
    
    
    printf("\n🍕 === PIZZERIA SIMULATION COMPLETED! === 🍕\n");
    printf("Thanks for managing Tony's Pizzeria!\n");
}

// ==================== YOUR IMPLEMENTATIONS ====================

// Initialize the pizza oven with a name
// Set front and rear to -1, size to 0, capacity to MAX_ORDERS
PizzaOven initOven(char ovenName[]) {
    // TODO: Implement this function
    // Hint: Don't forget to copy the oven name!

}

// Check if the oven is empty (no orders waiting)
// Return 1 if empty, 0 otherwise
int isOvenEmpty(PizzaOven *oven) {
    // TODO: Implement this function
    
}

// Check if the oven is full (at maximum capacity)
// Return 1 if full, 0 otherwise
int isOvenFull(PizzaOven *oven) {
    // TODO: Implement this function
    
}

// Add a new pizza order to the oven queue
// Handle circular array logic and customer notifications
void addOrder(PizzaOven *oven, PizzaOrder newOrder) {
    // TODO: Implement this function
    // Remember to handle:
    // 1. Full oven case: "Oven is full! Please wait, [CustomerName]!"
    // 2. First order case (when oven is empty)
    // 3. Circular wraparound for rear pointer
    // 4. Update size
    // 5. Success message: "[CustomerName]'s [PizzaType] added to oven queue!"
    
}

// Remove next order and start cooking it
// Handle circular array logic and empty oven cases
// Set status to "COOKING" when removed from queue
PizzaOrder startCooking(PizzaOven *oven) {
    // TODO: Implement this function
    // Remember to handle:
    // 1. Empty oven case: print "No orders to cook!" and return dummy order
    // 2. Update front pointer with wraparound
    // 3. Decrease size
    // 4. Change status to "COOKING"
    // 5. Print: "Started cooking [CustomerName]'s [PizzaType]!"
    
}

// Check what the next order is without removing it
// Handle empty oven case
PizzaOrder checkNextOrder(PizzaOven *oven) {
    // TODO: Implement this function
    // Should not modify the oven, just return copy of next order to cook
    // If empty, print "No orders waiting!" and return dummy order
    
}

// Return the current number of orders in the oven queue
int getCurrentOrders(PizzaOven *oven) {
    // TODO: Implement this function
    
}

// Cook the next pizza order and update restaurant stats
// Simulate cooking process and handle success/failure
void cookPizza(PizzaOven *oven, RestaurantStats *stats) {
    // TODO: Implement this function
    // 1. Check if oven is empty: "Kitchen is empty! No orders to cook!"
    // 2. Start cooking next order (remove from queue)
    // 3. Simulate cooking:
    //    - If orderID < 0: cooking fails (burnt/wrong ingredients)
    //    - If priority == 1 (VIP): always succeeds with bonus
    //    - Otherwise: random success/failure
    // 4. Update order status to "READY" or "CANCELLED"
    // 5. Update stats accordingly (revenue, completion, etc.)
    // 6. Print cooking results with emoji reactions
    
}

// Validate the kitchen operations and oven status
// Check for orders stuck in "COOKING" status, efficiency issues
void validateKitchen(PizzaOven *oven) {
    // TODO: Implement this function
    // 1. Check if oven is empty: "✅ Kitchen is clean and ready!"
    // 2. Count orders in each status
    // 3. Look for orders stuck in "COOKING" status (problem!)
    // 4. Check for efficiency issues
    // 5. Print validation results with appropriate emojis
    
}

// Calculate end-of-day restaurant statistics
RestaurantStats calculateDailyStats(PizzaOven *oven) {
    // TODO: Implement this function
    // 1. Count completed vs cancelled orders
    // 2. Calculate success rate and customer satisfaction
    // 3. Calculate average cooking time
    // 4. Calculate total revenue
    // 5. Return populated stats struct
    
}

// ==================== PROVIDED HELPER FUNCTIONS ====================

// DO NOT TOUCH - Creates a random pizza order
PizzaOrder createRandomOrder(int orderID) {
    PizzaOrder order;
    order.orderID = orderID;
    order.priority = 2; // Regular customer
    order.pizza.cookingTime = 12 + (rand() % 8); // 12-20 minutes
    strcpy(order.status, "WAITING");
    strcpy(order.orderTime, "12:30");
    strcpy(order.specialInstructions, "");
    
    // Random customer names
    char customers[][30] = {"Alice Johnson", "Bob Smith", "Charlie Brown", "Diana Prince", 
                           "Eddie Murphy", "Fiona Apple", "George Lucas", "Helen Hunt"};
    strcpy(order.pizza.customerName, customers[rand() % 8]);
    
    // Random pizza types
    char pizzas[][25] = {"Margherita", "Pepperoni", "Hawaiian", "Veggie Supreme", 
                        "Meat Lovers", "BBQ Chicken"};
    strcpy(order.pizza.pizzaType, pizzas[rand() % 6]);
    
    // Random size and price
    char sizes[][10] = {"Small", "Medium", "Large"};
    int sizeIdx = rand() % 3;
    strcpy(order.pizza.size, sizes[sizeIdx]);
    order.pizza.price = 8.99 + (sizeIdx * 3.00) + (rand() % 5); // $8.99-$19.99
    
    // Random toppings
    char toppings[][15] = {"Extra Cheese", "Mushrooms", "Pepperoni", "Sausage", "Bell Peppers"};
    order.pizza.numToppings = rand() % 3 + 1; // 1-3 toppings
    for(int i = 0; i < order.pizza.numToppings && i < MAX_TOPPINGS; i++) {
        strcpy(order.pizza.toppings[i], toppings[rand() % 5]);
    }
    
    return order;
}

// DO NOT TOUCH - Creates a VIP customer order (always succeeds)
PizzaOrder createVIPOrder(int orderID) {
    PizzaOrder order = createRandomOrder(orderID);
    order.priority = 1; // VIP customer
    strcpy(order.pizza.customerName, "VIP Customer");
    strcpy(order.specialInstructions, "Handle with care - VIP customer!");
    order.pizza.price += 5.00; // VIP surcharge
    return order;
}

// DO NOT TOUCH - Creates a problem order (will fail cooking)
PizzaOrder createProblemOrder(int orderID) {
    PizzaOrder order;
    order.orderID = -abs(orderID); // Negative ID triggers failure
    order.priority = 2;
    order.pizza.cookingTime = 25; // Takes too long
    strcpy(order.status, "WAITING");
    strcpy(order.pizza.customerName, "Difficult Customer");
    strcpy(order.pizza.pizzaType, "Impossible Pizza");
    strcpy(order.pizza.size, "XXL");
    order.pizza.price = 25.99;
    order.pizza.numToppings = 1;
    strcpy(order.pizza.toppings[0], "Burnt Crust");
    strcpy(order.specialInstructions, "Make it perfect or I want refund!");
    return order;
}

// DO NOT TOUCH - Displays current oven status with pizza theme
void displayOven(PizzaOven *oven) {
    printf("\n🔥 ========= %s STATUS ========= 🔥\n", oven->ovenName);
    printf("Oven Capacity: %d orders\n", oven->capacity);
    printf("Current Orders: %d\n", oven->size);
    printf("Next to Cook: Position %d | Last Added: Position %d\n", oven->front, oven->rear);
    
    if(isOvenEmpty(oven)) {
        printf("🍕 Oven is empty - ready for orders!\n");
        printf("🔥 ========================================= 🔥\n\n");
        return;
    }
    
    printf("\n%-8s %-15s %-15s %-10s %-8s %-8s\n", "Position", "Customer", "Pizza", "Size", "Price", "Status");
    printf("----------------------------------------------------------------\n");
    
    int current = oven->front;
    for(int i = 0; i < oven->size; i++) {
        printf("%-8d %-15s %-15s %-10s $%-7.2f %-8s\n", 
               current,
               oven->orders[current].pizza.customerName,
               oven->orders[current].pizza.pizzaType,
               oven->orders[current].pizza.size,
               oven->orders[current].pizza.price,
               oven->orders[current].status);
        current = (current + 1) % oven->capacity;
    }
    printf("🔥 ========================================= 🔥\n\n");
}

// DO NOT TOUCH - Displays restaurant statistics with emojis
void displayStats(RestaurantStats stats) {
    printf("\n📊 ========= %s - DAILY REPORT ========= 📊\n", stats.restaurantName);
    printf("Total Orders: %d\n", stats.totalOrders);
    printf("Completed Orders: %d ✅\n", stats.completedOrders);
    printf("Cancelled Orders: %d ❌\n", stats.cancelledOrders);
    
    float successRate = stats.totalOrders > 0 ? 
                       (float)(stats.completedOrders) / stats.totalOrders * 100 : 0;
    printf("Success Rate: %.1f%%\n", successRate);
    
    if(successRate >= 90) printf("Customer Satisfaction: 😃 EXCELLENT!\n");
    else if(successRate >= 75) printf("Customer Satisfaction: 🙂 Good\n");
    else if(successRate >= 50) printf("Customer Satisfaction: 😐 Average\n");
    else printf("Customer Satisfaction: 😞 Needs Improvement\n");
    
    printf("Total Revenue: $%.2f 💰\n", stats.totalRevenue);
    printf("Happy Customers: %d 😊\n", stats.happyCustomers);
    printf("Average Cooking Time: %.1f minutes ⏱️\n", stats.averageCookingTime);
    printf("📊 ================================================= 📊\n\n");
}