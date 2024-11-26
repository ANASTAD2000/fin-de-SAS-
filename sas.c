#include <stdio.h>


#define MAX_TASKS 100

// Define the Task structure
typedef struct {
    char title[50];
    char description[100];
    char dueDate[20];
    int priority; // 1 TO High, 2 TO Low
} Task;

Task tasks[MAX_TASKS]; // Array to store tasks
int taskCount = 0;     // Counter for the number of tasks













// Function to display the menu
void displayMenu() {
    printf("========== Task Management Menu ==========\n");
    printf("1. Add Task\n");
    printf("2. View Task List\n");
    printf("0. Exit\n");
    printf("==========================================\n");
    printf("Please select an option: ");
}












// Function add a task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }

    printf("Enter Task Title: ");
    scanf(" %[^\n]", tasks[taskCount].title); // Read title
    
    printf("Enter Task Description: ");
    scanf(" %[^\n]", tasks[taskCount].description); // Read description
    
    printf("Enter Due Date (ex: 01-12-2024): ");
    scanf(" %[^\n]", tasks[taskCount].dueDate); // Read date

    // input 1 for High, 2 for Low
    int priorityInput;
    printf("Enter Priority (1 for High, 2 for Low): ");
    scanf("%d", &priorityInput);
    
    // Store the priority based on user input

    if (priorityInput == 1) {
        tasks[taskCount].priority = 1; // High
    } else if (priorityInput == 2) {
        tasks[taskCount].priority = 2; // Low
    } else {
        printf("Invalid priority. Setting priority to Low by default.\n");
        tasks[taskCount].priority = 2; // Default to Low if invalid input
    }

    taskCount++;
    printf("Task added successfully!\n");
}








// Function view tasks
void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("========== Task List ==========\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d:\n", i + 1);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Due Date: %s\n", tasks[i].dueDate);
        printf("Priority: %s\n", tasks[i].priority == 1 ? "High" : "Low"); // Display priority as High or Low
        printf("-------------------------------\n");
    }
}

int main() {
    int choice;

    while (1) { // Infinite loop for the menu
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(); // Call addTask function
                break;
            case 2:
                viewTasks(); // Call viewTasks function
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0; // Exit the program
            default:
                printf("Invalid option. Please try again.\n");
        }

        printf("\n"); // Add a blank line for better readability
    }

    return 0;
}
