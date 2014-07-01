#ifndef TEMPLATES_H_
# define TEMPLATES_H_

/*
** CAT concatenates two define.
** Here the cheat to generate code during compilation time
*/

# define CAT(X, Y) X##_##Y
# define TEMPLATE(X, Y) CAT(X, Y)

#endif
