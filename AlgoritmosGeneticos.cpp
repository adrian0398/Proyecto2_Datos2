//
// Created by adrian on 12/10/19.
//

#include "AlgoritmosGeneticos.h"



#include <vector>
#include <iostream>
#include <algorithm>
#include <random>


// Valid Genes
const string GENES = "0123456789";

// Target string to be generated
const string TARGET = "999999";
#define POPULATION_SIZE 10

bool operator<(const AlgoritmosGeneticos &ind1, const AlgoritmosGeneticos &ind2)
{
    return ind1.fitness < ind2.fitness;
}

int AGrandom_num(int start, int end)
{
    int tmp1, tmp2;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(start,end);

    tmp1=dist6(rng);

    return dist6(rng);
}

// Create random genes for mutation
char AGmutated_genes()
{
    int len = GENES.size();
    int r = AGrandom_num(0, len-1);
    return GENES[r];
}


string AGcreate_gnome()
{
    int len = TARGET.size();
    string gnome = "";
    for(int i = 0;i<len;i++){
        //limitarle segun el tipo
        gnome += AGmutated_genes();}
    return gnome;
}

string combine(string tmp1, string tmp2)
{
    string nuevo="";

    for(int i=0;i<=5;i++){
        int rand=AGrandom_num(0,1);
        if(rand==0){
            nuevo+=tmp1.at(i);
        }
        if(rand==1){
            nuevo+=tmp2.at(i);
        }
    }

    return nuevo;
}

// Perform mating and produce new offspring
string AlgoritmosGeneticos::mate(Estudiantes* padre1, Estudiantes* padre2)
{
    // chromosome for offspring
    string child_chromosome = "";


        // random probability
        float p = AGrandom_num(0, 100);

        cout<<p<<"proba"<<endl;

        // if prob is less than 0.45, insert gene
        // from parent 1
        if(p <= 25)
            child_chromosome = padre1->chromosome;

            // if prob is between 0.45 and 0.90, insert
            // gene from parent 2
        else if(p>25 && p < 50)
            child_chromosome = padre2->chromosome;

        else if(p>=50 && p < 90) {
            child_chromosome=combine(padre1->chromosome,padre2->chromosome);
        }
            // otherwise insert random gene(mutate),
            // for maintaining diversity
        else {
            for(int i = 0;i<=5;i++) {
                child_chromosome += AGmutated_genes();

            }
            cout<<"sali de aqui";
            }




    // create new Individual(offspring) using
    // generated chromosome for offspring
    cout<<"Estoy  hasta  apich"<<child_chromosome<<endl;
    return child_chromosome;
};


// Calculate fittness score, it is the number of
// characters in string which differ from target
// string.
int AlgoritmosGeneticos::cal_fitness(string chromo)
{

    int fitness = 999999-stoi(chromo);

    return fitness;
};
