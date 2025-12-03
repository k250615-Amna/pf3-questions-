#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct LibraryShelf{
	int ID;
	int popularityScore; 
	int accessed;
};
struct LibraryShelf Books[10];
int capacity=10;
int bookCount=0;
int lastAccessed=0;

void ADD(int x , int y){
	int i;
	for(i=0;i<bookCount;i++){
		if(Books[i].ID==x){
			Books[i].popularityScore = y;
			Books[i].accessed = lastAccessed++;
			printf("Popularity score is updated!\n");
			return;
		}
	}
	if(bookCount<capacity){
		Books[bookCount].ID = x;
    	Books[bookCount].popularityScore = y;
    	Books[bookCount].accessed = lastAccessed++;
    	bookCount++;
	}
	else if(bookCount>=capacity){
		int smallest = Books[0].accessed;
		int newBook=0;
		for(i=1;i<bookCount;i++){
			if(smallest>Books[i].accessed){
				smallest=Books[i].accessed;
				newBook=i;	
			}
		}
		printf("Removing the least accessed book added\n");
		Books[newBook].ID=x;
		Books[newBook].popularityScore = y;
		Books[newBook].accessed = lastAccessed;
	}
	
}
int ACCESS(int x){
	int i;
	for(i=0;i<bookCount;i++){
		if(Books[i].ID==x){
			Books[i].accessed=lastAccessed++;
			return Books[i].popularityScore;
		}
	}
	return -1;
}
int main(){
	int access,add,total,numAccess,numAdd,x,y,i,result;
	char command[7];
	printf("How many books do you want to access and how many do you want to add? ");
	scanf("%d %d", &numAccess, &numAdd);
	total = numAccess + numAdd;
	printf("for accessing, write the command and then the book ID \n");
	printf("for adding, write the command and then the book ID and popularity score\n");
	for(i=1;i<=total;i++){
		scanf("%s",command);
		if(strcmp(command,"ACCESS")==0){
			scanf("%d",&access);
			result=ACCESS(access);
			printf("%d\n", result);
		}else if(strcmp(command,"ADD")==0){
			scanf("%d %d",&x,&y);
			ADD(x,y);
		}
	}
}
