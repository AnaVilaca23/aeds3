

#include<iostream>
using namespace std;

struct No {

int chave;//conteudo que ele guarda
No *esq;
No *dir;

};

struct ArvoreBinaria{
No *raiz;
void Criar();
No * Inserir(No *noAtual, int valor);
bool Pesquisar(No *noAtual,int valor);
void Inserir_semretorno(int valor);
void Imprime_ordem(No* noAtual);
void Imprime_preordem(No* noAtual);
void Imprime_posordem(No* noAtual);
void verificaFilhos(No* noAtual);
};

void ArvoreBinaria::Criar(){

raiz=NULL;

}
No * ArvoreBinaria::Inserir(No *noAtual, int valor){

if(noAtual==NULL){
    noAtual= new No;
    noAtual->dir=NULL;
    noAtual->esq=NULL;
    noAtual->chave=valor;
}else if(valor<noAtual->chave){// verificar se vai pra esq ou dir
    noAtual->esq= Inserir(noAtual->esq, valor);

}else {
        noAtual->dir= Inserir(noAtual->dir, valor);
}

return noAtual;

}


bool ArvoreBinaria::Pesquisar(No* noAtual, int valor){

if(noAtual==NULL){

return false;
}else if(noAtual->chave== valor){
    return true;
}else{
    if(valor<noAtual->chave){
        Pesquisar(noAtual->esq, valor);
    } else {
         Pesquisar(noAtual->dir, valor);
    }

}
}

void ArvoreBinaria::Inserir_semretorno(int valor){

raiz=Inserir(raiz, valor);
}

void ArvoreBinaria::Imprime_ordem(No* noAtual){

if(noAtual!=NULL){
    Imprime_ordem(noAtual->esq);
    cout<<"Elemento visitado foi o "<<noAtual->chave<<endl;
    Imprime_ordem(noAtual->dir);

}
}

void ArvoreBinaria::Imprime_preordem(No * noAtual){  
    if(noAtual != NULL){
        cout<<"Elemento visitado foi o "<< noAtual-> chave<< endl;
        Imprime_preordem(noAtual->esq);
        Imprime_preordem(noAtual->dir);
    }
}

void ArvoreBinaria::Imprime_posordem(No * noAtual){
    if(noAtual != NULL){
        Imprime_posordem(noAtual->esq);
        Imprime_posordem(noAtual->dir);
         cout<<"Elemento visitado foi o  "<<noAtual->chave<<endl;
    }
}

void ArvoreBinaria::verificaFilhos(No* noAtual){
        Imprime_posordem(noAtual->esq);
        Imprime_posordem(noAtual->dir);
        cout<<"Elemento visitado foi o  "<<noAtual->chave<<endl;
        if ((noAtual->esq==NULL) && (noAtual->dir==NULL)){
            cout<<"O nó visitado não possui filhos";
    }
}

int main(){
ArvoreBinaria arv;
arv.Criar();
arv.Inserir_semretorno(15);



if(arv.Pesquisar(arv.raiz,28)){
        cout<<"Elemento foi encontrado"<<endl;

   }else{
     cout<<"Elemento não foi encontrado"<<endl;

}

cout<<"Impressão em ordem"<<endl;
arv.Imprime_ordem(arv.raiz);

cout<<"Impressão em pre ordem"<<endl;
arv.Imprime_preordem(arv.raiz);

cout<<"Impressão em pos ordem"<<endl;
arv.Imprime_posordem(arv.raiz);

arv.verificaFilhos(arv.raiz);
return 0;
}


