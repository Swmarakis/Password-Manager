//Giorgos Somarakis
//csd4797

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//TODO: ENCRYPT ALL THE PASS FIRST AND THEN THE ENTIRE PASS FILE



//return == TRUE file exists else is not exists
bool file_exists(char path[]){
	FILE *file = fopen(path, "r");
	bool exists = false;

	if(file != NULL){
		exists = true;
		fclose(file);
	}

	return exists;
}

void search_csvFile(char *path, char *website, char *username, char *password){
	//Opeing the csv file
	FILE *file = fopen(path, "r");
	if(file == NULL ){
		perror("Couln't open or find the file\n");
		exit(EXIT_FAILURE);
	}

	//max line length 100
	char line[100];
	//max field length 128
	int max = 128;

	while(fgets(line, 100, file) != NULL){
		//Spliting the lines due to commas with strtok
		char *token = strtok(line, ",");
		char entry_website[max], entry_username[max], entry_password[max];
        int field_count = 0;
        while (token != NULL && field_count < 3) {
            // Store each field in a separate string
            if (field_count == 0) {
                strcpy(entry_website, token);
            } else if (field_count == 1) {
                strcpy(entry_username, token);
            } else if (field_count == 2) {
                strcpy(entry_password, token);
            }
            field_count++;
            token = strtok(NULL, ",");
        }

		//Searching for website
		if(strcmp(entry_website, website) == 0){
			//copy username and pass to the output variables

			strcpy(username, entry_username);
			strcpy(password, entry_password);
			break;
		}
	}
	fclose(file);
}

//SAVE MODE 
void save_mode(char path[], char website[], char username[], char password[]){
	printf("Path: %s, Website: %s, Username: %s, Pass: %s\n",path, website, username, password);

	//dynamically allocate memory
	char *master_pass;
	master_pass = (char *)malloc(100 * sizeof(char));
	printf("Enter password: ");
	scanf(" %s",master_pass);
	master_pass[strlen(master_pass)] = '\0';
	//-------------------------------------------------

	


	//Checking first is the pass file exists.
	if(file_exists(path)){
		FILE *file = fopen(path, "a");

		fprintf(file, "%s,%s,%s\n",website,username,password);
		fclose(file);

	}else{
		FILE *file = fopen(path,"w");
		//header line
		fprintf(file,"website,username,password\n");

		fprintf(file, "%s,%s,%s\n",website,username,password);
		fclose(file);
		
	}
	
	
}

//GET MODE 	
void get_mode(char path[], char website[]){
	printf("Path: %s, Website: %s\n", path, website);

	//dynamically allocate memory
	char *master_pass;
	master_pass = (char *)malloc(100 * sizeof(char));
	printf("Enter password: ");
	scanf(" %s",master_pass);
	master_pass[strlen(master_pass)] = '\0';
	//-------------------------------------------------



	char username[128], password[128];
	search_csvFile(path, website, username, password);

	//Output:
	printf("Website: %s, Username: %s, Password: %s\n", website, username, password);

	
}


/*
char encryption(char *string[]){

	return string;
}

char decryption(char *string[]){

	return string;
}
*/


int main(int argc, char *argv[]){
	if(argc > 7){
		perror("Too many arguments supplied.\n");
		perror("Please check the arguments, the argv must have this form,\npm save -f <path to password file> <website> <username> <password>\n");

		return 1;
	}else if(argv[1][0] == 's'){
		//Save mode.
		if(argc <= 6){
			perror("Too litle arguments supplied");
			return 1;
		}
		save_mode(argv[3], argv[4], argv[5], argv[6]);
		//save_mode(<path>, <website>, <username>, <password>)

	}else if(argv[1][0] == 'g'){
		//Get mode.
		if(argc <= 4){
			perror("Too lilte arguments supplied\n");
			return 1;
		}
		get_mode(argv[3], argv[4]);
		//get_mode(<path>, <website>)

	}
	
	return 0;
}

