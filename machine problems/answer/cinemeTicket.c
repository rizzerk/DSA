#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 50
#define MAX_NAME_LEN 50
#define MAX_MOVIE_LEN 60

typedef struct {
    char firstName[MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
    int age;
} Customer;

typedef struct {
    int ticketID;
    char movieTitle[MAX_MOVIE_LEN];
    char seatNumber[10];
    char ticketType[20]; // "Regular", "VIP", "Premium"
    float price;
} Ticket;

typedef struct TicketNode {
    Ticket ticketInfo;
    Customer customerInfo;
    struct TicketNode* next;
} TicketNode, *TicketList;

typedef struct {
    TicketList front;
    TicketList rear;
    int queueSize;
    char queueType[20]; // "Regular", "VIP", "Premium"
} TicketQueue;

typedef struct {
    TicketQueue regularQueue;
    TicketQueue vipQueue;
    TicketQueue premiumQueue;
    int totalTicketsSold;
    float totalRevenue;
} CinemaSystem;

// ========== PROVIDED FUNCTIONS (DO NOT MODIFY) ==========
void displayMenu();
void displayTicketQueue(TicketQueue tq);
void displayCinemaStatus(CinemaSystem cs);
void pause();
CinemaSystem initializeCinema();

// ========== PROBLEM FUNCTIONS TO IMPLEMENT ==========

// PROBLEM 1: Queue Management Functions
TicketQueue createQueue(char queueType[]);
int isQueueEmpty(TicketQueue tq);
void enqueue(TicketQueue* tq, Ticket newTicket, Customer customer);
TicketNode dequeue(TicketQueue* tq);

// PROBLEM 2: Ticket Processing Functions  
void processTicketSale(CinemaSystem* cs, char ticketType[], Ticket newTicket, Customer customer);
void processNextCustomer(CinemaSystem* cs, char queueType[]);
int countQueueByMovie(TicketQueue tq, char movieTitle[]);

// PROBLEM 3: Advanced Queue Operations
void transferPriorityCustomers(CinemaSystem* cs); // Move customers aged 60+ to VIP queue
void cancelTicketByID(CinemaSystem* cs, int ticketID);
TicketList findCustomerTickets(CinemaSystem cs, char firstName[], char lastName[]);

int main() {
    CinemaSystem starCinema;
    TicketNode processedTicket;
    TicketList customerTickets;
    
    // Sample ticket data
    Ticket tickets[8] = {
        {1001, "Avatar: The Way of Water", "A15", "Regular", 250.0},
        {1002, "Top Gun: Maverick", "B20", "VIP", 450.0},
        {1003, "Black Panther: Wakanda Forever", "C10", "Premium", 350.0},
        {1004, "Avatar: The Way of Water", "D05", "Regular", 250.0},
        {1005, "Top Gun: Maverick", "VIP-02", "VIP", 450.0},
        {1006, "Spider-Man: No Way Home", "PREM-08", "Premium", 350.0},
        {1007, "Avatar: The Way of Water", "A25", "Regular", 250.0},
        {1008, "Black Panther: Wakanda Forever", "VIP-15", "VIP", 450.0}
    };
    
    Customer customers[8] = {
        {"John", "Doe", 25},
        {"Maria", "Santos", 65},
        {"Carlos", "Rodriguez", 30},
        {"Ana", "Garcia", 22},
        {"Roberto", "Martinez", 70},
        {"Sofia", "Lopez", 28},
        {"Diego", "Hernandez", 35},
        {"Isabella", "Cruz", 19}
    };

    printf("=== STARLIGHT CINEMA RESERVATION SYSTEM ===\n");
    
    // ========== PROBLEM 1 TESTING ==========
    printf("\n=== PROBLEM 1: QUEUE INITIALIZATION ===\n");
    /* INSTRUCTIONS:
     * 1. Initialize the cinema system using initializeCinema()
     * 2. Display the initial cinema status
     * 3. Add the first 5 tickets and customers to their respective queues using processTicketSale()
     * 4. Display the cinema status after adding tickets
     * 5. Call pause()
     */
     
    // TODO: Implement Problem 1 instructions here
    
    
    
    // ========== PROBLEM 2 TESTING ==========
    printf("\n=== PROBLEM 2: TICKET PROCESSING ===\n");
    /* INSTRUCTIONS:
     * 1. Process 2 customers from the Regular queue
     * 2. Process 1 customer from the VIP queue  
     * 3. Process 1 customer from the Premium queue
     * 4. Display the updated cinema status
     * 5. Count and display how many "Avatar: The Way of Water" tickets are in Regular queue
     * 6. Add the remaining 3 tickets to their respective queues
     * 7. Display final cinema status
     * 8. Call pause()
     */
     
    // TODO: Implement Problem 2 instructions here
    
    
    
    // ========== PROBLEM 3 TESTING ==========
    printf("\n=== PROBLEM 3: ADVANCED OPERATIONS ===\n");
    /* INSTRUCTIONS:
     * 1. Transfer all senior citizens (age 60+) to VIP queue
     * 2. Display cinema status after transfer
     * 3. Cancel ticket with ID 1004
     * 4. Display cinema status after cancellation
     * 5. Find and display all tickets for customer "Roberto Martinez"
     * 6. Process all remaining customers in VIP queue
     * 7. Display final cinema status
     * 8. Call pause()
     */
     
    // TODO: Implement Problem 3 instructions here
    
    
    
    printf("\n=== END OF CINEMA OPERATIONS ===\n");
    return 0;
}

// ========== PROVIDED FUNCTIONS (COMPLETE - DO NOT MODIFY) ==========

CinemaSystem initializeCinema() {
    CinemaSystem cs;
    
    // Initialize regular queue
    strcpy(cs.regularQueue.queueType, "Regular");
    cs.regularQueue.front = NULL;
    cs.regularQueue.rear = NULL;
    cs.regularQueue.queueSize = 0;
    
    // Initialize VIP queue
    strcpy(cs.vipQueue.queueType, "VIP");
    cs.vipQueue.front = NULL;
    cs.vipQueue.rear = NULL;
    cs.vipQueue.queueSize = 0;
    
    // Initialize Premium queue
    strcpy(cs.premiumQueue.queueType, "Premium");
    cs.premiumQueue.front = NULL;
    cs.premiumQueue.rear = NULL;
    cs.premiumQueue.queueSize = 0;
    
    cs.totalTicketsSold = 0;
    cs.totalRevenue = 0.0;
    
    return cs;
}

void displayTicketQueue(TicketQueue tq) {
    TicketList current = tq.front;
    int position = 1;
    
    printf("\n--- %s QUEUE (Size: %d) ---\n", tq.queueType, tq.queueSize);
    if (isQueueEmpty(tq)) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("%-3s %-20s %-25s %-10s %-8s %-6s %s\n", 
           "Pos", "Customer", "Movie", "Seat", "ID", "Age", "Price");
    printf("-----------------------------------------------------------------------\n");
    
    while (current != NULL) {
        printf("%-3d %-20s %-25s %-10s %-8d %-6d $%.2f\n",
               position++,
               strcat(strcat(strcpy((char[100]){0}, current->customerInfo.firstName), " "), current->customerInfo.lastName),
               current->ticketInfo.movieTitle,
               current->ticketInfo.seatNumber,
               current->ticketInfo.ticketID,
               current->customerInfo.age,
               current->ticketInfo.price);
        current = current->next;
    }
}

void displayCinemaStatus(CinemaSystem cs) {
    printf("\n" "====== STARLIGHT CINEMA STATUS ======\n");
    printf("Total Tickets Sold: %d\n", cs.totalTicketsSold);
    printf("Total Revenue: $%.2f\n", cs.totalRevenue);
    
    displayTicketQueue(cs.regularQueue);
    displayTicketQueue(cs.vipQueue); 
    displayTicketQueue(cs.premiumQueue);
    printf("=====================================\n");
}

void pause() {
    printf("\nPress any key to continue...");
    getchar();
    system("clear");
}

// ========== FUNCTIONS TO IMPLEMENT ==========

/* PROBLEM 1 FUNCTIONS */

// Creates and initializes a new queue with the given type
// Returns a TicketQueue with all fields properly initialized
TicketQueue createQueue(char queueType[]) {
    // TODO: Implement this function
    TicketQueue tq;
    memset(&tq, 0, sizeof(TicketQueue));
    strcpy(tq.queueType, queueType);
    return tq;
}

// Checks if the queue is empty
// Returns 1 if empty, 0 otherwise
int isQueueEmpty(TicketQueue tq) {
    // TODO: Implement this function
    return tq.front == NULL;
}

// Adds a new ticket and customer to the rear of the queue
// Updates queue size and rear pointer appropriately
void enqueue(TicketQueue* tq, Ticket newTicket, Customer customer) {
    // TODO: Implement this function
    TicketList newNode = (TicketList)malloc(sizeof(TicketNode));
    newNode->ticketInfo = newTicket;
    newNode->customerInfo = customer;
    newNode->next = NULL;
    if(isQueueEmpty(*tq)){
        tq->front =tq->rear = newNode;
    }else{
        tq->rear->next = newNode;
        tq->rear = newNode;
    }
    tq->queueSize++;
    printf("Processing ticket sale: %s %s - %s (%s)\n", customer.firstName, 
                                                        customer.lastName,
                                                        newTicket.movieTitle,
                                                        tq->queueType);
}

// Removes and returns the front customer from the queue
// Updates queue size and front pointer appropriately
// Returns a TicketNode with empty data if queue is empty
TicketNode dequeue(TicketQueue* tq) {
    // TODO: Implement this function
    TicketNode copy;
    if(isQueueEmpty(*tq)){
        printf("Queue is Empty\n");
        memset(&copy, 0, sizeof(TicketNode));
        return copy;
    }else{
        TicketList temp = tq->front;
        copy = *temp;
        tq->front = tq->front->next;
        if(tq->front == NULL) //or if ma empty na sya
            {
                tq->rear = NULL;
            }
         tq->queueSize--;   
        free(temp);
    }
    return copy;
}

/* PROBLEM 2 FUNCTIONS */

// Processes a ticket sale by adding it to the appropriate queue based on ticket type
// Also updates the cinema system's total revenue
void processTicketSale(CinemaSystem* cs, char ticketType[], Ticket newTicket, Customer customer) {
    // TODO: Implement this function
    if(strcmp(ticketType, "Regular") == 0){
        strcpy(cs->regularQueue.queueType, ticketType);
        enqueue(&cs->regularQueue, newTicket, customer);
        


    }else if(strcmp(ticketType, "VIP") == 0){
        strcpy(cs->vipQueue.queueType, ticketType);
        enqueue(&cs->vipQueue, newTicket, customer);

    }else if(strcmp(ticketType, "Premium") == 0){
        strcpy(cs->premiumQueue.queueType, ticketType);
        enqueue(&cs->premiumQueue, newTicket, customer);

    }
    cs->totalRevenue += newTicket.price;
}

// Processes the next customer from the specified queue type
// Removes them from queue and updates total tickets sold
// Prints appropriate messages for successful processing or empty queue
void processNextCustomer(CinemaSystem* cs, char queueType[]) {
    // TODO: Implement this function
    TicketNode t;
    if(strcmp(queueType, "Regular") == 0){
        t =  dequeue(&cs->regularQueue);
        


    }else if(strcmp(queueType, "VIP") == 0){
        t = dequeue(&cs->vipQueue);

    }else if(strcmp(queueType, "Premium") == 0){
        t = dequeue(&cs->premiumQueue);
    }
    
    if(t.ticketInfo.ticketID != 0){
        printf("Ticket processed successfully! Enjoy your movie.\n");
    cs->totalTicketsSold++;
    }
}

// Counts how many tickets for a specific movie are in the given queue
// Returns the count as an integer
int countQueueByMovie(TicketQueue tq, char movieTitle[]) {
    // TODO: Implement this function
    int count=0;
    for(int i=0; i < tq.queueSize; i++){
        if(strcmp(tq.front->ticketInfo.movieTitle, movieTitle)){
            count++;
        }
        tq.front = tq.front->next;
    }
    return count;
}

/* PROBLEM 3 FUNCTIONS */

// Transfers all customers aged 60 and above from Regular and Premium queues to VIP queue
// Maintains the order of customers during transfer
void transferPriorityCustomers(CinemaSystem* cs) {
    // TODO: Implement this function
    TicketList regTrav = cs->regularQueue.front;
    for(int i=0; i < cs->regularQueue.queueSize; i++){
        if(regTrav->customerInfo.age >= 60){
            enqueue(&cs->regularQueue, regTrav->ticketInfo, regTrav->customerInfo);
        }
    
    }
    
}

// Cancels a ticket by removing it from any queue that contains the specified ticket ID
// Updates revenue and prints appropriate messages
void cancelTicketByID(CinemaSystem* cs, int ticketID) {
    // TODO: Implement this function
    
}

// Finds all tickets belonging to a customer with the given name
// Returns a linked list of tickets (or NULL if none found)
// Note: This creates a new list, original queues remain unchanged
TicketList findCustomerTickets(CinemaSystem cs, char firstName[], char lastName[]) {
    // TODO: Implement this function
    
}