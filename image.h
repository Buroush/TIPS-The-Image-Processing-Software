/*	Author : Pankaj Mondal
	Date: Friday, January 26, 2024, 8:49 PM	
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/	
#include <malloc.h>			// malloc.h is used for dynamic memory allocation
#include <stdbool.h> 			// stdbool.h is used for bool data type
#include <stdio.h> 			// The stdio.h library is used for fscanf and fprintf functions
#pragma pack()     			// To force the compiler to use tight packaging
#define MAX 255				// The maximum number representable is 255; the range of unsigned short int is 0 to 255

typedef struct PBM1d {			// Define a structure for 1D Portable Bitmap (PBM) format images
	unsigned short int P;   	// Magic number P1 ASCII or P4 Binary
	unsigned int row;       	// The total number of rows in the image
	unsigned int col;       	// The total number of columns in the image
	unsigned short int max; 	// The maximum value, always less than MAX(255)
	bool* array;            	// One-dimensional representation of PBM
} PBM1d;

typedef struct PGM1d {			// Define a structure for 1D Portable GrayMap (PGM) format images
	unsigned short int P;	        // Magic number P2 ASCII or P5 Binary
	unsigned int row;		// The total number of rows in the image
	unsigned int col; 	        // The total number of columns in the image
	unsigned short int max;     	// The maximum value, always less than MAX(255)
	unsigned short int* array; 	// One-dimensional representation of PGM
} PGM1d;

typedef struct PIX {			// Define a structure for a pixel
	unsigned short int red;   	// Represents the red color in the pixel
	unsigned short int green; 	// Represents the green color in the pixel
	unsigned short int blue;  	// Represents the blue color in the pixel
} PIX;

typedef struct PPM1d {			// Define a structure for 1D Portable PixMap (PPM) format images
	unsigned short int P;   	// Magic number P3 ASCII or P6 Binary
	unsigned int row;       	// The total number of rows in the image
	unsigned int col;	        // The total number of columns in the image
	unsigned short int max; 	// The maximum value, always less than MAX(255)
	PIX* array;             	// One-dimensional representation of PPM
} PPM1d;

const char maker[] = "#Author : Pankaj Mondal, LinkedIn : https://www.linkedin.com/in/buroush";	
					// Constant string with the author's information
void error(char* argv); 		// Declaration of error handler function
int char_to_int(unsigned char* string); // Converts a character string to an integer

/*	Author : Pankaj Mondal
	Date: T, January 30, 2024, 6:49 PM	
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/
					/* Function declarations for reading and writing different image formats	*/
PGM1d* read_PGM1d(FILE* fptr);		// Function for reading PGM1d
PPM1d* read_PPM1d(FILE* fptr);		// Function for reading PPM1d
PPM1d* read_PPM1d(FILE* fptr);		// Function for reading PPM1d
FILE* write_PGM1D(PGM1d* iptr);		// Function for writing PGM1d
FILE* write_PPM1D(PPM1d* iptr);		// Function for writing PPM1d
PGM1d* PPM1d_to_PGM1d(PPM1d*);		// Function for converting PPM1d to PGM1d
PPM1d* PGM1d_to_PPM1d(PGM1d*);		// Function for converting PGM1d to PPM1d
void put_int(FILE* fptr,
             int temp1); 		// Function for writing an integer to a file


void error( char* argv){ 		// Definition of the previously declared error function
	printf("Image software : error: %s",argv); 
					// Print the error message
	FILE* fptr;
	read_PGM1d(fptr); 		// Read a PGM1d file
}

int char_to_int(unsigned char* string){ // Converts a character string to an integer
	int i,var=0;
	for(i=0; string[i] != '\0'; i++){
		var += string[i] - '0'; // Convert character to integer and add to var
		if(string[i+1] != '\0')
			var *= 10;	// Multiply by 10 if not the last character
	}
	return var;
}

