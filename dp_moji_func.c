#include <stdio.h> 

void mat_print(int height,int width,int mat[height][width]){ 
		
		for(int i=0;i<height;i++){ 
				for(int j=0;j<width;j++){
						printf("%d\t",mat[i][j]);
				}
				printf("\n");
		}
}


void map_generate(int height,int width,char strA[],char strB[],int mat[height][width]){


	printf("  ");
	for(int i=0;i<width;i++)printf("%c ",strA[i]);
	printf("\n");
	for(int i=0;i<height;i++)printf("%c\n",strB[i]);
	printf("\n");


	for(int i=0;i<width;i++){
			for(int j=0;j<height;j++){
					if(strA[i] == strB[j])mat[j][i] = 1;
					else mat[j][i] = 3;
			}
	}
	mat_print(height,width,mat);
}



	
int main(){
	char strA[] = {'a','a','b','c','c','c'};
	char strB[] = {'a','b','b','b','c'};	
	int height,width;
	
	height = sizeof(strB);
	width = sizeof(strA);
	

	int map[height][width];

	map_generate(height,width,strA,strB,map);
}


