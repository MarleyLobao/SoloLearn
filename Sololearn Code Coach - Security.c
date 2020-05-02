#include <stdio.h>
#include <string.h>

#define space 20
/*
	Desenvolvido por: Marley Lobão de Sousa
	SoloLearn
	Code Coach - Security

	Descrição do problema:
			Há um banco composto por andares em que um ladrão(T) tenta roubar o dinheiro($),
		porém há seguranças(G). Em cada andar há apenas um dinheiro, e um ladrão, porém
		uma quantidade qualquer de seguranças.
			A string de entrada deve ser como os exemplos: "T$xxxxxxG" 
		"xxxxGxxxxTxxG$xxxxG".
			Se o ladrão estiver sem seguranças pelo caminho a saída deve ser: "ALARM", se não
		tiver seguranças pelo caminho a saída deve ser: "quiet".
*/
int main(){
	char input[space] = "xxxGGxx$xxGxxT", output[] = "quiet", cut[space];
	int i,money,real;										//variáveis de ambiente
	int thief,distMT;										//variáveis do ladrão
	int lessDist,guards=0,guard[space],distGM[space];		//variáveis dos guards
	
	//scanf("%s",input);
	real=strlen(input);
	
	for(i=0;i<real;i++){
		if(input[i]=='$') money=i;
		if(input[i]=='T') thief=i;
	}
	
	if(money<thief){
		//invertendo a string
		strrev(input);
			
		for(i=0;i<real;i++){
		   	if(input[i]=='$') money=i;
			if(input[i]=='T') thief=i;
		}			
	}
	for(i=0;i<money;i++) cut[i]=input[i];
	cut[money]='\0';//garantia que a cópia da string está correta
	
	for(i=0;i<money;i++)
		if(cut[i]=='G'){
			guards++;
			guard[guards]=i;
		}
		
	distMT=money-thief;
	if(guards==0) strcpy(output,"ALARM");
	else{
		for(i=1;i<=guards;i++) distGM[i]=money-guard[i];
	
		lessDist=distGM[1];
		for(i=2;i<=guards;i++) if(lessDist>distGM[i]) lessDist = distGM[i];
	
		if(lessDist>distMT) strcpy(output,"ALARM");
	}
		
	printf("%s",output);
	
	return 0;
}