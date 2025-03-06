#include <stdio.h>
#include <stdlib.h>

// Variáveis globais para armazenar os totais de cada categoria e o troco total
float totalMaterialLimpeza = 0.0;
float totalAlimentos = 0.0;
float totalPadaria = 0.0;
float totaldoDIA = 0.0;
float viewMenu = 0.0;
int numeroClientes = 0;

// Função para exibir o menu principal
void exibirMenu() {
    system("cls"); 
    printf(" ___________________________________ \n");
    printf("|  BEM VINDO(A) A MERCEARIA DA BERE |\n");
    printf("|           MENU PRINCIPAL          |\n");
    printf("|___________________________________|\n");
    printf("|      1- Material de Limpeza       |\n");
    printf("|      2- Venda de Alimentos        |\n");
    printf("|      3- Padaria                   |\n");
    printf("|      4- Pagamento                 |\n");
    printf("|      5- Sair/Exit                 |\n");
    printf("|-----------------------------------|\n");
    printf("|Escolha uma opcao:");
}

// Função ao prescionar a tecla 5 e finalizar o sistema
void encerrarSistema(){
    system("cls");
    printf(" _____________________________________ \n");
    printf("| ENCERRANDO O SISTEMA.......         |\n");
    printf("| POR FAVOR NAO DESLIGUE O COMPUTADOR.|\n");
    printf("|_____________________________________|\n");
    printf("| Faturamento do dia: R$%.2f\n", totaldoDIA);
    printf("| Total de vendar do dia:%d\n", numeroClientes);
}

// Função para processar a compra de um item e armazenar na vairavel global
void processarCompra(float preco, float *totalCategoria) {
    int quantidade;
 
    printf("Digite a quantidade:");
    // while se caso o usuario colocar uma letra ou simbolo..ira ficar no loop  
    while(scanf("%d", &quantidade)!= 1){
        printf("Valor invalido! pressione enter e tente novamente\n");
        limpabuffer();
        getchar();
        return;
     }
    if (quantidade <= 0){
        printf("Nenhuma quantidade foi debitada! por favor pressione enter e escolha novamente:\n");
       limpabuffer();
        getchar();
        getchar();
        return;
}
      else if (quantidade >= 1001){
       printf("Quantidade insuficiente! Maximo 1000 unid por vez..pressione enter e escolha novamente:\n");
       limpabuffer();
       getchar();
    return;
}
    else {
            float subtotal = quantidade * preco;
            *totalCategoria += subtotal;
            viewMenu += subtotal;
    

}
  
}
// Função para o menu de Material de Limpeza junto com processar compras....
void menuMaterialLimpeza() {

    int opcao;
    viewMenu += totalMaterialLimpeza;
do{
   
    system("cls"); 
    printf(" _____________________________________________\n");
    printf("|      MENU MATERIAL DE LIMPEZA               |\n");
    printf("|_____________________________________________|\n");
    printf(" TOTAL DO CARRINHO: R$%.2f\n", viewMenu);
    printf(" _____________________________________________\n");
    printf("| [11]     Detergente                 R$1.99  |\n");
    printf("| [12]     Sabao em Po(1Kg)           R$8.99  |\n");
    printf("| [13]     Esponja                    R$1.50  |\n");
    printf("| [14]     Amaciante(1Lt)             R$15.00 |\n");
    printf("| [15]     VOLTAR AO MENU PRINCIPAL           |\n");
    printf("|_____________________________________________|\n");
    printf(" Escolha um item:");
    scanf("%d", &opcao);
        

switch (opcao) {
    // Aqui entra a função processarCompra que faz o calculo de quantos itens foram escolhidos 
    case 11: processarCompra(1.99, &totalMaterialLimpeza); break;
    case 12: processarCompra(8.99, &totalMaterialLimpeza); break;
    case 13: processarCompra(1.50, &totalMaterialLimpeza); break;
    case 14: processarCompra(15.00, &totalMaterialLimpeza); break;
    case 15: break;
    default: 
    limpabuffer();
    printf("Opcao invalida: pressione enter\n");
    getchar();
    }
    } while (opcao != 15);
}

// Função para o menu de Alimentos..
void menuAlimentos() {
    int opcao;
do {
    system("cls"); 
    printf(" _____________________________________________\n");
    printf("|      MENU VENDA DE ALIMENTOS                |\n");
    printf("|_____________________________________________|\n");
    printf(" TOTAL DO CARRINHO: R$%.2f\n", viewMenu);
    printf(" _____________________________________________ \n");
    printf("| [21]      Cafe                      R$19.99 |\n");
    printf("| [22]      Leite(cx)                 R$5.90  |\n");
    printf("| [23]      Arroz(1Kg)                R$4.50  |\n");
    printf("| [24]      Feijao Preto(1Kg)         R$8.00  |\n");
    printf("| [25]      Acucar(1Kg)               R$5.00  |\n");
    printf("| [26]      VOLTAR AO MENU PRINCIPAL          |\n");
    printf("|_____________________________________________|\n");
    printf(" Escolha um item:");
    scanf("%d", &opcao);

switch (opcao) {
    case 21: processarCompra(19.99, &totalAlimentos);break;
    case 22: processarCompra(5.90, &totalAlimentos); break;
    case 23: processarCompra(4.50, &totalAlimentos); break;
    case 24: processarCompra(8.00, &totalAlimentos); break;
    case 25: processarCompra(5.00, &totalAlimentos); break;
    case 26: break;
    default: 
    limpabuffer();
    printf("Opcao invalida: pressione enter\n");
    getchar();
    
    }
    } while (opcao != 26);
}

