#include<iostream>
#include<stdlib.h>
#include<conio.h>

 using namespace std;
 
  struct  Nodo{
  	int dato ;
  	Nodo *der;
  	Nodo *izq;
  };
 // Prototipos de funciones
 Nodo *arbol = NULL;
 Nodo *crearNodo(int);
 void insertarNodo(Nodo *&, int );
 void menu();
 void mostrarArbol(Nodo*,int);
 bool busqueda(Nodo *,int );
 void PreOrden(Nodo*);
 void inOrden(Nodo*);
 void PostOrden(Nodo*);
 
int main()
{
	menu();
	getch();
	return 0;
}

void menu()
{
	 int dato, opcion, contador =0;
	 
	  do {
	  	 cout<<"\t.:MENU:."<<endl;
	  	 cout<<"1.Insertar un nuevo nodo"<<endl;
	  	 cout<<"2.Mostrar arbol completo"<<endl;
	  	 cout<<"3.Buscar elemento en el arbol"<<endl;
	  	 cout<<"4.Recorrer el arbol en Pre-Orden"<<endl;
	  	 cout<<"5.Recorrer el arbol en In-Orden"<<endl;
	  	 cout<<"6.Recorrer el arbol en Pos-Orden"<<endl;
	  	 cout<<"7.Salir"<<endl;
	  	 cout<<"Opcion: ";
	  	 cin>>opcion;
	  	 
	  	 
	  	 switch (opcion){
		    case 1: cout<<"Digite un numero: ";
		   			 cin>> dato;
		    	insertarNodo(arbol,dato);
		    	cout<<"\n";
		    	system("pause");
		    	
			break;
		    case  2 :cout<<"\nMostrando arbol Completo : \n\n";
			mostrarArbol(arbol,contador);
			cout<<"\n";
			system("pause");
			break;
		    
		    case 3: cout<<"\n\nDigite el elemento que a buscar :"<<endl;
		    cin>>dato;
		    cout<<"\n";
		   
		    if (busqueda(arbol,dato) == true){
		    	cout<<"\n\nElemento "<<dato<<" Ha sido encontrado en el arbol\n\n";
			}
			else {
				cout<<"\n\nElemento no encontrado: ";
			}
			cout<<"\n";
			 system("pause");
			break;
		    
		     case 4: cout<<"\n\nRecorrido en Pre-Orden: ";
		     PreOrden(arbol);
		     cout<<"\n\n";
		     system("pause");
		     	 
		     	 break;
		     	 case 5:cout<<"\n\nRecorrido en In-Orden: ";
		     	 inOrden(arbol);
		     	 cout<<"\n\n";
		     	 system("pause");
				  break;
				  
				  case 6: cout<<"\n\nRecorrido en Post-Orden";
				  PostOrden(arbol);
				  cout<<"\n\n";
				  system("pause");
				  break;
				  
				  case 7: break;
		
		   }
		  
		   system("cls");
	  }while(opcion !=7);
}
 
 Nodo *crearNodo(int n){
 	
 	
 	Nodo *nuevo_nodo = new Nodo();
 	
 	 nuevo_nodo ->dato =n;
 	 nuevo_nodo ->  der= NULL;
 	 nuevo_nodo ->izq  = NULL;
 	 
 	 
 	 return nuevo_nodo;
	
 }
 //Insetar Nodo en el arbol
 void insertarNodo(Nodo *&arbol , int n ){
 	
 	 if (arbol ==NULL)
 	 {
 	 	
 	 Nodo *nuevo_nodo = crearNodo(n);
 	 arbol = nuevo_nodo;
	  }
	  else{// si el arbol tiene un nodo o mas de un nodo
	  	 int valorRaiz = arbol->dato; // Obtenemos el valor de la raiz
	  	 
	  	  if ( n <valorRaiz)// si el elemento es menor a la raiz insertamos en izq
	  	  {
	  	  	insertarNodo(arbol->izq,n);
	  	  	
			}
			else{ //si el elemento es mayor insertamos en el lado derecho
				insertarNodo(arbol->der,n);
			}	  	 
	  }
 }
 
 void mostrarArbol(Nodo *arbol,int cont){
 	
 	
 	 if (arbol ==NULL){// si el arbol esta vacio retorna
 	 	return;
 	 	
 	 	
	  }
	  else {
	  	mostrarArbol(arbol->der,cont+1);
	  	 for(int i = 0; i<cont; i++)
	  	 {
	  	 	cout<<"   ";
		   }
		   cout<<arbol->dato<<endl;
		   mostrarArbol(arbol->izq,cont +1);
	  }
 	 
 }
 
  bool busqueda(Nodo *arbol ,int n ){
  	 if (arbol ==NULL){
  	 		 return false;
	   }
	   else if (arbol->dato == n){//  si el nodo es igual al elemento retorna true
	   	 	return true;
			}
	   
	   else if (n<arbol->dato){// si el elemento es menor 
	   	return busqueda(arbol->izq,n);
			}
	   	 else {
	   	 	return busqueda(arbol->der,n);
			}

  }
 // Funcion para recorrido en profundida PreOrden
  void PreOrden(Nodo*arbol)
  {
  	if(arbol== NULL){//si el arbol esta vacio Retorna
  		return;
	  }
	  else {
	  	cout<<arbol->dato<<" - ";
	  	PreOrden(arbol->izq);
	  	PreOrden(arbol->der);
	  }
  }
 
 // funcion de recorrido del arbol en In- Orden
  void inOrden(Nodo* arbol) {
  	 if (arbol == NULL){
  	 	return;
	   }
	   else {
	   	
	   	  inOrden(arbol->izq);
	   	  cout<<arbol->dato<<" - ";	  
		   inOrden(arbol->der); 	
	   }
  }
 
  void PostOrden(Nodo*arbol)
  {
  	if (arbol ==NULL){
  		return;
	  }
	  else{
	  	PostOrden(arbol->izq);
	  	PostOrden(arbol->der);
	  	cout<<arbol->dato<<" - ";
	  }
   } 
 
 
 
 
 	
