#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CUSTSIZE 10
#define MENUSIZE 6
#define DELIVERED 5

typedef struct Name{
	char fName[33];
	char mi;
	char lName[33];
}Name;

typedef struct Customer{
	char custID[9];
	Name custName;
}Customer;

typedef struct{
	char foodName[37];
	float price;
}FoodItem;

typedef struct{
	char drinkName[37];
	int size; /* 0 Regular, 1 Large, 2 Extra Large; */
	float price;
}DrinkItem;

typedef struct Combo{
	FoodItem food;
	DrinkItem drink;
}Combo;

typedef struct Meal{
	char mealCode[4];
	char mealName[37];
	Combo comboItem;
	float price; /* Contains the sum of the price of the FoodItem, and the DrinkItem */
}Meal;

typedef struct MealNode{
	Meal order;
	int qty; /* Actual quantity of of the order. */
	int delQty; /* Quantity that has already been delivered to the customer */
	int mealStat; /* 0 if the meal is still being prepared, 1 if the meal has been given to the customer */
	struct MealNode* link;
}MealNode, *MealList;

typedef struct MealOrder{
	MealList ML;
	int ordItems; /* Contains the number of Meals inside the MealList */
	Customer cust;
	float bill; /* Contains the sum of all the meals in the MealList */
	int ordStat; /* 0 if the order has not been completed. 1 if the order has been completed (ALL mealStats == 1) */
}MealOrder;

typedef struct Menu{
	Meal menuItems[MENUSIZE];
}Menu;

/* Completed Functions */
void generateCustFile(void);
Menu populateMenu(void);
void displayMenu(Menu);
void pause(void);

/* Problem 1 */
Customer* readCustRecords(void);
void displayCustomers(Customer[]);

/* Problem 2 */
MealOrder initMealOrder(Customer);
void addMealToOrder(MealOrder*, Menu, Meal);
void displayMealOrder(MealOrder);

/* Problem 3 */
void checkMealCompletion(MealOrder);
void checkOrderCompletion(MealOrder*);
void deliverMeals(MealOrder*, Meal[], int);

/* Problem 4 */
void removeMealFromOrder(MealOrder*, Meal);

/* Problem 5 */
void writeCompletedToFile(MealOrder);
void readCustPurchaseHistory(Customer);