// Função para o menu da Padaria..
void menuPadaria() {
    int opcao;
do {
   
    system("cls"); 
    printf(" _____________________________________________ \n");
    printf("|             MENU PADARIA                    |\n");
    printf("|_____________________________________________|\n");
    printf(" TOTAL DO CARRINHO: R$%.2f\n", viewMenu);
    printf(" _____________________________________________|\n");
    printf("| [31]     Pao de Forma               R$9.50  |\n");
    printf("| [32]     Pao Integral               R$12.50 |\n");
    printf("| [33]     Pao Frances(Unid)          R$1.90  |\n");
    printf("| [34]     Sonho                      R$8.50  |\n");
    printf("| [35]     VOLTAR AO MENU PRINCIPAL           |\n");
    printf("|_____________________________________________|\n");
    printf(" Escolha um item:");
    scanf("%d", &opcao);

switch (opcao) {
    case 31:processarCompra(9.50, &totalPadaria);break;
    case 32:processarCompra(12.50, &totalPadaria); break;
    case 33: processarCompra(1.90, &totalPadaria); break;
    case 34: processarCompra(8.50, &totalPadaria); break;
    case 35: break;
    default: 
    limpabuffer();
    printf("Opcao invalida! pressione enter:\n");
    getchar();
    }
    } while (opcao != 35);
}

// Função para processar o pagamento e calcular o total geral..
void pagamento() {
    system("cls");
float totalgeral = totalMaterialLimpeza + totalAlimentos + totalPadaria;
    int metodoPagamento;
    
    printf("\n==== Pagamento ====\n");
    printf("Total geral: R$%.2f\n", totalgeral);
if (totalgeral == 0) {
    printf("Nenhuma compra foi realizada! pressione enter para voltar ao menu:\n");
    getchar();
    getchar();
return;
    }
    printf("\nEscolha a forma de pagamento:\n");
    printf("1. Dinheiro (com desconto)\n");
    printf("2. Cartao\n");
    scanf("%d", &metodoPagamento);

if (metodoPagamento == 1) {  
    float desconto = 0.0;
if (totalgeral <= 50.00) {
 desconto = totalgeral * 0.05;
}
else if (totalgeral < 100.00) {
desconto = totalgeral * 0.10;
} else {
desconto = totalgeral * 0.18;
}

 float totalComDesconto = totalgeral - desconto;
 float valorRecebido, troco;
 

   printf("Total a pagar com desconto: R$%.2f\n", totalComDesconto);

do {
   printf("Digite o valor recebido: ");
   scanf("%f", &valorRecebido);
   limpabuffer();


if(valorRecebido < totalComDesconto){
   printf("Valor insuficiente! Digite novamente.\n");


}
}while (valorRecebido < totalComDesconto);
  troco = valorRecebido - totalComDesconto;
   printf("Troco: R$%.2f\n", troco);
   esperaopagamento();
       
}else if (metodoPagamento == 2) {  // Pagamento por cartão
   int confirmacao;
    printf("Pagamento na maquina realizado? (1 - Sim, 0 - Não): ");
    scanf("%d", &confirmacao);

if (confirmacao != 1) {
    printf("Pagamento nao concluído. Escolha outra forma de pagamento.\n");
    getchar();
    getchar();
    pagamento();  // Chama a função novamente para tentar outro pagamento
return;

}

}else {
   
    printf("Opcao invalida! Escolha novamente.\n");
    getchar();
    getchar();
   pagamento();
} 
    totaldoDIA += totalgeral;
    numeroClientes++;
// Zera as variaveis  totais após o pagamento ser concluído
    totalMaterialLimpeza = 0.0;
    totalAlimentos = 0.0;
    totalPadaria = 0.0;
    viewMenu = 0.0;   
}

// Função para passar para o proximo cliente.. 
void esperaopagamento(){
    printf("Pagamento concluido! aperte enter para finalizar seu atendimento.\n");
    getchar();
    getchar();
}

// Função para limpar o buffer do teclado.
void limpabuffer(){
    int letra;
    while((letra = getchar()) != '\n' && letra != EOF );
}

//Ponto inicial do codigo.. 
int main() {

int opcao;
    viewMenu = 0.0;//zerando o view menu cada vez que inica o codigo novamente.
do {
    exibirMenu();
    scanf("%d", &opcao);

switch (opcao) {
    case 1: menuMaterialLimpeza(); break;
    case 2: menuAlimentos(); break;
    case 3: menuPadaria(); break;
    case 4: pagamento(); break;
    case 5: encerrarSistema();break;
    default://caso nao for nenhuma delas.....
    limpabuffer();
    printf("Opcao invalida! pressione enter e Tente novamente.\n");
    getchar();
}
}while(opcao != 5);
return 0;
}