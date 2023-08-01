#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <string>

#include "SymbolTable.h"

using namespace std;

class Assembler {
   public:
    /** Instruction types */
    enum InstructionType {
        A_INSTRUCTION,
        C_INSTRUCTION,
        L_INSTRUCTION,
        NULL_INSTRUCTION
    };

    /** C-instruction destinations */
    enum InstructionDest {
        A,
        D,
        M,
        AM,
        AD,
        MD,
        AMD,
        NULL_DEST
    };

    /** C-instruction jump conditions */
    enum InstructionJump {
        JLT,
        JGT,
        JEQ,
        JLE,
        JGE,
        JNE,
        JMP,
        NULL_JUMP
    };

    /** C-instruction computations/op-codes */
    enum InstructionComp {
        CONST_0,
        CONST_1,
        CONST_NEG_1,
        VAL_A,
        VAL_M,
        VAL_D,
        NOT_A,
        NOT_M,
        NOT_D,
        NEG_A,
        NEG_M,
        NEG_D,
        A_ADD_1,
        M_ADD_1,
        D_ADD_1,
        A_SUB_1,
        M_SUB_1,
        D_SUB_1,
        D_ADD_A,
        D_ADD_M,
        D_SUB_A,
        D_SUB_M,
        A_SUB_D,
        M_SUB_D,
        D_AND_A,
        D_AND_M,
        D_OR_A,
        D_OR_M,
        NULL_COMP
    };

    /** Practical Assignment 5 methods */
    Assembler();
    ~Assembler();
    
    void doFirstPass(SymbolTable* symbolTable, string instructions[], int numOfInst);
    string doSecondPass(SymbolTable* symbolTable, string instructions[], int numOfInst);

    InstructionType parseInstructionType(string instruction);
    InstructionDest parseInstructionDest(string instruction);
    InstructionJump parseInstructionJump(string instruction);
    InstructionComp parseInstructionComp(string instruction);
    string parseSymbol(string instruction);

    string translateDest(InstructionDest dest);
    string translateJump(InstructionJump jump);
    string translateComp(InstructionComp comp);
    string translateSymbol(string symbol, SymbolTable* symbolTable);
};

#endif /* ASSEMBLER_H */