int main (void)
{
	Customer* custList;
	Menu menuList;
	MealOrder custOrder1, custOrder2;
	Meal orders1[4] = {{"B1", "Burger Steak Meal w/ [S]Drink", {{"Burger Steak", 46}, {"Coke[S]", 0, 14}}, 60.00},
					   {"C3", "2 Pc Chickenjoy w/ [L]Drink", {{"2 Pc Chickenjoy", 135}, {"Coke[L]", 2, 30}}, 165.0},
					   {"S1", "Spaghetti w/ [S]Drink", {{"Spaghetti", 46}, {"Coke[S]", 0, 14}}, 60.00},
 					   {"M1", "McDonald's Happy Meal", {{"Chicken Mcdo", 85}, {"Coke[S]", 0, 14}}, 99.00}
					  };
	
	Meal orders2[3] = {{"B1", "Burger Steak Meal w/ [S]Drink", {{"Burger Steak", 46}, {"Coke[S]", 0, 14}}, 60.00},
					   {"C2", "1 Pc Chickenjoy w/ [M]Drink", {{"Spicy Chickenjoy", 77}, {"Coke[M]", 1, 25}}, 102.00},
					   {"S2", "Pan Spaghetti w/ [L]Drink", {{"Pan Spaghetti", 170}, {"Coke[L]", 3, 30}}, 200.00}
					  };				  
					  
					  
	Meal deliverOrds1[5] = {{"B1", "Burger Steak Meal w/ [S]Drink", {{"Burger Steak", 46}, {"Coke[S]", 0, 14}}, 60.00},
						  	{"C3", "2 Pc Chickenjoy w/ [L]Drink", {{"2 Pc Chickenjoy", 135}, {"Coke[L]", 2, 30}}, 165.00},
						  	{"C3", "2 Pc Chickenjoy w/ [L]Drink", {{"2 Pc Chickenjoy", 135}, {"Coke[L]", 2, 30}}, 165.00},
							{"S1", "Spaghetti w/ [S]Drink", {{"Spaghetti", 46}, {"Coke[S]", 0, 14}}, 60.00},
						  	{"C2", "1 Pc Chickenjoy w/ [M]Drink", {{"Spicy Chickenjoy", 77}, {"Coke[M]", 1, 25}}, 102.00}
						   };
						 		  
	Meal deliverOrds2[2] = {{"S2", "Pan Spaghetti w/ [L]Drink", {{"Pan Spaghetti", 170}, {"Coke[L]", 3, 30}}, 200.00},
						  	{"C2", "1 Pc Chickenjoy w/ [M]Drink", {{"Spicy Chickenjoy", 77}, {"Coke[M]", 1, 25}}, 102.00}
						   };
	/* Problem 0 */
	/* Instructions:
		1) Generate the customerRecords file.
		2) Read the newly generated file into custList.
		3) Display the customers inside custList.
		4) Declare and initialize a variable cust1 to have the value of the first record in custList.
		5) Declare and initialize a variable cust2 to have the value of the second record in custList.
		6) Call the pause() function.
	*/
	printf("Problem 0");
	generateCustFile();
	menuList = populateMenu();
	displayMenu(menuList);
	pause	();

	/* Problem 1 */
	/* Instructions:
		1) Populate variable menuList.
		2) Display the menu.
		3) Call the pause() function.
	*/
	printf("Problem 1");
		custOrder1 = initMealOrder(custList[0]);
		addMealToOrder(&custOrder1, menuList, orders1[0]);
		addMealToOrder(&custOrder1, menuList, orders1[0]);
		addMealToOrder(&custOrder1, menuList, orders1[1]);
		addMealToOrder(&custOrder1, menuList, orders1[2]);
		addMealToOrder(&custOrder1, menuList, orders1[3]);
		displayMealOrder(custOrder1);
		pause();

	
	/* Problem 2 */
	/* Instructions:
		1) Initialize variable custOrder1, passing cust1 as the parameter.
		2) Call function addMealToOrder for custOrder1, passing order1[0] as the Meal parameter.
		3) Call function addMealToOrder for custOrder1, passing order1[0] as the Meal parameter.
		4) Call function addMealToOrder for custOrder1, passing order1[1] as the Meal parameter.
		5) Call function addMealToOrder for custOrder1, passing order1[2] as the Meal parameter.
		6) Call function addMealToOrder for custOrder1, passing order1[3] as the Meal parameter.
		7) Display the contents of custOrder1.
		8) Call the pause() function.
	*/
	printf("Problem 2");

	
	/* Problem 3 */
	/* Instructions:
		1) Deliver the meals for custOrder1 by passing all the values inside the deliveredOrds1 variable.
		2) Display the contents of custOrder1.
		3) Deliver the last meal for custOrder1 by passing just the FIRST index of deliveredOrds1.
		4) Display the contents of custOrder1.
		5) Call the pause() function.
	*/
	printf("Problem 3");

	
	/* Problem 4 */
	/* Instructions:
		1) 	Initialize variable custOrder2, passing cust2 as the parameter.
		2) 	Call function addMealToOrder for custOrder2, passing orders2[0] as the Meal parameter.
		3) 	Call function addMealToOrder for custOrder2, passing orders2[1] as the Meal parameter.
		4) 	Call function addMealToOrder for custOrder2, passing orders2[1] as the Meal parameter.
		5) 	Call function addMealToOrder for custOrder2, passing orders2[1] as the Meal parameter.
		6) 	Call function addMealToOrder for custOrder2, passing orders2[2] as the Meal parameter.		
		7) 	Display the contents of custOrder2.
		8) 	Deliver the meals for custOrder2 by passing all the values inside the deliveredOrds2 variable.
		9) 	Deliver another meal for custOrder2 by passing the SECOND index of deliveredOrds2 variable.
		10) Display the contents of custOrder2.
		11) Cancel one of the meal orders in custOrder2 by passing orders2[0].
		12) Cancel one of the meal orders in custOrder2 by passing orders2[1].
		13) Cancel one of the meal orders in custOrder2 by passing orders2[2].
		14) Display the contents of custOrder2.
		15) Call the pause() function.
	*/
	printf("Problem 4");

	return 0;
}

/* Code has been fully provided.
 */
