#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union record {
    char charptr[512];

    struct header {
		char name[100];
		char mode[8];
		char uid[8];
		char gid[8];
		char size[12];
		char mtime[12];
		char chksum[8];
		char typeflag;
		char linkname[100];
		char magic[8];
		char uname[32];
		char gname[32];
		char devmajor[8];
		char devminor[8];
	} header;
};

char* break_the_line(char line[512], char* broken[9], char del[]) {
	char *token;
		int i = 0;

    	token = strtok(line, del);

    	while( token != NULL ) {   

      		broken[i++] = token;

      		token = strtok(NULL, del);
   		}

   	return broken[0];
} // works, bruh..

void get_usermod(char* line_brok[9], union record *archive) {
	int val = 0;

	for (int i = 1; i < 4; ++i) { // owner
		if (line_brok[0][i] == 'r') {
			val += 400;
		}
		if (line_brok[0][i] == 'w') {
			val += 200;
		}
		if (line_brok[0][i] == 'x') {
			val += 100;
		}
	}

	for (int i = 4; i < 7; ++i) { // group
		if (line_brok[0][i] == 'r') {
			val += 40;
		}
		if (line_brok[0][i] == 'w') {
			val += 20;
		}
		if (line_brok[0][i] == 'x') {
			val += 10;
		}
	}

	for (int i = 7; i < 10; ++i) { // others
		if (line_brok[0][i] == 'r') {
			val += 4;
		}
		if (line_brok[0][i] == 'w') {
			val += 2;
		}
		if (line_brok[0][i] == 'x') {
			val += 1;
		}
	}

	sprintf(archive->header.mode, "0000%d", val);
}

void get_uid_gid(char* line_brok[9], union record *archive, FILE* users) {
	char uname[32];
	char gname[32];
	char line[512];
	char *users_brok[7];
	int uidd, gidd;
	char uid_oct[8], gid_oct[8];

	strcpy(uname, line_brok[2]);
	strcpy(gname, line_brok[3]);

	long size_users = -1;

	fseek(users, 0, SEEK_END);
	size_users = ftell(users);
	fseek(users, 0, SEEK_SET);


	while (ftell(users) != size_users) {
		fgets(line, 512, users);
		line[strlen(line) - 1] = '\0';

		users_brok[0] = break_the_line(line, users_brok, ":");

		if (!strcmp(users_brok[0], uname)) {

			uidd = atoi(users_brok[2]);
			gidd = atoi(users_brok[3]);

			sprintf(archive->header.uid, "%.7o", uidd);
			sprintf(archive->header.gid, "%.7o", gidd);
		}
	}

	sprintf(archive->header.uname, "%s", uname);
	sprintf(archive->header.gname, "%s", gname);
}

void write_content(char path[100], FILE* arch, union record *archive, int size){
	FILE* file = fopen(path, "rb");

	memset(archive->charptr, '\0', 512);

	while ( ftell(file) != size) {
		fgets(archive->charptr, 512, file);
		fwrite(archive->charptr, sizeof(archive->charptr), 1, arch);
	}

	fclose(file);
}

void write_header(FILE* arch, char folder_name[]) {
	FILE* list = fopen ("files.txt", "rt");
	FILE* users = fopen ("usermap.txt", "rt");
	FILE* file;
	char path[200];

	char line[512];
	long size_files = -1;
	char *line_brok[9];

	union record archive;

	fseek(list, 0, SEEK_END);
	size_files = ftell(list);
	fseek(list, 0, SEEK_SET);

	while ( ftell(list) != size_files) {
		fgets(line, 512, list);
		line[strlen(line) - 1] = '\0'; // inlocuiesc \n cu \0

		// pune stringurile in vector ca sa le pot folosi dupa
		line_brok[0] = break_the_line(line, line_brok, " ");
		
		memset(archive.header.name, '\0', 100);
		strcpy(archive.header.name, line_brok[8]);

		// construiesc path
		strcpy(path, folder_name);
		strcat(path, archive.header.name);
		
		memset(archive.header.mode, '0', 8);
		memset(archive.header.uname, '\0', 32);
		memset(archive.header.gname, '\0', 32);

		// pune usermod uid gid uname si gname
		get_usermod(line_brok, &archive);
		get_uid_gid(line_brok, &archive, users);

		// calculeaza size
		file = fopen(path, "rb");
		int size = -1;
	
		fseek(file, 0, SEEK_END);
		size = ftell(file);
		fseek(file, 0, SEEK_SET);

		fclose(file);

		sprintf(archive.header.size, "%.11o", size);

		// mtime
		sprintf(archive.header.mtime, "%o", 1577999488);
		// linkname = name
		memset(archive.header.linkname, '\0', 100);
		strcpy(archive.header.linkname, archive.header.name);
		// chksum
		sprintf(archive.header.chksum, "0000%o", 345); 
		// typeflag
		archive.header.typeflag = '\0';
		//magic
		strcpy(archive.header.magic,"GNUtar ");
		// devminor si devmajor
		memset(archive.header.devmajor, '\0', 8);
		memset(archive.header.devminor, '\0', 8);

/////////////////////////////////////////////////////////////////////////////

		fwrite(&archive.header, sizeof(archive.header), 1, arch);
		char caca[167];
		memset(caca, '\0', 167);
		fwrite(&caca, 167, 1, arch);

		write_content(path, arch, &archive, size);
	}

	fclose(users);
	fclose(list);
}

void create(char folder_name[], char arch_name[]) {
	FILE* arch = fopen (arch_name, "wb");
											        /*LATER*/
	write_header(arch, folder_name); // poate fac asta sa returneze path si sa fac o
									 // functie care sa scrie continutul fisierului
									 // luand parametrul path

	fclose(arch);
}
