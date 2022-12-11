#include "typedef.h"

ordonnanceur run(ordonnanceur A){
    while (A.file != 0){
        step(A);
    }
    return A;
}
