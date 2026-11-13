#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio2.h>
#include <stdlib.h>
#include <windows.h>

//Structs
struct TpClientes {
	char CPF[16], Nome[50], Telefone[15];
	char Status;
};

struct TpCarros {
	int Cod;
	char Modelo[20], Categoria[10], Status;
	float PrecoDiaria;
};

struct TpLocacoes {
	int CodCarroL, QtdeDias;
	char CPFL[16], Status;
	float ValorLocacao;
};

//Protótipos
void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF);
void Inicio(void);
void LimparTela(void);
void LimparTela2(int linha);
char MenuEscolha(void);
char MenuClientes(void);
char MenuCarros(void);
char MenuLocacoes(void);
char MenuRelatorios(void);
int BuscaExaustiva(FILE *Ptr, int Elem);
int BuscaExaustivaLocacao(FILE *Ptr, int TL, int Cod);
int BuscaClienteEcod(FILE *Ptr, char AuxCPF[16], int AuxCod);
int SequencialIndexada(FILE *Ptr, char Elem[16]);
int BuscaSentinela(FILE *Ptr, int Elem);
int BuscaBinariaCod(FILE *Ptr, int Cod);
int BuscaBinariaCPF(FILE *Ptr, char CPF[16]);
int SequencialIndexadaLocacao(FILE *Ptr, char Elem[16]);
int BuscaBinariaCodLocacao(FILE *Ptr, int AuxCod);
void InserctionSort(FILE *Ptr);
void SelectionSort(FILE *Ptr);
void BubbleSort(FILE *Ptr);
void InserctionSortLocacao(FILE *Ptr);
void CadCliente();
void ExclusaoClientes();
void AlterarClientes();
void ListagemClientes();
void CadCarro();
void ExclusaoCarros();
void AlterarCarros();
void ListagemCarros();
void OrdenarCodSelection();
void OrdenarModeloBubble();
void CadLocacao();
void ExclusaoLocacao();
void AlterarLocacao();
void ListagemLocacao();
void RelaA();
void RelaB();
void RelaC();
void RelaD();
void ExclusaoFisicaClientes();
void ExclusaoFisicaCarros();
void ExclusaoFisicaLocacoes();


void Moldura(int CI, int LI, int CF, int LF, int CorT, int CorF)
{
	int i;
	textcolor(CorT);
	textbackground(CorF);
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	
	for(i=CI+1; i<CF; i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		
		gotoxy(i,LF);
		printf("%c",205);
	}
	
	for(i=LI+1; i<LF; i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		
		gotoxy(CF,i);
		printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void Inicio(void)
{	
	gotoxy(33,3); printf("TRABALHO ATP 2");
	Moldura(1,1,80,25,9,3);
	Moldura(2,2,79,4,3,7);
	Moldura(31,5,79,24,3,7);
	Moldura(2,5,30,24,3,7);
}

void LimparTela(void)
{
	int i;
	for(i=6;i<24;i++)
	{
		gotoxy(32,i);printf ("                                               ");
	}
	
}

void LimparTela2(int linha)
{
	int i;
	for(i=linha;i<24;i++)
	{
		gotoxy(32,i);printf ("                                               ");
	}
	
}

char MenuEscolha(void)
{
	LimparTela();
	gotoxy(46,13); printf("ESCOLHA UMA OPCAO!");
	gotoxy(10,7); printf("### MENU ###\n");
	gotoxy(4,9);  printf("[A] Menu Clientes\n");
	gotoxy(4,10);  printf("[B] Menu Carros\n");
	gotoxy(4,11); printf("[C] Menu Locacoes\n");
	gotoxy(8,13); printf("### RELATORIOS ###\n");
	gotoxy(4,15); printf("[D] Menu Relatorios\n");
	gotoxy(4,19); printf("[ENTER] Finalizar\n");
	gotoxy(4,20); printf("e apaguar status != '1'");
	gotoxy(4,22); printf("Opcao: ");
	
	
	return toupper(getch());	
}

char MenuClientes(void)
{
	LimparTela();
	gotoxy(43,7); printf("# # # Menu Clientes # # #\n");
	gotoxy(34,9);  printf("[A] Cadastrar Cliente\n");
	gotoxy(34,10);  printf("[B] Excluir Cliente\n");
	gotoxy(34,11); printf("[C] Alterar Cliente\n");
	gotoxy(34,12); printf("[D] Listagem Cliente\n");
	gotoxy(34,20); printf("[ESC] Voltar\n");
	gotoxy(34,21); printf("Opcao: ");
	
	return toupper(getch());
}

char MenuCarros(void)
{
	LimparTela();
	gotoxy(43,7); printf("# # # Menu Carros # # #\n");
	gotoxy(34,9);  printf("[A] Cadastrar carro\n");
	gotoxy(34,10);  printf("[B] Excluir carro\n");
	gotoxy(34,11); printf("[C] Alterar carro\n");
	gotoxy(34,12); printf("[D] Listagem carro\n");
	gotoxy(34,13); printf("[E] Ordenar por codigo\n");
	gotoxy(34,14); printf("[F] Ordenar por modelo\n");
	gotoxy(34,20); printf("[ESC] Voltar\n");
	gotoxy(34,21); printf("Opcao: ");
	
	return toupper(getch());
}

char MenuLocacoes(void)
{	
	LimparTela();
	gotoxy(43,7); printf("# # # Menu Locacoes # # #\n");
	gotoxy(34,9);  printf("[A] Cadastrar locacao\n");
	gotoxy(34,10); printf("[B] Excluir locacao\n");
	gotoxy(34,11); printf("[C] Alterar locacao\n");
	gotoxy(34,12); printf("[D] Listagem locacoes\n");
	gotoxy(34,20); printf("[ESC] Voltar\n");
	gotoxy(34,21); printf("Opcao: ");
	
	return toupper(getch());
}

char MenuRelatorios(void)
{
	LimparTela();
	gotoxy(43,7); printf("# # # Menu Relatorios # # #\n");
	gotoxy(33,9);  printf("[A] Clientes que realizaram mais de 3 Locacoes\n");
	gotoxy(33,10);  printf("[B] Todos os carros de uma categoria\n");
	gotoxy(33,11); printf("[C] Locacoes que o valor e maior que o limite\n");
	gotoxy(33,12); printf("[D] Relatorio Completo\n");
	gotoxy(33,20); printf("[ESC] Voltar\n");
	gotoxy(34,21); printf("Opcao: ");
	
	return toupper(getch());
}

void CriarArquivos(void)
{
	FILE *PtrClientes = fopen("Clientes.dat","ab");
	fclose(PtrClientes);
	
	FILE *PtrCarros = fopen("Carros.dat","ab");
	fclose(PtrCarros);
	
	FILE *PtrLocacoes = fopen("Locacoes.dat","ab");
	fclose(PtrLocacoes);
}

//-------------------------BUSCAS--------------------------
int BuscaExaustiva(FILE *Ptr, int Elem)
{
	TpCarros aux;
	
	rewind(Ptr);
	fread(&aux,sizeof(TpCarros),1,Ptr);
	
	while (!feof(Ptr) && (aux.Cod != Elem || aux.Status!='1'))
		fread(&aux,sizeof(TpCarros),1,Ptr);
		
	if(aux.Cod == Elem)
		return ftell(Ptr)-sizeof(TpCarros); //Achou
	else
		return -1; //Não Achou
}

int BuscaExaustivaLocacao(FILE *Ptr, int Cod)
{
	TpLocacoes aux;
	
	rewind(Ptr);
	fread(&aux,sizeof(TpLocacoes),1,Ptr);
	
	while (!feof(Ptr) && (aux.CodCarroL != Cod || aux.Status!='1'))
		fread(&aux,sizeof(TpLocacoes),1,Ptr);
		
	if(aux.CodCarroL == Cod)
		return ftell(Ptr)-sizeof(TpLocacoes); //Achou
	else
		return -1; //Não Achou
}

int BuscaClienteEcod(FILE *Ptr, char AuxCPF[16], int AuxCod)
{
	TpLocacoes aux;
	
	rewind(Ptr);
	fread(&aux,sizeof(TpLocacoes),1,Ptr);
	
    while (!feof(Ptr))
    {
        if (stricmp(aux.CPFL,AuxCPF) == 0 && aux.CodCarroL == AuxCod && aux.Status == '1')
            return ftell(Ptr)-sizeof(TpLocacoes); //Achou
        
        fread(&aux,sizeof(TpLocacoes),1,Ptr);
    }

    return -1; //Não achou
}

int SequencialIndexada(FILE *Ptr, char Elem[16])
{	
	TpClientes aux;

	rewind(Ptr);
	fread(&aux,sizeof(TpClientes),1,Ptr);
	while(!feof(Ptr) && (stricmp(aux.CPF,Elem) < 0 || aux.Status!='1'))
		fread(&aux,sizeof(TpClientes),1,Ptr);
	
	if (!feof(Ptr) && stricmp(aux.CPF,Elem)==0)
		return ftell(Ptr) - sizeof(TpClientes); //Achou
	else
		return -1; //Não Achou	
}


int BuscaSentinela(FILE *Ptr, int Elem)
{
	TpCarros aux;
	
	aux.Cod = Elem;
	aux.Status = '1';
	
	fseek(Ptr,0,2);
	int TL = ftell(Ptr);
	fwrite(&aux,sizeof(TpCarros),1,Ptr);
	
	rewind(Ptr);
	
	fread(&aux,sizeof(TpCarros),1,Ptr);
	
	while(aux.Cod != Elem  || aux.Status != '1')	
		fread(&aux,sizeof(TpCarros),1,Ptr);
	
	int achou = ftell(Ptr);
	fseek(Ptr,TL,0);
	aux.Cod = Elem;
	aux.Status = '0';
	fwrite(&aux,sizeof(TpCarros),1,Ptr);
	
	if(achou<=TL)
		return achou; //Achou
	else
		return -1; //Não Achou
}



int BuscaBinariaCod(FILE *Ptr, int Cod)
{
	TpCarros aux;
	fseek(Ptr,0,2);
	int TL = ftell(Ptr) / sizeof(TpCarros);
	
	int inicio=0, meio, final=TL-1;
	meio = final/2;
	
	fseek(Ptr,meio*sizeof(TpCarros),0);
	fread(&aux,sizeof(TpCarros),1,Ptr);
	
	while(inicio < final && (aux.Cod != Cod || aux.Status != '1'))
	{
		if(aux.Cod < Cod)
			inicio = meio+1;
		else
			final = meio-1;
			
		meio = (inicio + final)/2;
		
		fseek(Ptr,meio*sizeof(TpCarros),0);
		fread(&aux,sizeof(TpCarros),1,Ptr);
	}
	
	if (aux.Cod==Cod && aux.Status == '1')
		return ftell(Ptr)-sizeof(TpCarros);
	else
		return -1;
}

int BuscaBinariaCPF(FILE *Ptr, char CPF[16])
{
	TpLocacoes aux;
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpLocacoes);
	
	int inicio=0, meio, final=TL-1;
	meio = final/2;
	
	fseek(Ptr,meio*sizeof(TpLocacoes),0);
	fread(&aux,sizeof(TpLocacoes),1,Ptr);
	
	while(inicio<final && (stricmp(aux.CPFL,CPF)!=0 || aux.Status !='1'))
	{
		if(stricmp(aux.CPFL,CPF)<0)
			inicio = meio+1;
		else
			final = meio-1;
			
		meio = (inicio + final)/2;
		
		fseek(Ptr,meio*sizeof(TpLocacoes),0);
		fread(&aux,sizeof(TpLocacoes),1,Ptr);
	}
	
	if (stricmp(aux.CPFL,CPF)==0 && aux.Status=='1')
		return ftell(Ptr)-sizeof(TpLocacoes);
	else
		return -1;
}





//-------------------------CLIENTES--------------------------
void InserctionSort(FILE *Ptr)
{
	TpClientes Aux1,Aux2;
	
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpClientes);
	TL--;
	fseek(Ptr,TL*sizeof(TpClientes), 0);
	fread(&Aux1,sizeof(TpClientes),1,Ptr);
	
	fseek(Ptr,(TL-1)*sizeof(TpClientes), 0);
	fread(&Aux2,sizeof(TpClientes),1,Ptr);
	
	while(TL>0 && stricmp(Aux1.CPF,Aux2.CPF) < 0)
	{
		fseek(Ptr,TL*sizeof(TpClientes),0);
		fwrite(&Aux2,sizeof(TpClientes),1,Ptr);
		
		fseek(Ptr,(TL-1)*sizeof(TpClientes),0);
		fwrite(&Aux1,sizeof(TpClientes),1,Ptr);
		
		TL--;
		
		fseek(Ptr, TL*sizeof(TpClientes), 0);
		fread(&Aux1,sizeof(TpClientes),1,Ptr);
	
		fseek(Ptr, (TL-1)*sizeof(TpClientes), 0);
		fread(&Aux2,sizeof(TpClientes),1,Ptr);
	}

}

