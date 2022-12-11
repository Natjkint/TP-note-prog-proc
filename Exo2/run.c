#include "typedef.h"

ordonnanceur run(ordonnanceur A){
    while (A.file != 0){
        A = step(A);
    }
    return A;
}
