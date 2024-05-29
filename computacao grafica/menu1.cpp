#include <iostream>
#include <conio2.h>
using namespace std;
void menu(){
	/*textbackground(CYAN);
	clrscr();
	textcolor(BLUE);*/
	gotoxy(10,3); cout<<"Opcoes:";
	gotoxy(15,5); cout<<"1-Soma";
	gotoxy(15,7); cout<<"2-Subtracao";
	gotoxy(15,9); cout<<"3-Multiplicacao";
	gotoxy(15,11); cout<<"4-Divisao";
	gotoxy(15,13); cout<<"5-Sair";
	gotoxy(10,15); cout<<"Escolha a opcao: ";
}
void soma(){
	int a,b;
	cout<<"Digite um numero: "; cin>>a;
	cout<<"Digite outro numero: "; cin>>b;
	cout<<"Soma = "<<a+b;
	cout<<"\n\nTecle algo para voltar ao menu...";
	getch();
}

void subtrair(){
	int a,b;
	cout<<"Digite um numero: "; cin>>a;
	cout<<"Digite outro numero: "; cin>>b;
	cout<<"Subtracao = "<<a-b;
	cout<<"\n\nTecle algo para voltar ao menu...";
	getch();
}
void multiplica(){
	int a,b;
	cout<<"Digite um numero: "; cin>>a;
	cout<<"Digite outro numero: "; cin>>b;
	cout<<"Multiplicacao = "<<a*b;
	cout<<"\n\nTecle algo para voltar ao menu...";
	getch();
}
void divide(){
	int a,b;
	cout<<"Digite um numero: "; cin>>a;
	cout<<"Digite outro numero: "; cin>>b;
	cout<<"Divisao = "<<a/b;
	cout<<"\n\nTecle algo para voltar ao menu...";
	getch();
}
int main(){
	int sair=0;
	char opcao;
	while (sair==0){
		menu();
		cin>>opcao;
		clrscr();
		switch(opcao){
		   case '1': { soma(); break; }
		   case '2': { subtrair(); break; }
		   case '3': { multiplica(); break; }
		   case '4': { divide(); break; }
		   case '5': { sair=1; break; }
		   default:{ cout<<"OPCAO INVALIDA!"; getch(); break; }
		}
	}
}

