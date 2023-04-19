#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100


// ���ڿ��� ���� �ִ� ���� ���ڸ� �����ϴ� �Լ�
void remove_newline(char* str) {
	int len = strlen(str);
	if (str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}


typedef struct StackType { 
	char stack[MAX];
	int top;
}StackType;

void init(StackType* s) {
	s->top = -1;
}

int is_full(StackType* s) {
	return (s->top == MAX - 1);
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

char pop(StackType* s) {
	char out; 
	out = s->stack[(s->top)--]; 
	return out; 
}

void push(StackType* s, char item) {
	s->stack[++(s->top)] = item; 
}

int check_matching(char input_string[]) {
    StackType s;
    int i = 0;
    init(&s);
    while (input_string[i] != NULL)
    {
        char c = input_string[i];
        if (isalpha(c)) 
        {
            if (is_full(&s)) {
                printf("������ ���� á���ϴ�.");
                return 0;
            }
            if (isupper(c)) 
            {
                c = tolower(c); 
            }
            push(&s, c);
        }
        i++;
    }

    char stripped[MAX];
    int j = 0;
    for (int i = 0; i < strlen(input_string); i++)
    {
        char c = input_string[i];
        if (isalpha(c)) 
        {
            if (isupper(c)) 
            {
                c = tolower(c); 
            }
            stripped[j] = c;
            j++;
        }
    }
    stripped[j] = '\0'; // ���ڿ� ���� �� ���� �߰�

    i = 0;
    while (stripped[i] != NULL)
    {
        if (pop(&s) != stripped[i])
            return 0;
        i++;
    }
    if (!is_empty(&s)) printf("������ ������� �ʽ��ϴ�.");
    return 1;
}

int main() {
	char input_string[MAX];
	char yesorno[MAX];

	printf("���ڿ��� �Է��Ͻÿ�>>");
	fgets(input_string, sizeof(input_string), stdin);
	remove_newline(input_string);

	if (check_matching(input_string) == 1) {
		printf("ȸ���Դϴ�.\n");
	}
	else {
		printf("ȸ���� �ƴմϴ�.\n");
	}

	printf("��� �Ͻðڽ��ϱ�? ");
	fgets(yesorno, sizeof(yesorno), stdin);
	remove_newline(yesorno);

	while (strcmp(yesorno, "yes") == 0) {
		printf("���ڿ��� �Է��Ͻÿ�>>");
		fgets(input_string, sizeof(input_string), stdin);
		remove_newline(input_string);

		if (check_matching(input_string) == 1) {
			printf("ȸ���Դϴ�.\n");
		}
		else {
			printf("ȸ���� �ƴմϴ�.\n");
		}

		printf("��� �Ͻðڽ��ϱ�? ");
		fgets(yesorno, sizeof(yesorno), stdin);
		remove_newline(yesorno);
	}

	return 0;
}