#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

//ideia principal: jogo 3 dificuldades onde se clica/atira em patinhos no lago, cronometrar para ver quem faz em menos tempo, quem erra menos tiro, e calcular sua pontuação.Extender varios modos de jogo.

typedef struct player{
int pontos,nivel;
char apelido;
}pessoa;

void obj(int x1, int y1, int x2, int y2);
void botao(int x1, int y1, int x2, int y2, char rotulo[30]);
void botaoPressionado(int x1, int y1, int x2, int y2, char rotulo[30]);

main(){

int j,i,i2,v[0][0],flag1=0,dificult;

initwindow(600,600,"jogo",0,0);

srand(time(NULL));

outtextxy(180,270,"escolha dificuldade 1 , 2 ou 3");
botao(200, 300, 230, 330, "1");
botao(260, 300, 290, 330, "2");
botao(320, 300, 350, 330, "3");
botao(230, 340, 320, 370, "jogar");

while(flag1==0 || flag1==1){

if(ismouseclick(WM_LBUTTONDOWN))
    clearmouseclick(WM_LBUTTONDOWN);

//1
if (mousex()>= 200 && mousex()<= 230 && mousey()>=300 && mousey()<=330 && ismouseclick(WM_LBUTTONDOWN))
        {
    botaoPressionado(200, 300, 230, 330, "1");
    clearmouseclick(WM_LBUTTONDOWN);
        botao(260, 300, 290, 330, "2");
        botao(320, 300, 350, 330, "3");

        flag1=1;
        dificult=12;
        }
//2
if (mousex()>= 260 && mousex()<= 290 && mousey()>=300 && mousey()<=330 && ismouseclick(WM_LBUTTONDOWN))
        {
    botaoPressionado(260, 300, 290, 330, "2");
    clearmouseclick(WM_LBUTTONDOWN);
        botao(200, 300, 230, 330, "1");
        botao(320, 300, 350, 330, "3");

        flag1=1;
        dificult=20;
        }
//3
if (mousex()>= 320 && mousex()<= 350 && mousey()>=300 && mousey()<=330 && ismouseclick(WM_LBUTTONDOWN))
        {
    botaoPressionado(320, 300, 350, 330, "3");
    clearmouseclick(WM_LBUTTONDOWN);
        botao(260, 300, 290, 330, "2");
        botao(200, 300, 230, 330, "1");

        flag1=1;
        dificult=28;
        }
//jogar
if(mousex()>= 230 && mousex()<= 320 && mousey()>=340 && mousey()<=370 && ismouseclick(WM_LBUTTONDOWN)){
    botaoPressionado(230, 340, 320, 370, "jogar");
    flag1=2;
}
i2=dificult;
v[0][0]=dificult,4;
}
//game
while(!kbhit()){
    if(flag1==2){
        clearviewport();
        readimagefile("agua.jpg",0,0,600,600);
            delay(100);
        for(i=0;i<dificult;i++){
           obj((rand()*rand())% 569+1,(rand()*rand())% 569+1, 0, 0);
                    j++;
                }
        flag1=0;
                }
    }
}
void obj(int x1, int y1, int x2, int y2)
{
    x2=x1+30;
    y2=y1+30;
    setfillstyle(1,14);
    bar(x1,y1,x2,y2);
}
void botao(int x1, int y1, int x2, int y2, char rotulo[30])
{
setfillstyle(1,7);
bar(x1,y1,x2,y2);
setlinestyle(0,0,2);
setcolor(15);
line(x1,y1,x2,y1);
line(x1,y1,x1,y2);
setcolor(8);
line(x2,y1+2,x2,y2);
line(x1+2,y2,x2,y2);
setbkcolor(7);
setcolor(0);
outtextxy(x1 + ((x2-x1-(strlen(rotulo)*8))/2) + 2, y1+8, rotulo);
}
void botaoPressionado(int x1, int y1, int x2, int y2, char rotulo[30])
{
setfillstyle(1,7);
bar(x1,y1,x2,y2);
setlinestyle(0,0,2);
setcolor(8);
line(x1,y1,x2,y1);
line(x1,y1,x1,y2);
setcolor(15);
line(x2,y1+2,x2,y2);
line(x1+2,y2,x2,y2);
setbkcolor(7);
setcolor(0);
outtextxy(x1 + ((x2-x1-(strlen(rotulo)*8))/2) + 2, y1+9, rotulo);
}
