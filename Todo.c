#include <stdio.h>
#include <stdlib.h>

struct todo
{
    struct todo *prev;
    int status;
    char work[20];
    struct todo *next;
};

int main()
{
    int choice;
    struct todo *temp, *ptr, *ptr1, *head;
    head = (struct todo *)malloc(sizeof(struct todo));
    ptr = head;
    ptr->prev = NULL;
    ptr->next = NULL;

    while (1)
    {
        printf("\n============= TO-DO LIST MENU ============\n");
        printf("1. Add Task\n2. Display Tasks\n3. Mark Task as Completed\n4. Task not completed\n5. Delete Task\n6. Exit\nENTER >>> ");
        if (scanf("%d", &choice) != 1)
        {
            break;
        }

        switch (choice)
        {
        case 1:
        {
            ptr->status = 0;
            printf("Enter The Task : ");
            scanf(" %[^\n]", ptr->work);

            temp = (struct todo *)malloc(sizeof(struct todo));

            ptr->next = temp;
            ptr->next->prev = ptr;
            ptr->next->next = NULL;
            ptr = ptr->next;
            break;
        }
        case 2:
        {
            temp = ptr;
            int i = 1;
            while (temp->prev != NULL)
            {
                temp = temp->prev;
                printf("%d. %s : %s\n", i, temp->work, (temp->status != 1) ? ("Pending") : ("Completed"));
                i++;
            }
            if (i == 1)
            {
                printf("No tasks found!\n");
            }
            temp = NULL;
            break;
        }
        case 3:
        {
            temp = ptr;
            int i = 1, c;
            while (temp->prev != NULL)
            {
                temp = temp->prev;
                printf("%d. %s (%s)\n", i, temp->work, (temp->status == 1) ? "Completed" : "Pending");
                i++;
            }
            if (i == 1)
            {
                printf("No tasks found!\n");
                break;
            }

            printf("Task which is completed (Enter 0 to stop) : ");
            while (scanf("%d", &c) == 1 && c > 0)
            {
                temp = head;
                int count = 1;
                while (temp != ptr && count < c)
                {
                    temp = temp->next;
                    count++;
                }
                if (temp != ptr)
                {
                    temp->status = 1;
                    printf("Task marked as completed!\n");
                }
                else
                {
                    printf("Invalid task number!\n");
                }
                printf("Any other Task (0 to stop) : ");
            }
            break;
        }
        case 4:
        {
            temp = ptr;
            int i = 1;
            printf("Task Not Completed :- \n");
            while (temp->prev != NULL)
            {
                temp = temp->prev; // Fixed: added traversal backward
                if (temp->status != 1)
                {
                    printf("%d. %s\n", i, temp->work);
                    i++;
                }
            }
            if (i == 1)
            {
                printf("No pending tasks!\n");
            }
            temp = NULL;
            break;
        }
        case 5:
        {
            int del;
            temp = ptr;
            int i = 1;
            while (temp->prev != NULL)
            {
                temp = temp->prev;
                printf("%d. %s \n", i, temp->work);
                i++;
            }
            if (i == 1)
            {
                printf("No tasks to delete!\n");
                break;
            }

            printf("Enter Which Task You Want To Delete (0 to stop) :- ");
            while (scanf("%d", &del) == 1 && del > 0)
            {
                temp = head;
                int count = 1;
                while (temp != ptr && count < del)
                {
                    temp = temp->next;
                    count++;
                }
                if (temp != ptr)
                {
                    if (temp->prev != NULL)
                        temp->prev->next = temp->next;
                    else
                        head = temp->next; // If deleting the first node

                    if (temp->next != NULL)
                        temp->next->prev = temp->prev;

                    free(temp);
                    printf("Task deleted successfully!\n");
                }
                else
                {
                    printf("Invalid task number!\n");
                }
                printf("Any More (0 to stop) :- ");
            }
            break;
        }
        case 6:
        {
            struct todo *current = head;
            struct todo *next_node;
            while (current != NULL)
            {
                next_node = current->next;
                free(current);
                current = next_node;
            }
            return 0;
        }
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

/*                            thank you                             */
/*                          𝑫𝒆𝒗𝒆𝒍𝒐𝒑𝒆𝒅 𝒃𝒚 😎𝔸𝕟𝕚𝕜𝕖𝕥 𝕂𝕦𝕞𝕒𝕣😎                   */
