#include"image.h"
int main(int argc, char* argv[]){		/* main function where every thing start executing */
	unsigned long int i, temp, file_type;
	FILE* fptr;
	for(file_type=0; argv[1][file_type+2]!='\0'; file_type++);	/* the file_type veriabel stor the type of the input file P/G/B */
	if(argv[1][file_type-1] != 'p' && argv[1][file_type+1] != 'm')
		error("UnKnown File Type");
	else{
		switch(argv[1][file_type]){
			case 'b':					
				break;
			case 'g':
				switch(argv[2][1]){
				PGM1d* image_ptr;
					case 'N':
						fptr = fopen(argv[1], "r");
						image_ptr = read_PGM1d(fptr);
						fclose(fptr);
						temp = image_ptr->row * image_ptr->col;
						for(i=0;i<temp;i++)
							(image_ptr->array)[i] = (image_ptr->max) - (image_ptr->array)[i];
						fclose(write_PGM1D(image_ptr));
						free(image_ptr->array);
						free(image_ptr);
						break;
					default :
						error("Unknown Command");
						break;
				}
				
				break;
			case 'p':
				switch(argv[2][1]){
				PPM1d* image_ptr;
					case 'G' :
						fptr = fopen(argv[1], "r");
						image_ptr = read_PPM1d(fptr);
						fclose(fptr);
						PGM1d* pgm = PPM1d_to_PGM1d(image_ptr);
						fclose(write_PGM1D(pgm));
						free(pgm->array);
						free(pgm);
						break;
					case 'r' :
						fptr = fopen(argv[1], "r");
						image_ptr = read_PPM1d(fptr);
						fclose(fptr);
						temp = image_ptr->row * image_ptr->col ;
						for(i=0;i<temp;i++){
							(image_ptr->array)[i].green = 0;
							(image_ptr->array)[i].blue = 0;
						}
						fclose(write_PPM1D(image_ptr));
						free(image_ptr->array);
						free(image_ptr);
						break;
					case 'g' :
						fptr = fopen(argv[1], "r");
						image_ptr = read_PPM1d(fptr);
						fclose(fptr);
						temp = image_ptr->row * image_ptr->col ;
						for(i=0;i<temp;i++){
							(image_ptr->array)[i].red = 0;
							(image_ptr->array)[i].blue = 0;
						}
						fclose(write_PPM1D(image_ptr));
						free(image_ptr->array);
						free(image_ptr);
						break;
					case 'b' :
						fptr = fopen(argv[1], "r");
						image_ptr = read_PPM1d(fptr);
						fclose(fptr);
						temp = image_ptr->row * image_ptr->col ;
						for(i=0;i<temp;i++){
							(image_ptr->array)[i].red = 0;
							(image_ptr->array)[i].green = 0;
						}
						fclose(write_PPM1D(image_ptr));
						free(image_ptr->array);
						free(image_ptr);
						break;
					case 'N' :
						fptr = fopen(argv[1], "r");
						image_ptr = read_PPM1d(fptr);
						fclose(fptr);
						temp = image_ptr->row * image_ptr->col ;
						for(i=0;i<temp;i++){
							(image_ptr->array)[i].red = (image_ptr->max) - (image_ptr->array)[i].red;
							(image_ptr->array)[i].green = (image_ptr->max) - (image_ptr->array)[i].green;
							(image_ptr->array)[i].blue = (image_ptr->max) - (image_ptr->array)[i].blue;
						}
						fclose(write_PPM1D(image_ptr));
						free(image_ptr->array);
						free(image_ptr);
						break;
					default :
						error("Unknown Command");
						break;
				}
				break;
			default :
				error("UnKnown File Type");
				return 1;
				break;
		}
	}
return 0;
}
