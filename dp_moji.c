#include <stdio.h> 

void mat_print(int height,int width,int mat[height][width]){ 
		
		for(int i=0;i<height;i++){ 
				for(int j=0;j<width;j++){
						printf("%d\t",mat[i][j]);
				}
				printf("\n");
		}
}


	
int main(){
	char strA[] = {'a','a','b'};
	char strB[] = {'a','b','b','b'};	
	
	int height = sizeof(strB);
	int width = sizeof(strA);

	printf("  ");
	for(int i=0;i<width;i++)printf("%c ",strA[i]);
	printf("\n");
	for(int i=0;i<height;i++)printf("%c\n",strB[i]);
	printf("\n");

	int map[height][width];

	for(int i=0;i<width;i++){
			for(int j=0;j<height;j++){
					if(strA[i] == strB[j])map[j][i] = 1;
					else map[j][i] = 3;
			}
	}
	mat_print(height,width,map);

}


