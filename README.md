
# Algoritmo de Ford-Fulkerson

Usando o Algoritmo de Ford-Fulkerson é possivel resolver problemas do dia a dia, como o fluxo da água, do caminho da origem até os locais de destino.

## Como Funciona o Algoritmo de Ford-Fulkerson

O algoritmo de Ford-Fulkerson opera encontrando iterativamente "caminhos de aumento" da fonte ao sumidouro na rede residual. Um caminho de aumento é uma rota onde ainda é possível enviar mais fluxo. A cada iteração:

## Como compilar o código
<br>1 passo: Abrir o prompt de comandp (cmd)
<br>2 passo: No terminal digitar cd(pasta em que o programa está) ex: cd Downloads
<br>3 passo: Apos abrir a pasta que o programa está, deve ser executado o seguinte comando "g++ ford_fulkerson.cpp -o ford_fulkerson" que criara um arquivo .exe do nosso código.
<br>4 passo: Apos a criação do .exe deve ser executado o seguinte comando ".\ford_fulkerson" e pressionar ENTER, o programa será executado. Ele calculará o fluxo máximo para o grafo predefinido no código mostrando o resultado no terminal.

<br>Com o grafo que já está definido no código a mensagem de resultado no terminal deve ser "Fluxo máximo na rede = 23"
