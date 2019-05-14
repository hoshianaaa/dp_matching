#include <stdio.h>

void mat_print(int height,int width,int mat[height][width]){ 
		
		for(int i=0;i<height;i++){ 
				for(int j=0;j<width;j++){
						printf("%d\t",mat[i][j]);
				}
				printf("\n");
		}
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

	int map[4][5] = { 
			{1,10,2,3,1},
			{3,2,3,9,10},
			{2,5,5,4,1},
			{3,3,3,5,2}
	};
	
	int height = sizeof(map)/sizeof(map[0]);
	int width = sizeof(map[0])/sizeof(map[0][0]);

	printf("<map>\n");
	mat_print(height,width,map);


	dp_matching(height,width,map);

	return 0;
}



