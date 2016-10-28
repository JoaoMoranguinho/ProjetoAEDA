/*
 * main.cpp
 *
 *  Created on: 11/10/2016
 *      Author: Morango
 */
#include <stdio.h>
#include <iostream>
#include "Piscina.h"
#include "Cliente.h"

using namespace std;

string input1, input2, input3, nomecliente, apelidocliente;
Cliente c1, c2;
Piscina p;

int diaHoje, mesHoje, anoHoje;

int main() {
	p.setClientes(p.LoadClientes());
	p.setAulas(p.LoadAulas());

	cout << "Insira a Data de hoje para configurar as suas aulas" << endl;
	cout << "Dia: ";
	cin >> diaHoje;
	cout << "Mes: ";
	cin >> mesHoje;
	cout << "Ano: ";
	cin >> anoHoje;

	p.setData(Data(diaHoje, mesHoje, anoHoje));

	cout << "|PISTA 1| |PISTA 2| |PISTA 3|\n"
			<< "|       | |       | |       |\n"
			<< "| AULAS | | LIVRE | | LIVRE |\n"
			<< "|       | |       | |       |\n";

	do {
		cout << "Insira o PRIMEIRO nome do Utilizador: (0 para sair)";
		cin >> nomecliente;
		cout << "Insira o APELIDO do Utilizador: (0 para sair)";
		cin >> apelidocliente;

		// Tentar lancar excepcao UserNaoExiste
		if (!(nomecliente == "0" && apelidocliente == "0")) {
			try {
				p.seekUser(nomecliente + " " + apelidocliente);
			} catch (UserNaoExiste u1) {
				cout << "User: " << u1.getNome() << " Nao Existe" << endl;
				continue;

			}
		} else
			break;

		//if (p.seekUser(nomecliente + " " + apelidocliente)) {
			do {
				cout
						<< "||||||||||||||||||||||||||||||Bem-Vindo ao nosso site||||||||||||||||||||||||||||||\n";
				cout
						<< "Escolha uma das opcoes inserindo o numero pretendido\n";
				cout
						<< "|1|Lista de Clientes|  |2|Horarios das Aulas|  |3|Consultar Vagas| |4|Entrar| \n";
				cin >> input1;

				//Lista de Clientes
				if (input1 == "1")
					p.PrintListaClientes();

				//Lista de Aulas
				if (input1 == "2") {
					p.PrintListaAulas();
				}

				if (input1 == "3") {

				}

				//ToDo Entrar
				if (input1 == "4") {
						p.Entra(c1);
				}

			} while (input1 != "0");
			break;

		//} else
			//cout << "Utilizador nao encontrado, tente novamente.\n";

	} while (nomecliente != "0");

	cout
			<< "||||||||||||||||||||||||||||||OBRIGADO||||||||||||||||||||||||||||||\n";
	return 0;
}

