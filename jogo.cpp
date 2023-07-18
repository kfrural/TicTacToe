#include <iostream>

using namespace std;

void printTabuleiro(char** tabuleiro, int tam){
    cout << "    1  2  3  \n";
    cout << "  ----------\n";
    for(int i = 0; i < tam; i++){
        cout<<i+1<<"| ";
        for(int j = 0; j < tam; j++){
            cout << "[" << tabuleiro[i][j] << "]";
        }
        cout << "\n";
    }
}

char** criaTabuleiro(int tam){
    char** tabuleiro = new char* [tam];
    for(int i = 0; i < tam; i++){
        tabuleiro[i] = new char[tam];
        for(int j = 0; j < tam; j++){
            tabuleiro[i][j] = ' ';
        }
    }
    return tabuleiro;
}

int main(){
    int tam = 3;
    char** tabuleiro = criaTabuleiro(tam);
    bool playerX = true;
    int linha = 0;
    int coluna = 0;
    
    cout << "----------JOGOZIN DA VELHA----------\n\n";
    
    printTabuleiro(tabuleiro, tam);
    

    return 0;
}
