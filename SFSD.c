#include <stdio.h>
#include <stdlib.h>





#define b 20
//N_readACC and N_writeACC: counters to track the number of write and read accesses to the file.
int N_readACC, N_writeACC = 0;

//ENTENTE DECLARATION
typedef struct Entete {
    int nbBloc;
    int nbEnreg;
}Entete;

//record declaration
typedef struct Student {
    int deleted;
    int key;
    char familyName[20];
    char firstName[20];
}Student;

//Bloc declaration
typedef struct Bloc {
    Student tab[20];
    int NB;
}Bloc;

typedef struct TNOF {
    FILE *F;
    Entete Ent;
}TNOF;

//Open function
TNOF* open(char fileName[], const char mode) {
    TNOF *file = malloc(sizeof(TNOF));
    if ((mode == 'A') || (mode == 'a')){
        file->F = fopen(fileName, "r+b");
        rewind(file->F);
        fread(&(file->Ent), sizeof(Entete), 1, file->F);
    }
    else if ((mode == 'N') || (mode == 'n')) {
            file->F = fopen(fileName,"w+b");
            // initialization de l'entete
            (file->Ent).nbBloc = 0;
            (file->Ent).nbEnreg = 0;
            rewind(file->F);
            fwrite(&(file->Ent), sizeof(Entete), 1, file->F);
        }
    else printf("unrecognized opening mode");
    return file;
}

//Close function
void close(TNOF *file) {
    //before we close a file we save its header
    rewind(file->F); //go to the beginning
    fwrite(&(file->Ent), sizeof(Entete), 1, file->F);
    fclose(file->F);
    free(file);
}

int ENTETE(TNOF *file, const int i) {
    if (i == 1) return (file->Ent).nbBloc;
    if (i == 2) return (file->Ent).nbEnreg;
}

void Aff_ENTETE(TNOF *file, const int i, const int val) {
    if (i == 1) (file->Ent).nbBloc = val;
    if (i == 2) (file->Ent).nbEnreg = val;
}

int Alloc_Bloc(TNOF *file) {
    Aff_ENTETE(file, 1, ENTETE(file, 1) + 1);
    return ENTETE(file, 1);
}

void readDir(TNOF *file, const int i, Bloc *Buf) {
    if (i <= ENTETE(file, 1)) {
        fseek(file->F, (i - 1) * sizeof(Bloc) + sizeof(Entete), SEEK_SET);
        fread(Buf, sizeof(Bloc), 1, file->F);
        N_readACC ++;
    }
}

void writeDir (TNOF *file, int i, Bloc Buf) {
    fseek(file->F, sizeof(Entete) + (i - 1) * sizeof(Bloc), SEEK_SET);
    fwrite(&Buf, sizeof(Bloc), 1, file->F);
    N_writeACC ++;
}



void insertStudent (Student s, TNOF *file) {

    Bloc buf;
    // if the file is empty
    if (ENTETE(file, 1) == 0) {
        Alloc_Bloc(file);
        buf.NB = 1;
        buf.tab[0] = s;
        buf.tab[0].deleted = 0;
        writeDir(file, 1, buf);
        Aff_ENTETE(file, 2, 1);
        return;
    }

    //if the file has logically deleted records
    int i = 1;
    while (i <= ENTETE(file, 1)) {
        readDir(file, i, &buf);
        for (int j = 0; j < buf.NB; j++) {
            if (buf.tab[j].deleted == 1) {
                buf.tab[j] = s;
                buf.tab[j].deleted = 0;
                writeDir(file, i, buf);
                Aff_ENTETE(file, 2, ENTETE(file, 2) + 1);
                return;
            }
        }
        i++;
    }

    //in the ordinary case
    //when there still empty space in the last bloc
    readDir(file, file->Ent.nbBloc, &buf);
    if (buf.NB < b) {
        buf.tab[buf.NB] = s;
        buf.tab[buf.NB].deleted = 0;
        buf.NB ++;
        writeDir(file, ENTETE(file, 1), buf);
        Aff_ENTETE(file, 2, ENTETE(file, 2) + 1);
        return;
    }
    // if all the blocs are full
    int newBloc = Alloc_Bloc(file);
    buf.NB = 1;
    buf.tab[0] = s;
    buf.tab[0].deleted = 0;
    writeDir(file, newBloc, buf);
    Aff_ENTETE(file, 2, ENTETE(file, 2) + 1);
}

