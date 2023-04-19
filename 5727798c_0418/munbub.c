#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100


// 문자열의 끝에 있는 개행 문자를 제거하는 함수
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
                printf("스택이 가득 찼습니다.");
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
    stripped[j] = '\0'; // 문자열 끝에 널 문자 추가

    i = 0;
    while (stripped[i] != NULL)
    {
        if (pop(&s) != stripped[i])
            return 0;
        i++;
    }
    if (!is_empty(&s)) printf("스택이 비어있지 않습니다.");
    return 1;
}

int main() {
	char input_string[MAX];
	char yesorno[MAX];

	printf("문자열을 입력하시오>>");
	fgets(input_string, sizeof(input_string), stdin);
	remove_newline(input_string);

	if (check_matching(input_string) == 1) {
		printf("회문입니다.\n");
	}
	else {
		printf("회문이 아닙니다.\n");
	}

	printf("계속 하시겠습니까? ");
	fgets(yesorno, sizeof(yesorno), stdin);
	remove_newline(yesorno);

	while (strcmp(yesorno, "yes") == 0) {
		printf("문자열을 입력하시오>>");
		fgets(input_string, sizeof(input_string), stdin);
		remove_newline(input_string);

		if (check_matching(input_string) == 1) {
			printf("회문입니다.\n");
		}
		else {
			printf("회문이 아닙니다.\n");
		}

		printf("계속 하시겠습니까? ");
		fgets(yesorno, sizeof(yesorno), stdin);
		remove_newline(yesorno);
	}

	return 0;
}