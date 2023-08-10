#include <iostream>
using namespace std;
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char outFileName[100];

//Find if there is Pipe "|" , ">" Symbol and Space
void find_Sp_Pip_gSym(char input[], int &noOfSpaces, int &noOfPipes, int &gSymbol)
{
    for (int i = 0; i < strlen(input) + 1; i++)
    {
        if (input[i] == '|')
            noOfPipes++;
        if (input[i] == '>')
            gSymbol++;
        if (input[i] == ' ')
            noOfSpaces++;
    }

    cout << "Spaces: " << noOfSpaces << endl;
    noOfSpaces++;
    cout << "Pipes: " << noOfPipes << endl;
    cout << ">: " << gSymbol << endl;
}

int findSpace(char input[])
{
    int count = 0;
    for (int i = 0; i < strlen(input) + 1; i++)
    {
        if (input[i] == ' ')
            count++;
    }
    cout << "Spaces: " << count << endl;
    return count + 1;
}

void tokenization_wrt_gSymbol(char *tokenized_arg[], char extra[], char outputFile[])
{
    char *tok;
    int i = 0;                                   //counter for traversing tokenized_arg
    while ((tok = strtok_r(extra, ">", &extra))) //tokenizing parameters after the command
    {
        tokenized_arg[i] = new char[strlen(tok) + 1];
        strcpy(tokenized_arg[i], tok); //store the parsed data
        cout << tok << endl;
        i++;
    }
    strcpy(outputFile, tokenized_arg[i - 1]); //2nd last points to outputFile name in case of >
    cout << "outputFileName: " << outputFile << endl;
    tokenized_arg[i - 1] = NULL;
}

void tokenization_wrt_Spaces(char *tokenized_arg[], char extra[])
{
    char *tok;
    int i = 0;                                   //counter for traversing tokenized_arg
    while ((tok = strtok_r(extra, " ", &extra))) //tokenizing parameters after the command
    {
        tokenized_arg[i] = new char[strlen(tok) + 1];
        strcpy(tokenized_arg[i], tok); //store the parsed data
        cout << tok << endl;
        i++;
    }
    tokenized_arg[i] = NULL;
}

void tokenization_wrt_Pipes(char *tokenized_arg[], char extra[])
{
    char *tok;
    int i = 0;                                   //counter for traversing tokenized_arg
    while ((tok = strtok_r(extra, "|", &extra))) //tokenizing the command
    {
        tokenized_arg[i] = new char[strlen(tok) + 1];
        strcpy(tokenized_arg[i], tok); //store the parsed data
        cout << tok << endl;
        i++;
    }
    tokenized_arg[i] = NULL;
}

void exec_Remaining_Pipes(char *tokenizedP[],int cPipe, int G)
{
    pid_t status;
    int fd[2];
    if (pipe(fd) == -1)
    {
        cout << "Pipe1 Failed";
        return;
    }


    status = fork();

    if (status < 0)
    {
        cout << "Fork() Failed :(" << endl;
        return;
    }

    else if (status == 0)
    {
        if(cPipe==0)    //not last pipe
        {
        int infile = open("tempFile.txt", O_RDONLY, 0);
        dup2(infile, STDIN_FILENO);
        close(infile);
        remove("tempFile.txt");

        int outfile = open("tempFile.txt", O_CREAT | O_WRONLY, 0777);
        dup2(outfile, STDOUT_FILENO);
        close(outfile);
        
        execvp(tokenizedP[0], tokenizedP);
        }

      

        else if(cPipe>0) //last pipe
        {
            if(G>0) //output in File
            {
                
            int file = open("tempFile.txt", O_RDONLY, 0);
            dup2(file, STDIN_FILENO);
            close(file);
            remove("tempFile.txt");

            int file2 = open(outFileName, O_CREAT | O_WRONLY, 0777);
            dup2(file2, STDOUT_FILENO);
            close(file2);
            execvp(tokenizedP[0], tokenizedP);
            }

            else    //ouptut on terminal
            {
                int file = open("tempFile.txt", O_RDONLY , 0);
                // close(fd[0]);
                // close(fd[1]);
                dup2(fd[1], STDOUT_FILENO); //write in pipe               

                

                dup2(fd[0], STDIN_FILENO);  //write on  terminal
                
                close(fd[0]);
                close(fd[1]);
            execvp(tokenizedP[0], tokenizedP);
            }
        }
        
    }

    else
    // {   
    //     close(fd[0]);
    //     close(fd[1]);
        wait(NULL);
    
}

