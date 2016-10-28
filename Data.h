#ifndef _Data_
 #define _Data_



class Data{

private:
	int Dia;
	int Mes;
	int Ano;

public:
	Data(){
		Dia = 0;
		Mes = 0;
		Ano = 0;
	}
	Data(int Dia, int Mes, int Ano){
		this->Dia =Dia;
		this->Mes = Mes;
		this->Ano = Ano;
	}

	int getAno() const {
		return Ano;
	}

	void setAno(int ano) {
		Ano = ano;
	}

	int getDia() const {
		return Dia;
	}

	void setDia(int dia) {
		Dia = dia;
	}

	int getMes() const {
		return Mes;
	}

	void setMes(int mes) {
		Mes = mes;
	}

	bool bigger(Data &data)
	{
		if(this->Ano == data.Ano && this->Mes == data.Mes && this->Dia > data.Dia)
			return true;
		else if(this->Ano < data.Ano)
			return false;
		else if(this->Ano == data.Ano && this->Mes < data.Mes)
			return false;
	}

	bool smaller(Data &data)
		{
			if(this->Ano == data.Ano && this->Mes == data.Mes && this->Dia < data.Dia)
				return true;
			else if(this->Ano > data.Ano)
				return false;
			else if(this->Ano == data.Ano && this->Mes > data.Mes)
				return false;
		}



	bool operator==(const Data &data) const{
		if(this->Ano == data.Ano && this->Mes == data.Mes && this->Dia == data.Dia)
			return true;
		else
			return false;
	}
};

#endif
