# Introduction

<!-- TODO -->
Projetado com o padrão singleton e com uma modelagem para reaproveitamento, o projeto Cowsay Clone possui quase todos os recursos da versão original e contém alguns bônus.

# Author(s)

<!-- TODO -->
Pedro Lucas Medeiros do Nascimento (pedrolucas.jsrn@gmail.com)

# Problems found or limitations

<!-- TODO -->

# Grading

<!-- TODO -->
Preencha os itens que você implementou, indicando qual a nota esperada para cada item.


Item     | Valor máximo   | Valor esperado
-------- | :-----: | :-----:
Read, validate, and process command-line arguments | 20 | 20
Show help as requested `-h` | 2 | 2
Support all cow moods `-bdgpstwy` (8 in total, 2 pts each)  | 16 | 16
Support cow flip `-f`    | 5 | 5
Suspend excessive white space elimination and text wrapping `-n` | 5 | 2
Allow manual definition of eyes with `-E eye_string` | 5 | 5
Allow manual definition of tongue with `-T tongue_string` | 5 | 5
Support definition of wrap column with `-W column_value` | 5 | 5
Read message from standard input correctly | 5 | 5
Remove all excessive white spaces and wrap text at or close to column 40 (default behavior) | 5 | 4
Support message with left-alignment (default behavior, no option needed) | 5 | 5
Support message with center-alignment `-J c` | 5 | 5
Support message with right-alignment `-J r` | 5 | 5
Print billboard decoration (frame) correctly, for single- and multi-line messages | 8 | 8
The project contains at least two classes | 10 | 10
Program handles errors properly | 4 | 4

# Compiling and Runnig

O projeto é compilado através do Make e seu executável estará presente na pasta "./build/".

<!-- TODO -->
```bash
make
./build/cowsay [OPTIONS] [text]
```
