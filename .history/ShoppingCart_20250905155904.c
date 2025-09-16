#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
#define PMSIZE 3

typedef struct{
	char promoCode[17];
	float discount;
}PromoCode;

typedef struct{
	char prodID[9];
	char prodName[33];
	float unitPrice;
	int qty;
}Product;

typedef struct{
	Product prodList[50];
	int lastProd; /* When ProdList is empty, lastProd is -1 */
}ProdList;

typedef struct nodeItem{
	Product item;
	struct nodeItem* nextItem;
}nodeItem, *SList;

typedef struct{
	float VAT;	/*12% of totalPrice */
	float discount; /* Value is equal to 0.00 if no Promo code has been used */
	float totalPrice;
}Invoice;

typedef struct{
	SList sCart;
	int numItems;
	char promoCode[17]; /* default value is "" (empty string) */
	Invoice receipt;
}Cart;

void pause(void);

/* Problem 1 */
/* Instructions: 
	1) displayProdList() - Partial Code is provided. The function will display the details of ALL the products in the 
						   passed ProductList.
	2) initProdList() - The function will initialize the passed ProductList.
	3) populateProdList() - Partial Code is provided. The function will populate the passed ProductList with ALL the
							products in the array of products defined within the function.
*/
void displayProdList(ProdList);
void initProdList(ProdList*);
void populateProdList(ProdList*);

/* Problem 2 */
/* Instructions:
	1) initCart() - The function will initialize the passed Cart to be empty.
	2) genReceipt() - The function will calculate for the values of the receipt for the passed Cart.
	3) displayCart() - Partial Code is provided. The function will display all the details of the Cart based on the format
					   given in the output screenshot. Note: The function will call genReceipt to calculate the Receipt details
					   of the given Cart before these details are displayed.
	4) addToCart() - The function will check if the passed productID exists in the ProdList and if there is enough stocks 
					 in the ProdList to accomodate your purchase. If both of these conditions are met, it will insert
					 the item into the FIRST node of your sCart. Update the necessary fields upon insertion. 
					 Note: Machine Problems will not normally say what the necessary fields are. But you can ask me if
					 	   you give up. :)
*/
Cart initCart(void);
void genReceipt(Cart*, PromoCode[], char[]);
void displayCart(Cart*);
void addToCart(Cart*, ProdList*, char[], int);

/* Problem 3 */
/* Instructions:
	1) returnItem() - The function will check if the passed productID exists in the passed Cart. If it does, also check if
					  the qty to be returned does not exceed the quantity you've purchased based on you Cart info. If both
					  these conditions are met, subtract the quantity for that item in your Cart. Also, if the quantity
					  for that item reaches ZERO, delete the item from your cart. Update the necessary fields upon successful
					  item return.
					  Note: Machine Problems will not normally say what the necessary fields are. But you can ask me if
					 	    you give up. :)
*/
void returnItem(Cart*, ProdList*, char[], int);

int main(void)
{
	ProdList groceryStore;
	Cart myCart;
	char prod1[] = "FR000001";
	char prod2[] = "FR000010";
	char prod3[] = "VG000001";

	puts("PROBLEM 1");
  initProdList(&groceryStore);
  populateProdList(&groceryStore);
  displayProdList(groceryStore);
  pause();


	/* Instructions:
		1) Initialize variable groceryStore. 
		2) Populate groceryStore with products.
		3) Display the products in the groceryStore.
		4) Call the pause() function.
	*/

  puts("PROBLEM 2");
  myCart = initCart();
	/*1) Initialize variable myCart.
		2) Call function addToCart passing prod1 as the string parameter, and 55 as the int parameter.
		3) Call function addToCart passing prod1 as the string parameter, and 10 as the int parameter.
		4) Call function addToCart passing prod2 as the string parameter, and 50 as the int parameter.
		5) Call function addToCart passing prod3 as the string parameter, and 10 as the int parameter.
		6) Display the contents of myCart.
		7) Display the products in the groceryStore.
		8) Call the pause() function.
	*/
	
	puts("PROBLEM 3");
	/* Instructions:
		1) Call function returnItem passing prod1 as the string parameter, and 20 as the int parameter.
		2) Call function returnItem passing prod1 as the string parameter, and 40 as the int parameter.
		3) Call function returnItem passing prod2 as the string parameter, and 10 as the int parameter.
		4) Call function returnItem passing prod3 as the string parameter, and 10 as the int parameter.
		5) Display the contents of myCart.
		6) Display the products in the groceryStore.
		7) Call the pause() function.
	*/

	
	return 0;
}