/*	Author : Pankaj Mondal
	Date Fryday, January, 27, 2024, 10:53 AM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/
	
PPM1d* read_PPM1d( FILE* fptr){		// Function for reading a PPM1d image
	unsigned short int P, max;
	PIX* array;
	unsigned int row, col;
	unsigned char string[10],c,r,g,b;
	unsigned long int temp, i;
	int R, G, B;
	PPM1d* image=NULL;
	fscanf(fptr, "%s", string);
	P = string[1] - '0' ;
	if(P == 3 ||P == 6){
		for(fscanf(fptr, "%s", string);string[0]=='#';fscanf(fptr, "%s", string))
			for(c = fgetc(fptr); c !='\n';c = fgetc(fptr));
		row = char_to_int(string);
		for(fscanf(fptr, "%s", string);string[0]=='#';fscanf(fptr, "%s", string))
			for(c = fgetc(fptr); c !='\n';c = fgetc(fptr));
		col = char_to_int(string);
		for(fscanf(fptr, "%s", string);string[0]=='#';fscanf(fptr, "%s", string))
			for(c = fgetc(fptr); c !='\n';c = fgetc(fptr));
		max = char_to_int(string);
		temp = row * col;
		array = (PIX*)malloc(temp * sizeof(PIX));
		if(P==6){
			c = fgetc(fptr);
            		for (i = 0; i < temp; i++) {
                		fscanf(fptr, "%c", &r);
                		fscanf(fptr, "%c", &g);
                		fscanf(fptr, "%c", &b);
                		(array[i]).red =r;
                		(array[i]).green =g;
                		(array[i]).blue =b;
            		}
		}
		else{
			for(i=0;i<temp;i++){
				fscanf(fptr, "%s", string);
				R = char_to_int(string);
				fscanf(fptr, "%s", string);
				G = char_to_int(string);
				fscanf(fptr, "%s", string);
				B = char_to_int(string);
				(array[i]).red = R;
                		(array[i]).green = G;
                		(array[i]).blue = B;
			}		
		}
		image = (PPM1d*)malloc(sizeof(PPM1d));
		image->P=3;
		image->row=row;
		image->col=col;
		image->max=max;
		image->array=array;
		return image;
	}
	return NULL;
}
void put_int(FILE *fptr, int temp1){
	int j=0;
	short int temp_array[10];
	while(temp1){
		temp_array[j++]=temp1%10;
		temp1 /= 10;
	}
	j--;
	while(j>-1)
		putc(temp_array[j--]+'0',fptr);
}
FILE* write_PPM1D(PPM1d* iptr){
	FILE* fptr_o;
	int i,temp;
	if((iptr->P)==3 || (iptr->P)==6)
		fptr_o = fopen("output.ppm","w");
	putc('P',fptr_o);
	putc('3',fptr_o);
	putc('\n',fptr_o);
	for(i = 0; maker[i]!='\0';i++)
		putc(maker[i],fptr_o);
	putc('\n',fptr_o);
	put_int(fptr_o,(iptr->row));
	putc(' ',fptr_o);
	put_int(fptr_o,(iptr->col));
	putc('\n',fptr_o);
	put_int(fptr_o,(iptr->max));
	putc('\n',fptr_o);
	temp=((iptr->row)*(iptr->col));
	for(i=0; i<temp; i++){
		if((iptr->array)[i].red+'0' > '9')
			put_int(fptr_o,(iptr->array)[i].red);
		else
			putc((iptr->array)[i].red+'0',fptr_o);
				// (iptr->array)[i].red+'0' this is pass because the intiger valu of the array + the ASCII valu of '0' 
		putc(' ',fptr_o);
		if((iptr->array)[i].green+'0' > '9')
			put_int(fptr_o,(iptr->array)[i].green);
		else
			putc((iptr->array)[i].green+'0',fptr_o);
				// (iptr->array)[i].green+'0' this is pass because the intiger valu of the array + the ASCII valu of '0'
		putc(' ',fptr_o);
		if((iptr->array)[i].blue+'0' > '9')
			put_int(fptr_o,(iptr->array)[i].blue);
		else
			putc((iptr->array)[i].blue+'0',fptr_o);
				// (iptr->array)[i].blue+'0' this is pass because the intiger valu of the array + the ASCII valu of '0' 
		putc(' ',fptr_o);
		if((i+1)%(iptr->col)==0)
			putc('\n',fptr_o);		
	}
	return fptr_o;
}
/*	Author : Pankaj Mondal
	Date: Friday, January 27, 2024, 2:12 PM
	LinkedIn : https://www.linkedin.com/in/buroush
	GitHub   : https://github.com/Buroush
	LeetCode : https://leetcode.com/Buroush        		*/

