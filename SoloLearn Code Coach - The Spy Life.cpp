#include <iostream>
#include <string>

using namespace std;

/*
	Desenvolvido por: Marley Lobão de Sousa
	SoloLearn
	Code Coach - The Spy Life

	Descrição do problema:
			Há uma mensagem secreta encriptada, e para decodificá-la é necessário realizar a
        retirada de caracteres que não fazem parte da mensagem, ou seja, espaços e qualquer
        caractere que não sejam letras.
			A string de entrada deve ser como o exemplo: "d89%l++5r19o7W *o=l645le9H" na saída fica "Hello World".
			A string de saída deve ser a mensagem secreta em linguagem humana compreensível.
*/

int main() {
    string input,justLetters,invert;
    int len,i,aux1,aux2;
    
    getline(cin,input);
    len = input.size();

    //retirando caracteres indesejados
    for(i=0;i<len;i++){
        if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') || (input[i]==' '))
            justLetters += input[i];
    }

    //variáveis de ajuste na inversão da string
    aux1 = justLetters.size();
    aux2 = aux1-1;

    //necessário para definição de espaço de memória!
    invert=justLetters;

    //invertendo a string
    for(i=0;i<aux1;i++){
        invert[i] = justLetters[aux2];
        aux2--;
    }

    //mostrando a saída
    cout << invert;

    return 0;
}