<h1 align="center">Laboratório de Biotecnologia</h1>

<p align="center">Repositório com o objetivo de solução do problema 2669 do Beecrowd/URI</p>

<div align="center">
  <img src="https://img.shields.io/badge/Status-Solved-%2363cf51?style=for-the-badge" />
  <img src="https://img.shields.io/github/languages/top/josefilho/Beecrowd-2669?color=%237159c1&style=for-the-badge" />
  <img src="https://img.shields.io/github/size/josefilho/Beecrowd-2669/2669.cpp?color=%237159c1&style=for-the-badge" />
  <img src="https://img.shields.io/badge/Made%20By-Jose%20Carlos-%237159c1?style=for-the-badge" />
</div>

## Resumo do problema

Uma cadeia ponderada é definida sobre um alfabeto **Σ** e uma função **f** que atribui um peso a cada caractere do alfabeto. Assim, podemos definir o peso de uma cadeia **s** como a soma dos pesos de todos os caracteres em **s**. Considerando que **s** é formada por letras minúsculas e cada letra tem um peso diferente entre 1 e 26: a letra a tem peso 1, a letra b tem peso 2 e assim por diante.
O objetivo é determinar, para uma cadeia **s**, a quantidade de pesos distintos encontrada ao avaliar os pesos de todas as subcadeias não vazias de caracteres consecutivos de **s**.

### Entrada

Apenas uma linha, que contém a cadeia **s** formada por letras minúsculas, cujo comprimento | s | satisfaz 1 ≤| s |≤ 10⁵.

### Saída

O programa deve produzir uma única linha com um inteiro representando a quantidade de pesos distintos das subcadeias não vazias de caracteres consecutivos de **s**.

### Exemplos de entradas

| Entrada  | Saída |
| -------- | ----: |
| abbab    |     8 |
| dacwabhw |    26 |

Caso queira mais detalhes sobre o problema, [acesse o link](https://judge.beecrowd.com/pt/problems/view/2669).

O problema foi resolvido utilizando a linguagem C++ e o código fonte está disponível no arquivo `2669.cpp`.

Note o arquivo `Finding_submasses_in_weighted_strings_with_Fast_Fourier_Transform.pdf` que possui uma explicação acerca do algoritmo utilizado para a resolução do problema.

## Motivação

Em 2019 meu professor de Algoritmos e Estruturas de Dados I, Nilton César de Paula, apresentou a turma alguns problemas do Beecrowd/URI como parte da nota semestral. Um deles foi o problema 2669, que me chamou muito a atenção por ser de **Nível 10** entretanto, acredito que ele não havia notado que era impossível que um aluno do primeiro ano de Ciência da Computação conseguisse resolver o problema, visto que ele exige um conhecimento avançado de algoritmos e estruturas de dados. Na época, eu não consegui resolver o problema mas não desisti dele, nos anos subsequentes houveram muitas tentativas frustradas de resolução. Até que em 2023 apresentei o problema ao professor Rubens, que disse ser um problema interessante e que iria pesquisar sobre ele. Após alguns dias, ele me apresentou um artigo que resolvia o problema de forma eficiente utilizando a Transformada Rápida de Fourier (FFT). A partir disso, levei um tempo para entender a ideia e implementar o algoritmo, mas finalmente consegui.

## Agradecimentos e referências

Um profundo agradecimento ao professor [Rubens Barbosa Filho](http://lattes.cnpq.br/7880961489665197) por me mostrar que minha visão era limitada sobre o problema, além de encontrar o artigo que soluciona o problema de forma eficiente. Atualmente, o 30º colocado no ranking do Beecrowd/URI para o problema 2669 com tempo de resolução 2,333. Outro agradecimento aos autores do artigo que segue a citação abaixo:
> Nikhil Bansal, Mark Cieliebak, Zsuzsanna Lipták, Finding submasses in weighted strings with Fast Fourier Transform, Discrete Applied Mathematics, Volume 155, Issue 6, 2007, Pages 707-718, ISSN 0166-218X, https://doi.org/10.1016/j.dam.2005.09.019.

## Instalação

Clone este repositório e abra sua pasta

```bash
git clone https://github.com/josefilho/URI-2669-CPP.git
cd Beecrowd-2669
```

Caso utilize CLion use (recomendo utilização):

```bash
clion .
```

Caso utilize Visual Studio Code use:

```bash
code .
```

_Edite apenas o código que se encontra dentro do arquivo `2669.cpp`._

Não é necessário instalação de bibliotecas adicionais além das já existentes no C++.

### Autor

<a href="https://app.rocketseat.com.br/me/jose-carlos">
  <img
    style="border-radius: 50%;"
    src="https://avatars.githubusercontent.com/u/65318203?v=4"
    width="100px;"
    alt=""
  />
  <br />
  <sub>
    <b>  José Carlos</b>
  </sub>
</a>

Feito com 💜 por José Carlos. 👋🏼 Entre em contato!

[![Linkedin Badge](https://img.shields.io/badge/Linkedin-Jose%20Carlos-7159c1?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/filhojosecs/)
[![Gmail Badge](https://img.shields.io/badge/Gmail-Jose%20Carlos-7159c1?style=for-the-badge&logo=Gmail&logoColor=white&link=mailto:iamjose.filho@gmail.com)](mailto:iamjose.filho@gmail.com)