//CADASTRO
void CadCliente()
{
	FILE *Ptr = fopen("Clientes.dat","rb+");
	TpClientes aux;

	char resp;
	
	LimparTela();
	
	gotoxy(41,7); printf ("* * * CADASTRAR CLIENTE * * *");
	gotoxy(34,9); printf ("CPF: ");
	gets(aux.CPF);
	fflush(stdin);
	
	while(aux.CPF[0] != '\0')
	{
		int pos = SequencialIndexada(Ptr,aux.CPF);
		if(pos == -1)
		{
			gotoxy(34,10); printf ("Nome: ");
			gets(aux.Nome);
			fflush(stdin);
			
			if(aux.Nome[0] == '\0')
			{
				gotoxy(40,10); printf ("Nao Cad!");
				strcpy(aux.Nome, "Nao Cad!");
			}
		
			gotoxy(34,11);printf ("Telefone: ");
			gets(aux.Telefone);
			fflush(stdin);
			
			if(aux.Telefone[0] == '\0')
			{
				gotoxy(44,11); printf ("Nao Cad!");
				strcpy(aux.Telefone, "Nao Cad!");
			}

			aux.Status = '1';
			
			fseek(Ptr,0,2);
			fwrite(&aux,sizeof(TpClientes),1,Ptr);
			
			InserctionSort(Ptr);
			
			fflush(stdin);
			gotoxy(47,17); printf ("Cliente Cadastrado!");
			getch();
			fflush(stdin);
			
			LimparTela();
			gotoxy(34,7); printf ("Cadastrar novo cliente? [S/N]");
			resp = toupper(getch());
			
			if(resp == 'S')
			{
				LimparTela();
				gotoxy(41,7); printf ("* * * CADASTRAR CLIENTE * * *");
				gotoxy(34,9); printf ("CPF: ");
				gets(aux.CPF);
				fflush(stdin);
			}
			else
				aux.CPF[0] = '\0';

		}
		else
		{
			gotoxy(34,9); printf ("Esse CPF ja esta cadastrado!");
			getch();
			
			LimparTela();
			
			gotoxy(34,7); printf ("Cadastrar novo cliente? [S/N]");
			resp = toupper(getch());
			
			if(resp == 'S')
			{
				LimparTela();
				gotoxy(41,7); printf ("* * * CADASTRAR CLIENTE * * *");
				gotoxy(34,9); printf ("CPF: ");
				gets(aux.CPF);
				fflush(stdin);
			}
			else
				aux.CPF[0] = '\0';
		}
	}
	
	fclose(Ptr);
}

//EXCLUSÂO
void ExclusaoClientes()
{	
	TpClientes Aux;
	
	FILE *PtrCliente = fopen("Clientes.dat", "rb+");
	FILE *PtrLocacao = fopen("Locacoes.dat", "rb");
	int pos, posCPF;
	char resp;
	
	LimparTela();
	fread(&Aux,sizeof(TpClientes),1,PtrCliente);
	if(!feof(PtrCliente))
	{
		gotoxy(41,7); printf ("* * * EXCLUIR CLIENTE * * *");
		gotoxy(34,9); printf ("CPF: ");
		gets(Aux.CPF);
		fflush(stdin);
		
		while(Aux.CPF[0] != '\0')
		{	
			pos = SequencialIndexada(PtrCliente,Aux.CPF);
			
			if(pos==-1)
			{
				gotoxy(34,9); printf ("Nao ha clientes cadastrado com esse CPF!");
				getch();
			}
			else
			{
				posCPF = SequencialIndexadaLocacao(PtrLocacao,Aux.CPF);
				
				if(posCPF == -1)
				{
					fseek(PtrCliente,pos,0);
					fread(&Aux,sizeof(TpClientes),1,PtrCliente);
					
					gotoxy(34,11); printf ("Nome: %s", Aux.Nome);
					gotoxy(34,12); printf ("Telefone: %s", Aux.Telefone);
						
					gotoxy(34,14); printf ("Deseja exluir? [S/N]");
					resp = toupper(getch());
						
					if(resp=='S')
					{
						Aux.Status = '0';
						
						fseek(PtrCliente,pos,0);
						fwrite(&Aux,sizeof(TpClientes),1,PtrCliente);
						
						gotoxy(47,17); printf ("Cliente Exluido!");
						getch();
					}
				}
				else
				{
					gotoxy(34,13); printf ("Exclua a Locacao do cliente para prosseguir!");
					getch();
				}
			}
			
			LimparTela();
			gotoxy(34,7);printf ("Excluir outro cliente? [S/N]");
			resp = toupper(getch());
			
			if(resp == 'S')
			{
				LimparTela();
				if(feof(PtrCliente))
				{
					gotoxy(41,7); printf ("* * * EXCLUIR CLIENTE * * *");
					gotoxy(41,9); printf ("Nao ha clientes cadastrados!");
					Aux.CPF[0] = '\0';
					getch();
				}
				else
				{
					fflush(stdin);
					gotoxy(41,7); printf ("* * * EXCLUIR CLIENTE * * *");
					gotoxy(34,9); printf ("CPF: ");
					gets(Aux.CPF);
					fflush(stdin);
				}
			}
			else
				Aux.CPF[0] = '\0';
			
		}
	}
	else
	{
		gotoxy(41,7); printf ("* * * EXCLUIR CLIENTE * * *");
		gotoxy(41,9); printf ("Nao ha clientes cadastrados!");
		getch();
	}
	
	fclose(PtrCliente);
	fclose(PtrLocacao);
}

