#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user{
	char name[50];
	char password[50];
	int age;
	char alergy[50];
};

int main(){
	FILE * fp;
	struct user usr;
	char filename[50], name[50], password[50], alergy[50], cont ='y', dele;
	int opt, age;
	
	while (cont == 'y'){
		system("cls");
		printf("Welcome to the patient records!");
		printf("\nPress 1 to start a new record");
		printf("\nPress 2 to view a record");
		printf("\nPress 3 to edit record");
		printf("\nPress 4 to change password");
	
		printf("\n\nType your answer: ");
		scanf("%d", &opt);
	
	
	
		switch(opt){
			case 1:
				system("cls");
				printf("You have selected to start a new record!");
				printf("\n\nPlease enter the patient name: ");
				scanf("%s", &name);
				
				strcpy(filename, name);
				
				fp = fopen(strcat(filename, ".dat"), "r");
				
				fclose(fp);
				
				if(fp == NULL){
					strcpy(usr.name, name);
					
					printf("Please enter the patient password: ");
					scanf("%s", &usr.password);
		
					printf("Please enter the age: ");
					scanf("%d", &usr.age);
			
					printf("Please enter alergies: ");
					scanf("%s", &usr.alergy);
				
				
					fp = fopen(filename, "w");
					fwrite(&usr, sizeof(struct user), 1, fp);
		
					if(fwrite != 0){
						printf("\n\nAccount successfully registered");
					}
		
					else{
						printf("\n\nSomething went wrong. Please try again.");
					}
					fclose(fp);
				}
		
				
				else{
					printf("\nFile already exist");	
					
				}
		
				
				break;
		
			
	
			case 2:
				system("cls");
				printf("You have selected to view a record");
				printf("\nPlease enter the patient name: ");
				scanf("%s", &name);
				printf("Please enter the patient password: ");
				scanf("%s", &password);
		
				strcpy(filename, name);
		
				fp = fopen(strcat(filename, ".dat"), "r");
		
		
				if(fp == NULL){
					printf("\n\nThe record does not exist");
				}
		
				else{
					fread(&usr, sizeof(struct user), 1, fp);
					fclose(fp);
				}
		
				if(!strcmp(password, usr.password)){
					system("cls");
					printf("Welcome to the %s record", name);
					printf("\n\nName of the patient: %s", usr.name);
					printf("\nPatient age: %d", usr.age);
					printf("\nPatient alergies: %s", usr.alergy);
			
			
			
				}
		
				else{
					printf("\n\nYou have entered a wrong password");
				}
				break;
				
				
				case 3:
					system("cls");
					printf("You have selected to edit the record!");
					printf("\n\nPlease enter record name you wish to edit: ");
					scanf("%s", &name);
					
					strcpy(filename, name);
					
					fp = fopen(strcat(filename, ".dat"), "r");
					fread(&usr, sizeof(struct user), 1, fp);
					
					
					if(fread != 0){
						printf("Enter the password: ");
						scanf("%s", &password);
						
						if(!strcmp(password, usr.password)){
							fp = fopen(filename, "w");
							fwrite(&usr, sizeof(struct user), 1, fp);
							
							
							system("cls");
							printf("Patient age: ");
							scanf("%d", &age);
							
							usr.age = age;
							
							printf("Patient alergies: ");
							scanf("%s", &alergy);
							strcpy(usr.alergy, alergy);
							
							
							fp = fopen(filename, "w");
							fwrite(&usr, sizeof(struct user), 1, fp);
						
							
							fclose(fp);
							fclose(fp);
							
							if(fwrite != 0){
								printf("\nFile has been edit");
							}
						}
						
						else{
							printf("\nInvalid password");
						}
						
						
					}
					
					else{
						printf("\nfile not registered");
					}
					
					fclose(fp);
					break;
				
				
				
				
				
				
				case 4:
					system("cls");
					printf("You have seleted to change the password!");
					printf("\n\nEnter patients name: ");
					scanf("%s", &name);
					
					
					strcpy(filename, name);
					
					fp = fopen(strcat(filename, ".dat"), "r");
					fread(&usr, sizeof(struct user), 1, fp);
					fclose(fp);
					
					if(fread != 0){
						printf("Enter new password: ");
						scanf("%s", &password);
						
						fp = fopen(filename, "w");
						strcpy(usr.password, password);
						fwrite(&usr, sizeof(struct user), 1, fp);
						
						
						
						if(fwrite != 0){
							printf("\nYou have successfully changed the password!");
							
						}
						else{
							printf("\nSomething went wrong!");
						}
						
					
						
						fclose(fp);
					}
					
					else{
						printf("\nFile doesn't exist");
					}
					break;
					
					
			
		
			}
			
			printf("\n\nDo you wish to go to the main panel[y/n]: ");
			scanf("%s", &cont);
			
		}
	
	
	
	
	return 0;
}
