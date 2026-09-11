# Classificador kNN em C++
 
Implementação do algoritmo **k-Nearest Neighbors (kNN)** em C++, desenvolvida para classificar produtos em categorias (`A` ou `B`) com base em dois atributos: **durabilidade** e **qualidade**.
 
O programa lê uma base de dados a partir de um arquivo CSV, recebe um novo exemplo digitado pelo usuário, calcula a distância desse exemplo até cada ponto da base e retorna a classe mais votada entre os `k` vizinhos mais próximos.
 
## Como funciona
 
1. Os dados de treino são carregados a partir de `dados.csv`.
2. O usuário informa a durabilidade e a qualidade de um novo produto.
3. O usuário escolhe a métrica de distância:
   - **Euclidiana**
   - **Manhattan**
4. O programa calcula a distância do novo exemplo até cada ponto da base e ordena os resultados do mais próximo ao mais distante.
5. O usuário escolhe o valor de `k` (quantidade de vizinhos considerados).
6. O programa exibe os `k` vizinhos mais próximos e retorna a classe prevista, com base na votação por maioria entre eles.
## Formato do dataset (`dados.csv`)
 
| Coluna | Descrição |
|---|---|
| `IDs` | Identificador do produto |
| `Durabilidade` | Nota de durabilidade do produto |
| `Qualidade` | Nota de qualidade do produto |
| `Classes` | Classe conhecida do produto (`A` ou `B`) |
 
Exemplo:
 
```csv
IDs,Durabilidade,Qualidade,Classes
0,8,10,A
1,6,9.1,A
2,3,9.7,A
3,9,5.7,B
```
 
> O arquivo `dados.csv` deve estar na mesma pasta do executável.
 
## Como compilar e executar
 
```bash
g++ Classificador_kNN.cpp -o classificador
./classificador
```
 
## Exemplo de uso
 
```
Passe a Durabilidade do produto:
7
Agora diga a qualidade do produto:
8.5
Qual maneira deseja escolher?
1 - Euclidiana | 2 - Manhattan
1
 
Digite o valor de k: 3
Vizinho1: A
Vizinho2: A
Vizinho3: B
 
Classe Prevista: A
```
 
## Estrutura do código
 
- `lerDados` — lê e converte os dados do CSV para os vetores/matrizes usados pelo programa.
- `distEuclidiana` / `distManhattan` — calculam a distância entre dois pontos, de acordo com a métrica escolhida.
- `organizar` — ordena os exemplos da base por distância crescente até o novo ponto (seleção direta).
- `encontrarVizinhos` — exibe os `k` vizinhos mais próximos.
- `classePrevista` — define a classe prevista por votação majoritária entre os `k` vizinhos.
## Possíveis melhorias futuras
 
- Tornar o número de exemplos da base dinâmico (hoje o cálculo de distâncias está fixado nos 10 primeiros registros).
- Permitir mais de dois atributos por exemplo.
- Ler o nome do arquivo CSV como parâmetro, em vez de fixo no código.
- Adicionar validação de entrada mais robusta.
## Tecnologias
 
- C++ (padrão)
- Bibliotecas: `iostream`, `fstream`, `sstream`, `string`, `cmath`
## Autor
 
Enzo Leonardo Ferreira Gonçalves
[GitHub](https://github.com/enzolfg09) · [LinkedIn](https://www.linkedin.com/in/enzo-leonardo-ferreira-gonçalves-a5483530b/)