Menu populateMenu(void)
{
	Menu menuList = {{{"B1", "Burger Steak Meal w/ [S]Drink", {{"Burger Steak", 46}, {"Coke[S]", 0, 14}}, 60.00},
					  {"C1", "1 Pc Chickenjoy w/ [S]Drink", {{"Chickenjoy", 75}, {"Coke[S]", 0, 14}}, 89.00},
					  {"C2", "1 Pc Chickenjoy w/ [M]Drink", {{"Spicy Chickenjoy", 77}, {"Coke[M]", 1, 25}}, 102.00},
					  {"C3", "2 Pc Chickenjoy w/ [L]Drink", {{"2 Pc Chickenjoy", 135}, {"Coke[L]", 2, 30}}, 165.00},
					  {"S1", "Spaghetti w/ [S]Drink", {{"Spaghetti", 46}, {"Coke[S]", 0, 14}}, 60.00},
					  {"S2", "Pan Spaghetti w/ [L]Drink", {{"Pan Spaghetti", 170}, {"Coke[L]", 3, 30}}, 200.00},
					 }};
					 
	return menuList;
}

/* Code has been fully provided.
 */
void displayMenu(Menu menuList)
{
	printf("\n\n<-- Menu -->\n");
	printf("%-10s", "Code");
	printf("%-40s", "Meal Name");
	printf("%-25s", "Food Item");
	printf("%-20s", "Drink Item");
	printf("%-10s", "Price");
	
	int i;
	for(i = 0; i < MENUSIZE; i++){
		printf("\n%-10s%-40s%-25s%-20s%-10.2f", menuList.menuItems[i].mealCode, menuList.menuItems[i].mealName,
		menuList.menuItems[i].comboItem.food.foodName, menuList.menuItems[i].comboItem.drink.drinkName,
		menuList.menuItems[i].price);
	}
}

/* Code has been fully provided.
 */
void pause(void)
{
	printf("\n\nPress any key to continue...");
	getchar();
	system("CLS");
}

/* Code has been fully provided.
 */
void generateCustFile(void)
{
	Customer custList[CUSTSIZE] = {{"00000001", {"Cris", 'G', "Tan"}}, {"00000002", {"Czar", 'C', "Espinola"}},
								   {"00000003", {"Ciar", 'T', "Janizola"}}, {"00000004", {"Dania", 'L', "Limuella"}},
								   {"00000005", {"Marai", 'K', "Tagle"}}, {"00000006", {"Josefine", 'L', "Lim"}},
								   {"00000007", {"Janssen", 'L', "Camotes"}}, {"00000008", {"Dante", 'A', "Duma"}},
								   {"00000009", {"Gabby", 'A', "De La Pena"}}, {"00000010", {"Patty", 'S', "Woo"}},
								  };
								  
	FILE* fp = fopen("customerRecords.bin", "wb");
	if(fp != NULL){
		fwrite(custList, sizeof(Customer), CUSTSIZE, fp);
	}
	
	fclose(fp);
}

/* Code has been fully provided.
 */
Customer* readCustRecords(void)
{
	Customer* customers = (Customer*) malloc (sizeof(Customer) * CUSTSIZE);
	if(customers != NULL){
		FILE* fp = fopen("customerRecords.bin", "rb");
		if(fp!= NULL){
			fread(customers, sizeof(Customer), CUSTSIZE, fp);
			fclose(fp);
		}else{
			printf("\nFile not found!\n");
		}
	}else{
		printf("\nMalloc failed. Disk drive is full.\n");
	}
	
	return customers;
}

/* Code has been fully provided.
 */
void displayCustomers(Customer CList[])
{
	int i;
	printf("\n\n<-- Customers -->\n");
	printf("%-20s", "Customer ID");
	printf("%s", "Customer Name");
	
	for(i = 0; i < CUSTSIZE; i++){
		printf("\n%-20s%s %c. %s", CList[i].custID, CList[i].custName.fName, CList[i].custName.mi, CList[i].custName.lName);
	}
}

/*This function creates a new order for a given customer. It initializes all fields of the MealOrder structure with default values, making sure the order starts empty.
 */
MealOrder initMealOrder(Customer cust)
{
	MealOrder order = {NULL, 0, cust, 0.0, 0};
	return order;
}

/* This function adds a meal to a customer’s order. It first checks if the meal exists in the store’s menu.
 •    If the meal exists and is not yet in the order, a new node is created and added to the order list.
 •    If the meal exists and is already in the order, its quantity is increased.
 •    If the meal does not exist in the menu, an error message is shown.
The total number of items, statuses, quantities and the bill are updated accordingly.
 
 */
