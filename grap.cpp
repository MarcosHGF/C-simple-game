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

int obj(int x1, int y1, int x2, int y2);
int objpress(int x1, int y1, int x2, int y2);
void botao(int x1, int y1, int x2, int y2, char rotulo[6]);
void botaoPressionado(int x1, int y1, int x2, int y2, char rotulo[15]);

int main(){

int j,i,i2,flag1=0,dificult=0,a1=0,b1=0,a2=0,b2=0;

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
    clearviewport();
}
i2=dificult;

}
//game
while(!kbhit()){
    if(flag1==2){
        readimagefile("agua.jpg",0,0,600,600);
            delay(100);
            int v[dificult][4];

        for(i=0;i<dificult;i++){

                a1 = rand() % 569 + 1;
                b1 = rand() % 569 + 1;
                a2 = a1+30;
                b2 = b1;
                v[i][0]=a1;
                v[i][1]=a2;
                v[i][2]=b1;
                v[i][3]=b2;
                printf("%d  ", a1);
        }
        for(i=0;i<dificult;i++){
            obj(v[i][0], v[i][2], v[i][1], v[i][3]);
        }
          if (mousex()>= v[i][0] && mousex()<= v[i][1] && mousey()>=v[i][2] && mousey()<=v[i][3] && ismouseclick(WM_LBUTTONDOWN)){
               objpress(v[i][0], v[i][2], v[i][1], v[i][3]);
                    clearmouseclick(WM_LBUTTONDOWN);
               }
        }
        dificult = -1;
        }

    flag1=0;
    return 0;
}
int obj(int x1, int y1, int x2, int y2)
{
    setfillstyle(1,14);
    bar(x1,y1,x2,y2);
    return x1,y1,x2,y2;
}
int objpress(int x1, int y1, int x2, int y2)
{
    setfillstyle(1,3);
    bar(x1,y1,x2,y2);
    return x1,y1,x2,y2;
}
void botao(int x1, int y1, int x2, int y2, char rotulo[6])
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