void pause(void)
{
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}

void displayProdList(ProdList PL)
{ 
  printf("\n\n<-- Product List -->\n");
	printf("%-10s", "ProdID");
	printf("%-15s", "ProdName");
	printf("%-10s", "Price");
	printf("%-10s", "Stocks");
  
  for(int i= 0; i <= PL.lastProd ; i ++){
  printf("\n%-10s%-15s%-10.2f%-10d%-15.2f", PL.prodList[i].prodID, 
                                            PL.prodList[i].prodName, 
                                            PL.prodList[i].unitPrice, 
                                            PL.prodList[i].qty);

  }
}

void initProdList(ProdList* PL)
{
  PL->lastProd = -1;
}

void populateProdList(ProdList* PL)
{
	int i;
	Product items[] = {{"FR000001", "Apple", 32.00, 60},
					   {"FR000002", "Orange", 25.00, 50},
					   {"FR000003", "Pineapple", 66.00, 30},
					   {"FR000004", "Durian", 45.00, 25},
					   {"FR000005", "Squash", 54.00, 40},
					   {"FR000006", "Grapes", 12.00, 150},
					   {"FR000007", "Mango", 33.00, 80},
					   {"FR000008", "Cherries", 7.00, 150},
					   {"VG000001", "Cabbage", 24.00, 40},
					   {"VG000002", "Broccoli", 18.00, 60},
					  };
  
  for(i = 0; i < SIZE; i++){
    ++PL->lastProd;
    PL->prodList[PL->lastProd] = items[i];
  }
}

Cart initCart(void)
{
  Cart newCart = {NULL, 0, "", {0,0,0}};

  return newCart;
}

void genReceipt(Cart* C, PromoCode promoList[], char promoCode[])
{
  int i;
  for (i=0; i <PMSIZE && strcmp(promoCode, promoList[i].promoCode) != 0; i++){}
  float discount = i < PMSIZE ? C->receipt.totalPrice * promoList[i].discount  : 0.0;
  C->receipt.VAT = C->receipt.totalPrice - discount;


	
}

void displayCart(Cart* C)
{
	PromoCode promos[PMSIZE] = {{"NEWCUSTOMER", 0.33},
						  {"FRIYAY", 0.15},
						  {"HURRAYFORPAYDAY", 0.20}
						 };
	
	printf("\n\n<-- Your Cart -->\n");
	printf("%-10s", "ProdID");
	printf("%-15s", "ProdName");
	printf("%-10s", "Price");
	printf("%-10s", "Qty");
	printf("%-15s", "Line Item Price");	/* Line item Price is the product of qty and price */


  SList temp;

	for(temp= C->sCart; temp!= NULL; temp->nextItem){
    float n = temp->item.unitPrice * temp->item.qty;
		printf("\n%-10s%-15s%-10.2f%-10d%-15.2f", temp->item.prodID, temp->item.prodName,
                                              temp->item.unitPrice, temp->item.qty, n);
    C->receipt.totalPrice += n;
	}

  genReceipt(&C, promos, "NEWCUSTOMER");
	
	printf("\n\nNumber of items: %d\n\nPromo Code: %s\nVAT: %.2f\nDiscount: %.2f\nTotal Price: %.2f\n", C->numItems, C->promoCode, C->receipt.VAT, C->receipt.discount, C->receipt.discount);
}

void addToCart(Cart* C, ProdList* PL, char prodID[], int itemQty)
{
  int i;
  for(i = 0; i < PL->lastProd && strcmp(PL->prodList[i].prodID, prodID) !=0 ; i++){}
  if(strcmp(PL->prodList[i].prodID, prodID) ==0){
    if(PL->prodList[i].qty > itemQty){
      SList temp = (SList)malloc(sizeof(nodeItem));
      strcpy(temp->item.prodID, PL->prodList[i].prodID);
      strcpy(temp->item.prodName,PL->prodList[i].prodName);
      temp->item.qty = itemQty;
      temp->item.unitPrice = PL->prodList[i].unitPrice;
      PL->prodList[i].qty -= itemQty;
      C->numItems++;
      temp->nextItem = C->sCart->nextItem;
      C->sCart = temp;

    }else{
      printf("Not enough stocks to complete the transaction.");
    }
  } else {
    printf("Product ID [%s] not found.", prodID);
  }

}

// void returnItem(Cart* C, ProdList* PL, char prodID[], int qty)
// {

// }