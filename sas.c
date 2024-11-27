#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

// Define the Task structure
typedef struct {
    char title[50];
    char description[100];
    char dueDate[20];
    int priority; // 1 for High, 2 for Low
} Task;

Task tasks[MAX_TASKS]; // Array to store tasks
int taskCount = 0;     // Counter for the number of tasks

// Function to display the menu
void displayMenu() {
    printf("========== Task Management Menu ==========\n");
    printf("1. Add Task\n");
    printf("2. View Task List\n");
    printf("3. Edit Task\n");
    printf("4. Delete Task\n");
    printf("5. Filter Tasks by Priority\n");
    printf("0. Exit\n");
    printf("==========================================\n");
    printf("Please select an option: ");
}

// Function to add a task
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }

    printf("Enter Task Title: ");
    scanf(" %[^\n]", tasks[taskCount].title); // Read the title
    
    printf("Enter Task Description: ");
    scanf(" %[^\n]", tasks[taskCount].description); // Read the description
    
    printf("Enter Due Date (ex: 01-12-2024): ");
    scanf(" %[^\n]", tasks[taskCount].dueDate); // Read the due date

    // Input 1 for High, 2 for Low
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

// Function to view tasks
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

// Function to edit a task
void editTask() {
    int taskIndex;
    
    if (taskCount == 0) {
        printf("No tasks available to edit.\n");
        return;
    }

    printf("Enter the task number to edit (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number!\n");
        return;
    }

    taskIndex--; // Adjust index to match array indexing (0-based)
  
    // Edit Title
    printf("Editing Task %d:\n", taskIndex + 1);
    printf("Current Title: %s\n", tasks[taskIndex].title);
    printf("Enter New Title (or press Enter to keep): ");
    scanf(" %[^\n]", tasks[taskIndex].title);

    // Edit Description
    printf("Current Description: %s\n", tasks[taskIndex].description);
    printf("Enter New Description (or press Enter to keep): ");
    scanf(" %[^\n]", tasks[taskIndex].description);

    // Edit Due Date
    printf("Current Due Date: %s\n", tasks[taskIndex].dueDate);
    printf("Enter New Due Date (ex: DD-MM-YYYY): ");
    scanf(" %[^\n]", tasks[taskIndex].dueDate);

    // Edit Priority
    printf("Current Priority: %s\n", tasks[taskIndex].priority == 1 ? "High" : "Low");
    printf("Enter New Priority (1 for High, 2 for Low): ");
    int newPriority;
    scanf("%d", &newPriority);
    tasks[taskIndex].priority = (newPriority == 1 || newPriority == 2) ? newPriority : tasks[taskIndex].priority;
}

// Function to delete a task
void deleteTask() {
    if (taskCount == 0) {
        printf("No tasks available to delete.\n");
        return;
    }

    int taskIndex;
    printf("Enter the task number to delete (1 to %d): ", taskCount);
    scanf("%d", &taskIndex);

    if (taskIndex < 1 || taskIndex > taskCount) {
        printf("Invalid task number. Please try again.\n");
        return;
    }

    taskIndex--; // Adjust to 0-based indexing for the array

    // Shift tasks to fill the gap
    for (int i = taskIndex; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    taskCount--; // Decrease task count
    printf("Task deleted successfully.\n");
}

// Function to filter tasks by priority
void filterTasksByPriority() {
    if (taskCount == 0) {
        printf("No tasks available to filter.\n");
        return;
    }

    int priorityInput;
    printf("Enter Priority to Filter (1 for High, 2 for Low): ");
    scanf("%d", &priorityInput);

    printf("========== Filtered Task List ==========\n");
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].priority == priorityInput) {
            printf("Task %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Due Date: %s\n", tasks[i].dueDate);
            printf("Priority: %s\n", tasks[i].priority == 1 ? "High" : "Low");
            printf("-------------------------------\n");
        }
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
            case 3:
                editTask(); // Call editTask function
                break;
            case 4:
                deleteTask(); // Call deleteTask function
                break;
            case 5:
                filterTasksByPriority(); // Call filterTasksByPriority function
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
