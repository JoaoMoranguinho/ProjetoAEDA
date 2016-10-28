/*
 * Aula.h
 *
 *  Created on: 12/10/2016
 *      Author: Morango
 */

#ifndef AULA_H_
#define AULA_H_
#include <string>
#include "Data.h"
#include "Cliente.h"

using namespace std;

class Aula {
	Data data;
	string nome;
	float hora;
	int capacidade;
public:
	Aula(){}
	Aula(Data d1, string n1, float h1) {
		data = d1;
		nome = n1;
		hora = h1;
		capacidade = 20;
	}

	void plus1(){
		capacidade--;
	}

	bool operator==(Aula a1) {
		if (nome == a1.nome && data == a1.data && hora == a1.hora)
			return true;
		return false;
	}
	string getNome() {
		return nome;
	}
	void setNome(string n1) {
		nome = n1;
	}

	float getHora() {
		return hora;
	}

	void setHora(float h1) {
		hora = h1;
	}

	int getCapacidade(){
		return capacidade;
	}

	void setCapacidade(int c1){
		capacidade=c1;
	}

	void setData(Data d1){
		data=d1;
	}

	Data getData(){
		return data;
	}
};

#endif /* AULA_H_ */
