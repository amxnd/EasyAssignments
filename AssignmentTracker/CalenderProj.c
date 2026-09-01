#include <stdio.h>

#define MAX_ASSIGNMENTS 100
#define MAX_PROJECTS 100
#define MAX_EXAMS 100

struct Task{
    char Name[100];
    char Module[100];
    int DaysLeft;
    int HoursNeeded;
    int Priority;
    float Grade;
    int Completed;
};
struct Task assignments[MAX_ASSIGNMENTS];
int AssignmentCount = 0;

struct Task projects[MAX_PROJECTS];
int ProjectCount = 0;

struct Task exams[MAX_EXAMS];
int ExamCount = 0;

void AddTask(void);
void AddAssignment(void);
void AddProject(void);
void AddExam(void);

void ViewTasks(void);
void ViewAssignments(void);
void ViewProjects(void);
void ViewExams(void);

void MarkAsComplete(void);

void DeleteTask(void);
void EditTask(void);

void SaveData(void);
void LoadData(void);

int main(void){
    int choice;
    do{
        printf("\nWhat do you want to do?\n");
        printf("[1] View tasks\n");
        printf("[2] Add a new task\n");
        printf("[3] Mark a task as complete\n");
        printf("[4] Edit a task\n");
        printf("[5] Delete a task\n");
        printf("[6] Back\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n') {}
            continue;
        }

        switch(choice){
            case 1:
                ViewTasks();
                break;
            case 2:
                AddTask();
                break;
            case 3:
                MarkAsComplete();
                break;
            case 4:
                EditTask();
                break;
            case 5:
                DeleteTask();
                break;
            case 6:
                break;    
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=6);
    return 0;
}

void AddTask(void){
    int choice;
    do{
        printf("\nWhat do you want to add?\n");
        printf("[1] Assignment\n");
        printf("[2] Project\n");
        printf("[3] Exam\n");
        printf("[4] Back\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'){}
            continue;
        }

        switch(choice){
            case 1:
                AddAssignment();
                break;
            case 2:
                AddProject();
                break;
            case 3:
                AddExam();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=4);
}

void AddAssignment(void){
    if(AssignmentCount >= MAX_ASSIGNMENTS){
        printf("Number of assignments cannot exceed 100!\n");
        return;
    }
    printf("\nEnter assignment name: ");
    scanf(" %[^\n]", assignments[AssignmentCount].Name);

    printf("Enter module: ");
    scanf(" %[^\n]", assignments[AssignmentCount].Module);

    printf("Enter days until deadline: ");
    scanf(" %d", &assignments[AssignmentCount].DaysLeft);

    printf("Enter estimated hours needed: ");
    scanf(" %d", &assignments[AssignmentCount].HoursNeeded);

    printf("Enter priority [1-5]: ");
    scanf(" %d", &assignments[AssignmentCount].Priority);

    printf("Enter grade [%%] against module: ");
    scanf(" %f", &assignments[AssignmentCount].Grade);

    assignments[AssignmentCount].Completed = 0;
    AssignmentCount++;

    printf("\nAssignment added successfully!\n");
}

void AddProject(void){
    if(ProjectCount >= MAX_PROJECTS){
        printf("Number of projects cannot exceed 100!\n");
        return;
    }
    printf("\nEnter project name: ");
    scanf(" %[^\n]", projects[ProjectCount].Name);

    printf("Enter module: ");
    scanf(" %[^\n]", projects[ProjectCount].Module);

    printf("Enter days until deadline: ");
    scanf(" %d", &projects[ProjectCount].DaysLeft);

    printf("Enter estimated hours needed: ");
    scanf(" %d", &projects[ProjectCount].HoursNeeded);

    printf("Enter priority [1-5]: ");
    scanf(" %d", &projects[ProjectCount].Priority);

    printf("Enter grade [%%] against module: ");
    scanf(" %f", &projects[ProjectCount].Grade);

    projects[ProjectCount].Completed = 0;
    ProjectCount++;

    printf("\nProject added successfully!\n");
}

void AddExam(void){
    if(ExamCount >= MAX_EXAMS){
        printf("Number of exams cannot exceed 100!\n");
        return;
    }
    printf("\nEnter exam name: ");
    scanf(" %[^\n]", exams[ExamCount].Name);

    printf("Enter module: ");
    scanf(" %[^\n]", exams[ExamCount].Module);

    printf("Enter days until deadline: ");
    scanf(" %d", &exams[ExamCount].DaysLeft);

    printf("Enter estimated hours needed: ");
    scanf(" %d", &exams[ExamCount].HoursNeeded);

    printf("Enter priority [1-5]: ");
    scanf(" %d", &exams[ExamCount].Priority);

    printf("Enter grade [%%] against module: ");
    scanf(" %f", &exams[ExamCount].Grade);

    exams[ExamCount].Completed = 0;
    ExamCount++;

    printf("\nExam added successfully!\n");
}

void ViewTasks(void){
    int choice;
    do{
        if(AssignmentCount == 0 && ProjectCount == 0 && ExamCount == 0){
            printf("\nYou have no tasks available.\n");
            return;
        }
        printf("\n\n[1] View %d assignments available", AssignmentCount);
        printf("\n[2] View %d projects available", ProjectCount);
        printf("\n[3] View %d exams available", ExamCount);
        printf("\n[4] Back");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'){}
            continue;
        }

        switch(choice){
            case 1:
                ViewAssignments();
                break;
            case 2:
                ViewProjects();
                break;
            case 3:
                ViewExams();
                break;
            case 4:
                break;
            default:
                printf("\nInvalid input!");
        }
    }while(choice!=4);
}

void ViewAssignments(void){
    if(AssignmentCount == 0){
        printf("\nThere are no available assignments.\n");
        return;
    }
    for(int i = 0; i < AssignmentCount; i++){
        printf("\nAssignment %d\n", i+1);
        printf("Name: %s\n", assignments[i].Name);
        printf("Module: %s\n", assignments[i].Module);
        printf("Days left: %d\n", assignments[i].DaysLeft);
        printf("Hours needed: %d\n", assignments[i].HoursNeeded);
        printf("Priority: %d\n", assignments[i].Priority);
        printf("Grade: %.2f%%\n", assignments[i].Grade);
        if(assignments[i].Completed == 0){
            printf("Incomplete!\n");
        }else{
            printf("Completed!\n");
        }
    }
}

void ViewProjects(void){
    if(ProjectCount == 0){
        printf("\nThere are no available projects.\n");
        return;
    }
    for(int i = 0; i < ProjectCount; i++){
        printf("\nProject %d\n", i+1);
        printf("Name: %s\n", projects[i].Name);
        printf("Module: %s\n", projects[i].Module);
        printf("Days left: %d\n", projects[i].DaysLeft);
        printf("Hours needed: %d\n", projects[i].HoursNeeded);
        printf("Priority: %d\n", projects[i].Priority);
        printf("Grade: %.2f%%\n", projects[i].Grade);
        if(projects[i].Completed == 0){
            printf("Incomplete!\n");
        }else{
            printf("Completed!\n");
        }
    }
}

void ViewExams(void){
    if(ExamCount == 0){
        printf("\nThere are no available exams.\n");
        return;
    }
    for(int i = 0; i < ExamCount; i++){
        printf("\nExam %d\n", i+1);
        printf("Name: %s\n", exams[i].Name);
        printf("Module: %s\n", exams[i].Module);
        printf("Days left: %d\n", exams[i].DaysLeft);
        printf("Hours needed: %d\n", exams[i].HoursNeeded);
        printf("Priority: %d\n", exams[i].Priority);
        printf("Grade: %.2f%%\n", exams[i].Grade);
        if(exams[i].Completed == 0){
            printf("Incomplete!\n");
        }else{
            printf("Completed!\n");
        }
    }
}

void MarkAsComplete(void){
    int choice;
    int taskchoice;
    do{
        if(AssignmentCount == 0 && ProjectCount == 0 && ExamCount == 0){
            printf("\nYou have no tasks available.\n");
            return;
        }
        printf("\n\n[1] View %d assignments available", AssignmentCount);
        printf("\n[2] View %d projects available", ProjectCount);
        printf("\n[3] View %d exams available", ExamCount);
        printf("\n[4] Back");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'){}
            continue;
        }

        switch(choice){
            case 1:
                ViewAssignments();
                printf("Which assignment do you want to mark as complete [Back: 0] ");
                if (scanf("%d", &taskchoice) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'){}
                    continue;
                }if(taskchoice == 0){
                    break;
                }if(taskchoice < 1 || taskchoice > AssignmentCount){
                    printf("Invalid input!\n");
                }else if(assignments[taskchoice - 1].Completed == 1){
                    printf("Assignment already marked as complete!\n");
                }else{
                    assignments[taskchoice - 1].Completed = 1;
                    printf("Assignment marked as complete!\n");
                }
                break;
            case 2:
                ViewProjects();
                printf("Which project do you want to mark as complete [Back: 0] ");
                if (scanf("%d", &taskchoice) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'){}
                    continue;
                }if(taskchoice == 0){
                    break;
                }if(taskchoice < 1 || taskchoice > ProjectCount){
                    printf("Invalid input!\n");
                }else if(projects[taskchoice - 1].Completed == 1){
                    printf("Project already marked as complete!\n");
                }else{
                    projects[taskchoice - 1].Completed = 1;
                    printf("Project marked as complete!\n");
                }
                break;
            case 3:
                ViewExams();
                printf("Which exam do you want to mark as complete [Back: 0] ");
                if (scanf("%d", &taskchoice) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'){}
                    continue;
                }if(taskchoice == 0){
                    break;
                }if(taskchoice < 1 || taskchoice > ExamCount){
                    printf("Invalid input!\n");
                }else if(exams[taskchoice - 1].Completed == 1){
                    printf("Exam already marked as complete!\n");
                }else{
                    exams[taskchoice - 1].Completed = 1;
                    printf("Exam marked as complete!\n");
                }
                break;
            case 4:
                break;
            default:
                printf("\nInvalid input!");
        }
    }while(choice!=4);
}

