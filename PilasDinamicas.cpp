# include <iostream>
# include <stdlib.h>
using namespace std;
struct pilas
{
	int valor;
	pilas *direccionA;
};
pilas *pilao,*pilaaux;
void ingreso();
void mostrar();
void eliminar();
void buscar();
int main()
{
	int opcion;
	while(true){
		cout<<"1 Ingreso de datos a la pila"<<endl;
		cout<<"2 Leer datos de la pila"<<endl;
		cout<<"3 Eliminar datos de la pila"<<endl;
		cout<<"4 Buscar datos en la pila"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:{
				ingreso();
				break;
			}
			case 2:{
				mostrar();
				break;
			}
			case 3:{
				eliminar();
				break;
			}
			case 4:{
				buscar();
				break;
			}

			
		}
	}
}
void ingreso(){
	if(pilao==NULL){
		pilao=new(pilas);
		cout<<"Mi Direccion "<<pilao<<endl;
		cout<<"Ingrese PRIMER dato a la pila"<<endl;
		cin>>pilao->valor;
		cout<<"Dato ingresado correctamente"<<endl;
		pilao->direccionA=NULL;
		cout<<"Direccion Anterior "<<pilao->direccionA<<endl;
		return;
	}
	pilaaux=new(pilas);
	cout<<"Ingrese dato a la pila"<<endl;
	cout<<"Mi Direccion "<<pilaaux<<endl;
	cin>>pilaaux->valor;
	cout<<"Dato ingresado correctamente"<<endl;
	pilaaux->direccionA=pilao;
	cout<<"Direccion Anterior "<<pilaaux->direccionA<<endl;
	pilao=pilaaux;
}
void mostrar(){
	if(pilao==NULL){
		cout<<"No hay datos en la pila"<<endl;
	}
	pilaaux=pilao;
	cout<<"Los datos de la pila son: "<<endl;
	while(pilaaux!=NULL){
		cout<<pilaaux->valor<<endl;
		pilaaux=pilaaux->direccionA;
	}
	cout<<"FIN"<<endl;
}
void eliminar(){
	if(pilao==NULL){
		cout<<"No hay datos en la pila"<<endl;
		return;
	}
	pilaaux=new(pilas);
	pilaaux=pilao;
	cout<<"Elemento eliminado "<<pilaaux->valor<<endl;
	pilao=pilaaux->direccionA;
	delete(pilaaux);
}
void buscar(){
	if(pilao==NULL){
		cout<<"La pila esta vacia"<<endl;
		return;
	}
	int buscardatos;
	bool encontrado=false;
	pilaaux=pilao;
	cout<<"Ingrese dato a buscar"<<endl;
	cin>>buscardatos;
	while(pilaaux!=NULL){
		if(buscardatos==pilaaux->valor){
			cout<<"Encontrador, el valor es; "<<pilaaux->valor<<endl;
			encontrado=true;
			break;
		}
		pilaaux=pilaaux->direccionA;
	}
	if(encontrado==false){
		cout<<"No se encontro el valor"<<endl;
	}
}
