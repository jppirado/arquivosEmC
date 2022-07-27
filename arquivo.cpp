#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>


using namespace std ;

struct lista{

char nome[100];
char telefone[11];
char email[100];

};



void criarContato( string  n , string t , string e ){

lista list ;

fstream arquivoLista("lista.dat" , ios::out|ios::in);

arquivoLista.seekp(0 ,arquivoLista.end);

strcpy( list.nome, n.c_str());
strcpy( list.email, e.c_str());
strcpy( list.telefone, t.c_str());

arquivoLista.write( ( const char * ) (&list) , sizeof(lista));

arquivoLista.close();


}

void listarContatos( ){

lista list ;
lista aux ; 

	fstream arquivoLista("lista.dat" ,  ios::in|ios::out);


	arquivoLista.read( (char *) (&list), sizeof(lista));
	
	while( arquivoLista && !arquivoLista.eof() ){
		if( strcmp( list.nome,aux.nome) == 1 ){
			cout << "Nome " << list.nome << " Telefone " <<  list.telefone << " Email " << list.email << endl;
		}
	
	arquivoLista.read( ( char * ) (&list) , sizeof(lista)) ;

	}

	arquivoLista.close( );


}

void listaContato( string n ){

	lista list ;
	
	fstream arquivoLista("lista.dat" ,  ios::in|ios::out);
	
	
		arquivoLista.read( (char *) (&list), sizeof(lista));
		
			while( arquivoLista && !arquivoLista.eof() ){
			
			if( strcmp( list.nome , n.c_str() ) == 0 ){
			
			cout << "Nome " << list.nome << " Telefone " <<  list.telefone << " Email " << list.email << endl;
			return;
			}
			
		arquivoLista.read( ( char * ) (&list) , sizeof(lista)) ;
		
		}
	
	cout << "Seu Contato nao existe " << endl;
	
	arquivoLista.close( );
	
	}

bool deleteContato( string te){
	
	lista list ;
	
	fstream arquivoLista("lista.dat" ,  ios::in|ios::out);
	
	
	arquivoLista.read( (  char *) (&list) ,sizeof( lista ) );
	
	while( arquivoLista && ! arquivoLista.eof( ) ){
	
	if( strcmp( list.nome , te.c_str() ) == 0 ){
	
		strcpy(list.nome ,	 ""); 
		strcpy(list.email , "");
		strcpy(list.telefone , "");
	
	arquivoLista.seekg(( long ) arquivoLista.tellg() - sizeof(lista));
	arquivoLista.write((const char *) (&list) , sizeof(lista));
	arquivoLista.close( );
	return true;

}

arquivoLista.read( ( char * ) (&list) , sizeof(lista));

}

arquivoLista.close();
return false;

}


int main ( ){

string no  , te , em ;
int op ;
fstream arquivoLista("lista.dat",ios::out|ios::app);
arquivoLista.close();


do {


cout << endl << "Lista Telefonica" << endl;
cout << "1 - Adicionar Contato" << endl;
cout << "2 - Listar dados" << endl;
cout << "3 - Listar toda a lista" << endl;
cout << "4 - Excluir" << endl;
cout << "Informe a opcao: ";
cin >> op;

if (op==1) {

 cout << "Digite o Nome " << endl;
 cin.ignore();
 getline(cin , no );
 cout << "Digite seu telefone " << endl;
 getline(cin , te );
 cout << "Digite seu email " << endl;
 getline(cin , em );

  criarContato(no, te , em );
 
 
}

if( op == 2){

cout << "Digite o nome " <<endl;
cin.ignore();
getline( cin , no);

listaContato(no);

}

if( op == 3 ){

listarContatos( );

}

if( op == 4 ){
cout << "digite o cotato para deletar" << endl;
cin.ignore();
getline( cin , no );

if(!deleteContato(no) ){
cout <<"nao foi possivel apagar o contto" << endl;
}else{
cout << "Contato apagaado com sucesso" << endl;
}

}




} while(op!=9);

}
