#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

#define MAX_L 200
#define MAX_C 20

void lerDados(string arquivoEmCSV, float vetor[], float matriz[][MAX_C], string classes[]){

    int linhaAtual = 0;
    ifstream csv(arquivoEmCSV);
    if(csv.is_open()){
        string linha;
        getline(csv, linha);
        while (getline(csv, linha)) {
            stringstream ss(linha);
            string id;
            getline(ss, id, ',');

            string durabilidade;
            getline(ss,durabilidade, ',');

            string qldd;
            getline(ss, qldd, ',');

            string classe;
            getline(ss, classe);

            vetor[linhaAtual] = stof(id);
            matriz[linhaAtual][0] = stof(durabilidade);
            matriz[linhaAtual][1] = stof(qldd);
            classes[linhaAtual] = classe;

            linhaAtual++;
        }
        csv.close();
    }
}

double distEuclidiana(float a[], float b[]){

    float dist = 0;
    for (int i = 0; i < 2; i++){
        dist = dist + pow(a[i] - b[i], 2);
    }
    return sqrt(dist);
}

double distManhattan(float a[], float b[]){

    float dist = 0;
    for(int i = 0; i < 2; i++){
        dist = dist + abs(a[i] - b[i]);
    }
    return dist;
}

void encontrarVizinhos(string m[], int n[], int a){

     for(int i = 0; i < a; i++){
        cout << "Vizinho" << i+1 << ": " << m[n[i]] << endl;
    }
}

string classePrevista(string m[], int n[], int a){

    string tagFin = " ";
    int maiorQntd = 0;
    bool empate;

    for(int i = 0; i < a; i++){
        int qntd = 0;
        for(int j = 0; j < a; j++){
            if(m[n[i]] == m[n[j]]){
                qntd++;
            }
        }

        if(qntd > maiorQntd){
            maiorQntd = qntd;
            tagFin = m[n[i]];
            empate = false;
        }else if(qntd == maiorQntd && m[n[i]] != tagFin){
            empate = true;
        }

        if(empate){
            return m[n[0]];
        }
    }
    return tagFin;
}

void organizar(float banana[], int maca[], int tamanhoDesejado){

    for(int i = 0; i < tamanhoDesejado; i++){
        for(int j = 0; j < tamanhoDesejado; j++){
            if(banana[i] < banana[j]){
                float bAux = banana[i];
                banana[i] = banana[j];
                banana[j] = bAux;

                int mAux = maca[i];
                maca[i] = maca[j];
                maca[j] = mAux;

            }
        }
    }
}

int main(){

    float ids[MAX_L];
    float dados[MAX_L][MAX_C];
    string tags[MAX_L];
    lerDados("dados.csv", ids, dados, tags);

    float novoEx[2];
    cout << "Passe a Durabilidade do produto :" << endl;
    cin >> novoEx[0];
    novoEx[0] = int(novoEx[0]);
    cout << "Agora diga a qualidade do produto: " << endl;
    cin >> novoEx[1];

    int opcao;
    cout << "Qual maneira deseja escolher?" << endl;
    cout << "1 - Euclidiana | 2 - Manhattan" << endl;
    cin >> opcao;
    while(opcao != 1 && opcao != 2){
        cout << "Escolha inválida" << endl;
        cin >> opcao;
    }

    float distancias[MAX_L];
    cout << endl;

    if(opcao == 1){
        for(int i = 0; i < 10; i++){
            distancias[i] = distEuclidiana(novoEx, dados[i]);
        }
    } else {
        for(int i = 0; i < 10; i++){
            distancias[i] = distManhattan(novoEx, dados[i]);
        }
    }

    for(int i = 0; i < 10; i++){
        cout << distancias[i] << " | ";
    }

    int ordem[MAX_L];
    for(int i = 0; i < 10; i++){
        ordem[i] = i;
    }

    organizar(distancias, ordem, 10);

    int k;
    cout << endl;
    cout << "Digite o valor de k: ";
    cin >> k;

    while(k <= 0 || k > 10){
        cout << "Este valor é maior que o numero de vizinhos existentes.";
        cin >> k;
    }

    encontrarVizinhos(tags, ordem, k);

    string resultado = classePrevista(tags, ordem, k);
    cout << endl << "Classe Prevista: " << resultado << endl;

    return 0;
}