void addMealToOrder(MealOrder* MO, Menu menuList, Meal newOrder)
{
	int i;
	for(i=0; i < MENUSIZE && strcmp(newOrder.mealCode, menuList.menuItems[i].mealCode) != 0; i++){} //if newOrder is found in the menulist i < MenuSize : i = Menusize 
	if(i < MENUSIZE){
		int j;
		MealList *temp;
		for(j= 0, temp = &MO->ML; j < MO->ordItems && strcmp(newOrder.mealCode, (*temp)->order.mealCode) != 0; j++, temp = &(*temp)->link);
		if(j < MO->ordItems){ // existing order
			(*temp)->qty ++;
			MO->bill += (*temp)->order.price;


		}else{ //insert last
			MealList newMeal = (MealList)malloc(sizeof(MealNode));
			newMeal->order = newOrder;
			newMeal->qty = 1;
			newMeal->mealStat = 0;
			newMeal->delQty =0;
			newMeal->link =NULL;

			(*temp)->link = newMeal;
			
			MO->ordItems ++;
			MO->ordStat = 0;
			MO->bill += newOrder.price;
		}

	}else {
		printf("We dont have the %s in our Store", newOrder.mealName);
	}
}

/* Code has been fully provided.
 */
void displayMealOrder(MealOrder MO)
{
	printf("\n\n<-- %s's Order -->\n", MO.cust.custName.fName);
	printf("%-10s", "Code");
	printf("%-35s", "Meal Name");
	printf("%-10s", "Qty");
	printf("%-10s", "Del Qty");
	printf("%-20s", "Price");
	printf("%-20s", "Line Item Price");
	printf("%-10s", "Delivered");
	
	MealList trav;
	for(trav = MO.ML; trav != NULL; trav = trav->link){
		printf("\n%-10s%-35s%-10d%-10d%-20.2f%-20.2f%-10s", trav->order.mealCode, trav->order.mealName, trav->qty, 
		trav->delQty, trav->order.price, trav->order.price * trav->qty, (trav->mealStat == 0) ? "NO" : "YES");
	}
	
	printf("\n\nNumber of items:%d\nTotal Bill: %.2f\n", MO.ordItems, MO.bill);
	
	printf("\n\n%s\n", MO.ordStat == 1 ? "Your order has been completed. Enjoy your meal.\n" : 
										 "Your order is still being prepared. We are sorry for the delay.\n");
}

/* This function checks if individual meals in an order are complete. A meal is considered complete if the delivered quantity (delQty) matches the ordered quantity (qty). If that condition is met, the meal’s status (mealStat) is updated to 1 (delivered).
 */
void checkMealCompletion(MealOrder MO)
{

}

/* This function checks if the entire order is complete. An order is considered complete if all the meals in the order have been delivered. If that condition is met, the order’s status (ordStat) is updated to indicate completion.
 */
void checkOrderCompletion(MealOrder* MO)
{

}

/* This function simulates the process of delivering meals from a customer’s order. It takes a list of meals to be delivered and updates the order:
 •    If the meal exists in the order and hasn’t been fully delivered, it increases the delivered quantity.
 •    If the meal has already been delivered before, it prints a message.
 •    If the customer never ordered that meal, it prints a message.
    Finally, it checks if the meal and the whole order is now complete.
 */
void deliverMeals(MealOrder* MO, Meal DList[], int numMeals)
{
	int i;
	MealList *trav;
	int dsize = sizeof(DList)/sizeof(DList[0]);
	for(int x=0; x < sizeof(DList); x++) // x = index sa DList
	{
		//check if naa sa Mealorder and Dlist[x] ? i < ordItems : i = ordItems
		for(i =0, trav = &MO->ML; i < MO->ordItems && strcmp(DList[x].mealCode, (*trav)->order.mealCode) != 0; i++, trav = &(*trav)->link){}
		if(i < MO->ordItems){ //naa sya sa mealorder
			if((*trav)->mealStat == 0){ // wapa na deliver / complete


			} else{
				printf("%s has already been delivered.", DList[x].mealName);
			}

		}else{
			printf("You didn't order a %s", DList[x].mealName);
		}


	}
	
}

/* This function removes a meal from a customer’s order. If the meal exists in the order and has not yet been delivered, the function decreases its quantity or removes it entirely (if the qty reaches 0). If the meal has already been delivered, the system should not allow cancellation. If the customer never ordered the meal, an error message is shown.
 */

void removeMealFromOrder(MealOrder* MO, Meal cancelMeal)
{

}
