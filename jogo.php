<?php

function printTabuleiro($tabuleiro, $tam) {
    echo "    1  2  3  \n";
    echo "  ----------\n";
    for($i = 0; $i < $tam; $i++) {
        echo($i+1)."| ";
        for($j = 0; $j < $tam; $j++) {
            echo "[" . $tabuleiro[$i][$j] . "]";
        }
        echo "\n";
    }
}

function criaTabuleiro($tam) {
    $tabuleiro = array();
    for($i = 0; $i < $tam; $i++) {
        $tabuleiro[$i] = array();
        for($j = 0; $j < $tam; $j++) {
            $tabuleiro[$i][$j] = ' ';
        }
    }
    return $tabuleiro;
}

function verificaGanhador($tabuleiro, $tam) {
    for($i = 0; $i < $tam; $i++) {
        if($tabuleiro[$i][0] == $tabuleiro[$i][1] && $tabuleiro[$i][1] == $tabuleiro[$i][2] && $tabuleiro[$i][0] != ' ') {
            return $tabuleiro[$i][0];
        }
    }
    for($j = 0; $j < $tam; $j++) {
        if($tabuleiro[0][$j] == $tabuleiro[1][$j] && $tabuleiro[1][$j] == $tabuleiro[2][$j] && $tabuleiro[0][$j] != ' ') {
            return $tabuleiro[0][$j];
        }
    }
    if($tabuleiro[0][0] == $tabuleiro[1][1] && $tabuleiro[1][1] == $tabuleiro[2][2] && $tabuleiro[0][0] != ' ') {
        return $tabuleiro[0][0];
    }
    if($tabuleiro[0][2] == $tabuleiro[1][1] && $tabuleiro[1][1] == $tabuleiro[2][0] && $tabuleiro[0][2] != ' ') {
        return $tabuleiro[0][2];
    }
    return ' ';
}

function tabuleiroEmpate($tabuleiro, $tam) {
    for($i = 0; $i < $tam; $i++) {
        for($j = 0; $j < $tam; $j++) {
            if($tabuleiro[$i][$j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

$tam = 3;
$tabuleiro = criaTabuleiro($tam);
$playerX = true;
$linha = 0;
$coluna = 0;
$vencedor = ' ';
$jogoFinal = false;

echo "----------JOGOZIN DA VELHA----------\n\n";

while(!$jogoFinal) {
    printTabuleiro($tabuleiro, $tam);
    
    if($playerX) {
        echo "Jogador X \n Digite a linha: ";
        $linha = fgets(STDIN);
        echo "Digite a coluna: ";
        $coluna = fgets(STDIN);
    } else {
        echo "Jogador O \n Digite a linha: ";
        $linha = fgets(STDIN);
        echo "Digite a coluna: ";
        $coluna = fgets(STDIN);
    }
    
    if($linha < 1 || $linha > $tam || $coluna < 1 || $coluna > $tam || $tabuleiro[$linha - 1][$coluna - 1] != ' ') {
        echo "Jogada inválida! Tente novamente.\n";
        continue;
    }
    
    if($playerX) {
        $tabuleiro[$linha-1][$coluna-1] = 'X';
    } else {
        $tabuleiro[$linha-1][$coluna-1] = 'O';
    }
    
    $vencedor = verificaGanhador($tabuleiro, $tam);
    
    if($vencedor != ' ') {
        printTabuleiro($tabuleiro, $tam);
        echo "Jogador " . $vencedor . " ganhou esse trem!\n";
        $jogoFinal = true;
    } else if(tabuleiroEmpate($tabuleiro, $tam)) {
        printTabuleiro($tabuleiro, $tam);
        echo "EMPATE!\n";
        $jogoFinal = true;
    }
    
    $playerX = !$playerX;
}
?>