void exec_1st_Pipe(char *tokenizedP[], char *tokenizedP2[], int noP, int G)
{
    pid_t status, status2;
    int fd[2];

    if (pipe(fd) == -1)
    {
        cout << "Pipe1 Failed";
        return;
    }

    //Create Process
    status = fork();

    if (status < 0) //Fork 1()failed
    {
        cout << "Fork1 Failed" << endl;
        return;
    }

    else if (status == 0) //Child 1
    {
        if (noP > 1)
        {
            int file = open("tempFile.txt", O_CREAT | O_WRONLY, 0777);
            dup2(file, STDOUT_FILENO); //redirect output to file
            close(file);
        }

        else if (noP == 1)
        {
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO); //write in pipe
            close(fd[1]);
        }
        execvp(tokenizedP[0], tokenizedP); //Command before "|"
    }
    wait(NULL);
    status2 = fork();

    if (status2 < 0)
    {
        cout << "Fork2 Failed" << endl;
        return;
    }

    else if (status2 == 0)
    {
        if (noP > 1)
        {
            int file = open("tempFile.txt", O_RDONLY, 0);
            dup2(file, STDIN_FILENO);
            close(file);
            remove("tempFile.txt");

            int file2 = open("tempFile.txt", O_CREAT | O_WRONLY, 0777);
            dup2(file2, STDOUT_FILENO);
            close(file2);
        }

        if (noP == 1)
        {
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
        }

        if (noP ==1 && G>0) //redirection (">") to specified file
        {
            int file = open("tempFile.txt", O_RDONLY, 0);
            dup2(file, STDIN_FILENO);
            close(file);
            remove("tempFile.txt");

            int file2 = open(outFileName, O_CREAT | O_WRONLY, 0777);
            dup2(file2, STDOUT_FILENO);
            close(file2);
        }

        execvp(tokenizedP2[0], tokenizedP2); //command after "|"
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
}

//Execution of simple commands without "|", ">" and "<"
int execSimpleCommands(char *tokenized_arg[], char input[])
{
    pid_t pid;
    pid = fork();

    if (pid > 0) //parent
    {
        wait(NULL);
    }

    else if (pid == 0) //child
    {
        if (strcmp("exit", input) != 0) //input!=exit
        {
            execvp(tokenized_arg[0], tokenized_arg);
        }
        else //input==exit
        {
            exit(0);
        }
    }

    else
    {
        cout << "Fork Failed :(\n";
        return 1;
    }

    return 0;
}

void execGreateSym(char *tokenized_before_gSym[], char input[])
{
    int fd[2]; // pipe (0=READ_END , 1=WRITE_END)
    pid_t status;

    if (pipe(fd) == -1)
    {
        cout << "Pipe Failed " << endl;
        return;
    }

    //Create Process

    status = fork();

    if (status < 0) //Fork 1()failed
    {
        cout << "Fork1 Failed" << endl;
        return;
    }

    else if (status == 0) //Child 1
    {
        int file = open(outFileName, O_CREAT | O_WRONLY, 0666);
        close(fd[0]);   //close READ_END
        dup2(fd[1], 1); //redirect to pipe WRITE_END
        close(fd[1]);   //close WRITE_END
        execvp(tokenized_before_gSym[0], tokenized_before_gSym); //Command before ">"
    }

    else //parent
    {
        close(fd[0]);
        close(fd[1]);
        wait(NULL);
    }
}

int main()
{
    char input[100];
    cout << "Welcome To MY OWN SHELL :) \n";
    cout << "\n******************************************";
    // while(strcmp("exit",input)!=0){
    cout << "\n\nEnter the Command OR Enter exit to Quit: " << endl;
    cin.getline(input, 100);

    char *extra, *extra2, *extra3;
    extra = extra2 = extra3 = input;
    int noOfSpaces = 0, noOfPipes = 0, greaterSym = 0;

    find_Sp_Pip_gSym(input, noOfSpaces, noOfPipes, greaterSym);
    char **tokenized_arg = new char *[noOfSpaces]; //depends upon the no.of spaces */

    if (noOfPipes == 0 && greaterSym == 0) //simple command
    {
        tokenization_wrt_Spaces(tokenized_arg, extra);
        execSimpleCommands(tokenized_arg, input);
    }

    else if (noOfPipes == 0 && greaterSym != 0) //redirection in some file
    {
        tokenization_wrt_gSymbol(tokenized_arg, extra2, outFileName);
        tokenization_wrt_Spaces(tokenized_arg, tokenized_arg[0]);
        execGreateSym(tokenized_arg, extra2);
    }

    else if (noOfPipes != 0)
    {   
        if(greaterSym > 0){
        tokenization_wrt_gSymbol(tokenized_arg, extra2, outFileName);
        }

        tokenization_wrt_Pipes(tokenized_arg, extra);

        char **pipeArg = new char *[noOfPipes + 1];
        char **pipeArg1 = new char *[noOfPipes + 1];

        tokenization_wrt_Spaces(pipeArg, tokenized_arg[0]);
        tokenization_wrt_Spaces(pipeArg1, tokenized_arg[1]);
        exec_1st_Pipe(pipeArg, pipeArg1, noOfPipes, greaterSym); //if 1 pipe

        if (noOfPipes > 1)
        {
            for (int i = 1; i < noOfPipes; ++i)
            {
                char **pipeArg2 = new char *[noOfPipes + 1];
                tokenization_wrt_Spaces(pipeArg2, tokenized_arg[i + 1]); //start from index 2
                if(i==noOfPipes-1){ //if its last
                exec_Remaining_Pipes(pipeArg2, i, greaterSym);
                }
                else{
                    exec_Remaining_Pipes(pipeArg2, 0, greaterSym);
                }

                //deallocating 2d array
                for (int j = 0; j < noOfPipes; ++j)
                {
                    if (pipeArg != nullptr && pipeArg1 != nullptr)
                    {
                        delete[] pipeArg[j];
                        delete[] pipeArg1[j];
                    }
                    delete[] pipeArg2[j];
                }
                delete pipeArg2;
                if (pipeArg != nullptr && pipeArg1 != nullptr)
                {
                    delete pipeArg, pipeArg1;
                }
            }
        }
    }

    return 0;
}
