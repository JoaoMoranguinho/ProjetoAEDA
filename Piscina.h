/*
 * Piscina.h
 *
 *  Created on: 11/10/2016
 *      Author: Morango
 */
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Cliente.h"
#include "Aula.h"
#ifndef PISCINA_H_
#define PISCINA_H_

using namespace std;

class Piscina {
	Data DataHoje;
	vector<Cliente> Clientes;
	vector<Aula> Aulas;
	vector<int> Pistas;
public:
////////////Print Lista Aulas////////////
	void PrintListaAulas() {
		for (size_t i = 0; i < Aulas.size(); i++) {
			if(!(Aulas[i].getData().getDia() != DataHoje.getDia() ||
					Aulas[i].getData().getMes() != DataHoje.getMes() ||
					Aulas[i].getData().getAno() != DataHoje.getAno()))
			{
			cout << Aulas[i].getData().getDia() << "/"
					<< Aulas[i].getData().getMes() << "/"
					<< Aulas[i].getData().getAno() << "<->Modalidade: "
					<< Aulas[i].getNome() << "<->Hora: " << Aulas[i].getHora()
					<< "<->Capacidade: " << Aulas[i].getCapacidade() << endl;
			}
		}
	}
////////////Seek User////////////
	bool seekUser(string nomecliente) {
		Cliente c1;
		c1.setNome(nomecliente);
		for (size_t i = 0; i < Clientes.size(); i++) {
			if (Clientes[i] == c1)
				return true;
		}
		throw UserNaoExiste(nomecliente);
		return false;
	}
////////////Entra Cliente////////////
	void Entra(Cliente c1) {
		int input;
		float n2;
		string n1;
		Report r;

		cout << "Modo de Utilizacao: |1|Aula| |2|Livre|\n";
		cin >> input;

		//Modo Aula
		if (input == 1) {
			cout << "Nome da aula: ";
			cin >> n1;
			cout << "\nHora da Aula: ";
			cin >> n2;

			//Encontrar aula
			if (seekAula(DataHoje, n1, n2)) {

				cout << "Aula encontrada!\n";
				cout << "Capacidade: "
						<< getAula(DataHoje, n1, n2).getCapacidade();

				//Ver capacidade
				if (getAula(DataHoje, n1, n2).getCapacidade() > 0) {
					c1.setPresente(true);
					c1.setModo(n1);
					getAula(DataHoje, n1, n2).plus1();
					cout << "\nEntrou! Boa Aula!\n";
					cout << "Capacidade: "
							<< getAula(DataHoje, n1, n2).getCapacidade();
					updateAulas(Aulas);
				} else
					cout << "\nErro! Aula Cheia!\n";

			}

			else
				cout << "Nao foi possivel encontrar a Aula" << endl;

		}

		//Modo Livre
		if (input == 2) {
			cout << "Atual Capacidade das pistas livres: ";
		}

	}
////////////Print Lista Clientes////////////
	void PrintListaClientes() {
		for (size_t i = 0; i < Clientes.size(); i++) {
			cout << Clientes[i].getId() << " " << Clientes[i].getNome() << " "
					<< Clientes[i].getCartaoCidadao() << "\n";
		}
	}
////////////Adicionar Cliente////////////
	void AdicionaCliente(Cliente c) {
		Clientes.push_back(c);
	}
////////////Load dos Clientes em txt////////////
	vector<Cliente> LoadClientes() {
		vector<Cliente> clientes;
		ifstream infile;
		infile.open("clientes.txt");
		if (infile.fail()) {      //Opening Fail
			cout << "File could not be opened\n";
			exit(EXIT_FAILURE);
		} else {
			Cliente c;
			string String;
			getline(infile, String);
			while (infile) {
				int pos = String.find_last_of(";");
				int pos2 = String.find_first_of(";");
				c.setId(atoi(String.substr(0, pos2).c_str()));
				if (c.getId() < 10)
					c.setNome(String.substr(pos2 + 1, pos - 2));
				else
					c.setNome(String.substr(pos2 + 1, pos - 3));

				c.setCartao(atoi(String.substr(pos + 1).c_str()));

				clientes.push_back(c);
				getline(infile, String);
			}

		}
		return clientes;

	}
	//ToDo Modalidade Errada
////////////Load das Aulas em txt////////////
	vector<Aula> LoadAulas() {
		vector<Aula> aulas;
		ifstream infile;
		infile.open("aulas.txt");
		if (infile.fail()) {      //Opening Fail
			cout << "File could not be opened\n";
			exit(EXIT_FAILURE);
		} else {
			Aula c;
			Data d;
			string String;
			getline(infile, String);
			while (infile) {
				int pos = String.find_first_of("|");
				int pos2 = String.find_first_of(";");
				int pos4 = String.find_last_of("/");
				int pos5 = String.find_first_of("|");

				cout << "Pos" << pos2;

				d.setDia(atoi(String.substr(0, 2).c_str()));
				d.setMes(atoi(String.substr(pos4 - 2, pos4 + 1).c_str()));
				d.setAno(atoi(String.substr(pos4 + 1, pos4 + 3).c_str()));
				c.setData(d);

				c.setNome(String.substr(pos - 1, pos2 ));

				c.setHora(atof(String.substr(pos + 1, pos + 4).c_str()));

				c.setCapacidade(
						atoi(String.substr(pos5 + 1, pos5 + 2).c_str()));

				Aulas.push_back(c);
				getline(infile, String);
			}

		}
		return Aulas;

	}

////////////////////////////////Update File/////////////////////////////
	void updateAulas(vector<Aula> aulas) {
		////Escreve para dentro de ficheiro///////////
		ofstream myfile;
		myfile.open("aulas.txt", ofstream::out);

		if (myfile.is_open()) {
			for (size_t k = 0; k < Aulas.size(); k++) {

				myfile << Aulas[k].getData().getDia() << "/"
						<< Aulas[k].getData().getMes() << "/"
						<< Aulas[k].getData().getAno() << ";"
						<< Aulas[k].getNome() << ";" << Aulas[k].getHora()
						<< "|" << Aulas[k].getCapacidade() << endl;

			}

			myfile.close();
		}

		else {
			cout << "Unable to find file!";

		}
	}

////////////Seek Aula////////////
		bool seekAula(Data d1, string n1, float n2) {
			Aula a1 = Aula(d1, n1, n2);

			for (size_t i = 0; i < Aulas.size(); i++) {
				if (Aulas[i] == a1)
				return true;
			}

			return false;
		}

////////////Get Aula////////////
		Aula
		getAula(Data d1, string n1, float n2) {
			Aula a1 = Aula(d1, n1, n2);

			for (size_t i = 0; i < Aulas.size(); i++) {
				if (Aulas[i] == a1)
				return Aulas[i];
			}

			return a1;
		}

////////////Setters e Getters////////////
		void setClientes(vector<Cliente> clientes) {
			Clientes = clientes;
		}

		vector < Cliente > getClientes()
		{
			return Clientes;
		}

		void setAulas(vector<Aula> aulas) {
			Aulas = aulas;
		}

		vector < Aula > getAulas()
		{
			return Aulas;
		}

		Data
		getData()
		{
			return DataHoje;
		}

	void setData(Data d1) {
		DataHoje = d1;
	}

}
;

#endif /* PISCINA_H_ */
