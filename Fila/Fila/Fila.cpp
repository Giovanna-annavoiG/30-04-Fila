#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* inicio = NULL;
NO* fim = NULL;

// headers
void menu();
void inicializar();
void insere();
void remove();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4) {
		system("cls"); // somente no windows
		cout << "Menu Fila";
		cout << endl << endl;
		cout << "1 - Inicializar Fila \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Remover elemento  \n";
		cout << "4 - Sair \n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:insere();
			break;
		case 3: remove();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = inicio;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	inicio = NULL;
	fim = NULL;
	cout << "Fila inicializada \n";

}


void insere()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO)); //1o: Criamos um espaço na memoria para armazenar o novo elemento na fila
	if (novo == NULL) //2o verifica se não há memoria disponivel
	{
		return;
	}

	cout << "Digite o elemento: "; //3o pede para o usuario inserir
	cin >> novo->valor; //4o Armazena o elemento inserido na variavel valor  do nó NOVO
	novo->prox = NULL; // 5o colocando o PROX como null pois é o ultimo da fila	

	if (inicio == NULL) { //se a fila estiver vazia
		inicio = novo; // novo é o primeiro
		fim = novo; // e o ultimo
		// portanto colocamos o elemento na fila
	}
	else {
		// se ja tem elemento na fila, adicionamos o novo ao final da fila
		fim->prox = novo; //Adicionar o novo no final da fila 
		fim = novo; // O ultimo é o elemento que é novo
	}


}

void remove()
{
	if (inicio == NULL) { //Se a lista for vazia
		cout << "Lista vazia. \n";
	}

	NO* aux = inicio; // coloca o inicio em uma variavel aux

	inicio = inicio->prox; //proximo vai ser armazenado no inicio

	free(aux); //liberar memoria
	cout << "Elemento removido. \n";
	if (inicio == NULL) { //verifica se tem algum elemento na fila
		fim = NULL;
	}


}

