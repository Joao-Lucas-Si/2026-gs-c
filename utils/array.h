#ifndef ARRAY
#define ARRAY

#define print_format(x) _Generic((x), float: "%f", int: "%d", char: "%c", char*: "%s", default: "padrao")


#define  debug(x) printf(print_format(x), x), printf("\n")

#define len(array) sizeof(array) / sizeof(array[0])
#define soma(array)                                                            \
  ({                                                                           \
    typeof(array[0]) total;                                                    \
    for (int i = 0; i < len(array); i++) {                                     \
      total += array[i];                                                       \
    }                                                                          \
    total;                                                                     \
  })

#define max(array) maxSize(array, len(array))

#define maxSize(array, size)                                                   \
  ({                                                                           \
    typeof(array[0]) total = 0;                                                \
    for (int i = 0; i < size; i++) {                                           \
      if (array[i] > total) {                                                  \
        total = array[i];                                                      \
      }                                                                        \
    }                                                                          \
    total;                                                                     \
  })

#define forEach(array, callback) forEachSize(array, len(array), callback)

#define forEachSize(array, size, callback)                                     \
  for (int i = 0; i < size; i++) {                                             \
    callback(array[i]);                                                        \
  }

#define mapSize(array, to, tamanho, transformar)                                            \
  ({                                                                           \
    for (int i = 0; i < tamanho; i++) {                                     \
      to[i] = transformar(array[i]);                                           \
    }                                                                          \
  })

#define map(array, to, transformar) mapSize(array, to, len(array), transformar)

#define find(array, validar)                                                   \
  ({                                                                           \
    typeof(array[0]) *item;                                                    \
    for (int i = 0; i < len(array); i++) {                                     \
      if (validar(array[i])) {                                                 \
        item = &array[i];                                                      \
        break;                                                                 \
      }                                                                        \
    }                                                                          \
    item;                                                                      \
  })

#define expand(array) realloc(array, (len(array) + 1) * sizeof(array[0]));

void* expandir(void* lista, int* tamanho) ;

#define containsSize(array, size, target)                                      \
  ({                                                                           \
    int tem = 0;                                                               \
    for (int i = 0; i < size; i++) {                                           \
      if (array[i] == target) {                                                \
        tem = 1;                                                               \
        break;                                                                 \
      }                                                                        \
    }                                                                          \
    tem;                                                                       \
  })

#define contains(array, target) containsSize(array, len(array), target)
#endif
