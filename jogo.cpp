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

char verificaGanhador(char** tabuleiro, int tam){
    for(int i = 0; i < tam; i++){
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' '){
            return tabuleiro[i][0];
        }
    }
    for(int j = 0; j < tam; j++){
        if(tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j] && tabuleiro[0][j] != ' '){
            return tabuleiro[0][j];
        }
    }
    
    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' '){
        return tabuleiro[0][0];
    }
    if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' '){
        return tabuleiro[0][2];
    }
    
    return ' ';
}

bool tabuleiroEmpate(char** tabuleiro, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(tabuleiro[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int tam = 3;
    char** tabuleiro = criaTabuleiro(tam);
    bool playerX = true;
    int linha = 0;
    int coluna = 0;
    char vencedor;
    bool jogoFinal = false;
    
    cout << "----------JOGOZIN DA VELHA----------\n\n";
    
    do{
        printTabuleiro(tabuleiro, tam);
        
        if(playerX){
            cout << "Jogador X \n Digite a linha: ";
            cin >> linha;
            cout << "Digite a coluna: ";
            cin >> coluna;
        }else{
            cout << "Jogador O \n Digite a linha: ";
            cin >> linha;
            cout << "Digite a coluna: ";
            cin >> coluna;
        }
        if(linha < 1 || linha > tam || coluna < 1 || coluna > tam || tabuleiro[linha - 1][coluna - 1] != ' '){
            cout << "Jogada inválida! Tente novamente.\n";
            continue;
        }
        if(playerX){
            tabuleiro[linha-1][coluna-1] = 'X';
        } else {
            tabuleiro[linha-1][coluna-1] = 'O';
        }
        vencedor = verificaGanhador(tabuleiro, tam);
        if(vencedor != ' '){
            printTabuleiro(tabuleiro, tam);
            cout << "Jogador " << vencedor << " ganhou esse trem!\n";
            jogoFinal = true;
        }else if(tabuleiroEmpate(tabuleiro, tam)){
            printTabuleiro(tabuleiro, tam);
            cout << "EMPATE!\n";
            jogoFinal = true;
        }
        playerX = !playerX;
    }while(!jogoFinal);
    

    return 0;
}