void EditTask(void){
    int choice;
    int taskchoice;
    int editchoice;
    do{
        if(AssignmentCount == 0 && ProjectCount == 0 && ExamCount == 0){
            printf("\nYou have no tasks available.\n");
            return;
        }
        printf("\n\n[1] View %d assignments available", AssignmentCount);
        printf("\n[2] View %d projects available", ProjectCount);
        printf("\n[3] View %d exams available", ExamCount);
        printf("\n[4] Back");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n'){}
            continue;
        }

        switch(choice){
            case 1:
                ViewAssignments();
                printf("Which assignment do you want to edit? [Back: 0] ");
                if (scanf("%d", &taskchoice) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'){}
                    continue;
                }if(taskchoice == 0){
                    break;
                }if(taskchoice < 1 || taskchoice > AssignmentCount){
                    printf("Invalid input!\n");
                }else{
                    printf("\n  You have selected assignment %d. Which element would you like to edit?\n", taskchoice);
                    printf("[1] Name: %s\n", assignments[taskchoice - 1].Name);
                    printf("[2] Module: %s\n", assignments[taskchoice - 1].Module);
                    printf("[3] Days left: %d\n", assignments[taskchoice - 1].DaysLeft);
                    printf("[4] Hours needed: %d\n", assignments[taskchoice - 1].HoursNeeded);
                    printf("[5] Priority: %d\n", assignments[taskchoice - 1].Priority);
                    printf("[6] Grade: %.2f%%\n", assignments[taskchoice - 1].Grade);
                    printf("[7] Back\n");
                    printf("\nEnter your choice: ");
                    if (scanf("%d", &editchoice) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n'){}
                        continue;
                    }
                    
                    switch(editchoice){
                        case 1:
                            printf("Enter the new name: ");
                            scanf(" %[^\n]", assignments[taskchoice - 1].Name);
                            break;
                        case 2:
                            printf("Enter the new module: ");
                            scanf(" %[^\n]", assignments[taskchoice - 1].Module);
                            break;
                        case 3:
                            printf("Enter the new days until deadline: ");
                            scanf(" %d", &assignments[taskchoice - 1].DaysLeft);
                            break;
                        case 4:
                            printf("Enter the new estimated hours needed: ");
                            scanf(" %d", &assignments[taskchoice - 1].HoursNeeded);
                            break;
                        case 5:
                            printf("Enter the new priority [1-5]: ");
                            scanf(" %d", &assignments[taskchoice - 1].Priority);
                            break;
                        case 6:
                            printf("Enter the new grade [%%] against module: ");
                            scanf(" %f", &assignments[taskchoice - 1].Grade);
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nInvalid input!");
                    }
                }
                break;
            case 2:
                ViewProjects();
                printf("Which project do you want to edit? [Back: 0] ");
                if (scanf("%d", &taskchoice) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'){}
                    continue;
                }if(taskchoice == 0){
                    break;
                }if(taskchoice < 1 || taskchoice > ProjectCount){
                    printf("Invalid input!\n");
                }else{
                    printf("\nYou have selected project %d. Which element would you like to edit?\n", taskchoice);
                    printf("[1] Name: %s\n", projects[taskchoice - 1].Name);
                    printf("[2] Module: %s\n", projects[taskchoice - 1].Module);
                    printf("[3] Days left: %d\n", projects[taskchoice - 1].DaysLeft);
                    printf("[4] Hours needed: %d\n", projects[taskchoice - 1].HoursNeeded);
                    printf("[5] Priority: %d\n", projects[taskchoice - 1].Priority);
                    printf("[6] Grade: %.2f%%\n", projects[taskchoice - 1].Grade);
                    printf("\nEnter your choice: ");
                    if (scanf("%d", &editchoice) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n'){}
                        continue;
                    }
                    
                    switch(editchoice){
                        case 1:
                            printf("Enter the new name: ");
                            scanf(" %[^\n]", projects[taskchoice - 1].Name);
                            break;
                        case 2:
                            printf("Enter the new module: ");
                            scanf(" %[^\n]", projects[taskchoice - 1].Module);
                            break;
                        case 3:
                            printf("Enter the new days until deadline: ");
                            scanf(" %d", &projects[taskchoice - 1].DaysLeft);
                            break;
                        case 4:
                            printf("Enter the new estimated hours needed: ");
                            scanf(" %d", &projects[taskchoice - 1].HoursNeeded);
                            break;
                        case 5:
                            printf("Enter the new priority [1-5]: ");
                            scanf(" %d", &projects[taskchoice - 1].Priority);
                            break;
                        case 6:
                            printf("Enter the new grade [%%] against module: ");
                            scanf(" %f", &projects[taskchoice - 1].Grade);
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nInvalid input!");
                    }
                }
                break;
            case 3:
                ViewExams();
                printf("Which exam do you want to edit? [Back: 0] ");
                if (scanf("%d", &taskchoice) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n'){}
                    continue;
                }if(taskchoice == 0){
                    break;
                }if(taskchoice < 1 || taskchoice > ExamCount){
                    printf("Invalid input!\n");
                }else{
                    printf("\nYou have selected exam %d. Which element would you like to edit?\n", taskchoice);
                    printf("[1] Name: %s\n", exams[taskchoice - 1].Name);
                    printf("[2] Module: %s\n", exams[taskchoice - 1].Module);
                    printf("[3] Days left: %d\n", exams[taskchoice - 1].DaysLeft);
                    printf("[4] Hours needed: %d\n", exams[taskchoice - 1].HoursNeeded);
                    printf("[5] Priority: %d\n", exams[taskchoice - 1].Priority);
                    printf("[6] Grade: %.2f%%\n", exams[taskchoice - 1].Grade);
                    printf("[7] Back\n");
                    printf("\nEnter your choice: ");
                    if (scanf("%d", &editchoice) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n'){}
                        continue;
                    }
                    
                    switch(editchoice){
                        case 1:
                            printf("Enter the new name: ");
                            scanf(" %[^\n]", exams[taskchoice - 1].Name);
                            break;
                        case 2:
                            printf("Enter the new module: ");
                            scanf(" %[^\n]", exams[taskchoice - 1].Module);
                            break;
                        case 3:
                            printf("Enter the new days until deadline: ");
                            scanf(" %d", &exams[taskchoice - 1].DaysLeft);
                            break;
                        case 4:
                            printf("Enter the new estimated hours needed: ");
                            scanf(" %d", &exams[taskchoice - 1].HoursNeeded);
                            break;
                        case 5:
                            printf("Enter the new priority [1-5]: ");
                            scanf(" %d", &exams[taskchoice - 1].Priority);
                            break;
                        case 6:
                            printf("Enter the new grade [%%] against module: ");
                            scanf(" %f", &exams[taskchoice - 1].Grade);
                            break;
                        case 7:
                            break;
                        default:
                            printf("\nInvalid input!");
                    }
                }
                break;
            case 4:
                break;
            default:
                printf("\nInvalid input!");
        }
    }while(choice!=4);
}

void DeleteTask(void){
    printf("\nDeleteTask functionality is not implemented yet.\n");
}