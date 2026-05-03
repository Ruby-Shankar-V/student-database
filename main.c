#include "header.h"

int c = 0;

int main(int argc, char *argv[]){

	/* ── CLI mode ── */
	if(argc >= 2){
		if(strcmp(argv[1], "--help") == 0){
			pf("\033[32;1m");
			pf("\nUsage: dbase [OPTION]\n\n");
			pf("  (no option)      Launch interactive menu\n");
			pf("  --help           Show this help message\n");
			pf("  --purge          Delete the saved database (root only)\n\n");
			pf("Data file  : ~/.dbase/student.dat\n");
			pf("Binary     : /sbin/dbase\n");
			pf("\033[0m\n");
			return 0;
		}

		if(strcmp(argv[1], "--purge") == 0){
			if(getuid() != 0){
				pf("\033[31;1;5m\n\tdbase: Permission Denied!\033[0m\n");
				pf("\033[33;1m\tHint: try  sudo dbase --purge\033[0m\n\n");
				return 1;
			}
			char path[512];
			get_db_path(path, sizeof(path));
			if(remove(path) == 0)
				pf("\033[32;1;5m\n\tDatabase purged successfully!\033[0m\n\n");
			else
				pf("\033[31;1m\n\tNothing to purge or permission error.\033[0m\n\n");
			return 0;
		}

		pf("\033[31;1m\ndbase: invalid option '%s'\033[0m\n", argv[1]);
		pf("\033[33;1mTry: dbase --help\033[0m\n\n");
		return 1;
	}

	/* ── Interactive menu mode ── */
	char op;
	int num = 3;
	SLL *hp = 0;

	init_db_dir();            /* create ~/.dbase/ if it doesn't exist */
	if(hp == 0) read_file(&hp);

	while(1){
		pslow("\033[32;1m", 5000);
		pslow("\n\n\t+++++++++++++++++++++++++++++++++++++++++++++++++\n", 5000);
		pslow("\t+\t\t STUDENT RECORD MENU\t\t+\n", 5000);
		pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n", 5000);
		pslow("\t+\ta/A\t: add new record\t\t+\n", 5000);
		pslow("\t+\td/D\t: delete a record\t\t+\n", 5000);
		pslow("\t+\ts/S\t: show the list\t\t\t+\n", 5000);
		pslow("\t+\tm/M\t: modify a record\t\t+\n", 5000);
		pslow("\t+\tt/T\t: sort the list\t\t\t+\n", 5000);
		pslow("\t+\tl/L\t: delete all records\t\t+\n", 5000);
		pslow("\t+\tr/R\t: reverse the list\t\t+\n", 5000);
		pslow("\t+\tv/V\t: save\t\t\t\t+\n", 5000);
		pslow("\t+\te/E\t: exit\t\t\t\t+\n", 5000);
		pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n\n", 5000);
		pslow("\033[0m", 5000);
		pslow("\033[34;1m\tEnter Your Choice: \033[0m", 5000);

		sf(" %c", &op);
		op = tolower(op);

		switch(op){
			case 'a': add_new_record(&hp); break;

			case 'd': {
					char ch;
					pslow("\033[32;1m", 5000);
					pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n", 5000);
					pslow("\t+\tR/r\t: Delete Based on RollNo\t+\n", 5000);
					pslow("\t+\tN/n\t: Delete Based on Name\t\t+\n", 5000);
					pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n\n", 5000);
					pslow("\033[0m", 5000);
					pslow("\033[34;1m\tEnter Your Choice: \033[0m", 5000);
					sf(" %c", &ch);
					ch = tolower(ch);
					switch(ch){
						case 'r': delete_record_rollno(&hp); break;
						case 'n': delete_record_name(&hp);   break;
						default:  pf("\033[31;1;5m\n\tInvalid User Input!\033[0m\n"); break;
					}
				}; break;

			case 's': show_the_list(hp); break;

			case 'm': {
					char ch;
					pslow("\033[32;1m", 5000);
					pslow("\n\n\t+++++++++++++++++++++++++++++++++++++++++++++++++\n", 5000);
					pslow("\t+\t STUDENT RECORD MODIFICATION\t\t+\n", 5000);
					pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n", 5000);
					pslow("\t+\tR/r\t: Search by RollNo\t\t+\n", 5000);
					pslow("\t+\tN/n\t: Search by Name\t\t+\n", 5000);
					pslow("\t+\tP/p\t: Search by Percentage\t\t+\n", 5000);
					pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n\n", 5000);
					pslow("\033[0m", 5000);
					pslow("\033[34;1m\tEnter Your Choice: \033[0m", 5000);
					sf(" %c", &ch);
					ch = tolower(ch);
					switch(ch){
						case 'r': search_rollno(hp);     break;
						case 'n': search_name(hp);       break;
						case 'p': search_percentage(hp); break;
						default:  pf("\033[31;1;5m\n\tInvalid User Input!\033[0m\n"); break;
					}
				}; break;

			case 'v': save(hp); break;

			case 'e': {
					char ch;
					pslow("\033[32;1m", 5000);
					pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n", 5000);
					pslow("\t+\tS/s\t: save and exit\t\t\t+\n", 5000);
					pslow("\t+\tE/e\t: exit without saving\t\t+\n", 5000);
					pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n\n", 5000);
					pslow("\033[0m", 5000);
					pslow("\033[34;1m\tEnter Your Choice: \033[0m", 5000);
					sf(" %c", &ch);
					ch = tolower(ch);
					switch(ch){
						case 's': save(hp); exit(0);
						case 'e': exit(0);
						default:  pf("\033[31;1;5m\n\tInvalid User Input!\033[0m\n"); break;
					}
				}; break;

			case 't': {
					char ch;
					pslow("\033[32;1m", 5000);
					pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n", 5000);
					pslow("\t+\tR/r\t: Sort by Roll No\t\t+\n", 5000);
					pslow("\t+\tN/n\t: Sort by Name\t\t\t+\n", 5000);
					pslow("\t+\tP/p\t: Sort by Percentage\t\t+\n", 5000);
					pslow("\t+++++++++++++++++++++++++++++++++++++++++++++++++\n\n", 5000);
					pslow("\033[0m", 5000);
					pslow("\033[34;1m\tEnter Your Choice: \033[0m", 5000);
					sf(" %c", &ch);
					ch = tolower(ch);
					switch(ch){
						case 'r': rollno_sorting(hp);     break;
						case 'n': name_sorting(hp);       break;
						case 'p': percentage_sorting(hp); break;
						default:  pf("\033[31;1;5m\n\tInvalid User Input!\033[0m\n"); break;
					}
				}; break;

			case 'l': {
					char conf[5];
					pslow("\033[33;1m\tAre You Sure! You want to Delete All (yes/no): \033[0m", 5000);
					sf("%4s", conf);
					for(int i = 0; conf[i]; i++) conf[i] = tolower(conf[i]);
					if(strcmp(conf, "yes") == 0)
						delete_all(&hp);
				}; break;

			case 'r': reverse_list(hp); break;

			default:
				pf("\033[31;1;5m\n\tInvalid User Input!\033[0m\n");
				num--;
				if(num == 0) exit(0);
		}
	}
}