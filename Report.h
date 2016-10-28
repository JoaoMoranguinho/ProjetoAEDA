#ifndef _Report_
#define _Report_
#include <string>
#include "Data.h"

using namespace std;

class Report {
	string cliente;
	Data data;
	string modo;

public:

	Data getData() {
		return data;
	}

	void setData(Data d1) {
		data = d1;
	}

	string getModo() {
		return modo;
	}

	void setModo(string m1) {
		modo = m1;
	}

	string getCliente(){
		return cliente;
	}

	void setCliente(string c1){
		cliente = c1;
	}
};

#endif