//ALTERAR
void AlterarClientes()
{
	TpClientes aux;
	FILE *Ptr = fopen("Clientes.dat", "rb+");
		
	int pos;
	char op, resp;
	
	LimparTela();
	
	fread(&aux,sizeof(TpClientes),1,Ptr);
	if(!feof(Ptr))
	{
		gotoxy(41,7); printf ("* * * ALTERAR CLIENTE * * *");
		gotoxy(34,9); printf ("Digite o CPF de quem deseja alterar: ");
		gets(aux.CPF);
		fflush(stdin);
		
		pos = SequencialIndexada(Ptr,aux.CPF);
		
		if(pos==-1)
		{
			gotoxy(34,9); printf ("Nao ha clientes cadastrado com esse CPF!");
			getch();
		}
		else
		{
			while (aux.CPF[0] != '\0')
			{
				fseek(Ptr,pos,0);
				fread(&aux, sizeof(TpClientes),1,Ptr);
				
				gotoxy(34,11); printf ("Nome: %s", aux.Nome);
				gotoxy(34,12); printf ("Telefone: %s", aux.Telefone);
					
				gotoxy(34,14); printf ("O que deseja alterar?");
				gotoxy(34,15); printf ("[A] CPF");
				gotoxy(34,16); printf ("[B] NOME");
				gotoxy(34,17); printf ("[C] TELEFONE");
				op = toupper(getch());
				
				LimparTela();
				
				switch(op)
				{
					case 'A':gotoxy(41,7); printf ("* * * ALTERAR CLIENTE * * *");
							gotoxy(34,10);printf ("Exclua o cliente e insira com o novo CPF!");
							getch();
							break;
					
					case 'B':gotoxy(43,7); printf ("* * * ALTERAR NOME * * *");
							gotoxy(34,9); printf ("Digite o novo Nome: ");
							fflush(stdin);
							gets(aux.Nome);
							
							fseek(Ptr,pos,0);
							fwrite(&aux, sizeof(TpClientes),1,Ptr);
							
							gotoxy(47,12); printf ("Nome Alterado!");
							getch();
							break;
					
					case 'C':gotoxy(41,7); printf ("* * * ALTERAR TELEFONE * * *");
							gotoxy(34,9); printf ("Digite o novo telefone: ");
							fflush(stdin);
							gets(aux.Telefone);
							
							fseek(Ptr,pos,0);
							fwrite(&aux, sizeof(TpClientes),1,Ptr);
							
							gotoxy(47,12); printf ("Telefone Alterado!");
							getch();
							break;
				}
				
				LimparTela();
				fflush(stdin);
				gotoxy(34,7);printf ("Alterar outro cliente? [S/N]");
				resp = toupper(getch());
				
				if(resp=='S')
				{
					LimparTela();
					gotoxy(41,7); printf ("* * * ALTERAR CLIENTE * * *");
					gotoxy(34,9); printf ("Digite o CPF de quem deseja alterar: ");
					gets(aux.CPF);
					fflush(stdin);
				}
				else
					aux.CPF[0] = '\0';
			}
		}			
	}
	else
	{	
		gotoxy(41,7); printf ("* * * ALTERAR CLIENTE * * *");
		gotoxy(41,9); printf ("Nao ha clientes cadastrados!");
		getch();
	}
	
	fclose(Ptr);
}

//LISTAGEM
void ListagemClientes()
{
	FILE *Ptr = fopen("Clientes.dat","rb");
	TpClientes aux;
	
	int i, linha=11;
	LimparTela();
	
	fread(&aux,sizeof(TpClientes),1,Ptr);
	if (!feof(Ptr))
	{
		
		gotoxy(41,7); printf ("* * * LISTAR CLIENTES * * *");
		gotoxy(39,9); printf ("CPF:");
		gotoxy(52,9); printf ("Nome:");
		gotoxy(67,9); printf ("Telefone:");
	    for(int col=33;col<78;col++)
	    {
	    	gotoxy(col,10); printf("%c",196);
	    }
				
		while (!feof(Ptr))
		{
			if(linha!=22)
			{
				if(aux.Status=='1')
				{
					gotoxy(34,linha); printf ("%s", aux.CPF);
					gotoxy(52,linha); printf ("%s", aux.Nome);
					gotoxy(64,linha); printf ("%s", aux.Telefone);
					linha++;
				}
				fread(&aux,sizeof(TpClientes),1,Ptr);
			}
			else
			{
				char op;
				
				gotoxy(61,23); printf("[P]Proxima Pagina");
				op = toupper(getch());
				fflush(stdin);
				
				if(op=='P')
				{
					LimparTela2(11);
					if(aux.Status=='1')
					{
						gotoxy(34,11); printf ("%s", aux.CPF);
						gotoxy(52,11); printf ("%s", aux.Nome);
						gotoxy(64,11); printf ("%s", aux.Telefone);
						linha++;	
					}
					fread(&aux,sizeof(TpClientes),1,Ptr);
				}
				else
					fseek(Ptr,0,2);
				
				linha = 11;
			}
		}
		getch();
	}
	else
	{
		gotoxy(41,7); printf ("* * * LISTAR CLIENTES * * *");
		gotoxy(41,9); printf ("Nao ha clientes cadastrados!");
		getch();
	}
	
	fclose(Ptr);
}

//-------------------------EXCLUSÃO FÍSICA--------------------------
void ExclusaoFisicaClientes()
{
	TpClientes aux;
	
	FILE *Ptr = fopen("Clientes.dat", "rb+");
	FILE *PtrTemp = fopen("Temp.dat", "wb");
	
	fread(&aux,sizeof(TpClientes),1,Ptr);
	while(!feof(Ptr))
	{
		if(aux.Status == '1')
			fwrite(&aux,sizeof(TpClientes),1,PtrTemp);
		
		fread(&aux,sizeof(TpClientes),1,Ptr);
	}

	fclose(PtrTemp);
	fclose(Ptr);
	
	remove("Clientes.dat");
	rename("Temp.dat", "Clientes.dat");
}

void ExclusaoFisicaCarros()
{
	TpCarros aux;
	
	FILE *Ptr = fopen("Carros.dat","rb");
	FILE *PtrTemp = fopen("Temp.dat", "wb");
	
	fread(&aux,sizeof(TpCarros),1,Ptr);
	while(!feof(Ptr))
	{
		if(aux.Status == '1')
			fwrite(&aux,sizeof(TpCarros),1,PtrTemp);
		
		fread(&aux,sizeof(TpCarros),1,Ptr);
	}
	
	fclose(Ptr);
	fclose(PtrTemp);
	remove("Carros.dat");
	rename("Temp.dat", "Carros.dat");
}

void ExclusaoFisicaLocacoes()
{
	TpLocacoes aux;
	
	FILE *Ptr = fopen("Locacoes.dat","rb");
	FILE *PtrTemp = fopen("Temp.dat", "wb");
	
	fread(&aux,sizeof(TpLocacoes),1,Ptr);
	while(!feof(Ptr))
	{
		if(aux.Status == '1')
			fwrite(&aux,sizeof(TpLocacoes),1,PtrTemp);
		
		fread(&aux,sizeof(TpLocacoes),1,Ptr);
	}

	fclose(PtrTemp);
	fclose(Ptr);
	remove("Locacoes.dat");
	rename("Temp.dat", "Locacoes.dat");
}
 
//-------------------------CARROS--------------------------

 
void SelectionSort(FILE *Ptr)
{
	TpCarros aux1, aux2;
	fseek(Ptr,0,2);
	int maior, pos, TL = ftell(Ptr)/sizeof(TpCarros);
	
	while(TL>0)
	{
		rewind(Ptr);
		fread(&aux1,sizeof(TpCarros),1,Ptr);
		pos=0;
		maior = aux1.Cod;
		
		for(int i=1;i<TL;i++)
		{
			fread(&aux1,sizeof(TpCarros),1,Ptr);
			if(maior<aux1.Cod)
			{
				maior = aux1.Cod;
				pos = i;
			}
		}
		
		if(pos<TL)
		{
			fseek(Ptr,pos*sizeof(TpCarros),0);
			fread(&aux1,sizeof(TpCarros),1,Ptr);
			
			fseek(Ptr,(TL-1)*sizeof(TpCarros),0);
			fread(&aux2,sizeof(TpCarros),1,Ptr);
			
			
			fseek(Ptr,pos*sizeof(TpCarros),0);
			fwrite(&aux2,sizeof(TpCarros),1,Ptr);
			
			fseek(Ptr,(TL-1)*sizeof(TpCarros),0);
			fwrite(&aux1,sizeof(TpCarros),1,Ptr);
		}
		 TL--;
	}
}

