#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10

// create the CircularBuffer struct
typedef struct{
  char buffer[SIZE];
  int head;
  int tail;
  int c;
} CircularBuffer;

// initialize the buffer attributes
void init(CircularBuffer *cb)
{
  cb->head = 0;
  cb->tail = 0;
  cb->c = 0;
}

// check the size of the buffer if it is full
bool is_full(CircularBuffer *cb){
  if(cb->c == SIZE)
    return true;
  else
    return false;
}


// check the size of the buffer if it is empty
bool is_empty(CircularBuffer *cb){
  if(cb->c == 0)
    return true;
  else
    return false;
}


// write on the buffer
void write(CircularBuffer *cb , char data){
  // check if we can add a charecter
  if(is_full(cb)){ 
    printf("Buffer Overflow!\n");
    return;
  }
  // writing into it if available
  else{
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->c++;
  }
}

char read(CircularBuffer *cb)
{
  
  char data = '\0' ;
  // check if the buffer empty or not to read
  if(is_empty(cb)){
    printf("Buffer underflow");
  }
  // read the chars in the buffer when it's available
  else{
    data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->c--;
  }
  //return the data we need (zero char or the data)
  return data;
}


int main(void) {
  
  CircularBuffer cb;
  init(&cb);
  
  
  // trying to make the buffer return (underflow)
  read(&cb);
  printf("\n");
  
  char name[50];
  
  printf("enter your name: ");
  scanf("%s" , name);
  
  char s[] = "CE-ESY";
  
  // merge the strings together
  strcat(name,s);
  for(int i=0;i<strlen(name);i++){
    write(&cb,name[i]);
  }
  
  while(!is_empty(&cb)){
    char ch = read(&cb);
    printf("%c" , ch);
  }
  printf("\n");
  
  if (is_empty(&cb)) {
       printf("Buffer is now empty.\n");
    }

  return 0;
}