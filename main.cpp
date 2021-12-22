#include <stdio.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv) {

    const char *shortOptions = "hvl:";

    static struct option longOptions[] = {
    	{"list",    required_argument, 0, 'l'},
    	{"version", no_argument,       0, 'v'},
        {"help ",    no_argument,       0, 'h'}, 
        {0, 0, 0},
    };

    const char *helpOption = "Program options:\n"
    "-l[<val1>,...]                        - list of available arguments\n"
    "-v or --version                       - current version of file\n"
    "-h or --help                          - messages with program options\n";

    

    bool h_bool, v_bool, l_bool = false;
    
    int index, code;

    while ((code = getopt_long(argc, argv, shortOptions, longOptions, &index)) != -1) {
        switch (code) {
            case 'h': {
                if (!h_bool) {
                    h_bool = true;
                    printf("%s\n", helpOption);
                }
                break;
            }
            case 'l': {
                if (!l_bool) {
                    char *args;
                    printf("List:  ");
                    args = strtok(optarg, ",");
                    while (args != NULL) {
                        printf("%s ", args);
                        args = strtok(NULL, ",");
                    }
                    printf("\n");
                    l_bool = true;
                }
                break;
            }
            case 'v': {
                if (!v_bool) {
                    v_bool = true;
                    printf("Current version\n");
                }
                break;
            }
            default: {
                printf("Error!\n");
                return 0;
            }
        }
    }
    return 0;
}