PGM1d* read_PGM1d(FILE* fptr){
	unsigned short int P, max;
	unsigned short int* array;
	unsigned int row, col;
	unsigned char string[10],c;
	unsigned long int temp, i;
	PGM1d* image=NULL;
	fscanf(fptr, "%s", string);
	P = string[1] - '0' ;
	if(P == 2 ||P == 5){
		for(fscanf(fptr, "%s", string);string[0]=='#';fscanf(fptr, "%s", string))
			for(c = fgetc(fptr); c !='\n';c = fgetc(fptr));
		row = char_to_int(string);
		for(fscanf(fptr, "%s", string);string[0]=='#';fscanf(fptr, "%s", string))
			for(c = fgetc(fptr); c !='\n';c = fgetc(fptr));
		col = char_to_int(string);
		for(fscanf(fptr, "%s", string);string[0]=='#';fscanf(fptr, "%s", string))
			for(c = fgetc(fptr); c !='\n';c = fgetc(fptr));
		max = char_to_int(string);
		temp = row * col;
		array = (unsigned short int*)malloc(temp * sizeof(unsigned short int));
		if(P==5){
			
            		for (i = 0; i < temp; i++) {
                		fscanf(fptr, "%c", &c);
                		array[i] = c;
            		}
		}
		else{
			for(i=0;i<temp;i++){
				fscanf(fptr, "%s", string);
				array[i] = char_to_int(string);
			}
		
		}
		image = (PGM1d*)malloc(sizeof(PGM1d));
		image->P=P;
		image->row=row;
		image->col=col;
		image->max=max;
		image->array=array;
		return image;
	}
	return NULL;
}
// Author : Pankaj Mondal
// Date: Friday, January 27, 2024, 2:12 PM
// Function for writing a PGM1d image
FILE* write_PGM1D(PGM1d* iptr){
	FILE* fptr_o;
	if((iptr->P)==2 || (iptr->P)==5)
		fptr_o = fopen("output.pgm","w"); // Open a file in binary write mode
	putc('P',fptr_o);
	putc('2',fptr_o);
	putc('\n',fptr_o);
	for(int i = 0; maker[i]!='\0';i++)
		putc(maker[i],fptr_o);
	putc('\n',fptr_o);
	{
		int j=0,temp1 = (iptr->row);
		short int temp_array[10];
		while(temp1){
			temp_array[j++]=temp1%10;
			temp1 /= 10;
		}
		j--;
		while(j>-1)
			putc(temp_array[j--]+'0',fptr_o);
		putc(' ',fptr_o);
	}
	{
		int j=0,temp1 = (iptr->col);
		short int temp_array[10];
		while(temp1){
			temp_array[j++]=temp1%10;
			temp1 /= 10;
		}
		j--;
		while(j>-1)
			putc(temp_array[j--]+'0',fptr_o);
		putc('\n',fptr_o);
	}	
	{
		int j=0,temp1 = (iptr->max);
		short int temp_array[10];
		while(temp1){
			temp_array[j++]=temp1%10;
			temp1 /= 10;
		}
		j--;
		while(j>-1)
			putc(temp_array[j--]+'0',fptr_o);
		putc('\n',fptr_o);
	}	
	int i;
	for(i=0; i<((iptr->row)*(iptr->col)); i++){
		if((iptr->array)[i]+'0' > '9'){
			int j=0,temp1 = (iptr->array)[i];
			short int temp_array[10];
			while(temp1){
				temp_array[j++]=temp1%10;
				temp1 /= 10;
			}
			j--;
			while(j>-1)
				putc(temp_array[j--]+'0',fptr_o);
			putc(' ',fptr_o);
		}
		else
			putc((iptr->array)[i]+'0',fptr_o);
				/* (iptr->array)[i]+'0' this is pass because the intiger valu of the array + the ASCII valu of '0' */
		putc(' ',fptr_o);
		if((i+1)%(iptr->col)==0)
			putc('\n',fptr_o);
	}
	return fptr_o;
}

PGM1d* PPM1d_to_PGM1d(PPM1d* ppm){
	unsigned int i,temp;
	PGM1d *pgm;
	if(ppm != NULL){
		pgm = (PGM1d*)malloc(sizeof(PGM1d*));
		pgm->P=2;
		pgm->row=ppm->row;
		pgm->col=ppm->col;
		pgm->max=ppm->max;
		temp=(ppm->row)*(ppm->col);
		pgm->array=(unsigned short int*)malloc(temp * sizeof(unsigned short int));
		for(i=0;i<temp;i++){
			(pgm->array)[i] = ((((ppm->array)[i].red)*0.299) + (((ppm->array)[i].green)*0.587) + (((ppm->array)[i].blue))*0.144);

		}
		return pgm;
	}
	return NULL;
}

PPM1d* PGM1d_to_PPM1d(PGM1d* pgm){
	unsigned int i,temp;
	PPM1d *ppm;
	if(pgm != NULL){
		ppm = (PPM1d*)malloc(sizeof(PPM1d*));
		ppm->P=3;
		ppm->row=pgm->row;
		ppm->col=pgm->col;
		ppm->max=pgm->max;
		temp=(pgm->row)*(pgm->col);
		ppm->array=(PIX*)malloc(temp * sizeof(PIX));
		for(i=0;i<temp;i++){
			((ppm->array)[i].red) = ((pgm->array)[i]/3);
			((ppm->array)[i].green) = ((pgm->array)[i]/3);
			((ppm->array)[i].blue) = ((pgm->array)[i]/3);
		}
		return ppm;
	}
	return NULL;
}


