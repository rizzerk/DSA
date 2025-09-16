#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct {
    char firstName[30];
    char lastName[30];
} FullName;

typedef struct {
    FullName fullName;
    int age;
} PersonalInfo;

typedef struct {
    PersonalInfo personal;
    char course[10];
    int yearLevel;
    char studentId[10];
    char email[50];
    float GPA;
} Student;

typedef struct {
    Student data[MAX];
    int top;
} StudentDatabase; // Stack implementation using array

// Completed Functions
void displayDatabase(StudentDatabase db);

// TODO Functions
void initializeDatabase(StudentDatabase *db);
void populateDatabase(StudentDatabase *db);
int isDatabaseEmpty(StudentDatabase db);
int isDatabaseFull(StudentDatabase db);
void addStudent(StudentDatabase *db, Student student);
void removeStudent(StudentDatabase *db);
Student peekLatestStudent(StudentDatabase db);

// DO NOT TOUCH MI BOMBOCLAAT
void pause();
void menu(StudentDatabase *db);
void menuAddStudent(StudentDatabase *db);

int main(){
    StudentDatabase db;
	
	// PROBLEM 0
	// Initialize the database by calling initializeDatabase() function.
	// Populate the database.
	// Display the contents of the database.
	// Finally, call the function pause().
	// Implement your code here...
	
	// PROBLEM 1 (Optional)
	// Call the function menu().
	// Implement your code here...

    return 0;
}

// This function initializes the database.
// Set the top to indicate that the database is currently empty.
// Once initialized, print message that the database is now ready for use.
void initializeDatabase(StudentDatabase *db){
    db->top = -1;
    printf("Database is now ready for use.\n");
}

// This function will populate the database.
// You are given an array of students that are DSA passers. (Manifesting)
// Insert each student into the database.
// Utilize the addStudent() function to do so.
void populateDatabase(StudentDatabase *db){
    Student dsaPassers[] = {
        {{{"Justine", "Lequigan"}, 20 }, "BSIT", 2, "24100001", "24100001@usc.edu.ph", 1.5},
        {{{"Akeah", "Diez"}, 20 }, "BSIT", 2, "24100002", "24100002@usc.edu.ph", 1.5},
        {{{"Zach", "Bacolod"}, 20 }, "BSIT", 2, "24100003", "24100003@usc.edu.ph", 1.5},
        {{{"Cris", "Arquiza"}, 20 }, "BSIT", 2, "24100004", "24100004@usc.edu.ph", 1.5},
        {{{"Hansen", "Tiodianco"}, 20 }, "BSIT", 2, "24100005", "24100005@usc.edu.ph", 1.5},
        {{{"Zyan", "Bugtong"}, 20 }, "BSIT", 2, "24100006", "24100006@usc.edu.ph", 1.5},
        {{{"Kate", "Abendan"}, 20 }, "BSIT", 2, "24100007", "24100007@usc.edu.ph", 1.5},
        {{{"Ericka", "Geonzon"}, 20 }, "BSIT", 2, "24100008", "24100008@usc.edu.ph", 1.5},
        {{{"Johnmike", "Hoban"}, 20 }, "BSIT", 2, "24100009", "24100009@usc.edu.ph", 1.5},
        {{{"Fern", "Rosello"}, 20 }, "BSIT", 2, "24100010", "24100010@usc.edu.ph", 1.5},
        {{{"Mauris", "Samson"}, 20 }, "BSIT", 2, "24100011", "24100011@usc.edu.ph", 1.5},
        {{{"Khen", "Lim"}, 20 }, "BSIT", 2, "24100012", "24100012@usc.edu.ph", 1.5},
        {{{"Antoinette", "Cabahug"}, 20 }, "BSIT", 2, "24100013", "24100013@usc.edu.ph", 1.5},
        {{{"Denise", "Bocado"}, 20 }, "BSIT", 2, "24100014", "24100014@usc.edu.ph", 1.5},
        {{{"Johnfranz", "Impas"}, 20 }, "BSIT", 2, "24100015", "24100015@usc.edu.ph", 1.5},
        {{{"Althea", "Cinco"}, 20 }, "BSIT", 2, "24100016", "24100016@usc.edu.ph", 1.5},
        {{{"Razel", "Arenas"}, 20 }, "BSIT", 2, "24100017", "24100017@usc.edu.ph", 1.5},
        {{{"Dinnesh", "Manondo"}, 20 }, "BSIT", 2, "24100018", "24100018@usc.edu.ph", 1.5},
        {{{"Torcy", "Suganob"}, 20 }, "BSIT", 2, "24100019", "24100019@usc.edu.ph", 1.5},
        {{{"Hannah", "Martinez"}, 20 }, "BSIT", 2, "24100020", "24100020@usc.edu.ph", 1.5},
        {{{"Zsofia", "Antolijao"}, 20 }, "BSIT", 2, "24100021", "24100021@usc.edu.ph", 1.5},
        {{{"Shane", "Valerie"}, 20 }, "BSIT", 2, "24100022", "24100022@usc.edu.ph", 1.5},
        {{{"Christan", "Martinez"}, 20 }, "BSIT", 2, "24100023", "24100023@usc.edu.ph", 1.5},
        {{{"Christian", "Tujan"}, 20 }, "BSIT", 2, "24100024", "24100024@usc.edu.ph", 1.5}
    };
	
    int size = sizeof(dsaPassers) / sizeof(dsaPassers[0]);
    int i;

    for (i = 0; i < size; i++) {
        addStudent(db, dsaPassers[i]);
    }
}

