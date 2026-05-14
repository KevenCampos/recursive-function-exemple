#include <iostream>           // Para usar a lib std
#include <cmath>              // Para usar a função round (arredondar numero)

/*
    Vamos usar o namespace std para poder omitir o std:: antes das chamadas das função
    da biblioteca std (cin, cout ..)
*/
using namespace std;

double CalculateFineAmount(int daysLate, float fineAmount, float taxPerDayPercent)
{
    /*
        Vamos verificar se o dia atual é menor ou igual a 0, 
    */
    if (daysLate <= 0)
    {
        /*
            Quando o código chegar aqui, significa que já somou o juros de todos os dias
            então vamos retornar o valor final já arredondado até a segunda casa decimal
        */
        double roundedAmount = round(fineAmount * 100) / 100;
        return roundedAmount;
    }
    else
    {
        /*
            Vamos remover um dia dos dias de atraso e vamos modificar a variavel "fineAmount",
            acrescentado o juros do dia atual. Após isso, com os novos valores de "fineAmount" e "daysLate"
            vamos chamar essa mesma função novamente, para repetir o mesmo ciclo mas para o proximo dia.
        */
        daysLate = daysLate - 1;
        fineAmount = fineAmount + ((taxPerDayPercent/100) * fineAmount);
        return CalculateFineAmount(daysLate, fineAmount, taxPerDayPercent);
    }
}


int main() {
    /*
        Vamos definir as variaveis que vamos preencher através da resposta do usuário
    */
    float fineAmount, taxPerDayPercent;
    int daysLate;

    /*
        Limpa o console das mensagens anteriores para ter uma experiencia mais limpa
    */
    system("cls");

    /*
        Realiza as perguntas ao usuário e atribui os respectivos valores as variaveis
    */
    cout << "Qual valor da multa ? ( R$ )\n";
    cin >> fineAmount;

    cout << "Quantos dias de atraso ?\n";
    cin >> daysLate;

    cout << "Qual a porcentagem de juros por dia de atraso ?\n";
    cin >> taxPerDayPercent;

    /*
        Chama a função recursiva e exibe o resutado como resposta para o usuário
    */
    double amountWithFine = CalculateFineAmount(daysLate, fineAmount, taxPerDayPercent);
    cout << "\nValor da multa com a taxa de atraso: R$" << round(amountWithFine * 100) / 100 <<  "\n";

    /*
        Encerra o código retornano 0 para indicar que o programa executou sem erro.
    */
    return 0;
}