# Calendario
A questão 03 se tratava de fazer um calendário, recebendo como entrada um ano em que o usuário deseja ver, e dado a entrada, mostrar o ano inteiro.
O maior problema com este código, com a lógica do código, foi conseguir fazer a folha de calendário assumindo que o ano é bissexto algumas vezes, e também a dificuldade com o início de cada mês. Para isso foi primeiramente feito a função bissexto (int ano). Nela é calculado se o ano digitado é bissexto ou não. Posteriormente foi feito o calculo usando a congruência de Zeller, cálculo este que serve para descobrir o dia da semana.
Depois, temos de assumir os meses com seus respectivos números, e para isso usamos a função imprimeCalendario(int ano), ela só recebe o ano, porém dentro do for de 1 a 12 que corresponde aos meses, já entra a função descobrirMes(int mês), que recebe o mês que está dentro do for como parâmetro, quando mês = 1, mês = Janeiro, e assim por diante.
Depois foi pensado o método para declarar até que dia vai cada mês, para isso foi usado a função calcularQuantDias(int ano, int mês), que também recebe como parâmetro os meses de 1 a 12 da função imprimeCalendario, e usa – se operadores lógicos para assumir os dias. Há também o caso especifico de fevereiro, que pode ter 28 ou 29 dias, dai que vem a função bissexto(int ano), é testado se a função retornar 1, caso retorne, fevereiro tem 29 dias, pois o ano é bissexto.
Por ultimo faltava apenas imprimir, já que todos os problemas tinham sido resolvidos, foi usado o for de 1 a 12 para percorrer os meses, uma saída na tela com os dias da semana para usar de referência para alinhar, depois usado uma saída com 4 espaços na tela (“    “) que servia para pular para o outro espaço embaixo de algum dia da semana, esse espaço foi dado pelo for de 0 até um dia da semana antes do que foi calculado. Por fim foi usado o for para imprimir os dias de acordo com a quantidade de dias de cada mês, e usamos a quebra de linha para alinhar o calendário bonitinho, usando a operação % 7 no dia da semana.
O main foi bem simples, apenas recebe o ano, executar a função principal que é para imprimir e fazer um teste se é maior que 1582, pois foi onde começou o calendário gregoriano.

// Referencia:

Para a congruência de zeller em programação:
https://www.geeksforgeeks.org/zellers-congruence-find-day-date/
