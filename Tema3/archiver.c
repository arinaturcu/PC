#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "create.h"

int main() {
	char line[512], *param[4];
	char *token, del[] = " ";

	while (fgets(line, 512, stdin)) { // citeste toata linia

		line[strlen(line) - 1] = '\0';

		for (int i = 0; i < 4; ++i){
			param[i] = NULL;
		}

    	token = strtok(line, del);
    	param[0] = token; // ia primul parametru (exit, create, list sau extract)

    	if (!strcmp(param[0], "exit")) {
    		return 0;
    	} else {

        	if (!strcmp(param[0], "create")) {
            	for (int i = 1; i < 3; ++i) {
               		param[i] = strtok(NULL, del);
/* create */
               		if (param[i] != NULL) {
               			param[i][strlen(param[i])] = '\0'; // vreau sa am \0 
               		}                                      // dupa fiecare parametru
            	}

            	if (param[2] == NULL || strtok(NULL, del) != NULL) {
            		printf("> Wrong command!\n"); // daca nr de prametrii e gresit
            	} else {
            		create(param[2], param[1]);

            		printf("> Done!\n");
            	}

        	} else {
        		if (!strcmp(param[0], "list")) {
        			param[1] = strtok(NULL, del);
/* list */
        			if (param[1] != NULL) {
        				param[1][strlen(param[1])] = '\0';
                    }

                	if (param[1] == NULL || strtok(NULL, del) != NULL) {
            	    	printf("> Wrong command!\n");
                	} else {
                		//list();
                    }

        		} else {
        			if (!strcmp(param[0], "extract")) {
                    	for (int i = 1; i < 3; ++i) {
                       		param[i] = strtok(NULL, del);
                       		if (param[i] != NULL) {
                       			param[i][strlen(param[i])] = '\0';
                       		}
                    	}
/* extarct */
                    	if (param[2] == NULL || strtok(NULL, del) != NULL) {
            	        	printf("> Wrong command!\n");
                    	} else {
                            //extract();
                    		printf("> Done!\n");
                    	}

        			} else { // daca comanda nu e create/list/extract/exit
        				printf("> Wrong command!\n");
        			}
        		}
        	}
    	}
	}

	return 0;
}
