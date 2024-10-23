#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int n, m, tt, s1, s2, tmax, t;
char command[255];
int surse = 2;
char* sources[] = {"sushi-0time", "sushi"};
int bruturi = 0;
char* brutes[] = {};
char* problem = "sushi";
char* gen_name = "gen-sushi";

void executa(int test, char* sursa)
{
    fprintf(stderr, "Executam la testul %d sursa %s\n", test, sursa);

    memset(command, 0, sizeof(command));
    sprintf(command, "%s.exe", sursa);
    system(command);

    fprintf(stderr, "\n");
}


int main()
{
    FILE *in = fopen("config.txt", "r");

    fscanf(in, "%d", &t);

    for(int i=1; i<=t; ++i)
    {
        fprintf(stderr, "Testul %d\n ", i);

        fscanf(in, "%d%d%d%d%d%d", &n, &m, &tt, &s1, &s2, &tmax);

        memset(command, 0, sizeof(command));
        sprintf(command, "%s.exe %d %d %d %d %d %d", gen_name, n, m, tt, s1, s2, tmax);
        system(command);

        if(i<=1)
        {
            for(int s=0; s<bruturi; ++s)
                executa(i, brutes[s]);
        }

        for(int s=0; s<surse; ++s)
            executa(i, sources[s]);

        memset(command, 0, sizeof(command));
        sprintf(command, "move %s.in %d-%s.in", problem, i, problem);
        system(command);

        memset(command, 0, sizeof(command));
        sprintf(command, "move %s.out %d-%s.ok", problem, i, problem);
        system(command);

        fprintf(stderr, "...gata\n\n", i);
    }

    fclose(in);

    return 0;
}
