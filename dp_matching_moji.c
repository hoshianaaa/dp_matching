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




	

void mat_clear(int height,int width,int mat[height][width]){

		for(int i=0;i<height;i++){ 
				for(int j=0;j<width;j++){
						mat[i][j] = 0;
				}
		}
}



int min(int a,int b,int c,int *num){
	int min = a;
	*num = 1;
	if(min > b){min = b;*num = 2;}
	if(min > c){min = c;*num = 3;}
	return min;
}

int dp_matching(int height,int width,int map[height][width]){
		
	int value[height][width];
	int route[height][width];

	mat_clear(height,width,value);
	mat_clear(height,width,route);

	for(int i=1;i<height;i++){value[i][0] = value[i-1][0] + map[i][0];route[i][0] = 1;}
	for(int i=1;i<width;i++){value[0][i] = value[0][i-1] + map[0][i];route[0][i] = 3;}

	printf("\n<value_preb>\n");
	mat_print(height,width,value);

	printf("\n<route_prev>\n");
	mat_print(height,width,route);
	
	
	for(int i=1;i<height;i++){
		for(int j=1;j<width;j++){

			int up = value[i-1][j] + map[i][j];
			int diagonal = value[i-1][j-1] + 2 * map[i][j];	
			int left = value[i][j-1] + map[i][j];
			value[i][j] = min(up,diagonal,left, &route[i][j]);

		}
	}

	printf("\n<value>\n");
	mat_print(height,width,value);

	printf("\n<route>\n");
	mat_print(height,width,route);
	
	
	int route_image[height][width];
	mat_clear(height,width,route_image);

	int x,y,r;
	x = height-1; 
	y = width-1;
	r = route[height-1][width-1];

	while(r){
			r = route[x][y];
			route_image[x][y] = 1;
			if(r == 1)x--;
			if(r == 2){x--;y--;}
			if(r == 3)y--;
	} 

	printf("\n<route_image>\n");
	mat_print(height,width,route_image);
}




int main(){

	char strA[] = {'a','a','b','c','c','c'};
	char strB[] = {'a','b','b','b','c'};	
	int height,width;
	
	height = sizeof(strB);
	width = sizeof(strA);
	

	int map[height][width];

	map_generate(height,width,strA,strB,map);

	dp_matching(height,width,map);

	return 0;
}



