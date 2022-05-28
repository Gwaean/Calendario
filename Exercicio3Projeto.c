#include<stdio.h>


int bissexto(int ano){
    if((ano % 4 == 0 && ano % 100 != 0)|| ano % 400 == 0)
        return 1;
    else
        return 0;

        //Função para Verificar se o ano é Bissexto

}

//Executando a congruencia de Zeller para descobrir o dia da semana em que o Mes em questão começou
int diaSemana(int mes ,int ano)
{
    int res,i, dia =1,k,j,d;

    if(mes == 1){
        mes = 13;
        ano --;
    }
    //Na congruencia de Zeller Segunda corresponde ao mes 13 e Fevereiro ao mes 14 do ano seguinte.
    // Exemplo dia 01/01/2019 seria como 01/14/2018.

    //Referencia do site https://www.geeksforgeeks.org/zellers-congruence-find-day-date/

    if(mes == 2){
        mes = 14;
        ano --;
    }

        k = ano % 100;
        j = ano/100;

        res = (dia+(((mes+1)*13)/5)+k+(k/4)+(j/4)+5*j)%7;
        res--;//Decrementei o res pois estava sempre ficando um dia a mais do que o devido,
        //Então apenas decrementei para ficar no dia certo.


        return res;
}

void imprimeCalendario(int a){
    int mes,dia,i,diaS;

    for(mes=1;mes<=12;mes++){ //Percorrer os 12 meses no for
        printf(" %d\n\n\nDom Seg Ter Qua Qui Sex Sab\n\n\n", a,(descobrirMes(mes))); // Aqui imprimimos o o ano, os dias da semana e o mes
        diaS = diaSemana(mes,a); //Variavel diaS recebe a função dia da semana
        for(i = 0;i < diaS; i++)   // Nesse trecho ele usa a função do dia da semana, percorrendo os dias vazios
            printf("    ");     //e coloca 4 espaços(DOM )tem 4 espaços. até chegar ao dia da semana correspondente.

        //Imprimir os dias
        for (dia=1;dia<=calcularQuantDias(a, mes);dia++){//Usamos a função para ver quantos dias tem o mes que estamos imprimindo.
            printf("%2d  ", dia); //Usa os 2 ultimos espaços para por o numero do dia, ou seja o numero fica no meio
            diaS++;//Incrementa até chegar ao final, embaixo do sabado
            if(diaS % 7 == 0)//Quebra uma linha logo quando o s chegar em 7,14,21,28, ou seja, chegar ao sabado pois é a setima posição.
                printf("\n\n");
        }
    }


}

void descobrirMes(int mes){//Função somente para determinar o mes pelo numero.
        if(mes == 1)
            printf("\n\n          Janeiro");
        if(mes == 2)
            printf("\n\n          Fevereiro");
        if(mes == 3)
            printf("\n\n          Marco");
        if(mes == 4)
            printf("\n\n          Abril");
        if(mes == 5)
            printf("\n\n          Maio");
        if(mes == 6)
            printf("\n\n          Junho");
        if(mes == 7)
            printf("\n\n          Julho");
        if(mes == 8)
            printf("\n\n          Agosto");
        if(mes == 9)
            printf("\n\n          Setembro");
        if(mes == 10)
            printf("\n\n          Outubro");
        if(mes == 11)
            printf("\n\n          Novembro");
        if(mes == 12)
            printf("\n\n          Dezembro");

    }

int calcularQuantDias(int ano, int mes){//Função para determinar pelo numero do mes, quantos dias tem o mes correspondente.
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        return 31;
    else
        if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
            return 30;
        if(mes == 2){
            if(bissexto(ano) == 1)
                return 29;
            else
                return 28;
        }


}

int main(){
    int a,m;
    printf("Informe o Ano Que deseja ver: \n");
    scanf("%d", &a);


    if(a < 1583){
        printf("Informe uma data acima de 1582");//Quando começou o calendario gregoriano.
        exit(0);
    }

    imprimeCalendario(a);//Tudo que precisa ser verificado esta dentro da funcção imprimeCalendario, então chamamos apenas ela
    //para imprimir o calendario normalmente.


}