void BubbleSort(FILE *Ptr)
{
	TpCarros Aux1,Aux2;
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpCarros);
	
	while(TL>1)
	{
		for(int i=0;i<TL-1;i++)
		{
			fseek(Ptr,i*sizeof(TpCarros),0);
	
			fread(&Aux1,sizeof(TpCarros),1,Ptr);
			fread(&Aux2,sizeof(TpCarros),1,Ptr);
			
			if(stricmp(Aux1.Modelo,Aux2.Modelo)>0)
			{	
				fseek(Ptr,i*sizeof(TpCarros),0);
				fwrite(&Aux2,sizeof(TpCarros),1,Ptr);
				
				fseek(Ptr,(i+1)*sizeof(TpCarros),0);
				fwrite(&Aux1,sizeof(TpCarros),1,Ptr);
			}
		}
		TL--;	
	}
}

 
//CADASTRO
void CadCarro()
{
	TpCarros Aux;
	FILE *Ptr = fopen("Carros.dat", "rb+");
	
	int pos;
	char resp;
	LimparTela();
	
	gotoxy(41,7); printf ("* * * CADASTRAR CARRO * * *");
	gotoxy(34,9); printf ("Codigo Carro: ");
	scanf ("%d", &Aux.Cod);
	fflush(stdin);
	
	while(Aux.Cod > 0)
	{
		pos = BuscaSentinela(Ptr,Aux.Cod);
		
		if(pos == -1)
		{
			gotoxy(34,10); printf ("Modelo: ");
			gets(Aux.Modelo);
			fflush(stdin);
			
			if(Aux.Modelo[0] == '\0')
			{
				gotoxy(42,10); printf ("Nao Cad!");
				strcpy(Aux.Modelo, "Nao Cad!");
			}
		
			gotoxy(34,11);printf ("Categoria: ");
			gets(Aux.Categoria);
			fflush(stdin);
			
			if(Aux.Categoria[0] == '\0')
			{
				gotoxy(45,11); printf ("Nao Cad!");
				strcpy(Aux.Categoria, "Nao Cad!");
			}
			
			gotoxy(34,12);printf ("Valor Diaria: ");
			scanf ("%f", &Aux.PrecoDiaria);
			fflush(stdin);
			
			while(Aux.PrecoDiaria < 0)
			{
				LimparTela();
				gotoxy(41,7); printf ("* * * CADASTRAR CARRO * * *");
				gotoxy(34,9); printf ("Digite um valor maior ou igual a 0! ");
				gotoxy(34,10);printf ("Valor Diaria: ");
				scanf ("%f", &Aux.PrecoDiaria);
			}
			
			Aux.Status = '1';
			
			fseek(Ptr,0,2);
			fwrite(&Aux,sizeof(TpCarros),1,Ptr);
			
			fflush(stdin);
			gotoxy(47,17); printf ("Carro Cadastrado!");
			getch();
			fflush(stdin);
			
			
			LimparTela();
			gotoxy(34,7); printf ("Cadastrar novo carro? [S/N]");
			resp = toupper(getch());
			
			if(resp == 'S')
			{
				LimparTela();
				gotoxy(41,7); printf ("* * * CADASTRAR CARRO * * *");
				gotoxy(34,9); printf ("Codigo Carro: ");
				scanf ("%d", &Aux.Cod);
				fflush(stdin);
			}
			else
				Aux.Cod = 0;
							
		}
		else
		{
			gotoxy(34,9); printf ("Esse codigo ja esta cadastrado!");
			getch();
			
			LimparTela();
			
			gotoxy(34,7); printf ("Cadastrar novo carro? [S/N]");
			resp = toupper(getch());
			
			if(resp == 'S')
			{
				LimparTela();
				gotoxy(41,7); printf ("* * * CADASTRAR CARRO * * *");
				gotoxy(34,9); printf ("Codigo Carro: ");
				scanf ("%d", &Aux.Cod);
				fflush(stdin);
			}
			else
				Aux.Cod = 0;
		}
	}
	SelectionSort(Ptr);
	fclose(Ptr);
}

//Exclusão
void ExclusaoCarros()
{
	TpCarros Aux;
	FILE *Ptr = fopen("Carros.dat", "rb+");
	FILE *PtrLocacao = fopen("Locacoes.dat", "rb");
	int pos, posLocacao, CodCarro;
	char resp;
	
	LimparTela();
	fread(&Aux,sizeof(TpCarros),1,Ptr);
	if(!feof(Ptr))
	{
		gotoxy(41,7); printf ("* * * EXCLUIR CARRO * * *");
		gotoxy(34,9); printf ("Codigo Carro: ");
		scanf("%d", &Aux.Cod);
		fflush(stdin);
		
		while(Aux.Cod > 0)
		{	
			pos = BuscaBinariaCod(Ptr,Aux.Cod);
			
			if(pos>=0)
			{

				posLocacao = BuscaExaustivaLocacao(PtrLocacao,Aux.Cod);
			
				if(posLocacao == -1)
				{
					fseek(Ptr,pos,0);
					fread(&Aux,sizeof(TpCarros),1,Ptr);
					
					gotoxy(34,11); printf ("Modelo: %s", Aux.Modelo);
					gotoxy(34,12); printf ("Categoria: %s", Aux.Categoria);
					gotoxy(34,13); printf ("Valor Diaria: R$ %.2f", Aux.PrecoDiaria);
					
					gotoxy(34,15); printf ("Deseja exluir? [S/N]");
					resp = toupper(getch());
					
					if(resp=='S')
					{
						Aux.Status = '0';
						
						fseek(Ptr,pos,0);
						fwrite(&Aux,sizeof(TpCarros),1,Ptr);
											
						gotoxy(47,17); printf ("Carro Exluido!");
						getch();
					}
				}
				else
				{
					gotoxy(34,9); printf ("Exclua a Locacao do carro para prosseguir!");
					getch();
				}
			}
			else
			{
				gotoxy(34,9); printf ("Nao ha carros cadastrado com esse codigo!");
				getch();
			}
			
		
			
			LimparTela();
			gotoxy(34,7);printf ("Excluir outro carro? [S/N]");
			resp = toupper(getch());
			
			
			if(resp == 'S')
			{
				LimparTela();
				if(feof(Ptr))
				{
					gotoxy(41,7); printf ("* * * EXCLUIR CARRO * * *");
					gotoxy(41,9); printf ("Nao ha carros cadastrados!");
					Aux.Cod = 0;
					getch();
				}
				else
				{
					fflush(stdin);
					gotoxy(41,7); printf ("* * * EXCLUIR CARRO * * *");
					gotoxy(34,9); printf ("Codigo Carro: ");
					scanf("%d", &Aux.Cod);
					fflush(stdin);
				}
			}
			else
				Aux.Cod = 0;
		}
	}
	else
	{
		gotoxy(41,7); printf ("* * * EXCLUIR CARRO * * *");
		gotoxy(41,9); printf ("Nao ha carros cadastrados!");
		getch();
	}
	
	fclose(Ptr);
	fclose(PtrLocacao);
}

//ALTERAR
void AlterarCarros()
{
	TpCarros Aux;
	FILE *Ptr = fopen("Carros.dat", "rb+");
	
	int pos;
	float AuxValor;
	char op, resp;
	
	LimparTela();
	
	if(!feof(Ptr))
	{
		gotoxy(41,7); printf ("* * * ALTERAR CARRO * * *");
		gotoxy(34,9); printf ("Digite o cod do carro que deseja alterar: ");
		scanf("%d", &Aux.Cod);
		fflush(stdin);
		
		pos = BuscaSentinela(Ptr, Aux.Cod);
		
		if(pos==-1)
		{
			LimparTela();
			gotoxy(41,7); printf ("* * * ALTERAR CODIGO * * *");
			gotoxy(34,9); printf ("Nao ha carros cadastrado com esse codigo!");
			getch();
		}
		else
		{
			while (Aux.Cod > 0)
			{
				fseek(Ptr,pos,0);
				fread(&Aux,sizeof(TpCarros),1,Ptr);
				
				gotoxy(34,11); printf ("Modelo: %s", Aux.Modelo);
				gotoxy(34,12); printf ("Categoria: %s", Aux.Categoria);
				gotoxy(34,13); printf ("Preco Diaria: R$ %.2f", Aux.PrecoDiaria);
					
				gotoxy(34,15); printf ("O que deseja alterar?");
				gotoxy(34,16); printf ("[A] CODIGO");
				gotoxy(34,17); printf ("[B] MODELO");
				gotoxy(34,18); printf ("[C] CATEGORIA");
				gotoxy(34,19); printf ("[D] PRECO DIARIA");
				op = toupper(getch());
				
				LimparTela();
				
				switch(op)
				{
					case 'A':gotoxy(41,7); printf ("* * * ALTERAR CODIGO * * *");
							gotoxy(34,10);printf ("Exclua o carro e insira com o novo codigo!");
							getch();
							break;
					
					case 'B':gotoxy(43,7); printf ("* * * ALTERAR MODELO * * *");
							gotoxy(34,9); printf ("Digite o novo Modelo: ");
							gets(Aux.Modelo);
							
							fseek(Ptr,pos,0);
							fwrite(&Aux,sizeof(TpCarros),1,Ptr);
							
							gotoxy(47,12); printf ("Modelo Alterado!");
							getch();
							break;
					
					case 'C':gotoxy(41,7); printf ("* * * ALTERAR CATEGORIA * * *");
							gotoxy(34,9); printf ("Digite a nova categoria: ");
							gets(Aux.Categoria);
							
							fseek(Ptr,pos,0);
							fwrite(&Aux,sizeof(TpCarros),1,Ptr);
							
							gotoxy(47,12); printf ("Categoria Alterada!");
							getch();
							break;
							
					case 'D':gotoxy(41,7); printf ("* * * ALTERAR DIARIA * * *");
							gotoxy(34,9); printf ("Digite o novo Preco da Diaria: ");
							scanf("%f", &Aux.PrecoDiaria);
							
							while(Aux.PrecoDiaria < 0)
							{
								LimparTela();
								gotoxy(41,7); printf ("* * * ALTERAR DIARIA * * *");
								gotoxy(34,10); printf ("Digite um valor maior ou igual a 0! ");
								gotoxy(34,11);printf ("Valor Diaria: ");
								scanf("%f", &Aux.PrecoDiaria);
						
							}
							
							fseek(Ptr,pos,0);
							fwrite(&Aux,sizeof(TpCarros),1,Ptr);
							
							gotoxy(47,13); printf ("Valor Alterado!");
							getch();
							break;
				}
				
				LimparTela();
				fflush(stdin);
				gotoxy(34,7);printf ("Alterar outro carro? [S/N]");
				resp = toupper(getch());
				
				if(resp=='S')
				{
					LimparTela();
					gotoxy(41,7); printf ("* * * ALTERAR CARRO * * *");
					gotoxy(34,9); printf ("Digite o cod do carro que deseja alterar: ");
					scanf("%d", &Aux.Cod);
					fflush(stdin);
				}
				else
					Aux.Cod = 0;
			}
		}			
	}
	else
	{	
		gotoxy(41,7); printf ("* * * ALTERAR CARRO * * *");
		gotoxy(41,9); printf ("Nao ha carros cadastrados!");
		getch();
	}
	
	fclose(Ptr);
}

