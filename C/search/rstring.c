#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

void
reverse(char *str) {
	assert( str && "Invalid parameter, str can not be NULL");
	char *temp = strdup(str);
	assert(temp && "Insufficient memory");
    int len = strlen(temp);
    for (int i=len-1; i >= 0; i--, str++) {
		*str = temp[i];
	}
	str[len] = '\0';
	free(temp);
	return;
}

int main(){
	char buffer[100];
    snprintf(buffer, sizeof(buffer), "%s", "Atul Patil");
	printf("Before: %s", buffer);
	reverse(buffer);
	printf("After: %s", buffer);
	getchar();
	return 0;
}
