#include <stdio.h>
#include <string.h>

#define SIZE 10


// create the struct
typedef struct{
	char buffer[SIZE];
	int head;
	int tail;
	int c;
} CircularBuffer;

// initialize the buffer attrs
void init(CircularBuffer *cb)
{
	cb->head = 0;
	cb->head = 0;
	cb->c = 0;
}

bool is_full(CircularBuffer *cb){
	if(cb->c == SIZE)
		return true;
	else
		return false;
}

bool is_empty(CircularBuffer *cb){
	if(cb->c == 0)
		return true;
	else
		return false;
}


void write(CircularBuffer *cb , char data){
	if(is_full(cb)){
		printf("buffer is overflowed!!!!!!")
		return;
	}
	else{
		cb->buffer[cb->tail] = data;
		cb->tail = (cb->tail + 1) % SIZE;
		cb->c++;
	}
}

void read(CircularBuffer *cb)
{
	
	char data = '\0' ;
	if(is_empty(cb)){
		printf("Buffer underflow");
	}
	else{
		data = cb->buffer[cb->head];
		cb->head = (cb->head + 1) % SIZE;
		cb->c--;
	}
	return data;
}


int main(void) {
	
	CircularBuffer cb;
	init(&cb);
	
	char name[50];
	
	printf("enter your name: ");
	scanf("%s" , name);
	
	string s = "CE-ESY";
	name = name + s;
	
	for(i=0;i<strlen(name);i++){
		write(&cb,name[i]);
	}
	
	while(!is_empty(&cb)){
		char ch = read(&cb);
		printf("%c" , ch);
	}
	
	
	if (is_empty(&cb)) {
       printf("Buffer is now empty.\n");
    }

	return 0;
}
