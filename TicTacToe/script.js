const tabuleiro = [['', '', ''], ['', '', ''], ['', '', '']];
let jogadorAtual = 'X';
let jogoFinalizado = false;

function fazerJogada(linha, coluna) {
  if (!jogoFinalizado && tabuleiro[linha][coluna] === '') {
    tabuleiro[linha][coluna] = jogadorAtual;
    document.getElementById('tabuleiro').children[linha * 3 + coluna].innerText = jogadorAtual;

    if (verificarVitoria()) {
      document.getElementById('tabuleiro').style.pointerEvents = 'none';
      jogoFinalizado = true;
      alert(`Jogador ${jogadorAtual} ganhou esse trem!`);
    } else if (verificarEmpate()) {
      jogoFinalizado = true;
      alert('Um pior q o outro, empatou esse trem!');
    } else {
      jogadorAtual = jogadorAtual === 'X' ? 'O' : 'X';
    }
  }
}

function verificarVitoria() {
  for (let i = 0; i < 3; i++) {
    if (tabuleiro[i][0] === jogadorAtual && tabuleiro[i][1] === jogadorAtual && tabuleiro[i][2] === jogadorAtual) {
      return true;
    }
    if (tabuleiro[0][i] === jogadorAtual && tabuleiro[1][i] === jogadorAtual && tabuleiro[2][i] === jogadorAtual) {
      return true;
    }
  }
  if (tabuleiro[0][0] === jogadorAtual && tabuleiro[1][1] === jogadorAtual && tabuleiro[2][2] === jogadorAtual) {
    return true;
  }
  if (tabuleiro[0][2] === jogadorAtual && tabuleiro[1][1] === jogadorAtual && tabuleiro[2][0] === jogadorAtual) {
    return true;
  }
  return false;
}

function verificarEmpate() {
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      if (tabuleiro[i][j] === '') {
        return false;
      }
    }
  }
  return true;
}
