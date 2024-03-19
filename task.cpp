#include <iostream>
#include <cstring>

using namespace std;


struct Task {
    char* description;
    bool completed;
};   // Structure to represent a task


void addTask(Task* &tasks, int &numTasks, const char* description);
void viewTasks(const Task* tasks, int numTasks);
void markTaskCompleted(Task* tasks, int numTasks, int index);
void removeTask(Task* &tasks, int &numTasks, int index);
void cleanup(Task* &tasks, int numTasks);

int main() {
    Task* tasks = nullptr;
    int numTasks = 0;
    char choice;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                char description[100];
                cout << "Enter task description: ";
                cin.ignore(); // clear input buffer
                cin.getline(description, 100);
                addTask(tasks, numTasks, description);
                break;
            }
            case '2':
                viewTasks(tasks, numTasks);
                break;
            case '3': {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, numTasks, index);
                break;
            }
            case '4': {
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(tasks, numTasks, index);
                break;
            }
            case '5':
                cout << "Exiting the to-do list manager." << endl;
                cleanup(tasks, numTasks);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

// Function to add a task to the list
void addTask(Task* &tasks, int &numTasks, const char* description) {
    tasks = (Task*)realloc(tasks, (numTasks + 1) * sizeof(Task));
    tasks[numTasks].description = strdup(description);
    tasks[numTasks].completed = false;
    numTasks++;
    cout << "Task added successfully." << endl;
}

// Function to view all tasks
void viewTasks(const Task* tasks, int numTasks) {
    if (numTasks == 0) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (int i = 0; i < numTasks; ++i) {
        cout << i+1 << ". " << tasks[i].description << " - "
             << (tasks[i].completed ? "Completed" : "Pending") << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(Task* tasks, int numTasks, int index) {
    if (index < 1 || index > numTasks) {
        cout << "Invalid task index." << endl;
        return;
    }

    tasks[index-1].completed = true;
    cout << "Task marked as completed." << endl;
}

// Function to remove a task from the list
void removeTask(Task* &tasks, int &numTasks, int index) {
    if (index < 1 || index > numTasks) {
        cout << "Invalid task index." << endl;
        return;
    }

    free(tasks[index - 1].description);
    for (int i = index - 1; i < numTasks - 1; ++i) {
        tasks[i] = tasks[i + 1];
    }
    numTasks--;
    tasks = (Task*)realloc(tasks, numTasks * sizeof(Task));
    cout << "Task removed successfully." << endl;
}

// Function to free allocated memory
void cleanup(Task* &tasks, int numTasks) {
    for (int i = 0; i < numTasks; ++i) {
        free(tasks[i].description);
    }
    free(tasks);
}
