#include "stack-vm.h"

/*
 * Instruction format
 * header: 2 bits
 * data: 30 bits
 *
 * header format:
 * 0 => positive integer
 * 1 => primitive instruction
 * 2 => negative integer
 * 3 => undefined
 * */

// functions
StackVM::StackVM() {
    // Initialising VM by reserving a block of memory
	memory.reserve(1000000);
}

/*
Extracting the type field froma  32 bit instr., and
storing it in the top 2 bits (31 and 30) */
i32 StackVM::getType(i32 instruction) {
	i32 type = 0xc0000000;
	type = (type & instruction) >> 30;
	return type;
}

/*
Extracting the data field and storing the data in
the lower 30 bits */
i32 StackVM::getData(i32 instruction) {
	i32 data = 0x3fffffff;
	data = data & instruction;
	return data;
}

// Fetching the next instruction:
void StackVM::fetch() {
	pc++;
}

// Decoding instr. currently in the PC 
void StackVM::decode() {
	typ = getType(memory[pc]);
	dat = getData(memory[pc]);
}

/*
Executing the current instr.
1. Checking if the instr. is pos or neg
2. Incrementing the stack pointer & pushing the data onto the stack
*/
void StackVM::execute() {
	if (typ == 0 || typ == 2) {
		sp++;
		memory[sp] = dat;
	} else {
		doPrimitive();
	}
}

// Executing a primitive operation based on the data field of the instr
void StackVM::doPrimitive() {
	switch (dat) {
		case 0: // halt
			std::cout << "halt" << std::endl;
			running = 0;
			break;
		case 1: // add
			std::cout << "add " << memory[sp - 1] << " " << memory[sp] << std::endl;
			memory[sp - 1] = memory[sp - 1] + memory[sp];
			sp--;
			break;
	}
}

// This runs the VM by executing instr.'s in a loop
void StackVM::run() {
	pc -= 1;
	while (running == 1) {
		fetch();
		decode();
		execute();
		std::cout << "tos: " << memory[sp] << std::endl;
	}
}

// Loading a program into the VM's memory
void StackVM::loadProgram(std::vector<i32> prog) {
	for (i32 i = 0; i < prog.size(); i++) {
		memory[pc + i] = prog[i];
	}	
}