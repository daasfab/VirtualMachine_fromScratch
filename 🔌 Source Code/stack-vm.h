#ifndef STACK_VM_H
#define STACK_VM_H

#include <iostream>
#include <vector>

// type definitions 
typedef int32_t i32; // signed int of 32 bits

class StackVM {
    // registers:
    i32 pc = 100; // program counter 
    i32 sp = 0; // stack pointer 
    std::vector<i32> memory; // memory that CPU will access
    i32 typ = 0;// type and data registers
    i32 dat = 0;
    i32 running = 1;

    // private functions:
    i32 getType(i32 instruction);
    i32 getData(i32 instruction);
    
    // CPU runs in a loop and performs 3 operations repeatedly:
    void fetch();
    void decode();
    void execute();
    void doPrimitive(); // helper function for executing instructions

    public:
    // public functions:
    StackVM();
    void run();
    void loadProgram(std::vector<i32> prog);
};

#endif