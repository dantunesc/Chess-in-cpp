# Chess-in-cpp
The Chess in C++
⇨ OBSERVAÇÕES: 
   - Para um melhor aproveitamento do programa, execute o código no sistema operacional do Windows, pela utilização de bibliotecas de cores e outros adicionais do programa.
    - De preferência, no prompt de comando, não utilize tela cheia para melhor experiência!
    - Como dito anteriormente no Intuito, este jogo tem a opção de ser mais dinâmico ou mais lento, conforme suas necessidades. Inspirado em um minigame de “It takes two”, o The Chess foi feito para que possa estimular as jogadas rápidas em detrimento da estratégia ou o contrário.
    - Para compilar e criar um arquivo executável do programa no Prompt de Comando após ser baixado, basta utilizar este formato: "g++ nomedoarquivo.cpp -o nomedoarquivo.exe" e em seguida: "nomedoarquivo.exe" para executar.
    - Evite fechar o The Chess fechando a aba, procure sempre fecha-lo no menu ou apertando Q após efetuar uma jogada.
   
  ⇨ MENU: 
O menu do game contém 5 opções, dentre elas: Iniciar uma Partida, Abrir uma Partida, Mudar Limite de Tempo, Regras e Fechar o Game.
      
1 - Iniciar uma Partida: Esta opção consiste em começar uma nova partida, digitando os nomes dos jogadores para armazenamento caso ela seja interrompida e salvando os movimentos dos jogadores (Maiúsculas: Brancas e Minúsculas: Pretas), lembrando que as Brancas sempre começam e a Rainha "escolhe sua casa". ;)
      
2 - Abrir uma Partida: Esta opção consiste em resgatar as jogadas feitas de uma partida interrompida no meio quando salva, conta ainda com um salvamento sem a especificação do formato de arquivo, já feita em .txt pelo próprio programa para que os usuários tenham menos trabalho e digite apenas o nome que deseja para o arquivo.
    
3 - Mudar Limite de Tempo: Esta opção é uma novidade para o xadrez que vem com este game, consiste em aumentar ou diminuir o tempo de limite para as jogadas de cada player, podendo dificultar ou facilitar a partida, tendo em vista que a menor quantidade de tempo obriga os jogadores a pensar de forma mais rápida e estimula o raciocínio lógico!
   
4 - Regras: Esta opção consiste em uma pequena aba contendo regras e outras informações cruciais para o funcionamento do programa conforme seu intuito e fluidez das partidas.
       
5 - Fechar o Game: Esta opção, quando acionada, fechará o game.

⇨ COMO FUNCIONA UMA PARTIDA NO THE CHESS:
       	
Assim que for escolhida a opção 1, o usuário deverá inserir o nome de dois jogadores, Peças Brancas (Maiúsculas) e Peças Pretas (Minúsculas), respectivamente, logo após iniciará a primeira rodada em que cada jogador terá um limite de tempo para jogadas (o default é 300 segundos) em que eles terão ao todo para executar uma partida, portanto, caso demore em uma rodada, é melhor acelerar na próxima! 

É possível alterar este limite de tempo na opção 3 (caso queira deixar a duração oficial de xadrez ou queira uma partida rápida), como já ressaltado anteriormente no tópico MENU.

 Preenchidas as configurações conforme as preferências dos usuários, será printado na tela o tabuleiro para que possa auxiliar na escolha das jogadas e sincronizar os movimentos escolhidos pelos usuários, para efetuar a movimentação de alguma peça, haverá números de indicações para movimentação na combinação de escolhas de uma linha e uma coluna para escolher a peça desejada para mover, após escolhida a peça, serão printados no tabuleiro "x" (em casas vazias) para indicar as casas que a peça pode ocupar após a movimentação desejada, escolha a casa com “x” ou onde está uma peça inimiga que está disponível para comer, movida mais uma vez por uma combinação de linha e coluna. 

Caso o player não saiba sobre a movimentação das peças, basta visitar a opção 4 do MENU, já citada anteriormente no tópico MENU!

 Para aqueles que insistirem em jogar sem conhecimento da movimentação das peças, haverá o tratamento desses erros para não atrapalhar a fluidez da partida. Portanto, aparecerá na tela que a jogada foi inválida e terá que jogar novamente!

 Sempre após a jogada de escolha do usuário ser executada aparecerá a opção de salvamento desta partida após o usuário pressionar "Q", caso o usuário queira interrompe-la no meio, o arquivo contendo as jogadas fará parte da mesma pasta em que foi baixado o game, podendo ser acessado por lá mesmo ou pelo game, tendo em vista que foi criada a opção 2 com este intuito, como já citada anteriormente no tópico MENU. Caso não queira salvar, basta apenas continuar a partida digitando qualquer outra tecla. 


