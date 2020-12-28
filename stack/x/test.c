#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool balanced(char *s, size_t n)
{
	char *stack = malloc(n);
	char *top = stack;

	size_t i;
	for (i = 0; i < n; i++) {
		switch (s[i]) {
		case '(':
		case '{':
		case '[':
			*top = s[i];
			top++;
			break;

		case ']':
			if (*(top - 1) != '[') {
				free(stack);
				return false;
			}
			top--;
			break;

		case '}':
			if (*(top - 1) != '{') {
				free(stack);
				return false;
			}
			top--;
			break;

		case ')':
			if (*(top - 1) != '(') {
				free(stack);
				return false;
			}
			top--;
			break;
		}
	}

	free(stack);
	return true;
}

void print_bool(bool b)
{
	if (b)
		puts("true");
	else
		puts("false");
}

int main()
{
	char *valid_str   = "({})";
	char *invalid_str = "({)}";
	char *bartu_str   = "({}{})";

	print_bool(balanced(valid_str, strlen(valid_str)));
	print_bool(balanced(invalid_str, strlen(invalid_str)));
	print_bool(balanced(bartu_str, strlen(bartu_str)));
}
