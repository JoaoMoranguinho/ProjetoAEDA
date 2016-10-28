/*
 * Cliente.h
 *
 *  Created on: 11/10/2016
 *      Author: Morango
 */
#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_
#include <string>
#include "Data.h"
#include "Report.h"

using namespace std;

class Cliente {
	int Id;
	string Nome;
	int CartaoCidadao;
	bool Aula;
	bool Presente;
	string Modo;
	vector<Report>Reports;
public:
	//Cliente();

	bool operator==(Cliente c1) {
		if (Nome == c1.Nome)
			return true;
		return false;
	}

////////////Setters e Getters////////////
	void setNome(string nome) {
		Nome = nome;
	}

	string getNome() {
		return Nome;
	}

	void setId(int id) {
		Id = id;
	}

	int getId() {
		return Id;
	}

	void setCartao(int cartao) {
		CartaoCidadao = cartao;
	}

	int getCartaoCidadao() {
		return CartaoCidadao;
	}

	string getModo() {
		return Modo;
	}

	void setModo(string modo) {
		Modo = modo;
	}

	bool getPresente() {
		return Presente;
	}

	void setPresente(bool p) {
		Presente = p;
	}

};

class UserNaoExiste {
		string nome;
	public:
		UserNaoExiste(){}
		UserNaoExiste(string n1){
			nome=n1;
		}
		string getNome(){
			return nome;
		}

		void setNome(string n1){
			nome = n1;
		}

	};

#endif /* SRC_CLIENTE_H_ */