//Listagem
void ListagemCarros()
{
	TpCarros aux;
	FILE *Ptr = fopen("Carros.dat", "rb");
	
	int i, linha =11;
	LimparTela();
	
	fread(&aux,sizeof(TpCarros),1,Ptr);
	if (!feof(Ptr))
	{
		
		gotoxy(41,7); printf ("* * * LISTAR CARROS * * *");
		gotoxy(33,9); printf ("Codigo:");
		gotoxy(41,9); printf ("Modelo:");
		gotoxy(52,9); printf ("Categoria:");
		gotoxy(65,9); printf ("Preco Diaria:");
	    for(int col=33;col<78;col++)
	    {
	    	gotoxy(col,10); printf("%c",196);
	    }
		
		while(!feof(Ptr))
		{
			if(linha!=22)
			{
				if(aux.Status == '1')
				{
					gotoxy(34,linha); printf ("%d", aux.Cod);
					gotoxy(41,linha); printf ("%s", aux.Modelo);
					gotoxy(52,linha); printf ("%s", aux.Categoria);
					gotoxy(68,linha); printf ("R$ %.2f", aux.PrecoDiaria);
					linha++;
				}
				fread(&aux,sizeof(TpCarros),1,Ptr);
			}
			else
			{
				char op;
				
				gotoxy(61,23); printf("[P]Proxima Pagina");
				op = toupper(getch());
				fflush(stdin);
				
				if(op=='P')
				{
					LimparTela2(11);
					if(aux.Status == '1')
					{
						gotoxy(34,11); printf ("%d", aux.Cod);
						gotoxy(41,11); printf ("%s", aux.Modelo);
						gotoxy(52,11); printf ("%s", aux.Categoria);
						gotoxy(68,11); printf ("R$ %.2f", aux.PrecoDiaria);
						linha++;
					}
					fread(&aux,sizeof(TpCarros),1,Ptr);
				}
				else
					fseek(Ptr,0,2);
					
				linha = 11;
			
			}
		}
		getch();
	}
	else
	{
		gotoxy(41,7); printf ("* * * LISTAR CARROS * * *");
		gotoxy(41,9); printf ("Nao ha carros cadastrados!");
		getch();
	}
	
	fclose(Ptr);
}

void OrdenarCodSelection()
{
	FILE *Ptr = fopen("Carros.dat","rb+");
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpCarros);
	LimparTela();
	if(TL>0)
	{
		SelectionSort(Ptr);
		
		gotoxy(41,7); printf ("* * * ORDENAR CODIGO * * *");
		gotoxy(41,9); printf ("Lista Ordenada por Codigo!");
		getch();
	}
	else
	{
		gotoxy(41,7); printf ("* * * ORDENAR CODIGO * * *");
		gotoxy(41,9); printf ("Nao ha carros cadastrados!");
		getch();
	}
	fclose(Ptr);
}


//ORDENAR MODELO - BUBBLE SORT
void OrdenarModeloBubble()
{
	FILE *Ptr = fopen("Carros.dat","rb+");
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpCarros);
	LimparTela();
	if(TL>1)
	{
		BubbleSort(Ptr);
		
		gotoxy(41,7); printf ("* * * ORDENAR MODELO * * *");
		gotoxy(41,9); printf ("Lista Ordenada por Modelo!");
		getch();
	}
	else
	{
		gotoxy(41,7); printf ("* * * ORDENAR MODELO * * *");
		gotoxy(41,9); printf ("Nao ha carros cadastrados!");
		getch();
	}
	fclose(Ptr);
}

//-------------------------LOCAÇÃO--------------------------

void InserctionSortLocacao(FILE *Ptr)
{
	TpLocacoes Aux1,Aux2;
	
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpLocacoes);
	TL--;
	fseek(Ptr,TL*sizeof(TpLocacoes), 0);
	fread(&Aux1,sizeof(TpLocacoes),1,Ptr);
	
	fseek(Ptr,(TL-1)*sizeof(TpLocacoes), 0);
	fread(&Aux2,sizeof(TpLocacoes),1,Ptr);
	
	while(TL>0 && stricmp(Aux1.CPFL,Aux2.CPFL) < 0)
	{
		fseek(Ptr,TL*sizeof(TpLocacoes),0);
		fwrite(&Aux2,sizeof(TpLocacoes),1,Ptr);
		
		fseek(Ptr,(TL-1)*sizeof(TpLocacoes),0);
		fwrite(&Aux1,sizeof(TpLocacoes),1,Ptr);
		
		TL--;
		
		fseek(Ptr, TL*sizeof(TpLocacoes), 0);
		fread(&Aux1,sizeof(TpLocacoes),1,Ptr);
	
		fseek(Ptr, (TL-1)*sizeof(TpLocacoes), 0);
		fread(&Aux2,sizeof(TpLocacoes),1,Ptr);
	}
}

int SequencialIndexadaLocacao(FILE *Ptr, char Elem[16])
{
	TpLocacoes aux;
	
	rewind(Ptr);
	fread(&aux,sizeof(TpLocacoes),1,Ptr);
	while(!feof(Ptr) && (stricmp(aux.CPFL,Elem) < 0 || aux.Status != '1'))
		fread(&aux,sizeof(TpLocacoes),1,Ptr);
	
	if (!feof(Ptr) && stricmp(aux.CPFL,Elem)==0)
		return ftell(Ptr) - sizeof(TpLocacoes); //Achou
	else
		return -1; //Não Achou	
}

int BuscaBinariaCodLocacao(FILE *Ptr, int AuxCod)
{
	TpLocacoes aux;
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpLocacoes);
	int inicio=0, meio, fim = TL-1;
	meio = fim/2;
	
	fseek(Ptr,meio*sizeof(TpLocacoes),0);
	fread(&aux,sizeof(TpLocacoes),1,Ptr);
	
	while(inicio<fim && (aux.CodCarroL != AuxCod || aux.Status !='1'))
	{
		if(aux.CodCarroL<AuxCod)
			inicio = meio+1;
		else
			fim = meio-1;
		
		meio = (inicio+fim)/2;
		
		fseek(Ptr,meio*sizeof(TpLocacoes),0);
		fread(&aux,sizeof(TpLocacoes),1,Ptr);
	}
	if(aux.CodCarroL == AuxCod && aux.Status == '1')
		return ftell(Ptr)-sizeof(TpLocacoes);
	else
		return -1;
}