// This function will return 1 if the database is empty, else it returns 0.
int isDatabaseEmpty(StudentDatabase db){
    // Implement your code here...
		return db.top == -1 ? 1 : 0;
}

// This function will return 1 if the database is full, else it returns 0;
int isDatabaseFull(StudentDatabase db){
    // Implement your code here...
		return db.top == MAX - 1 ? 1 : 0;

}

// This function will add a student to the database.
// It first checks if the database is full.
// If the database is full, print error message.
// If the database is not full, add the student to the database, and print message that you have added student to the database.
void addStudent(StudentDatabase *db, Student student){
    // Implement your code here...
		if(isDatabaseFull != 1){
			db->data[++db->top]= student; 
			printf("Added %s to the Database.\n", db->data->personal.fullName);
		}else {
			printf("\nDatabase is Full\n");
		}
    
}

// This function removes the last added student from the database.
// It first checks if the database is empty.
// If the database is empty, print error message.
// If the database is not empty, remove the student from the database, and print message that you have removed student from the database.
void removeStudent(StudentDatabase *db){
	// Implement your code here...
	if(isDatabaseEmpty != 1){
		printf("Removed %s from the database.\n", db->data[db->top--]);
	}else{
		printf("\nDatabase is empty\n");
	}
	
}

// This function will return the last added student from the database.
// It first checks if the database is empty.
// If the database is empty, return a dummy that have these initialized values ("" for string, 0 for int, and 0.0 for float).
// If the database is not empty, return the last added student from the database.
Student peekLatestStudent(StudentDatabase db){
	// Implement your code here...
	Student stud;
	if(!isDatabaseEmpty){
		stud = db.data[db.top];
	}else {
		Student dummy = {{{"Dummy", "Dummy"}, 0 }, "dummy", 0, "dummy", "dummy", 0.0};
		stud = dummy;
	}
	return stud;
}

// This function is completed for you.
void displayDatabase(StudentDatabase db){
	int i;
	
    printf("\n========================================= DSA Passers ===========================================\n");
    printf("%-12s %-12s %-13s %-5s %-8s %-6s %-30s %-5s\n",
           "Student ID", "First Name", "Last Name", "Age", "Course", "Year", "Email", "GPA");
    printf("-------------------------------------------------------------------------------------------------\n");

    for (i = db.top; i >= 0; i--) {
        printf("%-12s %-12s %-13s %-5d %-8s %-6d %-30s %-5.2f\n", db.data[i].studentId, db.data[i].personal.fullName.firstName, db.data[i].personal.fullName.lastName, db.data[i].personal.age, db.data[i].course, db.data[i].yearLevel, db.data[i].email, db.data[i].GPA);
    }
    
    printf("\n");
}

void pause(void) {
	printf("\nPress any key to continue...");
	getch();
	system("CLS");
}

// DO NOT TOUCH MI BOMBOCLAAT
void menu(StudentDatabase *db){
	Student student;
	char choice;
	
	printf("Welcome to the database.\n");
	
	do {
		printf("[A] Add Student\n");
		printf("[B] Remove Last Added Student\n");
		printf("[C] Display All Students\n");
		printf("[D] Peek Last Added Student\n");
		printf("[R] Clear History\n");
		printf("[X] Exit\n");
		
		printf("\nChoice (Must be Uppercase): ");
		scanf(" %c", &choice);
		
		switch(choice){
			case 'A':{
				menuAddStudent(db);
				break;
			}
			case 'B':{
				removeStudent(db);
				break;
			}
			case 'C':{
				displayDatabase(*db);
				break;
			}
			case 'D':{
				student = peekLatestStudent(*db);
				printf("\nThe last added student is: %s %s\n\n", student.personal.fullName.firstName, student.personal.fullName.lastName);
				break;
			}
			case 'X':{
				printf("Exiting the program...\n");
				break;
			}
			case 'R':{
				system("CLS");
				break;
			}
			default:{
				printf("Invalid Input.\n\n");
				break;
			}
		}
	} while (choice != 'X');
}

// DO NOT TOUCH MI BOMBOCLAAT
void menuAddStudent(StudentDatabase *db){
	Student student;
	
	printf("\nPlease enter the following information:\n");
	
	printf("Student ID: ");
	scanf("%s", student.studentId);
	
	printf("First Name: ");
	scanf("%s", &student.personal.fullName.firstName);
	
	printf("Last Name: ");
	scanf("%s", &student.personal.fullName.lastName);
	
	printf("Age: ");
	scanf("%d", &student.personal.age);
	
	printf("Course: ");
	scanf("%s", student.course);
	
	printf("Year: ");
	scanf("%d", &student.yearLevel);
	
	printf("Email: ");
	scanf("%s", student.email);
	
	printf("GPA: ");
	scanf("%f", &student.GPA);
	
	addStudent(db, student);
}