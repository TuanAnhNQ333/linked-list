#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct 1 node trong linked list
struct Node {
    int data;
    struct Node* next;
};

// hàm tạo node mới
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// hàm thêm phần tử vào cuối danh sách
void addLast(struct Node** head, int k) {
    // nếu danh sách rỗng, thêm phần tử vào làm phần tử đầu tiên
    if (*head == NULL) {
        *head = createNode(k);
        return;
    }
    // duyệt đến cuối danh sách để thêm phần tử
    struct Node* temp = *head;
    while (temp->next != NULL) {
        if (temp->data == k) {
            return; // nếu đã tồn tại, không thêm
        }
        temp = temp->next;
    }
    // kiểm tra phần tử cuối cùng
    if (temp->data == k) {
        return; // nếu đã tồn tại, không thêm
    }
    temp->next = createNode(k);
}

// hàm thêm phần tử vào đầu danh sách
void addFirst(struct Node** head, int k) {
    // tạo node mới và thêm vào đầu danh sách
    struct Node* newNode = createNode(k);
    newNode->next = *head;
    *head = newNode;
}

// hàm thêm phần tử vào sau 1 phần tử có giá trị v
void addAfter(struct Node** head, int u, int v) {
    struct Node* temp = *head;
    // tìm phần tử v trong danh sách
    while (temp != NULL && temp->data != v) {
        temp = temp->next;
    }
    // nếu tìm thấy v, thêm u sau v
    if (temp != NULL) {
        struct Node* newNode = createNode(u);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// hàm xóa phần tử có giá trị k khỏi danh sách
void removeNode(struct Node** head, int k) {
    if (*head == NULL) return;
    if ((*head)->data == k) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != k) {
        prev = temp;
        temp = temp->next;
    }
    // nếu tìm thấy k thì xóa k
    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}

// hàm in danh sách liên kết
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d", &n);
    struct Node* head = NULL; // khởi tạo list rỗng
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        addLast(&head, k);
    }
    char command[20];
    while (1) {
        scanf("%s", command);
        if (command[0] == '#') {
            break;
        }
        if (strcmp(command, "addlast") == 0) {
            scanf("%d", &k);
            addLast(&head, k);
        } else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &k);
            addFirst(&head, k);
        } else if (strcmp(command, "addafter") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            addAfter(&head, u, v);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &k);
            removeNode(&head, k);
        }
        printList(head); // in danh sách sau mỗi lệnh
    }
    return 0;
}
