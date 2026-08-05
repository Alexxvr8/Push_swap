*Este proyecto ha sido creado como parte del currículo de 42 por \<alvicent\>.*

# Libft

## Descripción

Libft es el primer proyecto del cursus de 42. Consiste en construir una librería estática en C (`libft.a`) reimplementando funciones de la libc, añadiendo algunas utilidades propias y trabajando con listas enlazadas.

La idea es sencilla: en lugar de usar las funciones que ya existen, las escribes tú desde cero. Así entiendes de verdad cómo funcionan cosas como `memcpy`, `split` o `atoi` antes de usarlas ciegamente en proyectos futuros. La librería se divide en tres partes:

- **Parte 1:** reimplementaciones de funciones estándar de libc (`ft_strlen`, `ft_memcpy`, `ft_atoi`…)
- **Parte 2:** funciones adicionales de manipulación de strings y salida por file descriptor (`ft_substr`, `ft_split`, `ft_itoa`…)
- **Parte 3:** funciones para manejar listas enlazadas simples con la estructura `t_list`

La librería crece con cada proyecto del cursus, así que merece la pena hacerla bien desde el principio.

---

## Instrucciones

### Compilar

```bash
make        # genera libft.a
make clean  # elimina los .o
make fclean # elimina los .o y libft.a
make re     # fclean + make
```

### Usar en otro proyecto

Copia `libft.a` y `libft.h` al directorio de tu proyecto y compila así:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o programa
```

En tus archivos fuente:

```c
#include "libft.h"
```

---

## Descripción detallada de la librería

### Parte 1 — Funciones de libc

Reimplementaciones directas de funciones estándar. No dependen de ninguna función externa.

| Función | Descripción |
|---|---|
| `ft_isalpha` | Comprueba si el carácter es alfabético |
| `ft_isdigit` | Comprueba si el carácter es un dígito |
| `ft_isalnum` | Comprueba si el carácter es alfanumérico |
| `ft_isascii` | Comprueba si el carácter está en el rango ASCII estándar |
| `ft_isprint` | Comprueba si el carácter es imprimible |
| `ft_toupper` | Convierte un carácter a mayúscula |
| `ft_tolower` | Convierte un carácter a minúscula |
| `ft_strlen` | Devuelve la longitud de una cadena |
| `ft_memset` | Rellena un bloque de memoria con un valor dado |
| `ft_bzero` | Pone a cero un bloque de memoria |
| `ft_memcpy` | Copia un bloque de memoria |
| `ft_memmove` | Copia un bloque de memoria (seguro ante solapamientos) |
| `ft_memchr` | Busca un byte en un bloque de memoria |
| `ft_memcmp` | Compara dos bloques de memoria |
| `ft_strlcpy` | Copia una cadena con límite de tamaño |
| `ft_strlcat` | Concatena cadenas con límite de tamaño |
| `ft_strchr` | Busca un carácter en una cadena desde el inicio |
| `ft_strrchr` | Busca un carácter en una cadena desde el final |
| `ft_strncmp` | Compara dos cadenas hasta n caracteres |
| `ft_strnstr` | Busca una subcadena dentro de otra con límite |
| `ft_atoi` | Convierte una cadena a entero |
| `ft_calloc` | Reserva memoria inicializada a cero |
| `ft_strdup` | Duplica una cadena en memoria dinámica |

### Parte 2 — Funciones adicionales

Funciones que no existen en libc o que se comportan de forma diferente.

| Función | Descripción |
|---|---|
| `ft_substr` | Extrae una subcadena a partir de un índice y longitud dados |
| `ft_strjoin` | Concatena dos cadenas en una nueva |
| `ft_strtrim` | Elimina caracteres del inicio y el final de una cadena |
| `ft_split` | Divide una cadena usando un carácter delimitador |
| `ft_itoa` | Convierte un entero a cadena (incluye negativos) |
| `ft_strmapi` | Aplica una función a cada carácter y devuelve la nueva cadena |
| `ft_striteri` | Aplica una función a cada carácter modificando la cadena original |
| `ft_putchar_fd` | Escribe un carácter en el file descriptor indicado |
| `ft_putstr_fd` | Escribe una cadena en el file descriptor indicado |
| `ft_putendl_fd` | Escribe una cadena seguida de `\n` en el file descriptor indicado |
| `ft_putnbr_fd` | Escribe un entero en el file descriptor indicado |

### Parte 3 — Listas enlazadas

Funciones para manejar una lista enlazada simple usando esta estructura:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Función | Descripción |
|---|---|
| `ft_lstnew` | Crea un nuevo nodo |
| `ft_lstadd_front` | Añade un nodo al principio de la lista |
| `ft_lstadd_back` | Añade un nodo al final de la lista |
| `ft_lstsize` | Devuelve el número de nodos de la lista |
| `ft_lstlast` | Devuelve el último nodo |
| `ft_lstdelone` | Libera un nodo sin tocar el siguiente |
| `ft_lstclear` | Libera todos los nodos de la lista |
| `ft_lstiter` | Recorre la lista aplicando una función a cada nodo |
| `ft_lstmap` | Recorre la lista y genera una nueva lista con los resultados |

---

## Recursos

- [man pages online](https://man7.org/linux/man-pages/) — referencia principal para el comportamiento de cada función
- [GNU libc manual](https://www.gnu.org/software/libc/manual/) — documentación completa de la libc
- [Makefile tutorial](https://makefiletutorial.com/) — para entender cómo funciona el Makefile

### Uso de IA

Se utilizó IA (Claude) puntualmente para consultar el comportamiento esperado de algunas funciones (equivalente a leer el man) y para estructurar el README. No se usó para generar el código de ninguna función de la librería.