//CADASTRO
void CadLocacao()
{
	TpLocacoes aux;
	TpCarros auxCarros;
	FILE *Ptr = fopen ("Locacoes.dat", "rb+");
	FILE *PtrClientes = fopen("Clientes.dat", "rb");
	FILE *PtrCarros = fopen("Carros.dat", "rb");
	
	int pos;
	char resp;
	
	LimparTela();
	gotoxy(41,7); printf ("* * * CADASTRAR LOCACOES * * *");
	gotoxy(34,9); printf ("CPF: ");
	gets(aux.CPFL);
	fflush(stdin);
	
	while(aux.CPFL[0] != '\0')
	{
		if(SequencialIndexada(PtrClientes, aux.CPFL)>=0)
		{
			gotoxy(34,10); printf ("Codigo Carro: ");
			scanf ("%d", &aux.CodCarroL);
			
			while(aux.CodCarroL>0)
			{
				
				pos = BuscaBinariaCod(PtrCarros, aux.CodCarroL);
					
				if(pos>=0)
				{
					fseek(PtrCarros,pos,0);
					fread(&auxCarros,sizeof(TpCarros),1,PtrCarros);
					
					if(BuscaClienteEcod(Ptr, aux.CPFL, aux.CodCarroL) == -1)
					{
						
						gotoxy(34,11); printf ("Quantidade de dias: ");
						scanf ("%d", &aux.QtdeDias);
							
						while (aux.QtdeDias<=0)
						{
							gotoxy(34,11); printf ("Digite uma quantidade maior que 0!");
							scanf ("%d", &aux.QtdeDias);
						}
							
						aux.ValorLocacao = auxCarros.PrecoDiaria * aux.QtdeDias;
						
						aux.Status = '1';
						
						fseek(Ptr,0,2);
						fwrite(&aux,sizeof(TpLocacoes),1,Ptr);
						
						gotoxy(34,12); printf ("Valor da Locacao: R$ %.2f", aux.ValorLocacao);
						
						gotoxy(47,17); printf ("Locacao Cadastrada!");
						getch();
						fflush(stdin);
						
						InserctionSortLocacao(Ptr);
						
						LimparTela();
						gotoxy(34,7); printf ("Cadastrar nova Locacao? [S/N]");
						resp = toupper(getch());
						
						if(resp == 'S')
						{
							LimparTela();
							gotoxy(41,7); printf ("* * * CADASTRAR LOCACOES * * *");
							gotoxy(34,9); printf ("CPF: ");
							gets(aux.CPFL);
							fflush(stdin);
							aux.CodCarroL = 0;
						}
						else
							aux.CPFL[0] = '\0';
							
							
						aux.CodCarroL = 0;
					}
					else
					{
						LimparTela();
						gotoxy(41,7); printf ("* * * CADASTRAR LOCACOES * * *");
						gotoxy(41,9); printf ("Essa Locacao Ja Existe!");
						getch();
						fflush(stdin);
						
						LimparTela();
						gotoxy(34,7); printf ("Cadastrar nova Locacao? [S/N]");
						resp = toupper(getch());
						
						if(resp == 'S')
						{
							LimparTela();
							gotoxy(41,7); printf ("* * * CADASTRAR LOCACOES * * *");
							gotoxy(34,9); printf ("CPF: ");
							gets(aux.CPFL);
							fflush(stdin);
							aux.CodCarroL = 0;
						}
						else
							aux.CPFL[0] = '\0';
						
							
						aux.CodCarroL = 0;
					}
							
				}
				else
				{
					LimparTela();
					gotoxy(41,7); printf ("* * * CADASTRAR LOCACOES * * *");
					gotoxy(41,9); printf ("O Carro nao esta cadastrado!");
					getch();
					fflush(stdin);
					
					aux.CodCarroL = 0;
					aux.CPFL[0] = '\0';
					LimparTela();

				}
			}
		}
		else
		{
			LimparTela();
			gotoxy(41,7); printf ("* * * CADASTRAR LOCACOES * * *");
			gotoxy(41,9); printf ("O Cliente nao esta cadastrado!");
			getch();
			aux.CPFL[0] = '\0';
		}
	}	
	fclose(Ptr);
	fclose(PtrClientes);
}


//EXCLUSÃO
void ExclusaoLocacao()
{
	TpLocacoes aux;
	FILE *Ptr = fopen("Locacoes.dat","rb+");
	fseek(Ptr,0,2);
	int pos, TL = ftell(Ptr)/sizeof(TpLocacoes);
	char resp;
	
	LimparTela();
	if(TL>0)
	{
		rewind(Ptr);
		gotoxy(41,7); printf ("* * * EXCLUIR LOCACOES * * *");
		gotoxy(34,9); printf ("CPF: ");
		gets(aux.CPFL);
		fflush(stdin);
		
		while (aux.CPFL[0] != '\0')
		{
			pos = BuscaBinariaCPF(Ptr, aux.CPFL);
			
			if(pos>=0)
			{
				gotoxy(34,10); printf ("Codigo Carro: ");
				scanf ("%d", &aux.CodCarroL);
				
				while(aux.CodCarroL>0)
				{
											
					if(BuscaExaustivaLocacao(Ptr, aux.CodCarroL) >= 0)
					{
						pos = BuscaClienteEcod(Ptr, aux.CPFL, aux.CodCarroL);
						
						if(pos >= 0)
						{
							fseek(Ptr,pos,0);
							fread(&aux,sizeof(TpLocacoes),1,Ptr);
							
							gotoxy(34,11); printf ("Quantidade de dias: %d", aux.QtdeDias);
							gotoxy(34,12); printf ("Valor da Locacao: R$ %.2f", aux.ValorLocacao);
							
							gotoxy(34,14); printf ("Deseja exluir? [S/N]");
							resp = toupper(getch());
				
							if(resp=='S')
							{
								aux.Status = '0';
								fseek(Ptr,pos,0);
								fwrite(&aux,sizeof(TpLocacoes),1,Ptr);
							
								gotoxy(47,17); printf ("Locacao Exluida!");
								getch();
							}
							
							
							LimparTela();
							gotoxy(34,7);printf ("Excluir outra Locacao? [S/N]");
							resp = toupper(getch());
							
							if(resp == 'S')
							{
								LimparTela();
								if(TL==0)
								{
									gotoxy(41,7); printf ("* * * EXCLUIR LOCACOES * * *");
									gotoxy(41,9); printf ("Nao ha Locacoes cadastradas!");
									aux.CPFL[0] = '\0';
									getch();
								}
								else
								{
									fflush(stdin);
									gotoxy(41,7); printf ("* * * EXCLUIR LOCACOES * * *");
									gotoxy(34,9); printf ("CPF: ");
									gets(aux.CPFL);
									fflush(stdin);
								}

							}
							else
								aux.CPFL[0] = '\0';
							

								
							aux.CodCarroL = 0;
						}
						else
						{
							LimparTela();
							gotoxy(41,7); printf ("* * * CADASTRAR LOCACOES * * *");
							gotoxy(41,9); printf ("Essa Locacao nao esta cadastrada!");
							getch();
							fflush(stdin);
							
							LimparTela();
							gotoxy(34,7);printf ("Excluir outra Locacao? [S/N]");
							resp = toupper(getch());
							
							if(resp == 'S')
							{
								LimparTela();
								if(!feof(Ptr))
								{
									gotoxy(41,7); printf ("* * * EXCLUIR LOCACOES * * *");
									gotoxy(41,9); printf ("Nao ha Locacoes cadastradas!");
									aux.CPFL[0] = '\0';
									getch();
								}
								else
								{
									fflush(stdin);
									gotoxy(41,7); printf ("* * * EXCLUIR LOCACOES * * *");
									gotoxy(34,9); printf ("CPF: ");
									gets(aux.CPFL);
									fflush(stdin);
								}
							}
							else
								aux.CPFL[0] = '\0';
				
								
							aux.CodCarroL = 0;
						}
								
					}
					else
					{
						LimparTela();
						gotoxy(41,7); printf ("* * * EXCLUIR LOCACOES * * *");
						gotoxy(34,9); printf ("Nao ha Locacoes cadastradas com esse codigo!");
						getch();
						fflush(stdin);
						
						aux.CPFL[0] = '\0';
						aux.CodCarroL = 0;
					}
				}
			}
			else
			{
				LimparTela();
				gotoxy(41,7); printf ("* * * EXCLUIR LOCACOES * * *");
				gotoxy(34,9); printf ("Nao ha Locacoes cadastradas com esse CPF!");
				getch();
				aux.CPFL[0] = '\0';
	
			}
		}	
	}
	else
	{
		gotoxy(41,7); printf ("* * * EXCLUIR LOCACOES * * *");
		gotoxy(41,9); printf ("Nao ha Locacoes cadastradas!");
		getch();
	}	
	
	fclose(Ptr);
}

