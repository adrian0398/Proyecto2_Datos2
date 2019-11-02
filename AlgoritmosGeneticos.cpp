//
// Created by adrian on 12/10/19.
//

#include "AlgoritmosGeneticos.h"



#include <vector>
#include <iostream>
#include <algorithm>


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
    int range = (end-start)+1;
    int random_int = start+(rand()%range);
    return random_int;
}

// Create random genes for mutation
char AGmutated_genes()
{
    int len = GENES.size();
    int r = AGrandom_num(0, len-1);
    return GENES[r];
}



AlgoritmosGeneticos::AlgoritmosGeneticos(string chromosome){
    this->chromosome=chromosome;
    fitness = cal_fitness();
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

// Perform mating and produce new offspring
AlgoritmosGeneticos AlgoritmosGeneticos::mate(Estudiantes* padre1, Estudiantes* padre2)
{
    // chromosome for offspring
    string child_chromosome = "";

    int len = chromosome.size();
    for(int i = 0;i<len;i++)
    {
        // random probability
        float p = AGrandom_num(0, 100)/100;

        // if prob is less than 0.45, insert gene
        // from parent 1
        if(p < 0.45)
            child_chromosome += padre1->chromosome;

            // if prob is between 0.45 and 0.90, insert
            // gene from parent 2
        else if(p < 0.90)
            child_chromosome += padre2->chromosome;

            // otherwise insert random gene(mutate),
            // for maintaining diversity
        else {
            child_chromosome += AGmutated_genes();
            }

        }


    // create new Individual(offspring) using
    // generated chromosome for offspring
    return AlgoritmosGeneticos(child_chromosome);
};


// Calculate fittness score, it is the number of
// characters in string which differ from target
// string.
int AlgoritmosGeneticos::cal_fitness()
{
    int len = TARGET.size();
    int fitness = 0;
    for(int i = 0;i<len;i++)
    {
        if(chromosome[i] != TARGET[i])
            fitness++;
    }
    return fitness;
};



Estudiantes* AlgoritmosGeneticos::run(Estudiantes* padre1, Estudiantes* padre2){


    Estudiantes* estudiantes;
    // current generation
    int generation = 0;

    vector<AlgoritmosGeneticos> population;
    bool found = false;

    // create initial population
   /* for(int i = 0;i<POPULATION_SIZE;i++)
    {
        string gnome = AGcreate_gnome();
        population.push_back(AlgoritmosGeneticos(gnome));
    }*/

    //while(! found)
    //{
        // sort the population in increasing order of fitness score
      //  sort(population.begin(), population.end());

        // if the individual having lowest fitness score ie.
        // 0 then we know that we have reached to the target
        // and break the loop
        //if(population[0].fitness <= 0)
        //{
          //  found = true;
            //break;
        //}

        // Otherwise generate new offsprings for new generation
        //vector<AlgoritmosGeneticos> new_generation;

        // Perform Elitism, that mean 10% of fittest population
        // goes to the next generation
       /* int s = (2*POPULATION_SIZE)/100;
        for(int i = 0;i<s;i++)
            new_generation.push_back(population[i]);

        // From 50% of fittest population, Individuals
        // will mate to produce offspring
        s = (90*POPULATION_SIZE)/100;
        for(int i = 0;i<s;i++)
        {
            int len = population.size();
            int r = AGrandom_num(0, POPULATION_SIZE/2);
            AlgoritmosGeneticos parent1 = population[r];
            r = AGrandom_num(0, POPULATION_SIZE/2);
            AlgoritmosGeneticos parent2 = population[r];
            AlgoritmosGeneticos offspring = parent1.mate(parent2);
            new_generation.push_back(offspring);
        }*/
        //population = new_generation;
        /*cout<< "Generation: " << generation << "\t";
        cout<< "String: "<< population[0].chromosome <<"\t";
        cout<< "Fitness: "<< population[0].fitness << "\n";*/

        //generation++;
    //}



    /*cout<< "Generation: " << generation << "\t";
    cout<< "String: "<< population[0].chromosome <<"\t";
    cout<< "Fitness: "<< population[0].fitness << "\n";*/

 return estudiantes;

};