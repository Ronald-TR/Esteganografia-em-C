#include <stdio.h>
#include <stdlib.h>
#define MAX 999
int main (){

int tam_extensions=10, i=0, k=0, tam_extensions_txt=2;//variaveis de tamanho da string extens�es e contador
char string[MAX];//string que armazenar� os paths do usuario
char extensions[10][10]={".jpg", ".jpg\"", ".jpeg", ".jpeg\"", ".png", ".png\"", ".gif", ".gif\"", ".bmp", ".bmp\""};//string de extens�es pra compara��o
char extensions_txt[2][5]={".txt", ".txt\""};
char comand[MAX]="copy /b ";//string para concatenar o comando para a fun��o system executar
printf("Wellcome to a simple esteganografia-script based on C and system commands\nMade by Ronald\nEnjoy!\n");
printf("Use this script if you want to input a text file inside a img code. (you can drag and drop here).\n");
printf ("Insert path from img file\n");
fgets(string, MAX, stdin);
string[strlen(string)-1]='\0';
while (1)//compara se o comando dado possui uma imagem
{

    for(i=0; i<tam_extensions; i++){
        if(strstr(string, extensions[i])==NULL){
            k++;//se n�o achar uma ocorrencia da extens�o, incrementa k
        }
    }
if(k==i){//se k for igual a i, significa que todas as posi��es do loop eram nulas a compara��o, ent�o alerta pra inserir um arquivo valido
    printf("Please insert a file with a valid img extension path\n");
    setbuf(stdin, NULL);
    fgets(string, MAX, stdin);
    string[strlen(string)-1]='\0';
    k=0;

    }else {//reinsere as aspas retiradas e sai da repeti��o
        k=0;
        break;}
}
strcat(comand, string);
strcat(comand,"+");
printf ("Insert path from txt file\n");
fgets(string, MAX, stdin);
string[strlen(string)-1]='\0';
while(1)//compara se o caminho dado � de um arquivo de extens�o txt
{


    for(i=0; i<tam_extensions_txt; i++){
        if(strstr(string, extensions_txt[i])==NULL){
            k++;//se n�o achar uma ocorrencia da extens�o, incrementa k
        }
    }
if(k==i){//se k for igual a i, significa que todas as posi��es do loop eram nulas a compara��o, ent�o alerta pra inserir um arquivo valido
    printf("Please insert a file with a valid img extension path\n");
    setbuf(stdin, NULL);
    fgets(string, MAX, stdin);
    string[strlen(string)-1]='\0';
    k=0;

    }else {//reinsere as aspas retiradas e sai da repeti��o
        break;}
}



strcat(comand, string);
printf("%s", comand);
strcat(comand, " new.jpg");
system(comand);

return 0;
}