//ALTERAR
void AlterarLocacao()
{
	TpLocacoes aux;
	
	FILE *Ptr = fopen("Locacoes.dat","rb+");
	
	fseek(Ptr,0,2);
	int pos, TL = ftell(Ptr)/sizeof(TpLocacoes);
	char op, resp;
	
	LimparTela();
	
	if(TL>0)
	{
		rewind(Ptr);
		gotoxy(41,7); printf ("* * * ALTERAR LOCACOES * * *");
		gotoxy(34,9); printf ("Digite o CPF: ");
		gets(aux.CPFL);
		fflush(stdin);
		
		while (aux.CPFL[0] != '\0')
		{	
			pos = SequencialIndexadaLocacao(Ptr, aux.CPFL);
			
			if(pos>=0)
			{
				gotoxy(34,10); printf ("Codigo Carro: ");
				scanf ("%d", &aux.CodCarroL);
				
				while(aux.CodCarroL > 0)
				{
					if(BuscaExaustivaLocacao(Ptr, aux.CodCarroL) >= 0)
					{
						pos = BuscaClienteEcod(Ptr, aux.CPFL, aux.CodCarroL);
						
						if(pos >= 0)
						{
							fseek(Ptr,pos,0);
							fread(&aux,sizeof(TpLocacoes),1,Ptr);
							
							gotoxy(34,11); printf ("QUANT. DIAS: %d", aux.QtdeDias);
							gotoxy(34,12); printf ("VALOR LOCACAO: R$ %.2f", aux.ValorLocacao);
									
							gotoxy(34,14); printf ("O que deseja alterar?");
							gotoxy(34,15); printf ("[A] CPF");
							gotoxy(34,16); printf ("[B] CODIGO CARRO");
							gotoxy(34,17); printf ("[C] QUANT. DIAS");
							gotoxy(34,18); printf ("[D] VALOR LOCACAO");
							op = toupper(getch());
								
							LimparTela();
								
							switch(op)
							{
								case 'A':gotoxy(41,7); printf ("* * * ALTERAR CLIENTE * * *");
										gotoxy(34,10);printf ("Exclua a Locacao e insira com o novo CPF!");
										getch();
										break;
								
								case 'B':gotoxy(43,7); printf ("* * * ALTERAR CODIGO * * *");
										gotoxy(34,10);printf ("Exclua a Locacao e insira com o novo Codigo!");
										getch();
										break;
										
									
								case 'C':gotoxy(41,7); printf ("* * * ALTERAR DIAS * * *");
										gotoxy(34,9); printf ("Digite a nova quant. de dias: ");
										scanf("%d", &aux.QtdeDias);
										
										fseek(Ptr,pos,0);
										fwrite(&aux,sizeof(TpLocacoes),1,Ptr);
										
										gotoxy(47,12); printf ("Qtde de dias alterado!");
										getch();
										break;
										
								case 'D':gotoxy(41,7); printf ("* * * ALTERAR VALOR * * *");
										gotoxy(34,10);printf ("Altere o Preco da Diaria do Carro!");
										getch();
										break;
							}
								
							LimparTela();
							fflush(stdin);
							gotoxy(34,7);printf ("Alterar outra Locacao? [S/N]");
							resp = toupper(getch());
								
							if(resp=='S')
							{
								LimparTela();
								gotoxy(41,7); printf ("* * * ALTERAR LOCACOES * * *");
								gotoxy(34,9); printf ("Digite o CPF de quem deseja alterar: ");
								gotoxy(34,10); gets(aux.CPFL);
								fflush(stdin);
							}
							else
								aux.CPFL[0] = '\0';
							
							aux.CodCarroL =0;
						}
						else
						{
							LimparTela();
							gotoxy(41,7); printf ("* * * ALTERAR LOCACOES * * *");
							gotoxy(41,9); printf ("Essa Locacao nao esta cadastrada!");
							getch();
							fflush(stdin);
							
							LimparTela();
							gotoxy(34,7);printf ("Alterar outra Locacao? [S/N]");
							resp = toupper(getch());
							
							if(resp == 'S')
							{
								LimparTela();
								fflush(stdin);
								gotoxy(41,7); printf ("* * * ALTERAR LOCACOES * * *");
								gotoxy(34,9); printf ("CPF: ");
								gets(aux.CPFL);
								fflush(stdin);
							}
							else
								aux.CPFL[0] = '\0';
				
							aux.CodCarroL = 0;
						}
					}
					else
					{
						LimparTela();
						gotoxy(41,7); printf ("* * * ALTERAR LOCACOES * * *");
						gotoxy(34,9); printf ("Nao ha Locacoes com esse CPF e Codigo!");
						getch();
						fflush(stdin);
						
						aux.CPFL[0] = '\0';
						aux.CodCarroL = 0;
					}
				}
			}
			else
			{
				LimparTela();
				gotoxy(41,7); printf ("* * * ALTERAR LOCACOES * * *");
				gotoxy(34,9); printf ("Nao ha Locacoes cadastradas com esse CPF!");
				getch();
				aux.CPFL[0] = '\0';
			}	
		}
	}

	else
	{	
		gotoxy(41,7); printf ("* * * ALTERAR LOCACOES * * *");
		gotoxy(41,9); printf ("Nao ha Locacoes cadastradas!");
		getch();
	}
	fclose(Ptr);
}


//LISTAGEM
void ListagemLocacao()
{
	TpLocacoes aux;
	FILE *Ptr = fopen("Locacoes.dat", "rb");
	int i, linha = 11;
	LimparTela();
	
	fread(&aux,sizeof(TpLocacoes),1,Ptr);
	if (!feof(Ptr))
	{
		
		gotoxy(41,7); printf ("* * * LISTAR LOCACOES * * *");
		gotoxy(39,9); printf ("CPF:");
		gotoxy(51,9); printf ("Cod:");
		gotoxy(57,9); printf ("Qtde Dias:");
		gotoxy(70,9); printf ("Valor:");
	    for(int col=33;col<78;col++)
	    {
	    	gotoxy(col,10); printf("%c",196);
	    }
		
		while(!feof(Ptr))
		{
			if(linha!=22)
			{
				if(aux.Status == '1')
				{
					gotoxy(34,linha); printf ("%s", aux.CPFL);
					gotoxy(51,linha); printf ("%d", aux.CodCarroL);
					gotoxy(60,linha); printf ("%d", aux.QtdeDias);
					gotoxy(68,linha); printf ("R$ %.2f", aux.ValorLocacao);
					linha++;
				}
				fread(&aux,sizeof(TpLocacoes),1,Ptr);
			}
			else
			{
				char op;
				
				gotoxy(61,23); printf("[P]Proxima Pagina");
				op = toupper(getch());
				fflush(stdin);
				
				if(op=='P')
				{
					LimparTela2(11);
					if(aux.Status == '1')
					{
						gotoxy(34,linha); printf ("%s", aux.CPFL);
						gotoxy(51,linha); printf ("%d", aux.CodCarroL);
						gotoxy(60,linha); printf ("%d", aux.QtdeDias);
						gotoxy(68,linha); printf ("R$ %.2f", aux.ValorLocacao);
						linha++;
					}
					fread(&aux,sizeof(TpLocacoes),1,Ptr);
				}
				else
					fseek(Ptr,0,2);
					
				linha = 11;
			}
		}
		getch();
	}
	else
	{
		gotoxy(41,7); printf ("* * * LISTAR LOCACOES * * *");
		gotoxy(41,9); printf ("Nao ha Locacoes cadastradas!");
		getch();
	}
	
	fclose(Ptr);
}

//-------------------------RELATÓRIOS--------------------------

void RelaA()
{
	FILE *PtrClientes = fopen("Clientes.dat","rb");
	FILE *PtrLocacoes = fopen("Locacoes.dat", "rb");
	
	TpClientes aux;
	TpLocacoes auxLocacoes;
	
	fseek(PtrClientes,0,2);
	fseek(PtrLocacoes,0,2);
	
	int TLClientes = ftell(PtrClientes)/sizeof(TpClientes);
	int TLLocacao = ftell(PtrLocacoes)/sizeof(TpLocacoes);
	
    LimparTela();
    
	if(TLClientes > 0 && TLLocacao > 0)
	{
	    gotoxy(35, 7); printf("* * * CLIENTES COM MAIS DE 3 LOCACOES * * *");
		
		rewind(PtrClientes);
		rewind(PtrLocacoes);
		
	    gotoxy(39,9); printf("CPF:");
	    gotoxy(52,9); printf("Nome:");
	    gotoxy(67,9); printf("Telefone:");
	    for(int col=33;col<78;col++)
	    {
	    	gotoxy(col,10); printf("%c",196);
	    }
	
		int linha=11, achou=0;
		char op;
		
		for(int i=0;i<TLClientes;i++)
		{
			fread(&aux,sizeof(TpClientes),1,PtrClientes);
			rewind(PtrLocacoes);
			int cont = 0;
			for(int j=0;j<TLLocacao;j++)
			{
				fread(&auxLocacoes,sizeof(TpLocacoes),1,PtrLocacoes);
				if(stricmp(aux.CPF,auxLocacoes.CPFL)==0 && auxLocacoes.Status=='1') 
					cont++;
			}

			
			if(cont>3)
			{
				if(linha!=22)
				{
					gotoxy(34, linha); printf("%s", aux.CPF);
			        gotoxy(52, linha); printf("%s", aux.Nome);
			        gotoxy(64, linha); printf("%s", aux.Telefone);
			        linha++;
			        achou++;
				}
				else
				{
					gotoxy(61,23); printf("[P]Proxima Pagina");
					op = toupper(getch());
					fflush(stdin);
					
					if(op == 'P')
					{
						LimparTela2(11);
						linha=11;
						gotoxy(34, linha); printf("%s", aux.CPF);
				        gotoxy(52, linha); printf("%s", aux.Nome);
				        gotoxy(64, linha); printf("%s", aux.Telefone);
				        linha++;
				        achou++;
					}
				}
			}
		}
		if(achou==0)
		{
			gotoxy(39, 12); printf("Nenhum cliente encontrado!");
		}

	    getch();
	}
	else
	{
		LimparTela();
		gotoxy(37, 12); printf("Nao ha dados suficientes para exibir");
		getch();
	}
	
	fclose(PtrClientes);
	fclose(PtrLocacoes);
}

