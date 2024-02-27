#ifndef CONFIG_H_
#define CONFIG_H_

#define SIZE 100
#define DA_APPEND(xs, x) \
do { \
    if ((xs).count >= (xs).capacity) { \
        if ((xs).capacity == 0) (xs).capacity = 256; \
        else (xs).capacity *= 2; \
        (xs).items = realloc((xs).items, (xs).capacity * sizeof(*(xs).items)); \
    } \
    (xs).items[(xs).count++] = (x); \
} while (0)


#endif //CONFIG_H
