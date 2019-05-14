#include <stdio.h> 
#define MAP_HEIGHT 2
#define MAP_WIDTH  3

void mat_print(int mat[MAP_HEIGHT][MAP_WIDTH]){ 
		
		for(int i=0;i<MAP_HEIGHT;i++){ 
				for(int j=0;j<MAP_WIDTH;j++){
						printf("%d\t",mat[i][j]);
				}
				printf("\n");
		}
}
	
int main(){
	char strA[] = {'a','a','b'};
	char strB[] = {'a','b'};	

	for(int i=0;i<sizeof(strA);i++)printf("%c ",strA[i]);
	printf("\n");
	for(int i=0;i<sizeof(strB);i++)printf("%c ",strB[i]);
	printf("\n");

	int map[MAP_HEIGHT][MAP_WIDTH] = {};

	for(int i=0;i<MAP_WIDTH;i++){
			for(int j=0;j<MAP_HEIGHT;j++){
					if(strA[i] == strB[j])map[j][i] = 1;
					else map[j][i] = 3;
			}
	}
	mat_print(map);

}