void RelaB()
{
	FILE *Ptr = fopen("Carros.dat","rb");
	TpCarros aux;
	
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpCarros);
	
	int achou=0,linha=13;
    char categoria[20], op;

    LimparTela();
    gotoxy(38,7); printf("* * * CARROS POR CATEGORIA * * *");

    gotoxy(34,9); printf("Digite a categoria que deseja buscar: ");
    gets(categoria);
    fflush(stdin);
    
	while(categoria[0]!='\0')
	{
	    gotoxy(33,11); printf("Codigo:");
	    gotoxy(50,11); printf("Modelo:");
	    gotoxy(65,11); printf("Preco Diaria:");
	    for(int col=33;col<78;col++)
	    {
	    	gotoxy(col,12); printf("%c",196);
	    }
	    
	    rewind(Ptr);
	    for(int i=0;i<TL;i++)
	    {
	    	fread(&aux,sizeof(TpCarros),1,Ptr);
	        if (stricmp(aux.Categoria,categoria) == 0 && aux.Status =='1')
	        {
	        	if(linha!=22)
	        	{
		            gotoxy(34, linha); printf("%d", aux.Cod);
		            gotoxy(50, linha); printf("%s", aux.Modelo);
		            gotoxy(68, linha); printf("R$ %.2f", aux.PrecoDiaria);
		            linha++;
		            achou++;
	        	}
	        	else
	        	{
	        		gotoxy(61,23); printf("[P]Proxima Pagina");
					op = toupper(getch());
					fflush(stdin);
					
					if(op == 'P')
					{
						LimparTela2(13);
						linha=13;
			            gotoxy(34, linha); printf("%d", aux.Cod);
			            gotoxy(50, linha); printf("%s", aux.Modelo);
			            gotoxy(68, linha); printf("R$ %.2f", aux.PrecoDiaria);
			            linha++;
			            achou++;
		      		}
	        	}
	        }
	    }
	    
	    if (achou == 0)
	    {
	        gotoxy(34,14); printf("Nenhum carro encontrado para esta categoria!");
	    }
	
	    getch();
	    categoria[0] = '\0';
	}
	
	fclose(Ptr);
}

void RelaC()
{
	FILE *Ptr = fopen("Locacoes.dat", "rb");
	TpLocacoes aux;
	
	fseek(Ptr,0,2);
	int TL = ftell(Ptr)/sizeof(TpLocacoes);
	
	int achou=0, linha=13;
	float valor;
	char op;
	
	LimparTela();
    gotoxy(38,7); printf("* * * LOCACOES POR LIMITE * * *");
    gotoxy(34,9); printf("Digite o valor limite: ");
    scanf("%f", &valor);
    
    while(valor>0)
    {
    	gotoxy(38,11); printf("CPF:");
		gotoxy(49,11); printf("Codigo:");
		gotoxy(58,11); printf("Dias:");
		gotoxy(65,11); printf("Preco Diaria:");
	    for(int col=33;col<78;col++)
	    {
	    	gotoxy(col,12); printf("%c",196);
	    }
	    
		rewind(Ptr);
    	for(int i=0;i<TL;i++)
    	{
    		fread(&aux,sizeof(TpLocacoes),1,Ptr);
    		if(aux.ValorLocacao>valor && aux.Status == '1')
    		{
    			if(linha!=22)
    			{
    				gotoxy(33, linha); printf("%s", aux.CPFL);
		            gotoxy(51, linha); printf("%d", aux.CodCarroL);
		            gotoxy(59, linha); printf("%d", aux.QtdeDias);
		            gotoxy(68, linha); printf("R$ %.2f", aux.ValorLocacao);
		            achou++;
		            linha++;
    			}
				else
				{
					gotoxy(61,23); printf("[P]Proxima Pagina");
					op = toupper(getch());
					fflush(stdin);
					
					if(op == 'P')
					{
						LimparTela2(13);
						linha=13;
						gotoxy(33, linha); printf("%s", aux.CPFL);
			            gotoxy(51, linha); printf("%d", aux.CodCarroL);
			            gotoxy(59, linha); printf("%d", aux.QtdeDias);
			            gotoxy(68, linha); printf("R$ %.2f", aux.ValorLocacao);
			            achou++;
			            linha++;
					}
				}
    		}
    	}
    		
    	if(achou==0)
    	{
    		gotoxy(34,14); printf("Nenhuma Locacao tem um valor maior!");
    	}
    	
    	getch();
    	valor=0;
    }
    
    fclose(Ptr);
}

void RelaD()
{
	FILE *PtrClientes = fopen("Clientes.dat","rb");
	FILE *PtrCarros = fopen("Carros.dat","rb");
	FILE *PtrLocacoes = fopen("Locacoes.dat","rb");
	
	TpClientes auxCliente;
	TpCarros auxCarro;
	TpLocacoes auxLocacao;
	
	fseek(PtrLocacoes,0,2);
	int TLLocacao = ftell(PtrLocacoes)/sizeof(TpLocacoes);
	
	LimparTela();
	gotoxy(41, 7); printf("* * * Relatorio Geral * * *");
	for(int col=33;col<78;col++)
	{
	    gotoxy(col,9); printf("%c",196);
	}
	
	char resp;
	
	rewind(PtrLocacoes);
	
	for(int j=0;j<TLLocacao;j++)
	{
		int posCod, posCPF;
		
		fread(&auxLocacao,sizeof(TpLocacoes),1,PtrLocacoes);
		
		if(auxLocacao.Status=='1')
		{
			posCPF = SequencialIndexada(PtrClientes,auxLocacao.CPFL);
			
			fseek(PtrClientes,posCPF,0);
			fread(&auxCliente,sizeof(TpClientes),1,PtrClientes);
			
			gotoxy(33,10); printf("Nome: %s",auxCliente.Nome);
			gotoxy(33,11); printf("CPF: %s",auxLocacao.CPFL);
			gotoxy(54,11); printf("Telefone: %s",auxCliente.Telefone);
				
			gotoxy(33,13); printf("Cod Carro: %d",auxLocacao.CodCarroL);
				
			posCod = BuscaExaustiva(PtrCarros,auxLocacao.CodCarroL);
			
			fseek(PtrCarros,posCod,0);
			fread(&auxCarro,sizeof(TpCarros),1,PtrCarros);
				
			gotoxy(33,14); printf("Modelo: %s", auxCarro.Modelo);
			gotoxy(50,14); printf("Categoria: %s", auxCarro.Categoria);
			gotoxy(69,14); printf("R$:%.2f", auxCarro.PrecoDiaria);
			
			gotoxy(33,16); printf("Quant. de Dias: %d", auxLocacao.QtdeDias);
			gotoxy(53,16); printf("Valor Locacao: R$ %.2f", auxLocacao.ValorLocacao);
			gotoxy(61,22); printf("[P]Proxima Pagina");
				
				
			resp = toupper(getch());
			fflush(stdin);
				
			if(resp == 'P')
				LimparTela2(10);
			else
			{
				LimparTela2(10);
				j=TLLocacao;
			}
			
		}

	}
	gotoxy(44,13); printf("Relatorio Finalizado!");
	gotoxy(38,15); printf("Pressione qualquer tecla para sair.");
	getch();
	
	fclose(PtrClientes);
	fclose(PtrCarros);
	fclose(PtrLocacoes);
}

int main (void)
{
	CriarArquivos();
	
	char op;
	
	Inicio();
	
	do
	{
		op = MenuEscolha();
		
		switch(op)
		{
		 	case 'A':
		 		do
		 		{
		 			op = MenuClientes();
		 			
		 			switch(op)
		 			{
		 				case 'A':CadCliente();
								 break;
							
						case 'B':ExclusaoClientes();
								break;
						
						case 'C':AlterarClientes();
								break;
							
						case 'D':ListagemClientes();
								break;
		 			}
		 			
		 		}while(op!=27);
		 		break;
					
			case 'B':
				do{
				
					op = MenuCarros();
					
					switch(op)
					{
		 				case 'A':CadCarro();
								 break;
							
						case 'B':ExclusaoCarros();
								break;
						
						case 'C':AlterarCarros();
								break;
							
						case 'D':ListagemCarros();
								break;
								
		 				case 'E':OrdenarCodSelection();
								 break;
								 
		 				case 'F':OrdenarModeloBubble();
								 break;
					}
					
				}while(op!=27);
					break;
					
			case 'C':
					do
					{
						op = MenuLocacoes();
		 			
			 			switch(op)
			 			{
			 				case 'A':CadLocacao();
									 break;
								
							case 'B':ExclusaoLocacao();
									break;
							
							case 'C':AlterarLocacao();
									break;
								
							case 'D':ListagemLocacao();
									break;
			 			}
					}while(op!=27);
		 			break;
		 			
		 	case 'D':
					do
					{
						op = MenuRelatorios();
		 			
			 			switch(op)
			 			{
			 				case 'A':RelaA();
									 break;
								
							case 'B':RelaB();
									break;
							
							case 'C':RelaC();
									break;
								
							case 'D':RelaD();
									break;
			 			}
					}while(op!=27);
		 			break;	 		
		}
	}while(op!=13);
	ExclusaoFisicaClientes();
	ExclusaoFisicaCarros();
	ExclusaoFisicaLocacoes();
	

	
	return 0;
}
