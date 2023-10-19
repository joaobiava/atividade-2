#include <iostream>
#include <string>
#include <cmath>
#define TAM 10
using namespace std;


int somaanteriores(int num);
void bissexto();
void binario();
bool validar(string senha);
double juroscompostos(double valor);
void ordenarinteiros();

int main(){
    int num, ano, valor;
    string senha;

    cin >> num;
    cout << somaanteriores(num) << endl;

    bissexto();

    binario();

    cin >> senha;
    if(validar(senha)){
        cout << "senha correta" << endl;
    }
    else{
        cout << "senha incorreta" << endl;
    }

    cin >> valor;
    cout << juroscompostos(valor) << endl;

    ordenarinteiros();
}

int somaanteriores(int num){
    int soma;
    for(num; num>0; num--){
        soma+=num;
    }
    return soma;
}

void bissexto(){
    int ano;
    cin >> ano;
    if(ano%400==0)
        ano/=400;
    if(ano%4==0)
        cout << "ano bissexto" << endl;
    else
        cout << "ano nao bissexto" << endl;
}

void binario(){
    int num, vetor[32]={0}, i=0;
    cin >> num;
    if(num==0)
        cout << "0" << endl;
    else{
        while(num>0){
            vetor[i]=num%2;
            num/=2;
            i++;
        }
    }
    for(i; i>=0; i--){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

bool validar(string senha){
    bool maiscula=false, minuscula=false, numeros=false;
    char validar={0};
    if(senha.length()<8)
        return false;
    else{
        for(int i=0; i<senha.length(); i++){
            validar=senha[i];
            if(validar>='A'&& validar<='Z')
                maiscula=true;
            
            else if(validar>='a' && validar<='z')
                minuscula=true;
            
            else if(validar>='0'&& validar<='9')
                numeros=true;
            
            if(numeros && maiscula && minuscula)
                return true;
        }
    }
    return false;
}

double juroscompostos(double valor){
    int tempo;
    double porcentagem, juros;
    cin >> juros >> tempo;
    juros=(juros/100)+1;
    valor=valor*(pow(juros, tempo));
    return valor;
}

void ordenarinteiros(){
    int i, j, x, vetor[TAM];
    for(int i=0; i<TAM; i++){
        cin >> vetor[i];
    }
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            if(vetor[j+1]<vetor[j]){
                x=vetor[j+1];
                vetor[j+1]=vetor[j];
                vetor[j]=x;
            }
        }
    }
    for(i=0; i<TAM; i++){
        cout << vetor[i] << " ";
    }
}