
#include <stdio.h>

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
    scanf(" %[^\n]", tasks[taskCount].title); // Read title
    
    printf("Enter Task Description: ");
    scanf(" %[^\n]", tasks[taskCount].description); // Read description
    
    printf("Enter Due Date (ex: DD-MM-YYYY): ");
    scanf(" %[^\n]", tasks[taskCount].dueDate); // Read date

    int priorityInput;
    printf("Enter Priority (1 for High, 2 for Low): ");
    scanf("%d", &priorityInput);
    
    if (priorityInput == 1 || priorityInput == 2) {
        tasks[taskCount].priority = priorityInput;
    } else {
        printf("Invalid priority. Setting priority to Low by default.\n");
        tasks[taskCount].priority = 2;
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
        printf("Priority: %s\n", tasks[i].priority == 1 ? "High" : "Low");
        printf("-------------------------------\n");
    }
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

    for (int i = taskIndex; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    taskCount--;
    printf("Task deleted successfully.\n");
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
    
    printf("Editing Task %d:\n", taskIndex + 1);
    printf("Current Title: %s\n", tasks[taskIndex].title);
    printf("Enter New Title (or press Enter to keep): ");
    scanf(" %[^\n]", tasks[taskIndex].title);

    printf("Current Description: %s\n", tasks[taskIndex].description);
    printf("Enter New Description (or press Enter to keep): ");
    scanf(" %[^\n]", tasks[taskIndex].description);

    printf("Current Due Date: %s\n", tasks[taskIndex].dueDate);
    printf("Enter New Due Date (ex: DD-MM-YYYY): ");
    scanf(" %[^\n]", tasks[taskIndex].dueDate);

    printf("Current Priority: %s\n", tasks[taskIndex].priority == 1 ? "High" : "Low");
    printf("Enter New Priority (1 for High, 2 for Low): ");
    int newPriority;
    scanf("%d", &newPriority);
    tasks[taskIndex].priority = (newPriority == 1 || newPriority == 2) ? newPriority : tasks[taskIndex].priority;

    printf("Task updated successfully!\n");
}


int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();//call to
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                editTask();
                break;
            case 4:
                deleteTask();//call to deleteTask
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}
