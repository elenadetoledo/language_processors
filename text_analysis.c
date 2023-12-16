#include <stddef.h>                                                             /* for NULL */
#include <stdlib.h>                                                             /* for EXIT_SUCCESS and>#include "parser.h"
#include <stdbool.h>
// yylex is used to get tokens from lex
extern int yylex();
int current_token;
void Program();
void MainClass();
void StmtList();
void Statement();
void VarDecl();
void LeftValue();
void Exp();
void Exp1();
void Exp2();
void Index();
void IndexTail();
void Type();
void T();
void ExpTail();
void VExpTail();

// advance current token
static void consume() {
    current_token = yylex();
}

// return true if current token is expected
// otherwise return false
static bool peek(int expected_token) {
    if(current_token == expected_token) {
        return true;
    }
    return false;
}

void match(int expect){
        if(peek(expect)){
        printf("\nToken %d has been matched ",current_token);
        fflush(stdout);
         consume();
        }
        else syntax_error();
}

// write code to perform recursive descent based on the grammar after
// rewriting it
void Program(){
        printf("\n Entering Program");
        fflush(stdout);
        if (peek(KW_CLASS)){
                MainClass();
        }
}
void MainClass(){
        printf("\n Entering MainClass ");
        fflush(stdout);
        match(KW_CLASS);
        match(ID);
        match(TOK_LCURL);
        match(KW_PUB);
        match(KW_STAT);
        match(KW_VOID);
        match(KW_MAIN);
        match(TOK_LPAR);
        match(KW_STRING);
        match(TOK_LBRACK);
        match(TOK_RBRACK);
        match(ID);
        match(TOK_RPAR);
        match(TOK_LCURL);
        StmtList();
        match(TOK_RCURL);
        match(TOK_RCURL);
}

void StmtList(){
        printf("\n Entering StmtList");
        fflush(stdout);
        if(peek(ID)||peek(TOK_LCURL)||peek(KW_INT)||peek(KW_BOOL)||peek(KW_STRING)||peek(KW_IF)||peek(K>        Statement();
        StmtList();
}else{
        return;
}

}
void Statement(){
        printf("\n Entering Statement");
        fflush(stdout);
        if(peek(KW_INT)||peek(KW_BOOL)||peek(KW_STRING)) VarDecl();
        if(peek(TOK_LCURL)){
        match(TOK_LCURL);
        StmtList();
        match(TOK_RCURL);
        }
        if(peek(KW_IF)){
        match(KW_IF);
        match(TOK_LPAR);
        printf("\n From Statemetn to Exp");
        Exp();
        printf("\n Reached here");
        fflush(stdout);
        match(TOK_RPAR);
        Statement();
        match(KW_ELSE);
        Statement();
        }
        if(peek(KW_WHILE)){
        match(KW_WHILE);
        match(TOK_LPAR);
        Exp();
        match(TOK_RPAR);
        Statement();
        }
        if(peek(KW_SOUT1)){
        match(KW_SOUT1);
        match(TOK_LPAR);
        Exp();
        match(TOK_RPAR);
        match(TOK_SEMICOLON);
        }
        if(peek(KW_SOUT2)){
        match(KW_SOUT2);
        match(TOK_LPAR);
        Exp();
        match(TOK_RPAR);
        match(TOK_SEMICOLON);
        }
        if(peek(ID)){
        LeftValue();
        match(TOK_EQUAL);
        Exp();
        match(TOK_SEMICOLON);
        }
        if(peek(KW_RETURN)){
        match(KW_RETURN);
        Exp();
        match(TOK_SEMICOLON);
        }
}

void VarDecl(){
        printf("\n Entering VarDecl");
        fflush(stdout);
        Type();
        match(ID);
        Exp1();
        Exp2();
        match(TOK_SEMICOLON);
}
void Exp1(){
        printf("\n Entering Exp1");
        fflush(stdout);
        if(peek(TOK_EQUAL)){
        match(TOK_EQUAL);
        Exp();
        }else{
        return;
        }
}
void Exp2(){
        printf("\nEntering Exp2");
        fflush(stdout);
        if(peek(TOK_COMMA)){
        match(TOK_COMMA);
        match(ID);
        Exp1();
        Exp2();
        }else{
        return;
        }
}
void PrimeType(){
        fflush(stdout);
        printf("\n Entering PrimeType");
        if(peek(KW_INT)){
        match(KW_INT);
