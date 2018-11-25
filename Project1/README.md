# **TP PDSII - Classe para Busca em Arquivos**
* **Dupla:** André Domingos Cursino e Roberto Demétrio Neves Júnior
* **Turma:** TFI - Engenharia de Controle e Automação

## **Documentação da Classe**

### **Métodos Públicos**

#### **void Inserir_Livro(string nome, string caminho)**
<p>Nome: Título do livro</p>
<p>Caminho: Caminho até o arquivo txt do livro. (Ex: C:\\livro.txt)</p>
<p>Essa função é utilizada para inserir um novo livro ao grupo de livros nos quais as buscas serão realizadas(pool de busca).</p>

#### **void Remover_Livro(string nome)**
<p>Nome: Título do livro</p>
<p>Essa função é utilizada para remover um livro do pool de busca.</p>


#### **int Quantidade_Livros()**
<p>Essa função retorna um inteiro que representa a quantidade de livros já inseridos no pool de busca.</p>

#### **void Limpa_Livros()**
<p>Essa função é utilizada para remover todos os livros do pool de busca.

#### **std::map\<string, std::set\<string\>\> Buscar(string fraseDigitada)**
<p>Frase Digitada: Grupo de palavras que o usuário deseja procurar, separadas por espaços</p>
<p>Essa função é responsável por realizar todo o mecanismo de busca que é o objetivo final da classe. A função recebe uma string como argumento e realiza a busca das palavras dessa string dentro do pool de livros.</p>
<p>A função retorna uma estrutura do tipo MAP, na qual a chave é a palavra buscada e o valor é uma estrutura do tipo SET, que contém os nomes dos livros que contêm aquela chave.</p>

### **Métodos Privados (Fins acadêmicos)**

#### **void Buscar_Frase(string fraseBusca)**
<p>Frase Busca: String a ser procurada</p>
<p>Essa função realiza a busca propriamente dita, entretanto, não retorna valor, somente armazena o resultado dentro do MAP (estrutura explicitada na justificativa). Essa separação (dessa função e a função pública que retorna o mapa) busca viabilizar a utilização do mecanismo de busca por outros métodos sem a necessidade do retorno de uma variável tão específica quanto um MAP\<string, set\<string\>\>. Ou seja, busca deixar um caminho para a construção de uma classe mais dinâmica, suscetível a futuras alterações.</p>

#### **string Arrumar_Palavra(string palavra)**
<p>Palavra: Palavra que será ajustada de acordo com as requisições do trabalho.</p>
<p>Essa função é responsável por ajustar a input do usuário, que, para correto funcionamento da classe deve ser constituída por letras minúsculas e números.</p>

#### **std::set\<string\> Busca_Nos_Arquivos(string palavra)**
<p>Palavra: Palavra que será buscada dentro de todos os arquivos.</p>
<p>Essa função organizará um SET com todos os arquivos que contêm a palavra passada como argumento. Ela não faz a varredura dos arquivos, somente trigga a função responsável, informando os arquivos a serem varridos e organizando as respostas.</p>

#### **bool Varre_Arquivo(string caminho, string palavra)**
<p>Caminho: Caminho do arquivo que será aberto e varrido.</p>
<p>Palavra: Palavra que será procurada dentro daquele arquivo.</p>
<p>Essa função realiza a abertura e varredura dos livros, retornando se o livro contém ou não aquela palavra.</p>

## **Justificativa da Estruturação**
<p>Nesse projeto, buscamos aumentar o nível de abstração ao máximo, de forma que todo o processo de busca seja invisível(transparente) ao usuário da classe.</p>
<p>Foi utilizada a estrutura <strong>MAP</strong> para organizar a busca, primeiramente por ser uma requisição do trabalho, mas também por ser a estruturação mais lógica para realizar a tarefa de relacionar as palavras com os resultados das buscas.</p>
<p>Também foi utilizado <strong>MAP</strong> para estruturar os livros no pool de busca, buscando viabilizar a "Nomeação" do livro. Com essa estrutura, o usuário pode ter um arquivo de texto com o nome diferente do escolhido como título do livro. (<strong>Exemplo:</strong> Livro: <em>João e Maria</em>  Arquivo: <em>joaoemaria.txt</em>)</p>
<p>Como Valor relacionada a cada chave na estrutura <strong>MAP</strong> de busca foi utilizada a estrutura <strong>SET</strong>, a qual foi uma forma encontrada de relacionar os múltiplos títulos de livros que resultaram da busca, sem perder a individualidade de cada um, ou seja, cada título do resultado pode ser obtido separadamente ainda que todos estejam relacionados em um mesmo SET.</p>
<p>Por fim, nota-se que o processo de busca é separado em diversas pequenas funções privadas, as quais são todas chamadas quando o usuário chama a função pública Buscar. Essa divisão em múltiplas funções se deu para facilitar o processo de testes e troubleshooting, e não é visível ao usuário.</p>