//structure to return when searching for an element
typedef struct position {
    int found;
    int blocNumber;
    int articleNumber;
}position;

//the search function
position search(TNOF *file, int key) {
    position p;
    p.found = 0;
    p.articleNumber = -1;
    p.blocNumber = -1;
    Bloc buf;
    for (int i = 1; i <= ENTETE(file, 1); i++) {
        readDir(file, i, &buf);
        for (int j = 0; j < buf.NB; j++) {
            if (buf.tab[j].key == key) {
                p.found = 1;
                p.articleNumber = j;
                p.blocNumber = i;
                return p;
            }
        }
    }
    return p;
}

//The logical delete function
void logicalDelete(TNOF *file, int key) {
    position p = search(file, key);
    if (p.found == 0) {
        printf("The element you want to delete doesn't exist");
        return;
    }
    Bloc buf;
    readDir(file, p.blocNumber, &buf);
    buf.tab[p.articleNumber].deleted = 1;
    writeDir(file, p.blocNumber, buf);
}


 // the real delete
void delete(TNOF *file, int key){
    position p = search(file, key);
    if (p.found == 0) return; // no such student, nothing to do

    Bloc buf;
    // if the record to delete is the last one
    if ( (p.blocNumber == ENTETE(file, 1)) && (p.articleNumber == buf.NB - 1) ) {
        readDir(file, ENTETE(file, 1), &buf);
        buf.NB --;
        if (buf.NB == 0) {
            Aff_ENTETE(file, 1, ENTETE(file, 1) - 1);
            Aff_ENTETE(file, 2, ENTETE(file, 2) - 1);
            return;
        }
        Aff_ENTETE(file, 2, ENTETE(file, 2) - 1);
        writeDir(file, ENTETE(file, 1), buf);
        return;
    }

    // in the regular case
    Student s;
    readDir(file, ENTETE(file, 1), &buf);
    s = buf.tab[buf.NB - 1];
    buf.NB --;
    if (buf.NB == 0) Aff_ENTETE(file, 1, ENTETE(file, 1) - 1);
    else writeDir(file, ENTETE(file, 1), buf);
    readDir(file, p.blocNumber, &buf);
    buf.tab[p.articleNumber] = s;
    Aff_ENTETE(file, 2, ENTETE(file, 2) - 1);
    writeDir(file, p.blocNumber, buf);
}

// a function to split one file to two files according to the records key
void splitFileToTwo(TNOF *originalFile, TNOF *file1, TNOF *file2, int key) {
    Bloc buf1, buf2, buf3;
    buf2.NB = 0;
    buf3.NB = 0;
    int k = 0, l = 0, kk = 0, ll=0;
    for (int i = 1; i <= ENTETE(originalFile, 1); i++) {
        readDir(originalFile, i, &buf1);
        for (int j = 0; j < buf1.NB; j++) {
            if (buf1.tab[j].key < key) {
                if (buf2.NB == b) {
                    l = Alloc_Bloc(file1);
                    Aff_ENTETE(file1, 2, ENTETE(file1, 2) + buf2.NB);
                    writeDir(file1, l, buf2);
                    k = 0;
                    buf2.NB = 0;
                }
                buf2.tab[k] = buf1.tab[j];
                buf2.NB ++;
                k ++;
                continue;
            }
            if (buf3.NB == b) {
                ll = Alloc_Bloc(file2);
                Aff_ENTETE(file2, 2, ENTETE(file2, 2) + buf3.NB);
                writeDir(file2, ll, buf3);
                kk = 0;
                buf3.NB = 0;
            }
            buf3.tab[kk] = buf1.tab[j];
            buf3.NB ++;
            kk ++;
        }
    }
    if (k != 0) {
        l = Alloc_Bloc(file1);
        Aff_ENTETE(file1, 2, ENTETE(file1, 2) + buf2.NB);
        writeDir(file1, l, buf2);
    }
    if (kk != 0) {
        ll = Alloc_Bloc(file2);
        Aff_ENTETE(file2, 2, ENTETE(file2, 2) + buf3.NB);
        writeDir(file2, ll, buf3);
    }
}
