/*
 * Professor.h
 *
 *  Created on: 27/10/2016
 *      Author: Morango
 */
#ifndef PROFESSOR_H_
#define PROFESSOR_H_
#include <string>
#include "Data.h"
#include "Cliente.h"

class Professor{
	vector<Aula> Aulas;
public:

	vector<Aula> getAulas(){
		return Aulas;
	}

	void setAulas(vector<Aula>a1){
		Aulas = a1;
	}
};



#endif /* PROFESSOR_H_ */
