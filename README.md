# Visual2DArray

This library aims to help you create C ++ programs to view and interact with two-dimensional arrays (matrices), like board games.

*Only pt_BR for now :-(*

	#include <visual2darray.hpp>
    using namespace visual2darray;

### Creating
	Visual2DArray g{n, m}; // Create an array with n rows and m columns.

### Definindo o visual da matriz
	g.title(string s);
Set window title.

	g.cellSize(int w, int h);
Set cells size (px).

	g.borderSize(int w);
Define a espessura das bordas da matriz, em pixels;

	g.backgroundColor(Color color);
Define a cor de fundo usando um nome de cor pré-definido (`Color::Green`, `Color::Red`, `Color::Black`, por exemplo).

	g.backgroundColor(string hexcode);
Define a cor de fundo usando uma cor em formato HTML (“#00FF00”, “#FF0000”, “#000000”, por exemplo).

	g.backgroundColor(int r, int g, int b);
Define a cor de fundo usando valores de 0 a 255 para os 3 componentes RGB.

	g.cellColor(Color color);
	g.cellColor(string hexcode);
	g.cellColor(int r, int g, int b);
Define a cor das células.

	g.messageColor(Color color);
	g.messageColor(string hexcode);
	g.messageColor(int r, int g, int b);
Define a cor das mensagens de texto.

	g.setImage(int value, string fileName);
Define o nome do arquivo da imagem que será exibida em uma célula quando o seu conteúdo for igual à *value*. As imagens devem estar em uma pasta *“img”*. Caso o nome do arquivo não definido, será procurado automaticamente um arquivo com nome idêntico ao valor da célula. Em último caso, nenhuma imagem será exibida e o valor da célula será apresentado. Recomenda-se usar arquivos .png

### Manipulando os dados

	g[l][c]
Acessa o elemento da matriz na linha *l*, coluna *c*.

	g.fill(int value);
Preenche toda a matriz com o valor especificado.

	g.shuffle();
Embaralha o conteúdo da matriz (reposiciona aleatoriamente os valores).


### Controlando o programa

	g.run();
Exibe a tela do programa.

	g.close();
Fecha a janela, encerrando o programa.

	g.restart();
Reinicia o programa.

	g.pause(int ms);

Pausa o programa pelo tempo especificado em milissegundos.

	g.confirm(string msg);

Exibe um diálogo de confirmação com a mensagem definida. Retorna um bool (*true* caso o usuário clicou no botão “Yes”, *false* caso contrário).

	g.alert(string msg);
Exibe um diálogo de alerta com a mensagem definida.

	g << valores;
Exibe conteúdos na área de mensagens do programa, de forma equivalente ao *cout*.

	g.clearMessage();
Limpa a área de mensagens do programa.

	g.beep();
Toca um alerta sonoro.

### Controlando os eventos do programa

	g.onMouseClicked(fn);
Executa a função *fn* cada vez que uma célula da matriz for clicada durante a execução do programa. A função deve receberá uma referência para o Visual2DArray atual e não retornará nenhum valor. Portanto ele deve ter a seguinte declaração (apenas o nome pode ser alterado): `void mousefn(Visual2DArray& game)`
		
	g.clickedRow();
Retorna o índice (0..*n*) da linha da última célula que foi clicada. Esta função somente pode ser chamada dentro do evento *onMouseClicked*.

	g.clickedCol();
Retorna o índice (0..*m*) da coluna da última célula que foi clicada. Esta função somente pode serchamada dentro do evento *onMouseClicked*.

	g.mouseButton();
Retorna qual botão do mouse foi pressionado no último clique em célula. Os valores possíveis são `MouseButton::Left`, `MouseButton::Middle` ou `MouseButton::Right`. Esta função somente pode ser chamada dentro do evento *onMouseClicked*.

g.onKeyPressed(fn);
Executa a função *fn* cada vez que uma tecla for pressionada durante a execução do programa. A função deve receberá uma referência para o Visual2DArray atual e não retornará nenhum valor. Portanto ele deve ter a seguinte declaração (apenas o nome pode ser alterado): `void keyboardfn(Visual2DArray& game)`

	g.lastKey();
Retorna qual foi a última tecla pressionada. Exemplos de teclas são `Key::Left`, `Key::Up`, `Key::Down`, `Key::Right` e `Key::Space`. Esta função somente pode ser chamada dentro do evento *onKeyPressed*.

	g.onStart(fn);
Executa a função *fn* cada vez que o programa for iniciado/reiniciado. Isto ocorre ao entrar no programa, se o usuário teclar F2 ou se a função *restart()* for executada. A função deve receberá uma referência para o Visual2DArray atual e não retornará nenhum valor. Portanto ele deve ter a seguinte declaração (apenas o nome pode ser alterado): `void startfn(Visual2DArray& game)`

### Sorteio aleatório

	g.randomRow();
Retorna o índice de uma linha aleatória dentro da matriz.

	g.randomCol()
Retorna o índice de uma coluna aleatória dentro da matriz.

	g.randomValue(int inf, int sup);
Retorna um valor inteiro aleatório entre *inf* e *sup*.


### Exemplo

![Preview](img/v2dpreview.png?raw=true "Preview")
